#include"Menu.h"
#include"TTB.h"
#include"Sort.h"
#include"Search.h"
#include"Thongke.h"

string ds_Menu[]= {"1. khoi tao danh sanh","2. In danh sach", "3. Sap xep",
"4. Tim kiem", "5. Thong ke", "6. Thoat"
};
string ds_ThemMoiHoSo[]={"1. Ma TTB", "2. Ten TTB", "3. Ngay san xuat",
"4. So luong ","5. Chung Loai "
};
string ds_SapXep[]={"1. Sap xep chon", "2. Sap xep chen", "3. Sap xep noi bot",
"4. Sap xep QuickSort","5. Thoat"
};
string ds_TimKiem[]={"1. Tim kiem nhi phan","2. Tim kiem tuan tu","3. Thoat"};
string ds_CapNhat[] = { " 1: Them moi ho so TTB"," 2: Sua ho so TTB"," 3: Xoa ho so TTB",
" 4.Tro Ve" };
string ds_KhoaSapXep_TimKiem[] = { " 1.Theo ma TTB" ,
				" 2.Theo ten TTB" ,
				" 3.Theo ngay SX" ,
				" 4.Theo So Luong" ,
				" 5.Theo Chung Loai" ,
				" 6.Tro lai" };
string luachon[] = { "Luu", "Sua" };
string Thong_ke[] = { "   Theo nam san xuat     ",
					"   Theo chung loai       ",
					"           MENU         "
};
char file_output[] = "ttb.txt";
char file_input[] = "ttb1.txt";


void Mainmenu(){
	
	system( "cls" );

	textcolor( 260 );
	veKhung( 45 , 4 , 30 , 1 );
	gotoxy( 50 , 5 );
	cout << "QUAN LI TRANG THIET BI";
	
	textcolor( 3 );
	
	switch( VeMenuDoc ( ds_Menu , 6 , 0 , 5 , 22 , 13 , 40 , 4  )){
		case 0:{
			CapNhatHoSo();
			break;
		}
		
		case 1:{
			InDanhSach();
			break;
		}
		
		case 2:{
			SapXep();
			break;
		}
		
		case 3:{
			TimKiem();
			break;
		}
		
		case 4:{
			Thongke();
			break;
		}
		
		case 5:{
			
			bye();
			break;
		}
	}
}

void CapNhatHoSo()
{
	//textcolor(TITLE_COLOR);	
	veKhung(68, 10, 50, 14);
	textcolor(260);
	switch (VeMenuDoc(ds_CapNhat, 4, 0, 3, 74, 12, 40, 3)) {
	case 0: {
		Them();
		break;
	}
	case 1: {
		ChinhSuaHoSo();
		break;
	}
	case 2: {
		XoaHoSo();
		break;
	}
	case 3: {
		Mainmenu();
		break;
	}
	
	}
}

void Them() {
	//system("cls");
	string tam1 = "", tam2 = "", tam3 = "", tam4 = "", tam5 = "", tam6 = "";
	veKhung(68, 27, 30, 1);
	veKhung(98, 27, 10, 1);
	gotoxy(69, 28);
	textcolor(260);
	cout << "NHAP SO LUONG TTB CAN THEM: ";
	gotoxy(99, 28);
	int sum;
	int trang = 1; string temp;
	while (temp == "")
	{
		gotoxy(99, 28);
		rewind(stdin);
		getline(cin, temp);
	}
	sum = atoi(temp.c_str());
	
	
	while (trang <= sum)
	{
		system("cls");
		textcolor(2);
		veKhung(93, 29, 7, 1);
		gotoxy(95, 30);
		cout << trang << "/" << sum;
		textcolor(5);
		veKhung(53, 2, 30, 1);
		gotoxy(59, 3);
		cout << "NHAP THONG TIN TTB";
		textcolor(2);
		veKhungThongTin();
		TrangThietBi obj;

		int toado = 0;
		while (true)
		{
			Menuluachon(toado);
			if (toado == 0)
			{
				obj.SetMatb(toado, tam1);
			}
			if (toado == 1)
			{
				obj.SetTentb(toado, tam3);
			}
			if (toado == 2)
			{
				obj.SetNgaysx(toado, tam4);
			}
			if (toado == 3)
			{
				obj.SetSoluong(toado, tam5);
			}
			if (toado == 4)
			{
				obj.SetChungloai(toado, tam6);
			}
			if (toado == 6)
			{
				list <TrangThietBi> dstb = ReadFile(file_output);
				dstb.push_back(obj);
				WritetoFile(file_output, obj);
				system("cls");
				gotoxy(50, 10);
				textcolor(206);
				cout << "LUU DU LIEU THANH CONG!";
				textcolor(0);
				Sleep(1200);
				break;
			}
		}
		position(1);
		trang++;
	}
	Mainmenu();
}

