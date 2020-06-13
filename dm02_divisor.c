#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("divisor.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "divisor.inp");
	}
	if ((output_fp = fopen("divisor.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "divisor.out");
	}
	int T, a, b, n;
	int i, j, k;
	int count, divisor;
	fscanf(input_fp, "%d", &T);

	for (i = 0; i < T; i++) {

		fscanf(input_fp, "%d %d", &a, &b);

		count = 0;
		for (a; a <= b; a++) {
			divisor = 0;
			for (k = 1; k*k <= a; k++) {
				if ((a%k) == 0) { 
					divisor++;
					if (k*k < a) {
						divisor++;
					}
				}
			}
			if (a%divisor == 0) count++;
		}


		fprintf(output_fp, "%d\n", count);
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}

