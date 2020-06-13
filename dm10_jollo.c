#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int MAX(int a, int b, int c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a&&b > c) {
		return b;
	}
	else
		return c;
}
int MID(int a, int b, int c) {
	if ((b > a && a > c) || (b < a &&a < c)) {
		return a;
	}
	else if ((a > b && b > c) || (a < b &&b < c)) {
		return b;
	}
	else
		return c;
}
int MIN(int a, int b, int c) {
	if (a < b&&a < c) {
		return a;
	}
	else if (b < a&&b < c) {
		return b;
	}
	else
		return c;
}
int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("jollo.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "jollo.inp");
	}
	if ((output_fp = fopen("jollo.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "jollo.out");
	}
	int A, B, C, X, Y;
	int s1, s2, s3, p1, p2;
	while (1) {
		fscanf(input_fp,"%d %d %d %d %d", &A, &B, &C, &X, &Y);
		if (A == 0)
			break;
		s1 = MIN(A, B, C);
		s2 = MID(A, B, C);
		s3 = MAX(A, B, C);
		if (X > Y) {
			p1 = Y;
			p2 = X;
		}
		else {
			p1 = X;
			p2 = Y;
		}
		
		if (p2<s1) {//1 d
			fprintf(output_fp,"-1\n");
		}
		else if (p1<s1 && s1<p2 && p2<s2) {//2d
			fprintf(output_fp,"-1\n");
		}
		else if (p1<s1 && s2<p2 && p2<s3) {//3d
			fprintf(output_fp,"-1\n");
		}
		else if (p1<s1 && p2>s3) {//4 psssp
			if (s3 + 1 == p2) {
				if (p2 == 52)
					fprintf(output_fp,"-1\n");
				else
					fprintf(output_fp,"%d\n", p2 + 1);
			}
			else
				fprintf(output_fp,"%d\n", s3 + 1);
		}
		else if (p1 > s1 && p2 < s2) {//5 sppss d
			fprintf(output_fp,"-1\n");
		}
		else if (p1 > s1 && p1<s2 && p2>s2 &&p2 < s3) {//6 spsps
			fprintf(output_fp,"-1\n");
		}
		else if (p1 > s1 && p1 < s2 && p2 > s3) {//7 spssp
			if (s3 + 1 == p2) {
				if (p2 == 52)
					fprintf(output_fp,"-1\n");
				else
					fprintf(output_fp,"%d\n", p2 + 1);
			}
			else
				fprintf(output_fp,"%d\n", s3 + 1);
		}
		else if (s2 < p1 && p2<s3) {//d8 sspps
			if ( s2 + 1 == p1) {
				if (p1 + 1 != p2) 
					fprintf(output_fp,"%d\n", p1 + 1);

				else {
					if (p2 + 1 != s3) 
						fprintf(output_fp,"%d\n", p2 + 1);

					else {
						if (s3 == 52) 
							fprintf(output_fp,"-1\n");
						else 
							fprintf(output_fp,"%d\n", s3 + 1);
					}
				}
			}
			else 
				fprintf(output_fp,"%d\n", s2 + 1);
			
		}
		else if (s2 < p1 && p1<s3 && s3<p2) {//d9
			if (s2 + 1 == p1) {
				if (p1 + 1 == s3) {
					if (s3 + 1 == p2) {
						if (p2 == 52) {
							fprintf(output_fp,"-1\n");
						}
						else
							fprintf(output_fp,"%d\n", s3 + 1);
					}
					else
						fprintf(output_fp,"%d\n", s3 + 1);
				}
				else {
					fprintf(output_fp,"%d\n", p1 + 1);
				}
			}
			else {
				fprintf(output_fp,"%d\n", s2 + 1);
			}
		}
		else if (s3 < p1) {//d10
			if (s1 != 1) {
				fprintf(output_fp,"1\n");
			}
			else if (s2 != 2) {
				fprintf(output_fp, "2\n");
			}
			else if (s3 != 3) {
				fprintf(output_fp, "3\n");
			}
			else if (p1 != 4) {
				fprintf(output_fp, "4\n");
			}
			else if (p2 != 5) {
				fprintf(output_fp, "5\n");
			}
			else {
				fprintf(output_fp, "6\n");
			}
		}
		



	}

	fclose(input_fp);
	fclose(output_fp);
	return 0;
}
