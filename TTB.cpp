#include "TTB.h"
#include"Menu.h"

TrangThietBi::TrangThietBi()
{
	Matb = Tentb = Ngaysanxuat = Chungloai = "";
	Soluong =0;
}

TrangThietBi::TrangThietBi(string Matb, string Tentb, string Ngaysanxuat, int Soluong, string Chungloai)
{
	this->Matb = Matb;
	this->Tentb = Tentb;
	this->Ngaysanxuat = Ngaysanxuat;
	this->Soluong = Soluong;
	this->Chungloai = Chungloai;
}

TrangThietBi::TrangThietBi(const TrangThietBi& tb)
{
	this->Matb = tb.Matb;
	this->Tentb = tb.Tentb;
	this->Ngaysanxuat = tb.Ngaysanxuat;
	this->Soluong = tb.Soluong;
	this->Chungloai = tb.Chungloai;
}

void TrangThietBi::SetMatb(string temp)
{
	this->Matb = temp;
}

void TrangThietBi::SetTentb(string temp)
{
	this->Tentb = temp;
}

void TrangThietBi::SetNgaysx(string temp)
{
	this->Ngaysanxuat = temp;
}

void TrangThietBi::SetSoluong(string temp)
{
	this->Soluong = atoi(temp.c_str());
}

void TrangThietBi::SetChungloai(string temp)
{
	this->Chungloai = temp;
}

void TrangThietBi::SetMatb(int &toado, string &temp)
{
	textcolor(6);
	string xau = "";
	int i = 0;
	gotoxy(69, 8);
	cout << "                                   ";
	gotoxy(69, 8);
	while (true) {
		rewind(stdin);// tra ve vi tri dau luong
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72) toado = 0;
			if (c == 80) toado = 1;

			break;
		}
		if (c == 13 && xau.length() <= 10 && xau.length() > 0)
		{
			temp = xau;
			toado = 1;
			break;
		}
		if (c == 27)
		{
			Them();
			break;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 8);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 8);
		}
		if (c != -32 && c != 13 && c != 27 && c != 8 && c != 72 && c != 80 && c != 75 && c != 77 && c != 9 && xau.length() < 10)
		{
			xau += c;
			gotoxy(69, 8);
			cout << "                                ";
			gotoxy(69, 8);
			cout << xau;
			i++;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 8);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 8);
		}
		if (c == 8 && i > 0)
		{
			gotoxy(69, 8);
			cout << "                                ";
			gotoxy(69, 8);
			i--;
			xau.pop_back();
			cout << xau;
			gotoxy(69 + i, 8);
		}
		if (xau.length() < 10)
		{
			gotoxy(110, 8);
			cout << "                    ";
			gotoxy(110 + i, 8);
		}
		if (xau.length() > 10)
		{
			continue;
		}
	}

	temp = ChuanHoaTen(temp);
	gotoxy(110, 8);
	std::cout << "                           ";
	gotoxy(69, 8);cout << "                     ";
	gotoxy(69, 8);cout << temp;
	this->Matb = temp;

}

void TrangThietBi::SetTentb(int& toado, string& temp)
{
	
	textcolor(6);
	string xau = "";
	int i = 0;
	gotoxy(69, 12);
	cout << "                                  ";
	gotoxy(69, 12);
	while (1)
	{
		rewind(stdin);
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72) toado = 0;
			if (c == 80) toado = 2;
			break;
		}

		if (c == 13 && xau.length() <= 10 && xau.length() > 0)
		{
			temp = xau;
			toado = 2;
			break;
		}
		if (c == 27)
		{
			Them();
			break;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 12);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 12);
		}
		if (c != -32 && c != 13 && c != 27 && c != 8 && c != 72 && c != 80 && c != 75 && c != 77 && c != 9 && xau.length() < 10)
		{
			xau += c;
			gotoxy(69, 12);
			cout << "                                ";
			gotoxy(69, 12);
			cout << xau;
			i++;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 12);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 12);
		}
		if (c == 8 && i > 0)
		{
			gotoxy(69, 12);
			cout << "                                ";
			gotoxy(69, 12);
			i--;
			xau.pop_back();
			cout << xau;
			gotoxy(69 + i, 12);
		}
		if (xau.length() < 10)
		{
			gotoxy(110, 12);
			cout << "                    ";
			gotoxy(69 + i, 12);
		}
		if (xau.length() > 10)
		{
			continue;
		}
	}
	temp = ChuanHoaTen(temp);
	gotoxy(69, 12);
	cout << "                                  ";
	gotoxy(110, 12);
	cout << "                          ";
	gotoxy(69, 12);
	cout << temp;
	this->Tentb = temp;

}

