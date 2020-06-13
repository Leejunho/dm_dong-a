#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("2digit_prime.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "2digit_prime.inp");
	}
	if ((output_fp = fopen("2digit_prime.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "2digit_prime.out");
	}
	int T, a, b, N;
	fscanf(input_fp, "%d", &T);
	int i, j, k, p;
	int prime;

	for (i = 0; i < T; i++) {
		fscanf(input_fp, "%d %d", &a, &b);
		prime = 0;

		for (a; a <= b; a++) {
			int A[5];
			int aa = a;
			int divisor;
			for (j = 0; j < 5; j++) {
				A[j] = aa % 10;
				if ((aa / 10) != 0) {
					aa = aa / 10;
				}
				else
					break;
			}
			//2자리 소수 찾기
			for (k = 0; k < (j*(j + 1)) / 2; k++) {
				divisor = 0;
				if (j == 0) {
					N = A[0];
				}
				if (j == 1) {
					N = A[0] * 10 + A[j];
				}
				if (j == 2) {
					if (k < j)
						N = A[k] * 10 + A[k + 1];
					else
						N = A[0] * 10 + A[2];
				}
				if (j == 3) {
					if (k<j)
						N = A[k] * 10 + A[k + 1];
					else if (k<5)
						N = A[k - 3] * 10 + A[k - 1];
					else
						N = A[0] * 10 + A[3];
				}
				if (j == 4) {
					if (k<j)
						N = A[k] * 10 + A[k + 1];
					else if (k<7)
						N = A[k - 4] * 10 + A[k - 2];
					else if (k < 9)
						N = A[k - 7] * 10 + A[k - 4];
					else
						N = A[0] * 10 + A[4];
				}
				if (N<10) continue;
				for (p = 1; p*p <= N; p++) {
					if (N%p == 0) {
						divisor++;
						if (p*p < N)
							divisor++;
					}
				}
				if (divisor == 2) {
					prime++;
					goto exit;
				}

			}

			for (k = 0; k < (j*(j + 1)) / 2; k++) {
				divisor = 0;
				if (j == 0) {
					N = A[0];
				}
				if (j == 1) {
					N = A[j] * 10 + A[0];
				}
				if (j == 2) {
					if (k < j)
						N = A[k + 1] * 10 + A[k];
					else
						N = A[2] * 10 + A[0];
				}
				if (j == 3) {
					if (k<j)
						N = A[k + 1] * 10 + A[k];
					else if (k<5)
						N = A[k - 1] * 10 + A[k - 3];
					else
						N = A[3] * 10 + A[0];
				}
				if (j == 4) {
					if (k<j)
						N = A[k + 1] * 10 + A[k];
					else if (k<7)
						N = A[k - 2] * 10 + A[k - 4];
					else if (k < 9)
						N = A[k - 4] * 10 + A[k - 7];
					else
						N = A[4] * 10 + A[0];
				}
				if (N<10) continue;
				for (p = 1; p*p <= N; p++) {
					if (N%p == 0) {
						divisor++;
						if (p*p < N)
							divisor++;
					}
				}
				if (divisor == 2) {
					prime++;
					goto exit;
				}
			}
		exit:
			continue;

		}
		fprintf(output_fp, "%d\n", prime);
	}


	fclose(input_fp);
	fclose(output_fp);
	return 0;
}

