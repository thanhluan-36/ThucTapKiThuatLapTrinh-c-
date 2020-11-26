#include "Search.h"
char Search[] = "Search.txt";


int compare_Search(string xau, string look)
{
	char* a = (char*)xau.c_str();
	char* b = (char*)look.c_str();
	char* s = strstr(a, b);
	if (s != NULL)
	{
		return 0;
	}
	else return -1;
}

void INDSTK()
{
	position(0);
	int x = 20, y = 5;
	list <TrangThietBi> dstb = ReadFile(Search);
	if (dstb.size() == 0)
	{
		system("cls");
	}
	else {
		system("cls");
		int i = 0, size = dstb.size();
		int j = 0, k = 0;
		int trang = size / 7;
		while (j <= trang)
		{
			textcolor(12);
			veKhung(38, 2, 50, 1);
			gotoxy(52, 3);
			cout << "IN DANH SACH TIM KIEM";
			gotoxy(55, 30);
			cout << ">> Trang " << j + 1 << " / " << trang + 1 << " <<";
			gotoxy(52, 35);
			cout << "Nhan Enter de sang trang";

			while (i < size)
			{
				InDs(20, 5, k + 2);
				textcolor(6);
				gotoxy(x + 2, y + 4 + k * 3); cout << (i + 1);
				gotoxy(x + 8, y + 4 + k * 3); cout << dstb.front().GetMatb();
				gotoxy(x + 24, y + 4 + k * 3); cout << dstb.front().GetTentb();
				gotoxy(x + 42, y + 4 + k * 3); cout << dstb.front().GetNgaysx();
				gotoxy(x + 62, y + 4 + k * 3); cout << dstb.front().GetSoluong();
				gotoxy(x + 78, y + 4 + k * 3); cout << dstb.front().GetChungloai();

				dstb.pop_front();
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
	Mainmenu();
}
//--------------TimKiemTuanTu-----------------------------------------
void TimKiemTheoMatb(char* file_name, string a, int n)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	list<TrangThietBi>dsm;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (compare_Search(dstb.front().GetMatb(), a) == 0)
		{
			dsm.push_back(dstb.front());
			dstb.pop_front();
			count++;
		}
		else {
			dstb.push_back(dstb.front());
			dstb.pop_front();
		}
	}
	WritetoFileNew(Search, dsm);
	gotoxy(52, 15);
	cout << "Co " << count << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
}



void TimKiemTheoTen(char* file_name, string a, int n)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	list<TrangThietBi>dsm;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (compare_Search(dstb.front().GetTentb(), a) == 0)
		{
			dsm.push_back(dstb.front());
			dstb.pop_front();
			count++;
		}
		else {
			dstb.push_back(dstb.front());
			dstb.pop_front();
		}
	}
	WritetoFileNew(Search, dsm);
	gotoxy(52, 15);
	cout << "Co " << count << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
}

void TimKiemTheoNgaysx(char* file_name, string a, int n)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	list<TrangThietBi>dsm;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (compare_Search(dstb.front().GetNgaysx(), a) == 0)
		{
			dsm.push_back(dstb.front());
			dstb.pop_front();
			count++;
		}
		else {
			dstb.push_back(dstb.front());
			dstb.pop_front();
		}
	}
	WritetoFileNew(Search, dsm);
	gotoxy(52, 15);
	cout << "Co " << count << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
}



void TimKiemTheoSoLuong(char* file_name, int a, int n)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	list<TrangThietBi>dsm;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a != dstb.front().GetSoluong())
		{
			dstb.push_back(dstb.front());
			dstb.pop_front();
		}
		else {
			dsm.push_back(dstb.front());
			dstb.pop_front();
			count++;
		}
	}
	WritetoFileNew(Search, dsm);
	gotoxy(52, 15);
	cout << "Co " << count << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
}


