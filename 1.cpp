#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int a[25][80], i, j, x, y, X, Y, w, q, dir, f, n, m, c, l, C, h, t, g, brk, u, v, e[25][80], r, o, bf, N, M, s, k, sm, F, z[25][80], slp, slpf, slps;
char b, head, eat, d, p[50];
string map, alf;
ifstream config, conf, high, dmp, mp, fmp;
ofstream out;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void buffersize(int x, int y)
{
	COORD size;
	size.X = x;
	size.Y = y;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), size);
}

void zero(int a)
{
	for (i = 0; i < 25; i++)
		for (j = 0; j < 80; j++)
		{
			if (a == 1)
				if (e[i][j] != -1)
					e[i][j] = 0;
			if (a == 0)
				if (z[i][j] != -1)
					z[i][j] = 0;
		}
}

void voln()
{
	o = r = 1;
	while (r && o < 1000)
	{
		o++;
		r = 0;
		for (i = 0; i < 25; i++)
			for (j = 0; j < 80; j++)
				if (e[i][j] == o - 1)
				{
					if (e[i][j + 1] == 0 && (a[i][j + 1] == 0 || a[i][j + 1] - u + o - 3 - c > 0 && a[i][j + 1] > 0))
						e[i][j + 1] = o;
					if (e[i][j - 1] == 0 && (a[i][j - 1] == 0 || a[i][j - 1] - u + o - 3 - c > 0 && a[i][j - 1] > 0))
						e[i][j - 1] = o;
					if (e[i + 1][j] == 0 && (a[i + 1][j] == 0 || a[i + 1][j] - u + o - 3 - c > 0 && a[i + 1][j] > 0))
						e[i + 1][j] = o;
					if (e[i - 1][j] == 0 && (a[i - 1][j] == 0 || a[i - 1][j] - u + o - 3 - c > 0 && a[i - 1][j] > 0))
						e[i - 1][j] = o;
					r = 1;
				}
	}
}

void neweat()
{
	n = m = 0;
	v = 0;
	while (a[n][m] != 0)
	{
		n = rand() % 21 + 3;
		m = rand() % 78 + 1;
		v++;
		if (v == 1000)
		{
			gotoxy(20, 6);
			cout << "Congratulations";
			m = x;
			n = y;
			break;
		}
	}
	gotoxy(m, n);
	cout << eat;

	zero(0);
	z[n][m] = r = o = 1;
	while (r && o < 1000)
	{
		o++;
		r = 0;
		for (i = 0; i < 25; i++)
			for (j = 0; j < 80; j++)
				if (z[i][j] == o - 1)
				{
					if (z[i][j + 1] == 0)
						z[i][j + 1] = o;
					if (z[i][j - 1] == 0)
						z[i][j - 1] = o;
					if (z[i + 1][j] == 0)
						z[i + 1][j] = o;
					if (z[i - 1][j] == 0)
						z[i - 1][j] = o;
					r = 1;
				}
	}

}

int way()
{
	i = n;
	j = m;
	k = 0;
	while (true)
	{
		if (i == y && j == x)
			return 1;
		if (k > 1000)
		{
			return 0;
		}
		N = i;
		M = j;
		if (e[i][j + 1] + 1 == e[i][j])
			j++;
		else if (e[i][j - 1] + 1 == e[i][j])
			j--;
		else if (e[i + 1][j] + 1 == e[i][j])
			i++;
		else if (e[i - 1][j] + 1 == e[i][j])
			i--;
		e[N][M] = -10;
		k++;
	}
	e[i][j] = -10;
}

void drawe()
{
	for (i = 3; i < 24; i++)
		for (j = 1; j < 79; j++)
		{
			gotoxy(j, i);
			if (e[i][j] == -10)
				cout << "@";
			else if (e[i][j] != -1)
				cout << alf[e[i][j] % (alf.length() + 1)];
		}
	gotoxy(m, n);
	cout << "$";
}

void draws()
{
	for (i = 3; i < 24; i++)
		for (j = 1; j < 79; j++)
		{
			if (a[i][j] > 0)
			{
				gotoxy(j, i);
				cout << char(a[i][j] + 'A' - 2 - u);
			}
		}
}

void bot()
{
	zero(1);
	e[y][x] = 1;
	voln();
	if (way() == 0)
		bf = s = 0;
}

