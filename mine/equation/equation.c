#include <stdio.h>

void	equation(int n)
{
	int a = 0;
	int b;
	int c;

	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			c = 0;
			while (c < 10)
			{
				if (a * 10 + b + c * 10 + a == n)
					printf("A = %i, B = %i, C = %i\n", a,b,c);
				c++;
			}
			b++;
		}
		a++;
	}
}
