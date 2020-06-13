#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char Alph_Order(int x) {
	return x + 64;
}
int Alph_int(char x) {
	if (x > 64 && x < 91 )
		return x - 64;
}

int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("spreadsheet.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "spreadsheet.inp");
	}
	if ((output_fp = fopen("spreadsheet.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "spreadsheet.out");
	}
	int T;
	fscanf(input_fp, "%d", &T);
	int i, k,m;

	for (i = 0; i < T; i++) {
		char N;
		int x = 0, y = 0;

		char str[100];
		fscanf(input_fp, "%s", &str);
		int strN = strlen(str);
		char num1[20], num2[20];
		int n = 0;
		if (str[0] == 'R') {
			
			for (k = 0; k < strN; k++) {
				if (str[k] > 47 && str[k] < 58) {
					num1[n] = str[k];
					n++;
				}
				if (str[k] == 'C') {
					num1[n] = '\0';
					break;
				}
			}
			n = 0;
			for (k; k < strN; k++) {
				if (str[k] > 47 && str[k] < 58) {
					num2[n] = str[k];
					n++;
				}
			}
			num2[n] = '\0';

			x += atoi(num1);
			y += atoi(num2);
			
			int check_k = 0;
			int arr_n[7];

			for (k = 4; k >= 0; k--) {
				int p;
				p = (int)pow(26.0, (double)k);

				if (y <= 26) {
					arr_n[check_k] = y;
					check_k++;
					break;
				}
				if (y / p != 0) {
					if (y%p == 0) {
						arr_n[check_k] = y / p - 1;
						y = y - ((y / p) - 1)*p;
						check_k++;
					}
					else {
						arr_n[check_k] = y / p;
						y = y % p;
						check_k++;
					}
				}
			}
			for (k = 0; k < check_k;k++) {
				fprintf(output_fp,"%c", Alph_Order(arr_n[k]));
			}
			fprintf(output_fp,"%d\n", x);
			   
			  



		}
		else {
			n = 0;
			for (k = 0; k < strN; k++) {
				if (str[k] > 47 && str[k] < 58) {
					num1[n] = str[k];
					n++;
				}
			}
			num1[n] = '\0';

			x += atoi(num1);
			fprintf(output_fp,"R%d", x);

			
			for (k = 0; k < strN; k++) {
				if (str[k] > 64 && str[k] < 91) {
					num2[k] = Alph_int(str[k]);
				}
				else
					break;
			}
			n = 0;
			for (m = k - 1; m >= 0; m--) {
				y = y + num2[n] * (int)pow(26.0, (double)m);
				n++;
			}
				
			
			fprintf(output_fp,"C%d\n", y);
		}
	}


	fclose(input_fp);
	fclose(output_fp);
	return 0;
}