void ChinhSuaHoSo()
{
	list<TrangThietBi>dstb = ReadFile(file_output);
	system("cls");
	textcolor(11);
	veKhung(38, 2, 50, 1);
	gotoxy(55, 3);
	textcolor(6);
	cout << "CHINH SUA HO SO";
	textcolor(11);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	textcolor(6);
	gotoxy(22, 11);
	cout << "Nhap ma thiet bi can sua:";
	gotoxy(83, 11);
	string matb;
	rewind(stdin);
	getline(cin, matb);
	for (int i = 0; i < matb.length(); i++)
	{
		matb[i] = toupper(matb[i]);
	}
	system("cls");
	TrangThietBi hsc = LayHoSo(matb, dstb);
	
	if (hsc.GetMatb() == "")
	{
		gotoxy(50, 10);
		textcolor(12);
		cout << "KHONG TIM THAY HO SO THIET BI CO MA: " << matb << "!" << endl;
	}
	else
	{
		veKhungThongTin();
		gotoxy(53, 4);
		cout << "NHAP THONG TIN SUA DOI" << endl;

		gotoxy(69, 8);
		cout << hsc.GetMatb();
		gotoxy(69, 12);
		cout << hsc.GetTentb();
		gotoxy(69, 16);
		cout << hsc.GetNgaysx();
		gotoxy(69, 20);
		cout << hsc.GetSoluong();
		gotoxy(69, 24);
		cout << hsc.GetChungloai();

		string x1, x2, x3, x4, x5, x6;
		ostringstream convert;
		convert << hsc.GetSoluong();
		x1 = hsc.GetMatb();
		x2 = hsc.GetTentb();
		x3 = hsc.GetNgaysx();
		x4 = hsc.GetSoluong();
		x5 = hsc.GetChungloai();
		TrangThietBi obj;
		

		int toado = 0;
		while (1)
		{
			Menuluachon(toado);
			if (toado == 0)
			{
				position(0);
				gotoxy(110, 8);
				cout << "<<<";
				char c = _getch();
				if (c == 13)
				{
					position(1);
					obj.SetMatb(toado, x1);
				}
				if (c == -32)
				{
					c = _getch();
					if (c == 80) toado = 1;
					gotoxy(110, 8);
					cout << "   ";
					obj.SetMatb(x1);
				}
			}
			
			if (toado == 1)
			{
				gotoxy(110, 12);
				cout << "<<<";
				position(0);
				char c = _getch();
				if (c == 13)
				{
					position(1);
					obj.SetTentb(toado, x2);
				}
				if (c == -32)
				{
					c = _getch();
					if (c == 72) toado = 0;
					if (c == 80) toado = 2;
					gotoxy(110, 12);
					cout << "   ";
					obj.SetTentb(x2);
				}
			}
			if (toado == 2)
			{
				gotoxy(110, 16);
				cout << "<<<";
				position(0);
				char c = _getch();
				if (c == 13)
				{
					position(1);
					obj.SetNgaysx(toado, x3);
				}
				if (c == -32)
				{
					c = _getch();
					if (c == 72) toado = 1;
					if (c == 80) toado = 3;
					gotoxy(110, 16);
					cout << "   ";
					obj.SetNgaysx(x3);
				}
			}
			
			
			if (toado == 3)
			{
				gotoxy(110, 20);
				cout << "<<<";
				position(0);
				char c = _getch();
				if (c == 13)
				{
					position(1);
					obj.SetSoluong(toado, x4);
				}
				if (c == -32)
				{
					c = _getch();
					if (c == 72) toado = 2;
					if (c == 80) toado = 4;
					gotoxy(110, 20);
					cout << "   ";
					obj.SetSoluong(x4);
				}
			}
			if (toado == 4)
			{
				gotoxy(110, 24);
				cout << "<<<";
				position(0);
				char c = _getch();
				if (c == 13)
				{
					position(1);
					obj.SetChungloai(toado, x5);
				}
				if (c == -32)
				{
					c = _getch();
					if (c == 72) toado = 3;
					if (c == 80) toado = 5;
					gotoxy(110, 24);
					cout << "   ";
					obj.SetChungloai(x5);
				}
			}
			if (toado == 6)
			{
				int vitri = Vitritb(hsc, dstb);
				int size = dstb.size();
				int count = 0;
				list<TrangThietBi>dsm;
				while (count < size)
				{
					if (count != vitri)
					{
						dsm.push_back(dstb.front());
						dstb.pop_front();
						count++;
					}
					else
					{
						dstb.pop_front();
						dsm.push_back(obj);
						count++;
					}
				}
				WritetoFileNew(file_output, dsm);
				system("cls");
				gotoxy(50, 10);
				textcolor(12);
				cout << "SUA THONG TIN THANH CONG!" << endl;
				break;
			}
		}
	}
	gotoxy(52, 12);
	system("pause");
	cout << endl;
	textcolor(0);
	Mainmenu();
}
void XoaHoSo()
{
	list<TrangThietBi>dstb = ReadFile(file_output);
	system("cls");
	textcolor(11);
	veKhung(38, 2, 50, 1);
	gotoxy(55, 3);
	textcolor(6);
	cout << "XOA HO SO TTB";
	textcolor(11);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	textcolor(6);
	gotoxy(22, 11);
	cout << "Nhap ma thiet bi can xoa:";
	gotoxy(83, 11);
	string matb;
	rewind(stdin);
	getline(cin, matb);

	TrangThietBi hsc = LayHoSo(matb, dstb);
	if (hsc.GetMatb() == "")
	{
		system("cls");
		gotoxy(50, 10);
		textcolor(12);
		cout << "KHONG TIM THAY HO SO THIET BI CO MA: " << matb << "!" << endl;
	}
	else
	{
		int vitri = Vitritb(hsc, dstb);
		int size = dstb.size();
		int count = 0;
		list<TrangThietBi>dsm;
		while (count < size)
		{
			if (count != vitri)
			{
				dsm.push_back(dstb.front());
				dstb.pop_front();
				count++;
			}
			else
			{
				dstb.pop_front();
				count++;
			}
		}
		WritetoFileNew(file_output, dsm);
		system("cls");
		gotoxy(50, 10);
		textcolor(12);
		cout << "XOA HO SO TTB THANH CONG!" << endl;
	}
	gotoxy(52, 12);
	system("pause");
	cout << endl;
	Mainmenu();
}
void InDanhSach()
{
	int x = 20, y = 5;
	list <TrangThietBi> dstb = ReadFile(file_output);
	if (dstb.size() == 0)
	{
		system("cls");
		gotoxy(55, 10);
		textcolor(12);
		cout << "DANH SACH TRONG!" << endl;
	}
	else {
		system("cls");
		gotoxy(23, 30);
		int i = 0, size = dstb.size();
		int j = 0, k = 0;
		int trang = size / 7;
		while (j <= trang)
		{
			textcolor(12);
			veKhung(38, 2, 50, 1);
			gotoxy(57, 3);
			cout << "IN DANH SACH";
			gotoxy(55, 30);
			cout << ">> Trang " << j + 1 << " / " << trang + 1 << " <<";
			gotoxy(52, 35);
			cout << "Nhan Enter de sang trang";
			InDs(20, 5, 8);
			while (i < size)
			{
				textcolor(6);
				gotoxy(x + 2, y + 4 + k * 3); cout  << (i + 1);// hien thi so thu tu
				gotoxy(x + 8, y + 4 + k * 3); cout  << dstb.front().GetMatb();
				gotoxy(x + 24, y + 4 + k * 3); cout << dstb.front().GetTentb();
				gotoxy(x + 42, y + 4 + k * 3); cout << dstb.front().GetNgaysx();
				gotoxy(x + 62, y + 4 + k * 3); cout << dstb.front().GetSoluong();
				gotoxy(x + 76, y + 4 + k * 3); cout << dstb.front().GetChungloai();

				dstb.pop_front();// loai bo phan tu dau tien , mang giam kich thuoc xuong 1
				i++;
				k++;
				if (k == 7) break;
			}
			x = 20, y = 5, k = 0;
			j++;
			_getch();
			system("cls");
		}
	}
	gotoxy(52, 12);
	system("pause");
	cout << endl;
	Mainmenu();
}
void SapXep() {

	//system("cls");
	textcolor(TITLE_COLOR);
	veKhung(70, 13, 44, 16);
	textcolor(3);
	switch (VeMenuDoc(ds_SapXep, 5, 0, 4, 74, 15, 40, 3)) {
	case 0: {
		system("cls");
		SapXepChon();
		break;
	}
	case 1: {
		system("cls");
		SapXepChen();
		break;
	}
	case 2: {
		system("cls");
		SapXepNoiBot();
		break;
	}
	case 3: {
		system("cls");
		SapXepNhanh();
		break;
	}
	case 4: {
		system("cls");
		Mainmenu();
		break;
	}
	}

}

