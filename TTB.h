#ifndef TTB_H
#define TTB_H

#include "DrawAndColor.h"
#include<ctype.h>
#include<string>
//#include"Menu.h"
class TrangThietBi
{
private:
	string Matb;
	string Tentb;
	string Ngaysanxuat;
	int Soluong;
	string Chungloai;
public:
	TrangThietBi();
	TrangThietBi(string Matb, string Tentb, string Ngaysanxuat, int Soluong, string Chungloai);
	TrangThietBi(const TrangThietBi& tb);
	~TrangThietBi();

	void SetMatb(int& toado, string& temp);
	void SetTentb(int& toado, string& temp);
	void SetNgaysx(int& toado, string& temp);
	void SetSoluong(int& toado, string& temp);
	void SetChungloai(int& toado, string& temp);

	void SetMatb(string temp);
	void SetTentb(string temp);
	void SetNgaysx(string temp);
	void SetSoluong(string temp);
	void SetChungloai(string temp);

	string GetMatb();
	string GetTentb();
	string GetNgaysx();
	int GetSoluong();
	string GetChungloai();

	bool KiemTraNgay(string date);
	string ChuanHoaTen(string& name);
};
#endif // !TRANGTHIETBI

