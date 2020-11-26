#ifndef SORT_H
#define SORT_H

#include"TTB.h"
#include"FileTTB.h"
#include"Menu.h"
#include"DrawAndColor.h"
#include <sstream>

void swap(string& s1, string& s2);

//----------------StringSort----------------------
void bubbleSort(string a[], int n);

void insertionSort(string a[], int n);

void selectionSort(string a[], int n);

int chiaDeTri(string a[], int low, int high);
void quickSort(string arr[], int low, int high);

//-----------------SupportStringSort------------------

string XuLyChuoi(string a);

//------------------Sorting-------------------------
void sortByName(char* file_name, int type);
void sortByDate(char* file_name, int type);
void sortByCode(char* file_name, int type);
void sortByClass(char* file_name, int type);
void sortByScore(char* file_name, int type);

#endif