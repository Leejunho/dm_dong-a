#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("fraction.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "fraction.inp");
	}
	if ((output_fp = fopen("fraction.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "fraction.inp");
	}
	int t, x, y, x1, x2;
	int check;
	
	while (1) {

		fscanf(input_fp, "%d", &t);
		if (t == 0) {
			break;
		}

		int i, j, k;
		check = 0;
		int vs[100];
		int v = 0;
		for (i = 2; i <= t + 1; i++) {
			x = i - 1;
			y = t*i;
			if (y % x == 0) {
				check++;
				vs[v]=
			}
			if (i >= 4) {
				for (j = 2; j < i / 2; j++) {
					x1 = i - j;
					if (y%x1 == 0 && y%x==0 && x != x1) {
						check++;
					}
				}
			}
		}
		printf("%d\n", check);

	}


	fclose(input_fp);
	fclose(output_fp);
	return 0;
}