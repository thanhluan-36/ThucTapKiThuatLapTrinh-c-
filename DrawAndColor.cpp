#include"DrawAndColor.h"
#include"Menu.h"

const char gocTT = 218;
const char gocTD = 192;
const char gocPT = 191;
const char gocPD = 217;
const char gachNgang = 196;
const char gachDoc = 179;
const char gachQT = 180;
const char gachQP = 195;
const char gachGiuaQT = 193;
const char gachGiuaQD = 194;

void gotoxy(int x, int y)
{
	COORD coord = { 0,0 };
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void textcolor(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, x);
}
void veKhung(int x, int y, int width, int height) {

	gotoxy(x, y); cout << gocTT;
	gotoxy(x + width - 1, y); cout << gocPT;
	gotoxy(x, y + 1 + height); cout << gocTD;
	gotoxy(x + width - 1, y + 1 + height); cout << gocPD;
	
	for (int j = 0; j < width - 2; j++) {
		gotoxy(x + 1 + j, y); cout << gachNgang;
		gotoxy(x + 1 + j, y + height + 1); cout << gachNgang;
	}
	
	for (int k = 0; k < height; k++) {
		gotoxy(x, y + 1 + k); cout << gachDoc;
		gotoxy(x + width - 1, y + 1 + k); cout << gachDoc;
	}
}

enum KEY_PRESS
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESC,
	ENTER,
};

KEY_PRESS key(int ikey)
{
	if (ikey == 224)
	{
		char c = _getch();
		if (c == 72)   return (UP);
		if (c == 80)   return DOWN;
		if (c == 75)   return LEFT;
		if (c == 77)   return RIGHT;
	}
	else if (ikey == 13)   return ENTER;
	else if (ikey == 27)   return ESC;
	
}
// string ds, n: so dong
int VeMenuDoc(string ds[], int n, int vitridau, int vitricuoi, int x, int y, int width, int dodich)
{
	int vitri = 0;
	int mau_dong[30];
	for (int i = 0; i < n; i++)
	{
		mau_dong[i] = NONE_COLOR;
	}
	mau_dong[vitri] = CURSOR_COLOR;
	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			textcolor(mau_dong[i]);
			veKhung(x - 2, y + i * dodich - 1, width, 1);
			gotoxy(x, y + i * dodich);
			cout << ds[i] << endl;
			
		}
		
		int ikey = _getch();
		KEY_PRESS batphim = key(ikey);
		switch (batphim)
		{
		case LEFT: {
			vitri -= 1;
			if (vitri < 0)
				vitri = vitricuoi;
			break;
		}

		case RIGHT: {
			vitri += 1;
			if (vitri > vitricuoi)
				vitri = vitridau;
			break;
		}

		case UP: {
			vitri -= 1;
			if (vitri < 0)
				vitri = vitricuoi;
			break;
		}
		case DOWN: {
			vitri += 1;
			if (vitri > vitricuoi)
				vitri = vitridau;
			break;
		}

		case ENTER: {
			return vitri;
			break;
		}
		case ESC: {
			system("cls");
			exit(0);
			break;
		}
		}
		for (int i = 0; i < n; i++)
		{
			mau_dong[i] = NONE_COLOR;
		}
		mau_dong[vitri] = CURSOR_COLOR;
	}
}


void veKhungThongTin() {// su dung khi them thong tin

	veKhung(27, 7, 40, 1);
	veKhung(27, 11, 40, 1);
	veKhung(27, 15, 40, 1);
	veKhung(27, 19, 40, 1);
	veKhung(27, 23, 40, 1);
	veKhung(67, 7, 40, 1);
	veKhung(67, 11, 40, 1);
	veKhung(67, 15, 40, 1);
	veKhung(67, 19, 40, 1);
	veKhung(67, 23, 40, 1);
	//-------------------------------------------------
	textcolor(3);
	gotoxy(29, 8);
	cout << "1. Ma TTB ";
	gotoxy(29, 12);
	cout << "2. Ten TTB ";
	gotoxy(29, 16);
	cout << "3. Ngay san xuat";
	gotoxy(69, 16);
	cout << "dd/mm/yyyy";
	gotoxy(29, 20);
	cout << "4. So Luong";
	gotoxy(29, 24);
	cout << "5. Chung Loai";

}