void TimKiemTheoChungLoai(char* file_name, string a, int n)
{
	list<TrangThietBi>dstb = ReadFile(file_name);
	list<TrangThietBi>dsm;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (compare_Search(dstb.front().GetChungloai(), a) == 0)
		{
			dsm.push_back(dstb.front());
			dstb.pop_front();
			count++;
		}
		else {
			dstb.push_back(dstb.front());
			dstb.pop_front();
		}
	}
	WritetoFileNew(Search, dsm);
	gotoxy(52, 15);
	cout << "Co " << count << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
}

void TimKiemTuanTu(char* file_name, int type)
{
	string temp = "";
	list<TrangThietBi>dstb = ReadFile(file_name);
	int size = dstb.size();
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM TUAN TU";
	position(1);
	if (type == 0)
	{
		gotoxy(23, 11);
		cout << "Nhap vao ma thiet bi can tim:";
		gotoxy(83, 11);
		rewind(stdin);
		getline(cin, temp);
		for (int i = 0; i < temp.length(); i++)
		{
			temp[i] = toupper(temp[i]);
		}
		TimKiemTheoMatb(file_name, temp, size);
		INDSTK();
	}
	
	if (type == 1)
	{
		gotoxy(23, 11);
		cout << "Nhap vao ten thiet bi can tim:";
		gotoxy(83, 11);
		rewind(stdin);
		getline(cin, temp);
		for (int i = 0; i < temp.length(); i++)
		{
			temp[i] = toupper(temp[i]);
		}
		TimKiemTheoTen(file_name, temp, size);
		INDSTK();
	}

	if (type == 2)
	{
		gotoxy(23, 11);
		cout << "Nhap vao ngay sx thiet bi can tim:";
		gotoxy(83, 11);
		rewind(stdin);
		getline(cin, temp);
		for (int i = 0; i < temp.length(); i++)
		{
			temp[i] = toupper(temp[i]);
		}
		TimKiemTheoNgaysx(file_name, temp, size);
		INDSTK();
	}
	
	if (type == 3)
	{
		gotoxy(23, 11);
		cout << "Nhap vao SL cua thiet bi can tim:";
		gotoxy(83, 11);
		rewind(stdin);
		getline(cin, temp);
		int num = atoi(temp.c_str());
		TimKiemTheoSoLuong(file_name, num, size);
		INDSTK();
	}
	
	if (type == 4)
	{
		gotoxy(23, 11);
		cout << "Nhap vao chung loai thiet bi can tim:";
		gotoxy(83, 11);
		rewind(stdin);
		getline(cin, temp);
		for (int i = 0; i < temp.length(); i++)
		{
			temp[i] = toupper(temp[i]);
		}
		TimKiemTheoChungLoai(file_name, temp, size);
		INDSTK();
	}
}

//---------------TimKiemNhiPhan------------------------------

void Free(Tree& root)
{
	if (root == NULL)
	{
		return;
	}
	Free(root->left);
	Free(root->right);
	free(root);
}

void InsertByMatb(Tree& t, TrangThietBi tb) {
	Node* node = new Node;
	if (t == NULL) {
		node->data = tb;
		node->left = NULL;
		node->right = NULL;
		t = node;
	}
	else {
		if ((t->data).GetMatb() >= tb.GetMatb()) {
			InsertByMatb(t->left, tb);
		}
		else InsertByMatb(t->right, tb);
	}
}

list<TrangThietBi> SearchByMatb(Tree node, string c) {
	list<TrangThietBi> dstk;
	while (node != NULL) {

		if ((node->data).GetMatb() == c) {
			dstk.push_back((node->data));
			node = node->left;
			if (node == NULL) break;
			if (((node->data).GetMatb()) != c) break;
		}
		else {
			if ((node->data).GetMatb() >= c) node = node->left;
			else node = node->right;
		}
	}
	return dstk;
}

