#include "SecondDisplay.h"

void SecondDisplay::setUserDate()
{
	while(1)
	{
		cout << ".'.'.'.'.'.'.'.'.'.'.'.'.'.'.'" << endl;

		cout << "Enter name of first Player: ";
		cin >> firstPlayer;
		cout << "He will do the pace of the X's character " << endl;

		cout << ".'.'.'.'.'.'.'.'.'.'.'.'.'.'.'" << endl;

		cout << "Enter name of second Player: ";
		cin >> secondPlayer;
		cout << "He will do the pace of the O's character " << endl;

		cout << ".'.'.'.'.'.'.'.'.'.'.'.'.'.'.'" << endl;

		if(firstPlayer != secondPlayer)
		{
			break;
		}
	}
}

string SecondDisplay::getFirstUserDate()
{
	return firstPlayer;
}

string SecondDisplay::getSecondUserDate()
{
	return secondPlayer;
}

void SecondDisplay::drawGameLog(const char * text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[25];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);

	glLineWidth(3);

	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void SecondDisplay::closeGame()
{
	char key[1];

	cout << "Click 'q' to quit the game" << endl;

	cin >> key;

	if (key == "q") 
	{
		exit(1);
	}
}

void SecondDisplay::Message()
{
	string WinFP = "Win " + getFirstUserDate() + " with X character";
	string WinSP = "Win " + getSecondUserDate() + " with O character";
	string printDraw = "Draw";

	/*switch (gameVal.getGamerValue())
	{
	case 0:

		drawGameLog(WinFP.data(), WinFP.size(), 150, 150);
		break;

	case 1:

		drawGameLog(WinSP.data(), WinSP.size(), 150, 150);
		break;
	}*/



		if (check.CheckVertical(gameWindow.row, gameWindow.col) && gameVal.getGamerValue() == 0)
		{
			drawGameLog(WinFP.data(), WinFP.size(), 150, 150);
		}

		if (check.CheckVertical(gameWindow.row, gameWindow.col) && gameVal.getGamerValue() == 1)
		{
			drawGameLog(WinSP.data(), WinSP.size(), 150, 150);
		}

		if (check.CheckHorizontal(gameWindow.row, gameWindow.col) && gameVal.getGamerValue() == 0)
		{
			drawGameLog(WinFP.data(), WinFP.size(), 150, 150);
		}

		if (check.CheckHorizontal(gameWindow.row, gameWindow.col) && gameVal.getGamerValue() == 1)
		{
			drawGameLog(WinSP.data(), WinSP.size(), 150, 150);
		}

		if (check.CheckDraw())
		{
			drawGameLog(printDraw.data(), printDraw.size(), 150, 150);
		}

		cout <<"Winer!!!!!! " << gameVal.getWiner() << endl;

		//closeGame();
	}