void SapXepChon() {

	textcolor(TITLE_COLOR);
	veKhung(45, 2, 40, 1);
	gotoxy(59, 3);
	cout << "Sap Xep Chon";
	textcolor(3);
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 6, 0, 5, 47, 10, 40, 3)) {
		case 0: {
			sortByCode(file_output, SELECTION_SORT);
			InDanhSach();
			break;
		}
		case 1: {
			
			sortByName(file_output, SELECTION_SORT);
			InDanhSach();
			break;
		}
		case 2: {
			sortByDate(file_output, SELECTION_SORT);
			InDanhSach();
			break;
		}
		case 3: {
			sortByScore(file_output, SELECTION_SORT);
			InDanhSach();
			break;
		}
		case 4: {
			sortByClass(file_output, SELECTION_SORT);
			InDanhSach();
			break;
		}
		case 5: {
			system("cls");
			SapXep();
			break;
		}
	}
}
void SapXepChen() {
	system("cls");
	textcolor(TITLE_COLOR);
	veKhung(45, 2, 40, 1);
	gotoxy(59, 3);
	cout << "Sap Xep Chen";
	textcolor(3);
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 6, 0, 5, 47, 10, 40, 3)) {
	case 0: {
		sortByCode(file_output, INSERTION_SORT);
		InDanhSach();
		break;
	}
	case 1: {
		sortByName(file_output, INSERTION_SORT);
		InDanhSach();
		break;
	}
	case 2: {
		sortByDate(file_output, INSERTION_SORT);
		InDanhSach();
		break;
	}
	case 3: {
		sortByScore(file_output, INSERTION_SORT);
		InDanhSach();
		break;
	}
	case 4: {
		sortByClass(file_output, INSERTION_SORT);
		InDanhSach();
		break;
	}
	case 5: {
		system("cls");
		SapXep();
		break;
	}
	}
}
void SapXepNoiBot() {
	system("cls");
	textcolor(TITLE_COLOR);
	veKhung(45, 2, 40, 1);
	gotoxy(59, 3);
	cout << "Sap Xep Noi Bot";
	textcolor(3);
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 6, 0, 5, 47, 10, 40, 3)) {
	case 0: {
		sortByCode(file_output, BUBBLE_SORT);
		InDanhSach();
		break;
	}
	case 1: {
		sortByName(file_output, BUBBLE_SORT);
		InDanhSach();
		break;
	}
	case 2: {
		sortByDate(file_output, BUBBLE_SORT);
		InDanhSach();
		break;
	}
	case 3: {
		sortByScore(file_output, BUBBLE_SORT);
		InDanhSach();
		break;
	}
	case 4: {
		sortByClass(file_output, BUBBLE_SORT);
		InDanhSach();
		break;
	}
	case 5: {
		system("cls");
		SapXep();
		break;
	}
	}
}