void ln(int k)
{
	gotoxy(k, 0);
	cout << char(0xD1);
	gotoxy(k, 1);
	cout << char(0xB3);
	gotoxy(k, 2);
	cout << char(0xCF);
}

int Abs(int a)
{
	return max(a, -a);
}

int main()
{

	SetConsoleTitle("Snke 1.1");
	srand(t = time(NULL));
	buffersize(80, 40);

	out.open("readme.txt");
	out << "Snke 1.1\nФайл справки\n\nУправление:\nКлавиши вверх, вправо, вниз, влево изменяют направление движения\nЕсли клавиша зажата по направлению движения, включается режим ускорения\n/ - режим удлинения\nb - автоматический режим\nv - суперускорение\n\nВерхняя панель:\n1. Длина\n2. Координаты головы\n3. Направление\n4. Координаты еды\n5. Расстояние до еды\n6. Координаты хвоста\n7. Шаги\n8. Двойная горизонтальная линия - режим ускорения; вертикальные линии - автоматический режим; горизонтальная линия - суперускорение\n9. Время\n10. Расстояние до еды в обход стенам\n11. Название карты\n12. Рекордная длина\n\nФайлы:\nreadme.txt\n	Файл справки\nconfig.txt\n	1. Начальная абцисса головы\n	2. Начальная ордината головы\n	3. Начальная длина\n	4. Начальное направление\n	5. Если 0, то удлинение выключено\n	6. Стандартная задержка\n	7. Задержка режима ускорения\n	8. Задержка суперускорения\n	9. Символ головы\n	10. Символ еды\n	11. Имя файла карты\nhighscore.txt\n	Рекордная длина\ndefault.map\n	Файл карты\n	21 строк, 78 столбцов\n	Если указана 1, то в соответсвующем месте на игровом поле стена";
	out.close();

	config.open("config.txt");
	if (config)
	{
		config >> x >> y >> l >> dir >> sm >> slp >> slpf >> slps >> head >> eat >> map;
		config.close();
	}
	else
	{
		config.close();
		out.open("config.txt");
		out << "40 11 5 2 1 400 25 0 O $ default.map";
		out.close();
		conf.open("config.txt");
		conf >> x >> y >> l >> dir >> sm >> slp >> slpf >> slps >> head >> eat >> map;
		conf.close();
	}
	high.open("highscore.txt");
	high >> h;
	high.close();

	strcpy(p, map.c_str());
	fmp.open(p);
	if (!fmp)
	{
		fmp.close();
		out.open(p);
		for (i = 0; i < 21; i++)
		{
			for (j = 0; j < 78; j++)
				out << "0";
			out << endl;
		}
		out.close();
	}
	dmp.open("default.map");
	if (!dmp)
	{
		dmp.close();
		out.open("default.map");
		for (i = 0; i < 21; i++)
		{
			for (j = 0; j < 78; j++)
				out << "0";
			out << endl;
		}
		out.close();
	}

	mp.open(p);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 78; j++)
		{
			mp >> d;
			if (d == '1')
				a[i + 3][j + 1] = e[i + 3][j + 1] = z[i + 3][j + 1] = -1;
		}
	}
	mp.close();

	y += 2;
	X = x - l + 1;
	Y = y;
	w = x;
	q = y;
	u = 10;
	//alf = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 25; i++)
		for (j = 0; j < 80; j++)
		{
			if (i == 0 || i == 2 || i == 24 ||
				j == 0 || j == 79)
				a[i][j] = e[i][j] = z[i][j] = -1;
			if (a[i][j] == -1)
			{
				gotoxy(j, i);
				cout << char(0xDB);
			}
		}

	for (i = x; i >= X; i--)
	{
		a[y][i] = u + 2 + c++;
		gotoxy(i, y);
		cout << char(0xC4);
	}

	gotoxy(0, 24);
	for (i = 0; i < 80; i++)
		cout << char(0xCD);
	for (i = 0; i < 25; i++)
	{
		gotoxy(0, i);
		cout << char(0xBA);
	}
	for (i = 0; i < 25; i++)
	{
		gotoxy(79, i);
		cout << char(0xBA);
	}
	gotoxy(0, 0);
	for (i = 0; i < 80; i++)
		cout << char(0xCD);
	gotoxy(0, 2);
	for (i = 0; i < 80; i++)
		cout << char(0xCD);
	gotoxy(0, 0);
	cout << char(0xC9);
	gotoxy(0, 2);
	cout << char(0xCC);
	gotoxy(79, 0);
	cout << char(0xBB);
	gotoxy(79, 2);
	cout << char(0xB9);
	gotoxy(0, 24);
	cout << char(0xC8);
	gotoxy(79, 24);
	cout << char(0xBC);
	gotoxy(57, 1);
	cout.width(15);
	cout << map.substr(0, map.find("."));
	ln(6);
	ln(14);
	ln(20);
	ln(28);
	ln(33);
	ln(41);
	ln(47);
	ln(50);
	ln(56);
	ln(61);
	ln(73);
	buffersize(80, 25);

	neweat();

	while (true)
	{

		gotoxy(1, 1);
		cout.width(4);
		cout << c;
		gotoxy(8, 1);
		cout.width(2);
		cout << x << " ";
		cout.width(2);
		cout << y - 2;
		gotoxy(16, 1);
		cout << dir;
		gotoxy(22, 1);
		cout.width(2);
		cout << m << " ";
		cout.width(2);
		cout << n - 2;
		gotoxy(29, 1);
		cout.width(3);
		cout << Abs(y - n) + Abs(x - m);
		gotoxy(35, 1);
		cout.width(2);
		cout << X << " ";
		cout.width(2);
		cout << Y - 2;
		gotoxy(42, 1);
		cout.width(4);
		cout << C;
		gotoxy(51, 1);
		cout.width(4);
		cout << time(NULL) - t;
		gotoxy(74, 1);
		cout.width(4);
		cout << (h = max(h, c));
		gotoxy(57, 1);
		cout.width(3);
		cout << z[y][x];

		gotoxy(18, 1);
		if (dir == 1)
		{
			y--;
			cout << char(24);
		}
		if (dir == 2)
		{
			x++;
			cout << char(26);
		}
		if (dir == 3)
		{
			y++;
			cout << char(25);
		}
		if (dir == 4)
		{
			x--;
			cout << char(27);
		}

		a[y][x] += u + 1;

		if ((x == m && y == n || g == 1))
		{
			if (x == m && y == n)
			{
				F = 1;
				neweat();
				if (bf == 1)
					bot();
			}
			c++;
		}
		if ((F == 0 || sm == 0) && g == 0)
		{
			gotoxy(X, Y);
			cout << " ";
			a[Y][X] = 0;
			if (a[Y - 1][X] == max(max(a[Y - 1][X], a[Y][X + 1]), max(a[Y + 1][X], a[Y][X - 1])))
				Y--;
			else if (a[Y][X + 1] == max(max(a[Y - 1][X], a[Y][X + 1]), max(a[Y + 1][X], a[Y][X - 1])))
				X++;
			else if (a[Y + 1][X] == max(max(a[Y - 1][X], a[Y][X + 1]), max(a[Y + 1][X], a[Y][X - 1])))
				Y++;
			else if (a[Y][X - 1] == max(max(a[Y - 1][X], a[Y][X + 1]), max(a[Y + 1][X], a[Y][X - 1])))
				X--;
		}
		F = 0;

		gotoxy(X, Y);
		if (a[Y][X] - a[Y - 1][X] == 1)
			cout << char(30);
		else if (a[Y][X] - a[Y][X + 1] == 1)
			cout << char(16);
		else if (a[Y][X] - a[Y + 1][X] == 1)
			cout << char(31);
		else if (a[Y][X] - a[Y][X - 1] == 1)
			cout << char(17);

		if (a[y][x] == u || a[y][x] > u + 1)
			a[y][x] = u + 1, brk = 1;

		gotoxy(w, q);
		if (a[q][w - 1] - a[q][w + 1] == 2 ||
			a[q][w - 1] - a[q][w + 1] == -2)
			cout << char(0xC4);
		else if (a[q - 1][w] - a[q + 1][w] == 2 ||
				 a[q - 1][w] - a[q + 1][w] == -2)
			cout << char(0xB3);
		else if (Abs(a[q][w - 1] - a[q][w]) == 1 &&
				 Abs(a[q][w] - a[q + 1][w]) == 1)
			cout << char(0xBF);
		else if (Abs(a[q][w + 1] - a[q][w]) == 1 &&
				 Abs(a[q][w] - a[q + 1][w]) == 1)
			cout << char(0xDA);
		else if (Abs(a[q][w + 1] - a[q][w]) == 1 &&
				 Abs(a[q][w] - a[q - 1][w]) == 1)
			cout << char(0xC0);
		else if (Abs(a[q][w - 1] - a[q][w]) == 1 &&
				 Abs(a[q][w] - a[q - 1][w]) == 1)
			cout << char(0xD9);
		w = x; q = y;

		if (brk)
			break;

		gotoxy(x, y);
		cout << head;

		for (i = 1; i < 24; i++)
			for (j = 1; j < 79; j++)
				if (a[i][j] > 0)
					a[i][j]++;

		if (f)
			Sleep(slpf);
		else if (s)
			Sleep(slps);
		else
			Sleep(slp);

		f = 0;
		while (_kbhit())
		{
			b = getch();
			if (b == 47 || b == 46)
			{
				if (g == 1)
					g = 0;
				else
					g = 1;
			}
			if (b == 98 || b == -88)
			{
				if (bf == 1)
					bf = s = 0;
				else
				{
					bf = 1;
					gotoxy(48, 0);
					cout << char(0xD1) << char(0xD1);
					gotoxy(48, 1);
					cout << char(0xB3) << char(0xB3);
					gotoxy(48, 2);
					cout << char(0xCF) << char(0xCF);
					bot();
				}
			}
			if (b == 118 || b == -84)
			{
				if (s == 1)
					s = 0;
				else
				{
					s = 1;
					if (bf)
					{
						gotoxy(48, 0);
						cout << char(0xD1) << char(0xD1);
						gotoxy(47, 1);
						cout << char(0xC3) << char(0xC5) << char(0xC5) << char(0xB4);
						gotoxy(48, 2);
						cout << char(0xCF) << char(0xCF);
					}
				}
			}
			if (b == 75 && bf == 0)
			{
				if (dir == 4)
					f = 1;
				else if (dir != 2)
					dir = 4;
				break;
			}
			if (b == 80 && bf == 0)
			{
				if (dir == 3)
					f = 1;
				else if (dir != 1)
					dir = 3;
				break;
			}
			if (b == 77 && bf == 0)
			{
				if (dir == 2)
					f = 1;
				else if (dir != 4)
					dir = 2;
				break;
			}
			if (b == 72 && bf == 0)
			{
				if (dir == 1)
					f = 1;
				else if (dir != 3)
					dir = 1;
				break;
			}
		}

		if (bf == 1)
		{
			if (e[y - 1][x] == -10)
			{
				if (dir == 3)
					bf = s = 0;
				else
					dir = 1;
			}
			if (e[y][x + 1] == -10)
			{
				if (dir == 4)
					bf = s = 0;
				else
					dir = 2;
			}
			if (e[y + 1][x] == -10)
			{
				if (dir == 1)
					bf = s = 0;
				else
					dir = 3;
			}
			if (e[y][x - 1] == -10)
			{
				if (dir == 2)
					bf = s = 0;
				else
					dir = 4;
			}
			if (e[y][x] == -10)
				e[y][x] = -12;
		}


		if (f)
		{
			gotoxy(48, 0);
			cout << char(0xCD) << char(0xCD);
			gotoxy(47, 1);
			cout << char(0xC6) << char(0xCD) << char(0xCD) << char(0xB5);
			gotoxy(48, 2);
			cout << char(0xCD) << char(0xCD);
		}
		else if (bf == 1 && s == 0)
		{
			gotoxy(48, 0);
			cout << char(0xD1) << char(0xD1);
			gotoxy(47, 1);
			cout << char(0xB3) << char(0xB3) << char(0xB3) << char(0xB3);
			gotoxy(48, 2);
			cout << char(0xCF) << char(0xCF);
		}
		else if (bf == 0 && s == 0)
		{
			gotoxy(48, 0);
			cout << char(0xCD) << char(0xCD);
			gotoxy(47, 1);
			cout << char(0xB3) << "  " << char(0xB3);
			gotoxy(48, 2);
			cout << char(0xCD) << char(0xCD);
		}
		C++;
	}

	out.open("highscore.txt");
	out << h;
	out.close();

	gotoxy(x, y);
	if (v == 1000)
		cout << "$";
	else
		cout << char(0xB2);
	gotoxy(20, 4);
	system("pause");

	return 0;
}
