#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("frog.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "frog.inp");
	}
	if ((output_fp = fopen("frog.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "frog.out");
	}
	while (1) {
		int T;
		char charTemp = '\0';
		fscanf(input_fp, "%d%c", &T, &charTemp);
		int N = 0, D = 0;
		int i;
		for (i = 0; i < N; i++) {

		}

	}
	fclose(input_fp);
	fclose(output_fp);
	return 0;
}