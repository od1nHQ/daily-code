#include <stdio.h>

int main() 
{
	short h;
	double x=0, y;
	for (int n = 0; n < 5; n++) {
		for (; x <= 4; x += 0.25)
		{

			if (x >= 0 && x < 2) y = x - 1;
			else if (x == 2) {
				for (y = -1; y <= 1; y += 0.25)
					printf("* ");
				h = 0;
				goto end;

			}
			else if (x >= 2 && x < 3) y = x - 3;
			else if (x == 3) {
				for (y = -1; y <= 0; y += 0.25)
					printf("* ");

				h = 0;
				goto end;

			}
			else if (x >= 3 && x < 4) y = -1;
			else if (x == 4) {
				for (x = 3; x <= 3.25; x += 0.25) {
					printf("*\n");
				}
				goto finish;
			}
			h = (y + 1) * 10;
		end:
			for (; h > 0; h--)
			{
				printf(" ");
			}
			printf("*\n");


		}

	finish:
		x = 0;
	}
	return 0;
}
