#include <stdio.h>
//1231168 and 2395456
int getScore(int num)
{
	int digit;
	int score=0, count_ones=0;
	int prev_digit=13, seq_len=1;
	int flag = 0;

	if(num%7==0)
	{
		score++;
	}

	while(num!=0)
	{
		digit = num%10;
		if(!(digit & 0x01))
		{
			score+=2;
			// printf("Even number found %d\n", digit);
		}

		if(digit == 9)
		{
			score+=4;
			// printf("Nine found %d\n", digit);
		}

		if(digit == 1)
		{
			count_ones++;
			if(count_ones>=2)
			{
				score+=5;
				// printf("Consecutive ones found %d\n", digit);
			}
		}
		else
		{
			count_ones=0;
		}

		if(digit == prev_digit-1)
		{
			seq_len++;
			flag = 1;
			// printf("Sequence found %d\n", digit);
		}
		else
		{
			score+=(seq_len*seq_len);
			seq_len=1;
			flag = 0;
		}
		prev_digit = digit;
		num = num/10;
	}

	if(flag)
	{
		score+=(seq_len*seq_len);
		score--;
	}

	return score;
}

int main() 
{
	printf("Score for number 1231168 is %d\n", getScore(1231168));
	return 0;
}
