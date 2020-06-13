#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("mail.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "mail.inp");
	}
	if ((output_fp = fopen("mail.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "mail.inp");
	}
	int T,i;
	fscanf(input_fp, "%d", &T);
	char A[6] = { '0','0','0','0','0','0' };
	char B[6] = { '0','0','1','1','1','1' };
	char C[6] = { '0','1','0','0','1','1' };
	char D[6] = { '0','1','1','1','0','0' };
	char E[6] = { '1','0','0','1','1','0' };
	char F[6] = { '1','0','1','0','0','1' };
	char G[6] = { '1','1','0','1','0','1' };
	char H[6] = { '1','1','1','0','1','0' };
	for (i = 0; i < T; i++) {
		int N;
		fscanf(input_fp, "%d\n", &N);
		char mail[100][6];
		int j,k;
		for (j = 0; j < N; j++) {
			for (k = 0; k < 6; k++) {
				mail[j][k] = fgetc(input_fp);
			}
		}	
		for (j = 0; j < N; j++) {
			int ch_A = 0, ch_B = 0, ch_C = 0, ch_D = 0, ch_E = 0, ch_F = 0, ch_G = 0, ch_H = 0;
			for (k = 0; k < 6; k++) {
				if (mail[j][k] != A[k]) ch_A++;
				if (mail[j][k] != B[k]) ch_B++;
				if (mail[j][k] != C[k]) ch_C++;
				if (mail[j][k] != D[k]) ch_D++;
				if (mail[j][k] != E[k]) ch_E++;
				if (mail[j][k] != F[k]) ch_F++;
				if (mail[j][k] != G[k]) ch_G++;
				if (mail[j][k] != H[k]) ch_H++;
			}
			if (ch_A == 0) fprintf(output_fp,"A");
			else if (ch_B == 0) fprintf(output_fp,"B");
			else if (ch_C == 0) fprintf(output_fp,"C");
			else if (ch_D == 0) fprintf(output_fp,"D");
			else if (ch_E == 0) fprintf(output_fp,"E");
			else if (ch_F == 0) fprintf(output_fp, "F");
			else if (ch_G == 0) fprintf(output_fp, "G");
			else if (ch_H == 0) fprintf(output_fp, "H");
			else {
				if (ch_A == 1 && ch_B > 1 && ch_C > 1 && ch_D > 1 && ch_E > 1 && ch_F > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "A");
				else if (ch_B == 1 && ch_A > 1 && ch_C > 1 && ch_D > 1 && ch_E > 1 && ch_F > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "B");
				else if (ch_C == 1 && ch_B > 1 && ch_A > 1 && ch_D > 1 && ch_E > 1 && ch_F > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "C");
				else if (ch_D == 1 && ch_B > 1 && ch_C > 1 && ch_A > 1 && ch_E > 1 && ch_F > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "D");
				else if (ch_E == 1 && ch_B > 1 && ch_C > 1 && ch_D > 1 && ch_A > 1 && ch_F > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "E");
				else if (ch_F == 1 && ch_B > 1 && ch_C > 1 && ch_D > 1 && ch_E > 1 && ch_A > 1 && ch_G > 1 && ch_H > 1) fprintf(output_fp, "F");
				else if (ch_G == 1 && ch_B > 1 && ch_C > 1 && ch_D > 1 && ch_E > 1 && ch_F > 1 && ch_A > 1 && ch_H > 1) fprintf(output_fp, "G");
				else if (ch_H == 1 && ch_B > 1 && ch_C > 1 && ch_D > 1 && ch_E > 1 && ch_F > 1 && ch_G > 1 && ch_A > 1) fprintf(output_fp, "H");
				else fprintf(output_fp,"X");
			}
		}
		fprintf(output_fp,"\n");
	}
	fclose(input_fp);
	fclose(output_fp);
	return 0;
}