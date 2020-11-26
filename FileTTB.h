#ifndef FILETTB_H
#define FILETTB_H

#include "DrawAndColor.h"
#include<list>
#include<vector>
#include<fstream>
#include<string>
#include "TTB.h"

// Doc du lieu tu file
list <TrangThietBi> ReadFile(char* file_name);

// Ghi du lieu ra file
void WritetoFile(char* file_name, TrangThietBi tb);
void WritetoFile(char* file_name, list<TrangThietBi>dstb);
void WritetoFileNew(char* file_name, list<TrangThietBi>dstb);
TrangThietBi LayHoSo(string matb, list<TrangThietBi>dstb);
int Vitritb(TrangThietBi tb, list<TrangThietBi>dstb);

#endif // FILETTB