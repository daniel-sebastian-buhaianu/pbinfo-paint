#include <stdio.h>
#include <stdlib.h>

#define NMAX 250000
#define MMAX 250000
#define KMAX 100000

int main()
{
	unsigned n, k, m, i, d, lg, *z, nr, s;

	FILE *fin = fopen("paint.in", "r");

	if (!fin) { printf("Eroare paint.in\n"); return 1; }

	fscanf(fin, "%u %u %u", &n, &k, &m);

	if (n < 1 || n > NMAX) { printf("Eroare valoare n\n"); return 2; }

	if (m < 1 || m > MMAX) { printf("Eroare valoare m\n"); return 3; }

	if (k < 1 || k > KMAX) { printf("Eroare valoare k\n"); return 4; }

	z = (unsigned*)calloc(n, sizeof(unsigned));

	for (i = 0; i < m; i++) {
		fscanf(fin, "%u %u", &d, &lg);

		z[d]++;

		if (d+lg < n) z[d+lg]--;
	}

	fclose(fin);

	for (nr = s = i = 0; i < n; i++) {
		s += z[i];
		
		if (s < k) nr++;
	}

	free(z);

	FILE *fout = fopen("paint.out", "w");

	fprintf(fout, "%u", nr);

	fclose(fout);

	return 0;
}
// scor 100
