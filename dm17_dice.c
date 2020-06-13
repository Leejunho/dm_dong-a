#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("dice.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "dice.inp");
	}
	if ((output_fp = fopen("dice.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "diec.inp");
	}
	int T;
	fscanf(input_fp, "%d", &T);
	int i, j,k;
	char charTemp = '\0';
	int dice[10000][6];
	int floor=0, top=0;
	int f_pos, t_pos;
	int max = 0, sum = 0;
	int result = 0;

	for (i = 0; i < T; i++) {
		for (j = 0; j < 6; j++) {
			fscanf(input_fp, "%d%c", &dice[i][j], &charTemp);
		}
	}
	int op[6] = {5,3,4,1,2,0};
	for (i = 0; i < 7; i++) {
		floor = i;
		for (k = 0; k < T; k++) 
		{
			
			for (j = 0; j < 6; j++)
			{
				if (dice[k][j] == floor) 
					break;
			}
			top = dice[k][op[j]];


			for (j = 0; j < 6; j++)
			{
				if (dice[k][j] != floor && dice[k][j] != top)
				{
					if (dice[k][j] > max)
					{
						max = dice[k][j];
					}
				}
			}

			sum = sum + max;

			max = 0;
			floor = top;
		}

		if (result < sum)
		{
			result = sum;
		}
		sum = 0;
	}
	fprintf(output_fp,"%d", result);


	fclose(input_fp);
	fclose(output_fp);
	return 0;
}