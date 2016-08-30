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

int a[25][80], i, j, x, y, X, Y, w, q, dir, f, n, m, c, l, C, h, t, g, brk, u, v;
char b, head, eat, d, p[50];
string map;
ifstream config, conf, high, dmp, mp, fmp;
ofstream out;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

	SetConsoleTitle("Snke 1.0");
	srand(t = time(NULL));

	out.open("readme.txt");
	out << "Snke 1.0\nФайл справки\n\nУправление:\nКлавиши вверх, вправо, вниз, влево изменяют направление движения\nЕсли клавиша зажата по направлению движения, включается режим ускорения\n/ - режим удлинения\n\nОкно программы:\n1. Длина\n2. Координаты головы\n3. Направление\n4. Координаты еды\n5. Расстояние до еды\n6. Координаты хвоста\n7. Шаги\n8. Режим ускорения\n9. Время\n10. Название карты\n11. Рекордная длина\n\nФайлы:\nreadme.txt\n	Файл справки\nconfig.txt\n	1. Начальная абцисса головы\n	2. Начальная ордината головы\n	3. Начальная длина\n	4. Начальное направление\n	5. Символ головы\n	6. Символ еды\n	7. Название файла карты\nhighscore.txt\n	Рекордная длина\ndefault.map\n	Файл карты\n	21 строк, 78 столбцов\n	Если указана 1, то в соответсвующем месте на игровом поле стена";
	out.close();

	config.open("config.txt");
	if (config)
	{
		config >> x >> y >> l >> dir >> head >> eat >> map;
		config.close();
	}
	else
	{
		config.close();
		out.open("config.txt");
		out << "40 11 5 2 O $ default.map";
		out.close();
		conf.open("config.txt");
		conf >> x >> y >> l >> dir >> head >> eat >> map;
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
				a[i + 3][j + 1] = -1;
		}
	}
	mp.close();

	y += 2;
	X = x - l + 1;
	Y = y;
	w = x;
	q = y;
	u = 10;

	for (i = 0; i < 25; i++)
		for (j = 0; j < 80; j++)
		{
			if (i == 0 || i == 2 || i == 24 ||
				j == 0 || j == 79)
				a[i][j] = -1;
			if (a[i][j] == -1)
			{
				gotoxy(j, i);
				cout << char(0xDB);
			}
		}

	for (i = x; i >= X; i--)
	{
		a[y][i] = 8 + c++;
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
	ln(73);

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

		if (x == m && y == n || g == 1)
		{
			if (x == m && y == n)
				neweat();
			c++;
		}
		else
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
			Sleep(25);
		else
			Sleep(400);

		f = 0;
		while (_kbhit())
		{
			b = getch();
			if (b == 47)
			{
				if (g == 1)
					g = 0;
				else
					g = 1;
			}
			if (b == 75)
			{
				if (dir == 4)
					f = 1;
				else if (dir != 2)
					dir = 4;
				break;
			}
			if (b == 80)
			{
				if (dir == 3)
					f = 1;
				else if (dir != 1)
					dir = 3;
				break;
			}
			if (b == 77)
			{
				if (dir == 2)
					f = 1;
				else if (dir != 4)
					dir = 2;
				break;
			}
			if (b == 72)
			{
				if (dir == 1)
					f = 1;
				else if (dir != 3)
					dir = 1;
				break;
			}
		}

		gotoxy(47, 1);
		if (f)
			cout << char(0xC6) << char(0xCD) << char(0xCD) << char(0xB5);
		else
			cout << char(0xB3) << "  " << char(0xB3);

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
