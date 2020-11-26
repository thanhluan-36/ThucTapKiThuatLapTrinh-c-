#include "Thongke.h"
// thong ke theo cac moc nam:
//- truoc nam 2000
//- tu nam 2000 -> 2005
//- tu nam 2005 -> 2010
//- tu nam 2010 -> 2015
//- tu nam 2015 -> nay

string luachontk1[] = { "  Xem do thi ", "    Menu   " };
string luachontk2[] = { "     Menu    " };
string LayNam(string s)
{
	string y1, y2, y3, y4, result = "";
	if (s.length() != 10)
	{
		return result;
	}
	else
	{
		y1.push_back(s[6]);
		y2.push_back(s[7]);
		y3.push_back(s[8]);
		y4.push_back(s[9]);
		result = y1 + y2 + y3 + y4;
		return result;
	}
}

int DemSoluong(string s[], int n)
{
	int i = 0;
	int dem = 0;
	while (i != n)
	{
		if (s[i] == s[i + 1])
		{
			i++;
			continue;
		}
		else
		{
			i++;
			dem++;
		}
	}
	return dem;
}

void ThongKeTheoNamsx(char* file_name)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	int size = dstb.size();
	string y[100];
	string year[100];
	int tk[5];
	double tyle[5];
	for (int i = 0; i < 5; i++)
	{
		tk[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		y[i] = LayNam(dstb.front().GetNgaysx());
		dstb.push_back(dstb.front());
		dstb.pop_front();
	}

	quickSort(y, 0, size - 1);

	int j = 0;
	int dem = DemSoluong(y, size);
	int* count = new int[dem];
	for (int i = 0; i < dem; i++)
	{
		count[i] = 1;
	}

	if (size == 0)
	{
		system("cls");
		gotoxy(20, 15);
		cout << "DANH SACH THIET BI TRONG!";
		Mainmenu();
	}
	else
	{
		system("cls");
		textcolor(20);
		veKhung(38, 2, 50, 1);
		gotoxy(39, 3);
		cout << "          THONG KE THEO NAM SAN XUAT            ";
		j = 0;
		int i = 0;
		while (j != size)
		{
			if (y[j] == y[j + 1])
			{
				j++;
				count[i]++;
				continue;
			}
			else
			{
				year[i] = y[j];
				j++;
				i++;
			}
		}
		year[i] = y[j];
	}

	for (int i = 0; i < dem; i++)
	{
		if (atoi(year[i].c_str()) <= 1945)
		{
			tk[0] += count[i];
		}
	}

	for (int i = 0; i < dem; i++)
	{
		if (atoi(year[i].c_str()) >= 1946 && atoi(year[i].c_str()) <= 1990)
		{
			tk[1] += count[i];
		}
	}

	for (int i = 0; i < dem; i++)
	{
		if (atoi(year[i].c_str()) >= 1991 && atoi(year[i].c_str()) <= 2000)
		{
			tk[2] += count[i];
		}
	}

	for (int i = 0; i < dem; i++)
	{
		if (atoi(year[i].c_str()) >= 2001 && atoi(year[i].c_str()) <= 2015)
		{
			tk[3] += count[i];
		}
	}

	for (int i = 0; i < dem; i++)
	{
		if (atoi(year[i].c_str()) >= 2016)
		{
			tk[4] += count[i];
		}
	}
	tyle[0] = ((tk[0] * 1.00) / (size * 1.00)) * 100.00;
	tyle[1] = ((tk[1] * 1.00) / (size * 1.00)) * 100.00;
	tyle[2] = ((tk[2] * 1.00) / (size * 1.00)) * 100.00;
	tyle[3] = ((tk[3] * 1.00) / (size * 1.00)) * 100.00;
	tyle[4] = ((tk[4] * 1.00) / (size * 1.00)) * 100.00;

	Vebangthongke1(30, 7, 5);
	gotoxy(73, 11); cout << tk[0];
	gotoxy(73, 14); cout << tk[1];
	gotoxy(73, 17); cout << tk[2];
	gotoxy(73, 20); cout << tk[3];
	gotoxy(73, 23); cout << tk[4];
	gotoxy(79, 26); cout << size;
	gotoxy(89, 11); cout << tyle[0] << "%";
	gotoxy(89, 14); cout << tyle[1] << "%";
	gotoxy(89, 17); cout << tyle[2] << "%";
	gotoxy(89, 20); cout << tyle[3] << "%";
	gotoxy(89, 23); cout << tyle[4] << "%";
	Veluachontk1(30, tyle);
	for (int i = 0; i < 100; i++)
	{
		y[i].clear();
	}
	for (int i = 0; i < 100; i++)
	{
		year[i].clear();
	}
	delete[]count;
	dstb.clear();
}

