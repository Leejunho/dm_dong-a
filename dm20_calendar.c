#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int totalday_case1(int y, int m, int d)
{
	int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;
	int total = 0;
	total = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	
	if (!(y % 4) && y % 100 || !(y % 400))
		months[1]++;
	for (i = 0; i<m - 1; i++)
		total += months[i];
	total += d;

	return total;
}
int totalday_case2(int y, int m, int cnt , char day)
{
	int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;
	int total = 0;
	total = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;

	if (!(y % 4) && y % 100 || !(y % 400))
		months[1]++;
	for (i = 0; i<m - 1; i++)
		total += months[i];
	total += 1;
	check_day(total);
	
	return 0;
}
int check_day(int total) {
	char days[7][3] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
	int a;
	a = total % 7;
	printf("%s\n", days[a]);

	return 0;
}
int main() {
	FILE *input_fp, *output_fp;

	if ((input_fp = fopen("calendar.inp", "rt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "calendar.inp");
	}
	if ((output_fp = fopen("calendar.out", "wt")) == NULL)
	{
		fprintf(stderr, "can't open %s\n", "calendar.out");
	}
	while (1) {
		int T;
		char charTemp = '\0';
		fscanf(input_fp, "%d%c", &T, &charTemp);

		int Y = 0, M = 0, D = 0;
		int Y2 = 0, M2 = 0, D2 = 0;
		int cnt = 0;
		char day[3], day2[3];
		char *days2 = day2;
		int result = 0;
		if (T == 0) {
			fscanf(input_fp, "%d-%d-%d %d-%d-%d", &Y, &M, &D, &Y2, &M2, &D2);
			result = totalday_case1(Y, M, D) - totalday_case1(Y2, M2, D2);
			if (result < 0)
				result = -result;
			printf("%d\n", result);
		}
		else if (T == 1) {
			fscanf(input_fp, "%d-%d-%d %d-%d-%d-%s\n", &Y, &M, &D, &Y2, &M2, &cnt, &day2);
			printf("%s\n", days2);
		}
		else if (T == 2) {

		}
		else if (T == 3) {

		}
		else if (T == -1)
			break;
	}


	fclose(input_fp);
	fclose(output_fp);
	return 0;
}