void hangKhungIn(int x, int y) {
	// ke cac goc cua cah tren
	gotoxy(x, y); cout << gocTT;
	gotoxy(x + 6, y); cout << gachGiuaQD;
	gotoxy(x + 20, y); cout << gachGiuaQD;
	gotoxy(x + 40, y); cout << gachGiuaQD;
	gotoxy(x + 59, y); cout << gachGiuaQD;
	gotoxy(x + 75, y); cout << gachGiuaQD;
	gotoxy(x + 90, y); cout << gocPT;
	// ke cac goc cua canh duoi
	gotoxy(x, y + 2); cout << gocTD;
	gotoxy(x + 6, y + 2); cout << gachGiuaQT;
	gotoxy(x + 20, y + 2); cout << gachGiuaQT;
	gotoxy(x + 40, y + 2); cout << gachGiuaQT;
	gotoxy(x + 59, y + 2); cout << gachGiuaQT;
	gotoxy(x + 75, y + 2); cout << gachGiuaQT;
	gotoxy(x + 90, y + 2); cout << gocPD;

	for (int i = 0; i <= 90; i++) {

		if (i != 0 && i != 6 && i != 20 && i != 40 && i != 59 && i != 75 && i != 90) {
			gotoxy(x + i, y);
			cout << gachNgang;
			gotoxy(x + i, y + 2);
			cout << gachNgang;
		}
		else {
			gotoxy(x + i, y + 1);
			cout << gachDoc;
		}
	}

}

void InDs(int x, int y, int row)
{
	textcolor(6);
	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 7, y + 1); cout << "Ma thiet bi";
	gotoxy(x + 23, y + 1); cout << "Ten thiet bi";
	gotoxy(x + 44, y + 1); cout << "Ngay san xuat";
	gotoxy(x + 61, y + 1); cout << "So luong";
	gotoxy(x + 77, y + 1); cout << "Chung loai";


	textcolor(3);
	for (int i = 0; i < row; i++)
	{
		hangKhungIn(x, y + i * 3);
	}
}


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Menuluachon(int& toado)
{
	int x = 7;
	if (toado == 5)
	{
		x = x - 1;
	}
	textcolor(x);
	veKhung(63, 27, 10, 1);
	gotoxy(66, 28);
	cout << "LUU";
	if (toado == 5)
	{
		position(0);
		rewind(stdin);
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72)
			{
				toado = 4;
				x = 7;
			}
		}
		if (c == 13)
		{
			toado = 6;
		}
		textcolor(x);
		veKhung(63, 27, 10, 1);
		gotoxy(66, 28);
		cout << "LUU";
		position(1);
	}
}