void SapXepNhanh() {

	system("cls");
	textcolor(TITLE_COLOR);
	veKhung(45, 2, 40, 1);
	gotoxy(59, 3);
	cout << "Sap Xep Nhanh";
	textcolor(3);
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 6, 0, 5, 47, 10, 40, 3)) {
	case 0: {
		sortByCode(file_output, QUICK_SORT);
		InDanhSach();
		break;
	}
	case 1: {
		sortByName(file_output, QUICK_SORT);
		InDanhSach();
		break;
	}
	case 2: {
		sortByDate(file_output, QUICK_SORT);
		InDanhSach();
		break;
	}
	case 3: {
		sortByScore(file_output, QUICK_SORT);
		InDanhSach();
		break;
	}
	case 4: {
		sortByClass(file_output, QUICK_SORT);
		InDanhSach();
		break;
	}
	case 5: {
		system("cls");
		SapXep();
		break;
	}
	}
}
void modau(){
	system("cls");
	
	int i=0;
 
    while(1) {

        i++; 
		if (i>15) {
			i=1;
		}
        textcolor(i);
        test();
        Sleep(100);

        textcolor(2);

		mantrang();           

		if(_kbhit() ){
			break;
		}
		textcolor(1);

   }

	_getch();

	
	Mainmenu();
	
}

