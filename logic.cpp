#include "logic.h"


void logic::CheckVertical(int row, int col)
{
	bool state;

	for (int i = 0; i < N; i++)
	{
		int a;
		int b;
		a = c[i][col].value;
		b = gamerVal.getGamerValue();
		if (a==b)
		{
			state = 0;
		}
		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "You have won by 'Y'" << gamerVal.getGamerValue() << endl;
	}
}

void logic::CheckHorizontal(int row, int col)
{
	bool state = 0;

	for (int i = 0; i < M; i++)
	{
		if (c[row][i].value == !gamerVal.getGamerValue()) {}

		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "You have won by 'X'" << gamerVal.getGamerValue() << endl;
	}
}

void logic::CheckFirstDiagonal()
{
	bool state = 0;

	for (int i = 0; i < M; i++)
	{
		if (c[i][i].value == gamerVal.getGamerValue()) {}
		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "Diagonal win" << gamerVal.getGamerValue() << endl;
	}

	for (int i = 0; i < M; i++)
	{
		if (c[i][i].value == !gamerVal.getGamerValue()) {}
		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "Diagonal win" << gamerVal.getGamerValue() << endl;
	}
}

void logic::CheckSecondDiagonal()
{
	bool state = 0;
	for (int i = 0, j = M - 1; i < M; j++, i--)
	{
		if (c[i][j].value == gamerVal.getGamerValue()) {}
		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "Diagonal win" << gamerVal.getGamerValue() << endl;
	}
}

void logic::CheckDraw()
{
	if (gamerVal.numb > N * M - 1)
	{
		cout << "Draw";
	}
}