#include<iostream>
#include<fstream>
#include "Graf.h"

using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	int row;
	ifstream fin;
	fin.open("Matrix.txt");
	fin >> row;
	try{
		Graf matrix(fin, row);
		if(row==1)
		{
			cout << "Кратчайшего пути нет, т.к. имеется всего одна точка!" << endl;
			return 0;
		}
		cout << "Матрица путей: " << matrix << "Матрица кратчайших путей: " << matrix.AlgoritmFY();
		(matrix.AlgoritmFY()).Print();
	}catch(const char* massage)
	{
		cout << "Error: " << massage << endl;
	}
	//++++++++++++++++++++++++++++++++++++
	unsigned int one = clock()/1000.0;
	for(int i =0; i< 50000; i++)
	{
		int pr = i;
		if(pr == 45000)
			break;
	}
	unsigned int one_2 = clock()/1000.0;
	unsigned int f_1 = one_2 - one;
	unsigned int one_1 = clock()/1000.0;
	for(int i =0; i< 50000; i++)
	{
		int *pr = &i;
		if(*pr == 45000)
			break;
	}
	unsigned int one_3 = clock()/1000.0;
	unsigned int f_2 = one_3 - one_1;
	cout << "Второе время: " << f_2 << endl;
	cout << "Первое время: " << f_1 << endl;
}