void TrangThietBi::SetNgaysx(int& toado, string& temp)
{
	textcolor(6);
	string xau = "";
	int i = 0;
	gotoxy(69, 16);
	cout << "                                ";
	gotoxy(69, 16);
	while (1)
	{
		rewind(stdin);
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72) toado = 1;
			if (c == 80) toado = 3;
			break;
		}

		if (c == 13 && xau.length() == 10)
		{
			if (KiemTraNgay(xau) == false)
			{
				gotoxy(110, 16);
				cout << "<-- Loi du lieu!";
				gotoxy(69, 16);
				cout << "                      ";
				gotoxy(69, 16);
				xau = "";
				i = 0;
				continue;
			}
			else {
				gotoxy(110, 16);
				cout << "                    ";
				temp = xau;
				toado = 3;
				break;
			}
		}
		if (c == 27)
		{
			Them();
			break;
		}
		if (c != -32 && c != 13 && c != 27 && c != 8 && c != 72 && c != 80 && c != 75 && c != 77 && c != 9 && xau.length() < 10 && isdigit(c) != 0)
		{
			xau += c;
			gotoxy(69, 16);
			cout << "                                ";
			gotoxy(69, 16);
			cout << xau;
			i++;
			if (i == 2 || i == 5)
			{
				xau.push_back('/');
				gotoxy(69, 16);
				cout << "                                ";
				gotoxy(69, 16);
				cout << xau;
				i++;
			}
		}

		if (c == 8 && i > 0)
		{
			gotoxy(69, 16);
			cout << "                                ";
			gotoxy(69, 16);
			i--;
			xau.pop_back();
			cout << xau;
			gotoxy(69 + i, 16);
		}
		if (xau.length() > 10)
		{
			continue;
		}
	}
	this->Ngaysanxuat = temp;
	gotoxy(110, 16);
	cout << "                          ";
}

void TrangThietBi::SetSoluong(int& toado, string& temp)
{
	
	textcolor(6);
	string xau = "";
	int i = 0;
	gotoxy(69, 20);
	cout << "                                ";
	gotoxy(69, 20);
	while (1)
	{
		rewind(stdin);
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72) toado = 2;
			if (c == 80) toado = 4;
			break;
		}
		if (c == 13 && xau.length() <= 10 && xau.length() > 0)
		{
			temp = xau;
			toado = 4;
			break;
		}
		if (c == 27)
		{
			Them();
			break;
		}
		if (c != -32 && c != 13 && c != 27 && c != 8 && c != 72 && c != 80 && c != 75 && c != 77 && c != 9 && xau.length() < 10 && isdigit(c) != 0)
		{
			xau += c;
			gotoxy(69, 20);
			cout << "                                ";
			gotoxy(69, 20);
			cout << xau;
			i++;
		}
		if (c == 8 && i > 0)
		{
			gotoxy(69, 20);
			cout << "                                ";
			gotoxy(69, 20);
			i--;
			xau.pop_back();
			cout << xau;
			gotoxy(69 + i, 20);
		}
		if (xau.length() > 10)
		{
			continue;
		}
	}
	this->Soluong = atoi(temp.c_str());
	gotoxy(110, 20);
	cout << "                          ";
}

