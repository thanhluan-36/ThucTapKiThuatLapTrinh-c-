#ifndef SEARCH
#define SEARCH

#include "TTB.h"
#include "FileTTB.h"
#include "Sort.h"

struct Node
{
	TrangThietBi data;
	Node* left;
	Node* right;
};

typedef Node* Tree;
int compare_Search(string xau, string look);
void TimKiemTuanTu(char* file_name, int type);
void INDSTK();
void TimKiemTheoMatb(char* file_name, string a, int n);
void TimKiemTheoTen(char* file_name, string a, int n);
void TimKiemTheoNgaysx(char* file_name, string a, int n);
void TimKiemTheoSoLuong(char* file_name, int a, int n);
void TimKiemTheoChungLoai(char* file_name, string a, int n);

void Free(Tree& root);

void InsertByMatb(Tree& t, TrangThietBi tb);
list<TrangThietBi> SearchByMatb(Tree node, string c);
void TimKiemNhiPhanTheoMatb(char* file_name);

void InsertbyTentb(Tree& t, TrangThietBi tb);
list<TrangThietBi>SearchbyTentb(Tree t, string c);
void TimKiemNhiPhanByTentb(char* file_name);

void InsertbyNgaysx(Tree& root, TrangThietBi tb);
list<TrangThietBi>SearchbyNgaysx(Tree root, string c);
void TimKiemNhiPhanTheoNgaysx(char* file_name);

void InsertbyChungloai(Tree& t, TrangThietBi tb);
list<TrangThietBi>SearchbyChungloai(Tree t, string c);
void TimKiemNhiPhanByChungloai(char* file_name);

#endif // !SEARCH
