#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("line2.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "line2.inp");
	}
	if ((output_fp = fopen("line2.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "line2.out");
	}
	int T, n;
	fscanf(input_fp, "%d", &T);
	int i, j, k, l;
	int line_A[1000];
	int line_L[1000];
	int temp[1000];
	int pick[1000];
	int N;
	for (i = 0; i < T; i++) {
		fscanf(input_fp, "%d", &n);
		for (j = 0; j < n; j++) {
			fscanf(input_fp, "%d ", &N);
			line_A[j] = N;
		}
		
		for (j = 0; j < n; j++) {
			fscanf(input_fp, "%d ", &N);
			line_L[j] = N;
		}

		for (j = n - 1; j >= 0; j--) {
			for (k = 0; k < n; k++) {
				if (line_A[j] == line_L[k]) {
					pick[line_A[j] - 1] = j - k;
					for (l = 0; l < n; l++)
						temp[l] = line_L[l];
					for (l = k; l <= j; l++) {
						if (l == j) {
							line_L[l] = line_A[j];
							break;
						}
						line_L[l] = temp[l + 1];
					}
					break;
				}
			}
		}
		for (k = 0; k < n; k++) {
			fprintf(output_fp, "%d", pick[k]);
			if (k != n - 1)
				fprintf(output_fp, " ");
		}
		fprintf(output_fp, "\n");
	}



	fclose(input_fp);
	fclose(output_fp);
	return 0;
}