void TimKiem()
{
	system("cls");
	textcolor(206);
	veKhung(38, 2, 50, 1);
	gotoxy(39, 3);
	cout << "                   TIM KIEM                     ";
	switch (VeMenuDoc(ds_TimKiem, 3, 0, 2, 46, 10, 40, 3))
	{
	case 0: {
		Tim_Kiem_Tuan_Tu();
		break;
	}
	case 1: {
		Tim_Kiem_Nhi_Phan();
		break;
	}
	case 2: {
		Mainmenu();
		break;
	}
	}
}
void Tim_Kiem_Tuan_Tu()
{
	system("cls");
	textcolor(206);
	veKhung(38, 2, 50, 1);
	gotoxy(39, 3);
	cout << "               TIM KIEM TUAN TU                 ";
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 5, 0, 4, 46, 10, 40, 3))
	{
	case 0: {
		TimKiemTuanTu(file_output, 0);
		break;
	}
	case 1: {
		TimKiemTuanTu(file_output, 1);
		break;
	}
	case 2: {
		TimKiemTuanTu(file_output, 2);
		break;
	}
	case 3: {
		TimKiemTuanTu(file_output, 3);
		break;
	}
	case 4: {
		TimKiemTuanTu(file_output, 4);
		break;
	}
	
	
	}
}

void Tim_Kiem_Nhi_Phan()
{
	system("cls");
	textcolor(206);
	veKhung(38, 2, 50, 1);
	gotoxy(39, 3);
	cout << "               TIM KIEM NHI PHAN                 ";
	switch (VeMenuDoc(ds_KhoaSapXep_TimKiem, 3, 0, 2, 46, 10, 40, 3))
	{
	case 0: {
		TimKiemNhiPhanTheoMatb(file_output);
		break;
	}
	case 1: {
		TimKiemNhiPhanByTentb(file_output);
		break;
	}
	case 2: {
		TimKiemNhiPhanTheoNgaysx(file_output);
		break;
	}
	
	}
}


void Thongke()
{
	system("cls");
	textcolor(20);
	veKhung(38, 2, 50, 1);
	gotoxy(39, 3);
	cout << "                    THONG KE                    ";
	switch (VeMenuDoc(Thong_ke, 3, 0, 2, 46, 10, 40, 3))
	{
	case 0: {
		ThongKeTheoNamsx(file_output);
		break;
	}
	case 1: {
		ThongKeTheoChungLoai(file_output);
		break;
	}
	
	case 2: {
		Mainmenu();
	}
	}
}




