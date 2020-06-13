#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("numgame.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "numgame.inp");
	}
	if ((output_fp = fopen("numgame.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "numgame.inp");
	}
	int T;
	fscanf(input_fp, "%d", &T);
	int i,j;
	for (i = 0; i < T; i++) {
		int N;
		fscanf(input_fp, "%d", &N);
		for (j = 0; j < N; j++) {

		}
	}



	fclose(input_fp);
	fclose(output_fp);
	return 0;
}