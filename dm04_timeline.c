#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10000

int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("timeline.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "timeline.inp");
	}
	if ((output_fp = fopen("timeline.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "timeline.out");
	}
	int T, N;
	fscanf(input_fp, "%d", &T);
	int i, j,k,l,m;

	for (i = 0; i < T; i++) {
		fscanf(input_fp, "%d", &N);

		int start[NUM], start_2[NUM];
		int end[NUM],end_2[NUM];
		int sy, sm, sd, ey, em, ed;
		for (j = 0; j < N; j++) {
			fscanf(input_fp,"%d.%d.%d %d.%d.%d", &sy, &sm, &sd, &ey, &em, &ed);
			start[j] = sy * 10000 + sm * 100 + sd;
			end[j] = ey * 10000 + em * 100 + ed;
		}
		int line = 1,total_line=1;
		int cnt,check;
		for (j = 0; j < N; j++) {
			cnt = 1;
			for (k = 0; k < N; k++) {
				start_2[0] = start[j];
				end_2[0] = end[j];
				if (k != j) {
					if (end[j] > start[k])
						if (end[k] > start[j]) {
							check = 1;
							if (1<cnt) {
								for (l = 0; l <= cnt; l++) {
									if ((start[k] > end_2[l]) || (end[k] < start_2[l])) {
										check = 0;
										break;
									}
								}
							}
							if (check) {
								start_2[cnt] = start[k];
								end_2[cnt] = end[k];
								cnt++;
							}
						}
				}
			}
			line = cnt;
			if (total_line <= line)
				total_line = line;
				
		}
		fprintf(output_fp, "%d\n", total_line);
		

		}
		





	fclose(input_fp);
	fclose(output_fp);
	return 0;
}

