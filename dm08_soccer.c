#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("soccer.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "soccer.inp");
	}
	if ((output_fp = fopen("soccer.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "soccer.out");
	}
	int T;
	int i, j, l, m,s;
	fscanf(input_fp, "%d", &T);
	for (i = 0; i < T; i++) {
		fprintf(output_fp, "Test Case #%d:", i + 1);
		int n, k;
		fscanf(input_fp, "%d %d", &n, &k);
		int point[1000] = { 0, };
		int gd[1000] = { 0, };
		int away[1000] = { 0, };
		int rank[20] = { 0, };
		int X, Y, goal_x, goal_y;
		for (j = 0; j < k; j++) {
			for (l = 0; l < 2 * (n - 1); l++) {
				for (m = 0; m < n / 2; m++) {
					fscanf(input_fp, "%d %d", &X, &Y);
					fscanf(input_fp, "%d %d", &goal_x, &goal_y);
					
					if (goal_x > goal_y) {
						point[X] += 3;
						point[Y] += 0;
					}
					else if (goal_x < goal_y) {
						point[X] += 0;
						point[Y] += 3;
					}
					else if (goal_x == goal_y) {
						point[X] += 1;
						point[Y] += 1;
					}

					gd[X] += goal_x - goal_y;
					gd[Y] += goal_y - goal_x;

					away[X] += goal_x;
				}
			}
		}
		
		int cnt;
		for (j = 1; j <= n; j++) {
			cnt = 1;
			for (l = 1; l <= n; l++) {
				if ((j != l) && (point[j] < point[l])) {
					cnt++;
				}
			}
			rank[j] = cnt;
		}
		int c = 0;
		for (m = 1; m <= n; m++) {
			cnt = 0;
			for (l = 1; l <= n; l++) {
				if ((m != l) && (rank[m] == rank[l])) {
					c++;
					if (gd[m] < gd[l]) {
						c--;
						cnt++;
					}
				}
			}
			rank[m] += cnt;
		}
		if (c != 0) {
			for (m = 1; m <= n; m++) {
				cnt = 0;
				for (l = 1; l <= n; l++) {
					if ((m != l) && (rank[m] == rank[l])) {
						if (away[m] < away[l]) {
							cnt++;
						}
					}
				}
				rank[m] += cnt;
			}
		}
		
		


		for (j = 1; j <= n; j++) {
			fprintf(output_fp, " %d", rank[j]);
		}
		fprintf(output_fp, "\n");
	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}