void TimKiemNhiPhanTheoMatb(char* file_name)
{
	string temp = "";
	Tree root = NULL;
	list<TrangThietBi>dstb = ReadFile(file_name);
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM NHI PHAN";
	position(1);

	gotoxy(23, 11);
	cout << "Nhap vao ma thiet bi can tim:";
	gotoxy(83, 11);
	rewind(stdin);
	getline(cin, temp);

	for (int i = 0; i < temp.length(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	int size = dstb.size();
	int count = 0;

	while (count < size) {
		InsertByMatb(root, dstb.front());
		dstb.pop_front();
		count++;
	}

	list<TrangThietBi>dstk = SearchByMatb(root, temp);

	gotoxy(52, 15);
	cout << "Co " << dstk.size() << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");

	WritetoFileNew(Search, dstk);
	Free(root);
	INDSTK();
}

//////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////

void InsertbyTentb(Tree& t, TrangThietBi tb)
{
	Node* node = new Node;
	if (t == NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = tb;
		t = node;
	}
	else
	{
		if ((t->data).GetTentb() >= tb.GetTentb())
		{
			InsertbyTentb(t->left, tb);
		}
		else InsertbyTentb(t->right, tb);
	}
}

list<TrangThietBi>SearchbyTentb(Tree t, string c)
{
	list<TrangThietBi>dstk;
	while (t != NULL)
	{
		if ((t->data).GetTentb() == c)
		{
			dstk.push_back(t->data);
			t = t->left;
			if (t == NULL) break;
			if ((t->data).GetTentb() != c) break;
		}
		else
		{
			if ((t->data).GetTentb() >= c)
			{
				t = t->left;
			}
			else t = t->right;
		}
	}
	return dstk;
}

void TimKiemNhiPhanByTentb(char* file_name)
{
	string temp = "";
	Tree root = NULL;
	list<TrangThietBi>dstb = ReadFile(file_name);
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM NHI PHAN";
	position(1);

	gotoxy(23, 11);
	cout << "Nhap vao ten thiet bi can tim:";
	gotoxy(83, 11);
	rewind(stdin);
	getline(cin, temp);

	for (int i = 0; i < temp.length(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	int size = dstb.size();
	int count = 0;
	while (count < size)
	{
		InsertbyTentb(root, dstb.front());
		dstb.pop_front();
		count++;
	}

	list<TrangThietBi>dstk = SearchbyTentb(root, temp);
	WritetoFileNew(Search, dstk);

	gotoxy(52, 15);
	cout << "Co " << dstk.size() << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
	Free(root);
	INDSTK();
}

////////////////////////////////////////////////////////////////////////////////////

void InsertbyNgaysx(Tree& root, TrangThietBi tb)
{
	Node* node = new Node;
	if (root == NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = tb;
		root = node;
	}
	else
	{
		if (XuLyChuoi((root->data).GetNgaysx()) >= XuLyChuoi(tb.GetNgaysx()))
		{
			InsertbyNgaysx(root->left, tb);
		}
		else InsertbyNgaysx(root->right, tb);
	}
}

list<TrangThietBi>SearchbyNgaysx(Tree root, string c)
{
	list<TrangThietBi>dstk;
	while (root != NULL)
	{
		if ((root->data).GetNgaysx() == c)
		{
			dstk.push_back(root->data);
			root = root->left;
			if (root == NULL) break;
			if ((root->data).GetNgaysx() != c) break;
		}
		else
		{
			if (XuLyChuoi((root->data).GetNgaysx()) >= XuLyChuoi(c))
			{
				root = root->left;
			}
			else root = root->right;
		}
	}
	return dstk;
}

void TimKiemNhiPhanTheoNgaysx(char* file_name)
{
	string temp = "";
	Tree root = NULL;
	list<TrangThietBi>dstb = ReadFile(file_name);
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM NHI PHAN";
	position(1);

	gotoxy(23, 11);
	cout << "Nhap vao ngaysx thiet bi can tim:";
	gotoxy(83, 11);
	rewind(stdin);
	getline(cin, temp);

	for (int i = 0; i < temp.length(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	int size = dstb.size();
	int count = 0;

	while (count < size)
	{
		InsertbyNgaysx(root, dstb.front());
		dstb.pop_front();
		count++;
	}

	list<TrangThietBi>dstk = SearchbyNgaysx(root, temp);
	WritetoFileNew(Search, dstk);

	gotoxy(52, 15);
	cout << "Co " << dstk.size() << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
	Free(root);
	INDSTK();
}


///////////////////////////////////////////////////////////////////////////


void InsertbySLtb(Tree& t, TrangThietBi tb)
{
	Node* node = new Node;
	if (t == NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = tb;
		t = node;
	}
	else
	{
		if ((t->data).GetSoluong() >= tb.GetSoluong())
		{
			InsertbySLtb(t->left, tb);
		}
		else InsertbySLtb(t->right, tb);
	}
}

list<TrangThietBi>SearchbySLtb(Tree t, int c)
{
	list<TrangThietBi>dstk;
	while (t != NULL)
	{
		if ((t->data).GetSoluong() == c)
		{
			dstk.push_back(t->data);
			t = t->left;
			if (t == NULL) break;
			if ((t->data).GetSoluong() != c) break;
		}
		else
		{
			if ((t->data).GetSoluong() >= c)
			{
				t = t->left;
			}
			else t = t->right;
		}
	}
	return dstk;
}

void TimKiemNhiPhanBySLtb(char* file_name)
{
	int temp;
	Tree root = NULL;
	list<TrangThietBi>dstb = ReadFile(file_name);
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM NHI PHAN";
	position(1);

	gotoxy(23, 11);
	cout << "Nhap vao SL cua thiet bi can tim:";
	gotoxy(83, 11);
	cin >> temp;

	int size = dstb.size();
	int count = 0;
	while (count < size)
	{
		InsertbySLtb(root, dstb.front());
		dstb.pop_front();
		count++;
	}

	list<TrangThietBi>dstk = SearchbySLtb(root, temp);
	WritetoFileNew(Search, dstk);

	gotoxy(52, 15);
	cout << "Co " << dstk.size() << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
	Free(root);
	INDSTK();
}

//////////////////////////////////////////////////////////////////////////////


void InsertbyChungloai(Tree& t, TrangThietBi tb)
{
	Node* node = new Node;
	if (t == NULL)
	{
		node->left = NULL;
		node->right = NULL;
		node->data = tb;
		t = node;
	}
	else
	{
		if ((t->data).GetChungloai() >= tb.GetChungloai())
		{
			InsertbyChungloai(t->left, tb);
		}
		else InsertbyChungloai(t->right, tb);
	}
}

list<TrangThietBi>SearchbyChungloai(Tree t, string c)
{
	list<TrangThietBi>dstk;
	while (t != NULL)
	{
		if ((t->data).GetChungloai() == c)
		{
			dstk.push_back(t->data);
			t = t->left;
			if (t == NULL) break;
			if ((t->data).GetChungloai() != c) break;
		}
		else
		{
			if ((t->data).GetChungloai() >= c)
			{
				t = t->left;
			}
			else t = t->right;
		}
	}
	return dstk;
}

void TimKiemNhiPhanByChungloai(char* file_name)
{
	string temp = "";
	Tree root = NULL;
	list<TrangThietBi>dstb = ReadFile(file_name);
	system("cls");
	textcolor(11);
	veKhung(42, 5, 40, 1);
	veKhung(20, 10, 40, 1);
	veKhung(80, 10, 25, 1);
	gotoxy(53, 6);
	textcolor(6);
	cout << "TIM KIEM NHI PHAN";
	position(1);

	gotoxy(22, 11);
	cout << "Nhap vao chung loai thiet bi can tim:";
	gotoxy(83, 11);
	rewind(stdin);
	getline(cin, temp);

	for (int i = 0; i < temp.length(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	int size = dstb.size();
	int count = 0;
	while (count < size)
	{
		InsertbyChungloai(root, dstb.front());
		dstb.pop_front();
		count++;
	}

	list<TrangThietBi>dstk = SearchbyChungloai(root, temp);
	WritetoFileNew(Search, dstk);

	gotoxy(52, 15);
	cout << "Co " << dstk.size() << " ket qua duoc tim thay!";
	gotoxy(50, 16);
	system("pause");
	Free(root);
	INDSTK();
}