void position(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Khungthongke(int x, int y)
{
	textcolor(3);
	gotoxy(x, y); printf("%c", 201);
	gotoxy(x + 10, y); printf("%c", 203);
	gotoxy(x + 30, y); printf("%c", 203);
	gotoxy(x + 55, y); printf("%c", 203);
	gotoxy(x + 70, y); printf("%c", 187);

	gotoxy(x, y + 2); printf("%c", 200);
	gotoxy(x + 10, y + 2); printf("%c", 202);
	gotoxy(x + 30, y + 2); printf("%c", 202);
	gotoxy(x + 55, y + 2); printf("%c", 202);
	gotoxy(x + 70, y + 2); printf("%c", 188);

	for (int i = 0; i <= 70; i++)
	{
		if (i != 0 && i != 10 && i != 30 && i != 55 && i != 70)
		{
			gotoxy(x + i, y);
			printf("%c", 205);
			gotoxy(x + i, y + 2);
			printf("%c", 205);
		}
		else
		{
			gotoxy(x + i, y + 1);
			printf("%c", 186);
		}
	}
}

void Vebangthongke1(int x, int y, int row)
{
	string nam[] = { "Truoc nam 1945", "Tu 1946 -> 1990", "Tu 1991 -> 2000", "Tu 2001 -> 2015", "Tu 2015 -> nay" };
	int i = 0;
	textcolor(6);
	gotoxy(x + 4, y + 1); cout << "STT";
	gotoxy(x + 14, y + 1); cout << "THEO CAC NAM";
	gotoxy(x + 39, y + 1); cout << "SO LUONG";
	gotoxy(x + 58, y + 1); cout << "TY LE";
	for (int j = 1; j <= 5; j++)
	{
		gotoxy(x + 5, y + j * 3 + 1);
		cout << j;
	}
	for (int j = 1; j <= 5; j++)
	{
		gotoxy(x + 12, y + j * 3 + 1);
		cout << nam[j - 1];
	}
	for (i; i <= row; i++)
	{
		Khungthongke(x, y + i * 3);
	}
	textcolor(9);
	veKhung(x, y + i * 3, 33, 1);
	veKhung(x + 33, y + i * 3, 33, 1);
	textcolor(6);
	gotoxy(x + 15, y + i * 3 + 1); cout << "TONG:";
}

void Vebangthongke2(int x, int y, int row)
{
	int i = 0;
	textcolor(6);
	gotoxy(x + 4, y + 1); cout << "STT";
	gotoxy(x + 16, y + 1); cout << "CHUNG LOAI";
	gotoxy(x + 40, y + 1); cout << "SO LUONG";
	gotoxy(x + 58, y + 1); cout << "TY LE";
	for (int j = 1; j <= row; j++)
	{
		gotoxy(x + 5, y + j * 3 + 1);
		cout << j;
	}
	for (i; i <= row; i++)
	{
		Khungthongke(x, y + i * 3);
	}
	textcolor(9);
	veKhung(x, y + i * 3, 33, 1);
	veKhung(x + 33, y + i * 3, 33, 1);
	textcolor(6);
	gotoxy(x + 15, y + i * 3 + 1); cout << "TONG:";
}

void Vebangthongke3(int x, int y, int row)
{
	int i = 0;
	textcolor(6);
	gotoxy(x + 4, y + 1); cout << "STT";
	gotoxy(x + 16, y + 1); cout << "CHUNG LOAI";
	gotoxy(x + 40, y + 1); cout << "SO LUONG";
	gotoxy(x + 58, y + 1); cout << "TY LE";
	for (int j = 1; j <= row; j++)
	{
		gotoxy(x + 5, y + j * 3 + 1);
		cout << j;
	}
	for (i; i <= row; i++)
	{
		Khungthongke(x, y + i * 3);
	}
	textcolor(9);
	veKhung(x, y + i * 3, 33, 1);
	veKhung(x + 33, y + i * 3, 33, 1);
	textcolor(6);
	gotoxy(x + 15, y + i * 3 + 1); cout << "TONG:";
}
void Vekhungdothi(int x, int y)
{
	textcolor(9);
	gotoxy(x - 3, y - 2); cout << "Ratio";
	textcolor(13);
	gotoxy(x, y - 1); printf("^");
	for (int i = 0; i < 25; i++)
	{
		gotoxy(x, y + i);
		printf("%c\n", 186);
	}
	gotoxy(x, y + 25); printf("%c", 200);
	for (int i = 1; i < 80; i++)
	{
		gotoxy(x + i, y + 25);
		printf("%c", 205);
	}
	gotoxy(x + 80, y + 25); printf(">");
	textcolor(11);
	gotoxy(x + 1, y + 26); cout << "Before 1945" << endl;
	gotoxy(x + 17, y + 26); cout << "1946->1990" << endl;
	gotoxy(x + 32, y + 26); cout << "1990->2000" << endl;
	gotoxy(x + 47, y + 26); cout << "2001->2015" << endl;
	gotoxy(x + 62, y + 26); cout << "After 2016" << endl;
	textcolor(11);
	gotoxy(x + 80, y + 26); cout << "Year" << endl;
	int phantram = 0;
	for (int i = 0; i <= 5; i++)
	{
		gotoxy(x - 4, y + 25 - 5 * i); cout << phantram << "%";
		phantram += 20;
	}
}