void Veluachontk1(int y, double *tyle)
{
	switch (VeMenuDoc(luachontk1, 2, 0, 1, 60, y, 18, 3))
	{
	case 0: {
		system("cls");
		Vekhungdothi( 10, 5);
		textcolor(22);
		gotoxy(20, 35); cout << "BIEU DO THE HIEN PHAN TRAM SO LUONG TTB SAN XUAT THEO NAM";
		for (int i = 0;i < 5;i += 1) {
			textcolor(20+ 30*i );
			
			if (tyle[i] >= 0 && tyle [i] <= 5.0) {
				gotoxy(15 * i + 13, 27);cout << tyle[i] << "%";
				for (int j = 29; j < 30; j++) { gotoxy((15 * i) + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 5.0 && tyle[i] <= 10.0) {
				gotoxy(15 * i + 13, 25);cout << tyle[i] << "%";
				for (int j = 27; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 10.0 && tyle[i] <= 15.0) {
				gotoxy(15 * i + 13, 24);cout << tyle[i] << "%";
				for (int j = 26; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 15.0 && tyle[i] <= 20.0) {
				gotoxy(15 * i + 13, 22);cout << tyle[i] << "%";
				for (int j = 24; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 20.0 && tyle[i] <= 25.0) {
				gotoxy(15 * i + 13, 21);cout << tyle[i] << "%";
				for (int j = 23; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 25.0 && tyle[i] <= 30.0) {
				gotoxy(15 * i + 13, 19);cout << tyle[i] << "%";
				for (int j = 21; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 30.0 && tyle[i] <= 35.0) {
				gotoxy(15 * i + 13, 18);cout << tyle[i] << "%";
				for (int j = 20; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 35.0 && tyle[i] <= 40.0) { 
				gotoxy(15 * i + 13, 16);cout << tyle[i] << "%";
				for (int j = 18; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 40.0 && tyle[i] <= 45.0) {
				gotoxy(15 * i + 13, 15);cout << tyle[i] << "%";
				for (int j = 17; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 45.0 && tyle[i] <= 50.0) {
				gotoxy(15 * i + 13, 13);cout << tyle[i] << "%";
				for (int j = 15; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 50.0 && tyle[i] <= 55.0) {
				gotoxy(15 * i + 13, 12);cout << tyle[i] << "%";
				for (int j = 14; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 55.0 && tyle[i] <= 60.0) {
				gotoxy(15 * i + 13, 10);cout << tyle[i] << "%";
				for (int j = 12; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 60.0 && tyle[i] <= 65.0) {
				gotoxy(15 * i + 13, 9);cout << tyle[i] << "%";
				for (int j = 11; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 65.0 && tyle[i] <= 70.0) {
				gotoxy(15 * i + 13, 7);cout << tyle[i] << "%";
				for (int j = 9; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 70.0 && tyle[i] <= 75.0) {
				gotoxy(15 * i + 13, 5);cout << tyle[i] << "%";
				for (int j = 7; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 75.0 && tyle[i] <= 80.0) {
				gotoxy(15 * i + 13, 4);cout << tyle[i] << "%";
				for (int j = 6; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 80.0 && tyle[i] <= 85.0) { 
				gotoxy(15 * i + 13, 2);cout << tyle[i] << "%";
				for (int j = 4; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 85.0 && tyle[i] <= 90.0) {
				gotoxy(15 * i + 13, 1);cout << tyle[i] << "%";
				for (int j = 3; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 90.0 && tyle[i] <= 95.0) {
				gotoxy(15 * i + 13, -1);cout << tyle[i] << "%";
				for (int j = 1; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else if (tyle[i] > 95.0 && tyle[i] <= 100.0) {
				gotoxy(15 * i + 13, -3);cout << tyle[i] << "%";
				for (int j = 0; j < 30; j++) { gotoxy(15 * i + 15, j);cout << "     "; }
			}
			else {
				
			}
			
		}
		textcolor(0);
		_getch();
		Mainmenu();
	}
	case 1:
		Mainmenu();
		break;
	}
}

void Veluachontk2(int y)
{
	switch (VeMenuDoc(luachontk2, 1, 0, 0, 60, y, 18, 3))
	{
	case 0: {
		Mainmenu();
		break;
	}
	}
}




void ThongKeTheoChungLoai(char* file_name)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	int size = dstb.size();
	string cl[100];
	string chungloai[100];

	for (int i = 0; i < size; i++)
	{
		cl[i] = dstb.front().GetChungloai();
		dstb.push_back(dstb.front());
		dstb.pop_front();
	}

	quickSort(cl, 0, size - 1);

	int j = 0;
	int dem = DemSoluong(cl, size);
	int* count = new int[dem];
	for (int i = 0; i < dem; i++)
	{
		count[i] = 1;
	}

	if (size == 0)
	{
		system("cls");
		gotoxy(20, 15);
		cout << "DANH SACH THIET BI TRONG!";
		Mainmenu();
	}
	else
	{
		system("cls");
		textcolor(206);
		veKhung(38, 2, 50, 1);
		gotoxy(39, 3);
		cout << "            THONG KE THEO CHUNG LOAI            ";
		j = 0;
		int i = 0;
		while (j != size)
		{
			if (cl[j] == cl[j + 1])
			{
				j++;
				count[i]++;
				continue;
			}
			else
			{
				chungloai[i] = cl[j];
				j++;
				i++;
			}
		}
		chungloai[i] = cl[j];
	}

	Vebangthongke2(30, 7, dem);
	for (int i = 0; i < dem; i++)
	{
		gotoxy(45, 11 + i * 3);
		cout << chungloai[i];
		gotoxy(73, 11 + i * 3);
		cout << count[i];
		gotoxy(88, 11 + i * 3);
		cout << (count[i] * 1.0) / (size * 1.0) * 100.0 << "%";
	}
	gotoxy(77, 7 + (dem + 1) * 3 + 1);
	cout << size;
	Veluachontk2(7 + (dem + 3) * 3 + 1);
	for (int i = 0; i < 100; i++)
	{
		cl[i].clear();
	}
	for (int i = 0; i < 100; i++)
	{
		chungloai[i].clear();
	}
	delete[]count;
	dstb.clear();
}

