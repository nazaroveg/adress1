// address.cpp :
//nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

class adress
{
public:
	
	void fread(std::ifstream& fin)
	{
		fin >> city;
		fin >> street;
		fin >> house_number;
		fin >> apartment;
	}
	void write(std::ofstream& fout)
	{
		fout << city << ", " << street << ", " << house_number << ", " << apartment << std::endl;
	}



private:
	std::string city;
	std::string street;
	int house_number;
	int apartment;


};







int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	adress adr;
	
	std::ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open()) {
		std::cout << "Error: unable to open file " << "in.txt" << " for writing" << '\n';
		return -1;
	}
	int count = 0;
	fin >> count;
	if (count <= 0)
	{
		std::cout << "Ошибка: недопустимый размер  " << count << '\n';
		return -2;
	}
	std::ofstream fout;
	fout.open("out.txt");
	if (!fin.is_open()) {
		std::cout << "Error: unable to open file " << "out.txt" << " for writing" << '\n';
		return -3;
	}
	fout << count << std::endl;
	
	
	for (int i = 0; i < count; ++i)
	{
		adr.fread(fin);
		adr.write(fout);
	}
	fin.close();
	fout.close();




}

