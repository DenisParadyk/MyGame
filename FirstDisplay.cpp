#include "FirstDisplay.h"

logic FirstDisplay::check;
int FirstDisplay::row = 0;
int FirstDisplay::col = 0;

jmp_buf env;

void FirstDisplay::printConsole_map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {

			cout << check.c[i][j].value << " ";

		} cout << endl;

	} 
	cout << endl;
}

void FirstDisplay::mouse_click(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
		row = y / scale;
		col = x / scale;

		if (check.c[row][col].value == -1) {
			check.c[row][col].value = check.c[row][col].getGamerValue();
		}
		else return;

		printConsole_map();

		if(check.CheckAll(row, col) == true)
		{
			longjmp(env, 1);
		}

		check.c[row][col].numb++;
		check.c[row][col].invert();
	}
}

void FirstDisplay::draw_field()
{
	glBegin(GL_LINES);

	glColor3f(0.0, 0.0, 0.1);

	for (int i = 0; i < w; i += scale)
	{
		glVertex2i(i, 0); glVertex2i(i, h);
	}
	for (int i = 0; i < h; i += scale)
	{
		glVertex2i(0, i); glVertex2i(w, i);
	}

	glEnd();
}

void FirstDisplay::draw_circle(float x, float y, float r, int amountSegments)
{
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}

	glEnd();
}

void FirstDisplay::draw_map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check.c[i][j].value != -1)
			{
				glLineWidth(3);
				if (check.c[i][j].value == 0)
				{

					glBegin(GL_LINES);

					glVertex2i(j * scale, i * scale);
					glVertex2i(j * scale + scale, i * scale + scale);
					glVertex2i(j * scale, i * scale + scale);
					glVertex2i(j * scale + scale, i * scale);

					glEnd();
				}
				if (check.c[i][j].value == 1)
				{
					draw_circle((j * scale + (scale / 2)),
						(i * scale + (scale / 2)), 34, 20);
				}
			}
		}
	}
}