void TrangThietBi::SetChungloai(int& toado, string& temp)
{
	
	textcolor(6);
	string xau = "";
	int i = 0;
	gotoxy(69, 24);
	cout << "                                ";
	gotoxy(69, 24);
	while (1)
	{
		rewind(stdin);
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72) toado = 3;
			if (c == 80) toado = 5;
			break;
		}
		if (c == 13 && xau.length() <= 10 && xau.length() > 0)
		{
			temp = xau;
			toado = 5;
			break;
		}
		if (c == 27)
		{
			Them();
			break;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 24);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 24);
		}
		if (c != -32 && c != 13 && c != 27 && c != 8 && c != 72 && c != 80 && c != 75 && c != 77 && c != 9 && xau.length() < 10)
		{
			xau += c;
			gotoxy(69, 24);
			cout << "                                ";
			gotoxy(69, 24);
			cout << xau;
			i++;
		}
		if (xau.length() == 9)
		{
			gotoxy(110, 24);
			cout << "<-- Kich thuoc max!";
			gotoxy(69 + i, 24);
		}
		if (c == 8 && i > 0)
		{
			gotoxy(69, 24);
			cout << "                                ";
			gotoxy(69, 24);
			i--;
			xau.pop_back();
			cout << xau;
			gotoxy(69 + i, 24);
		}
		if (xau.length() < 10)
		{
			gotoxy(110, 24);
			cout << "                    ";
			gotoxy(69 + i, 24);
		}
		if (xau.length() > 10)
		{
			continue;
		}
	}
	temp = ChuanHoaTen(temp);
	gotoxy(110, 24);
	cout << "                            ";

	gotoxy(69, 24);
	cout << temp;
	this->Chungloai = temp;

}

TrangThietBi :: ~TrangThietBi()
{
	Matb = Tentb = Ngaysanxuat =  Chungloai = "";
	Soluong = 0;
}

string TrangThietBi::GetMatb()
{
	return Matb;
}

string TrangThietBi::GetNgaysx()
{
	return Ngaysanxuat;
}

string TrangThietBi::GetTentb()
{
	return Tentb;
}

int TrangThietBi::GetSoluong()
{
	return Soluong;
}

string TrangThietBi::GetChungloai()
{
	return Chungloai;

}

bool TrangThietBi::KiemTraNgay(string date)
{
	bool check;
	if (date.length() == 10) check = true;
	else return false;

	if (date[2] == '/' && date[5] == '/') check = true;
	else return false;

	string day = "", month = "", year = "";
	string d1, d2, m1, m2, y1, y2, y3, y4;
	d1.push_back(date[0]);
	d2.push_back(date[1]);
	m1.push_back(date[3]);
	m2.push_back(date[4]);
	y1.push_back(date[6]);
	y2.push_back(date[7]);
	y3.push_back(date[8]);
	y4.push_back(date[9]);
	day = d1 + d2;
	month = m1 + m2;
	year = y1 + y2 + y3 + y4;
	int ngay, thang, nam;
	ngay = atoi(day.c_str());
	thang = atoi(month.c_str());
	nam = atoi(year.c_str());

	if (ngay <= 0 || ngay > 31 || thang <= 0 || thang > 12 || nam < 1000 || nam > 2020) check = false;
	else check = true;

	if (nam % 4 == 0 && thang == 2)
	{
		if (ngay <= 29 && ngay > 0) check = true;
		else check = false;
	}

	if (nam % 4 != 0 && thang == 2)
	{
		if (ngay <= 28 && ngay > 0) check = true;
		else check = false;
	}

	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		if (ngay <= 31 && ngay > 0) check = true;
		else check = false;
	}

	if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
	{
		if (ngay <= 30 && ngay > 0) check = true;
		else check = false;
	}

	return check;
}

string TrangThietBi::ChuanHoaTen(string& name)
{
	//char ten[50];
	//int first = 0, last = name.length();
	//int j = 0;
	//for (int i = 0; name[i] == ' '; i++)
	//{
	//	first++;// so khoang trang o dau
	//}
	//for (int i = name.length() - 1; name[i] == ' '; i--)
	//{
	//	last--;// so khoang trang o cuoi
	//}
	//for (int i = first; i < last; i++)
	//{
	//	if (name[i] == name[i + 1] && name[i] == ' ')// xoa khoang trang
	//	{
	//		continue;
	//	}
	//	else
	//	{
	//		ten[j++] = name[i];
	//	}
	//}
	//ten[j] = '\0';
	//for (int i = 0; i < strlen(ten); i++)
	//{
	//	ten[i] = toupper(ten[i]);
	//}
	//name = ten;
	for (int i = 0; i < name.length(); i++)
	{
		name[i] = toupper(name[i]);
	}
	return name;
}