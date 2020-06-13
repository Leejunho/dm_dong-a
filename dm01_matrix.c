#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("matrix.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "matrix.inp");
	}
	if ((output_fp = fopen("matrix.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "matrix.out");
	}
	unsigned int matrix[300][300];
	unsigned int T = 0, i, j, k, m;
	unsigned int a, b, s, t, check;

	fscanf(input_fp, "%d", &T);

	for (i = 0; i < T; i++) {
		unsigned int n;
		fscanf(input_fp, "%d", &n);

		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				unsigned int a;
				fscanf(input_fp, "%d", &a);
				matrix[j][k] = a;
			}
		}

	    for (a = 0; a < n; a++) {	
			for (b = 0; b < n; b++) {
				if (matrix[a][b] == 1) continue;
				else if (matrix[a][b] != 1) {
					check = 0;
					/*정방행렬인지 검사*/
					for (s = 0; s < n; s++) {						
						if (matrix[a][s] > matrix[a][b] || s==b) continue;
						for (t = 0; t < n; t++) {
							if (t==a || matrix[t][b] > matrix[a][b]) continue;
							else if ((matrix[a][s] + matrix[t][b]) == matrix[a][b]) {
								check=1;
								break;
							}
						}
						if (check) break;
					}//정방행렬 검사 끝나는 지점
					if (check==0) goto Exit;
				}
			}
		}
	Exit:
		if (check == 0) {
			fprintf(output_fp, "0\n");
		}
		else {
			fprintf(output_fp, "1\n");
		}
		

	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}

