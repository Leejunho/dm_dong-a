#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000000
long long number_term(long long A,long long L,int term) {
	if (A == MAX)
		return term;
	if (A > L)
		return term;
	if (A == 1) {
		term++;
		return term;
	}
	else if (A % 2 == 0) {
		number_term(A / 2, L, term+1);
	}
	else if (A % 2 == 1 ) {
		number_term(3 * A + 1, L, term + 1);
	}
}
int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("sequence.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "sequence.inp");
	}
	if ((output_fp = fopen("sequence.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "sequence.out");
	}
	int casenum = 1;
	while (1) {
		long long A = 0, L = 0;
		fscanf(input_fp, "%lld %lld", &A, &L);
		if (A < 0 && L < 0)
			break;

		int term = 0;
		term = number_term(A, L, term);

		fprintf(output_fp, "Case %d: A = %lld, limit = %lld, number of terms = %d\n", casenum, A, L, term);
		casenum++;

	}
	fclose(input_fp);
	fclose(output_fp);
	return 0;
}