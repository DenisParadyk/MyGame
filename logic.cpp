#include "logic.h"


bool logic::CheckVertical(int row, int col)
{
	bool state;

	for (int i = 0; i < N; i++)
	{
		if (c[i][col].value == gamerVal.getGamerValue())
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
		return true;
	}
	else
	{
		return false;
	}
}

bool logic::CheckHorizontal(int row, int col)
{
	bool state = 0;

	for (int i = 0; i < M; i++)
	{
		if (c[row][i].value == gamerVal.getGamerValue()) {}

		else
		{
			state = 1;
			break;
		}
	}
	if (!state)
	{
		cout << "You have won by 'X'" << gamerVal.getGamerValue() << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool logic::CheckFirstDiagonal()
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
		return true;
	}
	else
	{
		return false;
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
		return true;
	}
	else
	{
		return false;
	}
}

bool logic::CheckSecondDiagonal()
{
	bool state = 0;
	for (int i = 0, j = M; i < M; j++, i--)
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
		return true;
	}
	else
	{
		return false;
	}
}

bool logic::CheckDraw()
{
	if (c[M][N].numb > N * M - 2)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}

bool logic::CheckAll(int row, int col)
{
	if (CheckVertical(row, col) ||
		CheckHorizontal(row, col) ||
		CheckFirstDiagonal()||
		CheckSecondDiagonal()) 
	{
		gamerVal.setWiner();

		return true;
	}

	return CheckDraw();
}