#pragma once
#include<iostream>
#include<fstream>
#include <ctime>

class Graf
{
private:
	int **arr;
	int row;
public:
	Graf(std::istream&, int);
	Graf AlgoritmFY();
	void Print();
	~Graf(void);
	Graf(const Graf& other); 
	friend std::ostream& operator<<(std::ostream& os, Graf& other);

};

