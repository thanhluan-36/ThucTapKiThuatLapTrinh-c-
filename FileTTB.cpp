#include "FileTTB.h"

list <TrangThietBi> ReadFile(char* file_name)
{
	list <TrangThietBi> dstb;
	ifstream ReadfromFile;
	ReadfromFile.open(file_name, ios::in);
	if (!ReadfromFile)
	{
		cout << "Khong the mo file!";
		return dstb;
	}

	while (!ReadfromFile.eof())
	{
		string matb, tentb, ngaysx, soluong, chungloai;
		int isoluong;

		getline(ReadfromFile, matb);
		getline(ReadfromFile, tentb);
		getline(ReadfromFile, ngaysx);
		getline(ReadfromFile, soluong);
		getline(ReadfromFile, chungloai);

		isoluong = atoi(soluong.c_str());

		/*if (matb != "")
		{
			TrangThietBi tb(matb, tentb, ngaysx, isoluong, chungloai);
			dstb.push_back(tb);
		}*/
		for (int i = 0; i < matb.length(); i++)
		{
			matb[i] = toupper(matb[i]);
		}
		for (int i = 0; i < tentb.length(); i++)
		{
			tentb[i] = toupper(tentb[i]);
		}
		for (int i = 0; i < chungloai.length(); i++)
		{
			chungloai[i] = toupper(chungloai[i]);
		}
		if (matb != "" || tentb != "" || ngaysx != "" || soluong != "" || chungloai != "" )
		{
			TrangThietBi tb(matb, tentb, ngaysx, isoluong, chungloai);
			dstb.push_back(tb);
		}
	}
	WritetoFileNew(file_name, dstb);
	ReadfromFile.close();
	return dstb;
}

// Ghi du lieu ra file
void WritetoFile(char* file_name, TrangThietBi tb)
{
	ofstream fileOutput(file_name, ios::app);// mo tep va ghi noi dung vao cuoi tep

	if (fileOutput.fail())
	{
		cout << "Khong the mo file!" << endl;
		return;
	}
	fileOutput << tb.GetMatb() << endl;
	fileOutput << tb.GetTentb() << endl;
	fileOutput << tb.GetNgaysx() << endl;
	fileOutput << tb.GetSoluong() << endl;
	fileOutput << tb.GetChungloai() << endl;

	fileOutput.close();
}

void WritetoFile(char* file_name, list<TrangThietBi>dstb)
{
	ofstream fileOutput(file_name, ios::app);
	if (fileOutput.fail())
	{
		cout << "Khong the mo file!" << endl;
		return;
	}
	int count = 0;
	int size = dstb.size();
	while (count < size)
	{
		fileOutput << dstb.front().GetMatb() << endl;
		fileOutput << dstb.front().GetTentb() << endl;
		fileOutput << dstb.front().GetNgaysx() << endl;
		fileOutput << dstb.front().GetSoluong() << endl;
		fileOutput << dstb.front().GetChungloai() << endl;
		dstb.pop_front();
		count++;
	}
	fileOutput.close();
}

void WritetoFileNew(char* file_name, list<TrangThietBi>dstb)
{
	ofstream fileOutput(file_name, ios::out);
	if (fileOutput.fail())
	{
		cout << "Khong the mo file!" << endl;
		return;
	}
	int count = 0;
	int size = dstb.size();
	while (count < size)
	{
		fileOutput << dstb.front().GetMatb() << endl;
		fileOutput << dstb.front().GetTentb() << endl;
		fileOutput << dstb.front().GetNgaysx() << endl;
		fileOutput << dstb.front().GetSoluong() << endl;
		fileOutput << dstb.front().GetChungloai() << endl;
		dstb.pop_front();
		count++;
	}
	fileOutput.close();
}

//Tim mot ho so 
TrangThietBi LayHoSo(string matb, list<TrangThietBi>dstb)
{
	list<TrangThietBi>ds = dstb;
	int count = 0;
	int size = ds.size();
	while (count < size)
	{
		if (ds.front().GetMatb() == matb)
		{
			return ds.front();
		}
		else
		{
			ds.pop_front();
			count++;
		}
	}
	TrangThietBi tb;
	return tb;
}

// Lay vi tri cua trang thiet bi trong ho so de sua
int Vitritb(TrangThietBi tb, list<TrangThietBi>dstb)
{
	list<TrangThietBi>ds = dstb;
	int count = 0;
	int size = ds.size();
	while (count < size)
	{
		if (tb.GetMatb() == ds.front().GetMatb())
		{
			return count;
		}
		else
		{
			count++;
			ds.pop_front();
		}
	}
	return -1;
}

