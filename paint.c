#include <stdio.h>
#include <stdlib.h>

#define NMAX 250000
#define MMAX 250000
#define KMAX 100000

int main()
{
	unsigned n, k, m, i, d, lg, j, l, *z, v;

	FILE *fin = fopen("paint.in", "r");

	if (!fin) { printf("Eroare paint.in\n"); return 1; }

	fscanf(fin, "%u %u %u", &n, &k, &m);

	if (n < 1 || n > NMAX) { printf("Eroare valoare n\n"); return 2; }

	if (m < 1 || m > MMAX) { printf("Eroare valoare m\n"); return 3; }

	if (k < 1 || k > KMAX) { printf("Eroare valoare k\n"); return 4; }

	z = (unsigned*)calloc(n, sizeof(unsigned));

	for (v = i = 0; i < m; i++) {
		fscanf(fin, "%u %u", &d, &lg);

		/*if (!(0 <= d && d < lg && lg < n)) {
			printf("Eroare valoare d[%u], lg[%u]\n", i, i);
			return 5;
		}*/

		for (j = d, l = 0; l < lg && j < n; j++, l++) {
			z[j]++;
			
			if(z[j] == k) v++;
		}
	}

	free(z);

	fclose(fin);
	
	FILE *fout = fopen("paint.out", "w");

	fprintf(fout, "%u", n-v);

	fclose(fout);

	return 0;
}
// scor 40
