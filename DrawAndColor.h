#ifndef DRAW_COLOR
#define DRAW_COLOR

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;

#define NONE_COLOR 1
#define CURSOR_COLOR 2
#define FRAME_COLOR 3
#define TITLE_COLOR 4



void gotoxy(int x, int y);

void textcolor(int x);

void veKhung(int x, int y, int width, int height) ;

int VeMenuDoc(string ds[], int n, int vitridau, int vitricuoi, int x, int y, int width, int dodich);

void hangKhungIn(int x, int y);

void veKhungThongTin();

void InDs(int x, int y, int row);

void resizeConsole(int width, int height);

void Menuluachon(int& toado);

void position(bool CursorVisibility);

void Khungthongke(int x, int y);
void Vebangthongke1(int x, int y, int row);
void Vebangthongke2(int x, int y, int row);
void Vebangthongke3(int x, int y, int row);

void Vekhungdothi(int x, int y);

#endif // !DRAW_COLOR