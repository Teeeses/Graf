#include "Graf.h"
#include<iostream>
#include<fstream>

Graf:: Graf(std::istream& file, int row)
{
	if(!file)
	{
		throw "Файл не найден или не заполнен!";
	}
	this->row=row;
	arr=new int*[row];
	for(int i=0; i<row; i++)
		arr[i]=new int[row];
	for(int i=0; i<row; i++)
	{
		for(int j=0; j< row; j++)
		{
				file >> arr[i][j];
				if(!file || arr[i][j]<0)
				{
					throw "Неверно заданы данные!";
				}
		}
	}
	for(int i=0; i<row; i++)
	{
	if(arr[i][i]!=0)
		throw "Все элементы главной диагонали должны иметь значение 0!";
	}
}

void Graf:: Print()
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<row; j++)
		{
			if(i!=j)
			{
				std::cout << "Кратчайший путь из вершины " << i+1 << " в вершину " << j+1 << " : ";
				if(arr[i][j]!=0)
					std::cout << arr[i][j] << std::endl;
				else
					std:: cout << "пути нет!" << std::endl;
			}
		}
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, Graf& other)
{
	os << std::endl << std:: endl;
	for(int i=0; i<other.row; i++)
	{
		for(int j=0; j<other.row; j++)
		{
			os << " " << other.arr[i][j] << " ";	
		}
		os << std::endl;
	}
	os << std::endl;
	return os;
}

Graf::Graf(const Graf& other) 
{
	row = other.row;
	arr=new int*[other.row];
	for(int i=0; i< other.row; i++)
		arr[i]=new int[other.row];
	for(int i=0; i<other.row; i++)
		for(int j=0; j<other.row; j++)
			arr[i][j]=other.arr[i][j];
}

Graf Graf::AlgoritmFY()

{
	Graf ArrEnd(*this);
	for(int k=0; k<row; k++)
		for(int i=0; i<row; i++)
			for(int j=0; j<row; j++)
				if(ArrEnd.arr[i][k] && ArrEnd.arr[k][j] && i!=j)
					if(ArrEnd.arr[i][k]+ArrEnd.arr[k][j]<ArrEnd.arr[i][j] || ArrEnd.arr[i][j]==0)
						ArrEnd.arr[i][j]=ArrEnd.arr[i][k]+ArrEnd.arr[k][j];
			
					
	return ArrEnd;
}

Graf::~Graf(void)
{
	for(int i=0; i<row; i++)
		delete arr[i];
	delete arr;
}

