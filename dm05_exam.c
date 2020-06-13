#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 1000
int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("exam.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "exam.inp");
	}
	if ((output_fp = fopen("exam.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "exam.out");
	}
	int T, test_case_num;
	fscanf(input_fp, "%d\n", &T);
	int i, k, j, l, m, n;

	char good_char[NUM];
	char P[NUM];
	char Q[NUM];

	int good_num, P_num, Q_num;
	for (i = 0; i < T; i++) {
		fprintf(output_fp, "Test Case: #%d\n", i + 1);

		fscanf(input_fp, "%s", &good_char);
		good_num = strlen(good_char);
		fscanf(input_fp, "%s", &P);
		P_num = strlen(P);

		fscanf(input_fp, "%d\n", &test_case_num);
		for (k = 0; k < test_case_num; k++) {
			fscanf(input_fp, "%s", &Q);
			Q_num = strlen(Q);
			int check = 0;
			int check_num = 0;
			for (j = 0; j < P_num; j++) {
				if ((P[j] != '?') && (P[j] != '*') && (P[j] != Q[j])) {
					check++;
					break;
				}//이부분은 수정좀 해야할듯 ;;

				if (P[j] == '?') {
					check_num++;
					for (m = 0; m < good_num; m++) {
						if (Q[j] == good_char[m]) {
							check++;
							break;
						}
						
					}
				}
				if (P[j] == '*') {
					check_num++;
					int count = 0;
					for (l = P_num - 1; l >= j; l--) {
						if (P[l] == '?') {
							check_num++;
							for (m = 0; m < good_num; m++) {
								if (Q[(Q_num - 1 - count)] == good_char[m]) {
									check++;
									break;
								}
							}
						}
						if (P[l] == '*') {
							if (P_num == Q_num + 1)
								check++;
							else {
								int star_check = 0;
								int for_check = 0;
								for (n = j; n < Q_num - count; n++) {
									for_check++;
									for (m = 0; m < good_num; m++) {
										if (Q[n] == good_char[m]) {
											star_check++;
											break;
										}

									}

								}
								if (star_check != for_check)
									check++;
							}
						}
						count++;
					}
					break;
				}
			}
			if (check == check_num)
				fprintf(output_fp, "Yes\n");
			else
				fprintf(output_fp, "No\n");


		}




	}



	fclose(input_fp);
	fclose(output_fp);
	return 0;
}


