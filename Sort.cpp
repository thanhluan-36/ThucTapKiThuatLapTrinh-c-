#include "Sort.h"

void swap(string& s1, string& s2) {
	string temp = s1;
	s1 = s2;
	s2 = temp;
}

//----------------StringSort----------------------
void bubbleSort(string a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			if ((XuLyChuoi(a[j]) > XuLyChuoi(a[j + 1]))) {
				swap(a[j], a[j + 1]);
			}
	}
}

void insertionSort(string a[], int n) {
	int i, j;
	string key;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && (XuLyChuoi(a[j]) > XuLyChuoi(key)))
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void selectionSort(string a[], int n) {
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++)

			if (XuLyChuoi(a[j]) < XuLyChuoi(a[min_idx]))
			{
				min_idx = j;
			}

		swap(a[min_idx], a[i]);
	}
}

int chiaDeTri(string a[], int low, int high) {
	string chot = a[low];
	int left = low + 1;
	int right = high;
	while (true) {
		while (left <= right && (XuLyChuoi(a[left]) < XuLyChuoi(chot))) left++;
		while (right >= left && (XuLyChuoi(a[right]) > XuLyChuoi(chot))) right--;
		if (left >= right) break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[right], a[low]);
	return right;
}

void quickSort(string arr[], int low, int high)
{
	if (low < high)
	{
		/* phan tu chia mang thanh 2 phan trai phai */
		int pi = chiaDeTri(arr, low, high);
		// Giai de quy
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//-----------------SupportStringSort------------------

string XuLyChuoi(string a)
{
	string result = "";
	string temp[4];
	int j = 0;
	int len = a.length();
	for (int i = 0; i < len; i++)
	{
		if (a[i] != ' ' && a[i] != '/')
		{
			temp[j] = temp[j] + a[i];
		}
		else
		{
			j++;
		}
	}
	for (int i = 3; i >= 0; i--)
	{
		result = result + temp[i];
	}
	return result;
}
//------------------Sorting------------------

void sortByCode(char* file_name, int type) {
	list<TrangThietBi> listTTB = ReadFile(file_name);
	string strCode[50];
	int count = 0;
	int a = listTTB.size();

	for (int i = 0; i < a; i++) {
		strCode[i] = listTTB.front().GetMatb();
		listTTB.push_back(listTTB.front());
		listTTB.pop_front();
		count++;
	}

	if (type == 2)
	{
		bubbleSort(strCode, count);
	}
	if (type == 1)
	{
		insertionSort(strCode, count);
	}
	if (type == 0)
	{
		selectionSort(strCode, count);
	}
	if (type == 3)
	{
		quickSort(strCode, 0, count - 1);
	}
	list<TrangThietBi> sortedList;

	for (int i = 0; i < count; i++) {

		while (strCode[i] != listTTB.front().GetMatb()) {

			listTTB.push_back(listTTB.front());
			listTTB.pop_front();

		}

		sortedList.push_back(listTTB.front());
		listTTB.pop_front();

	}

	//WritetoFile(file_name, sortedList);
	WritetoFileNew(file_name, sortedList);
	for (int i = 0; i < 50; i++)
	{
		strCode[i].clear();
	}
	listTTB.clear();
	sortedList.clear();

}

void sortByName(char* file_name, int type) {

	list<TrangThietBi> listTTB = ReadFile(file_name);

	string strName[50];// chuyen listTTB.size() thanh 10
	int count = 0;
	while (count < listTTB.size()) {

		strName[count] = listTTB.front().GetTentb();
		listTTB.push_back(listTTB.front());
		listTTB.pop_front();
		count++;

	}

	if (type == 2)
	{
		bubbleSort(strName, count);
	}
	if (type == 1)
	{
		insertionSort(strName, count);
	}
	if (type == 0)
	{
		selectionSort(strName, count);
	}
	if (type == 3)
	{
		quickSort(strName, 0, count - 1);
	}

	list<TrangThietBi> sortedList;

	for (int i = 0; i < count; i++) {

		while (strName[i] != listTTB.front().GetTentb()) {

			listTTB.push_back(listTTB.front());
			listTTB.pop_front();

		}

		sortedList.push_back(listTTB.front());
		listTTB.pop_front();

	}

	//WritetoFile(file_name, sortedList); // WriteListToFile thanh WritetoFile
	WritetoFileNew(file_name, sortedList);
	for (int i = 0; i < 50; i++)
	{
		strName[i].clear();
	}
	listTTB.clear();
	sortedList.clear();
}

void sortByDate(char* file_name, int type) {

	list<TrangThietBi> listTTB = ReadFile(file_name);

	string strDate[50];

	int count = 0;
	while (count < listTTB.size()) {

		strDate[count] = listTTB.front().GetNgaysx();
		listTTB.push_back(listTTB.front());
		listTTB.pop_front();
		count++;

	}

	if (type == 2)
	{
		bubbleSort(strDate, count);
	}
	if (type == 1)
	{
		insertionSort(strDate, count);
	}
	if (type == 0)
	{
		selectionSort(strDate, count);
	}
	if (type == 3)
	{
		quickSort(strDate, 0, count - 1);
	}

	list<TrangThietBi> sortedList;

	for (int i = 0; i < count; i++) {

		while (strDate[i] != listTTB.front().GetNgaysx()) {

			listTTB.push_back(listTTB.front());
			listTTB.pop_front();

		}

		sortedList.push_back(listTTB.front());
		listTTB.pop_front();

	}

	//WritetoFile(file_name, sortedList);
	WritetoFileNew(file_name, sortedList);
	for (int i = 0; i < 50; i++)
	{
		strDate[i].clear();
	}
	listTTB.clear();
	sortedList.clear();
}

void sortByScore(char* file_name, int type) {

	list<TrangThietBi> listTTB = ReadFile(file_name);

	string strScore[50];

	int count = 0;
	while (count < listTTB.size()) {

		ostringstream convert;//Chuyen tu double->string
		convert << listTTB.front().GetSoluong();
		strScore[count] = convert.str();
		listTTB.push_back(listTTB.front());
		listTTB.pop_front();
		count++;

	}

	if (type == 2)
	{
		bubbleSort(strScore, count);
	}
	if (type == 1)
	{
		insertionSort(strScore, count);
	}
	if (type == 0)
	{
		selectionSort(strScore, count);
	}
	if (type == 3)
	{
		quickSort(strScore, 0, count - 1);
	}

	list<TrangThietBi> sortedList;

	for (int i = 0; i < count; i++) {

		while (atof(strScore[i].c_str()) != (listTTB.front().GetSoluong())) {//chuyen tu string->double de so sanh

			listTTB.push_back(listTTB.front());
			listTTB.pop_front();

		}

		sortedList.push_back(listTTB.front());
		listTTB.pop_front();

	}

	//WritetoFile(file_name, sortedList);
	WritetoFileNew(file_name, sortedList);
	for (int i = 0; i < 50; i++)
	{
		strScore[i].clear();
	}
	listTTB.clear();
	sortedList.clear();
}
void sortByClass(char* file_name, int type) {// get ma lop thanh get chung loai

	list<TrangThietBi> listTTB = ReadFile(file_name);

	string strClass[50];

	int count = 0;
	while (count < listTTB.size()) {

		strClass[count] = listTTB.front().GetChungloai();
		listTTB.push_back(listTTB.front());
		listTTB.pop_front();
		count++;
	}

	if (type == 2)
		bubbleSort(strClass, count);
	if (type == 1)
		insertionSort(strClass, count);
	if (type == 0)
		selectionSort(strClass, count);
	if (type == 3)
		quickSort(strClass, 0, count - 1);

	list<TrangThietBi> sortedList;

	for (int i = 0; i < count; i++) {

		while (strClass[i] != listTTB.front().GetChungloai()) {

			listTTB.push_back(listTTB.front());
			listTTB.pop_front();

		}

		sortedList.push_back(listTTB.front());
		listTTB.pop_front();

	}

	//WritetoFile(file_name, sortedList);
	WritetoFileNew(file_name, sortedList);
	for (int i = 0; i < 50; i++)
	{
		strClass[i].clear();
	}
	listTTB.clear();
	sortedList.clear();
}
