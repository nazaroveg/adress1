// address.cpp :
//nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>



class address
{
public:
	address() { city, street, house, apartment; }

	std::string get_output_address(std::string ci, std::string st, int hou, int apart)
	{
		std::string a = std::to_string(hou);
		std::string b = std::to_string(apart);
		std::string out_add = (ci + ", " + st + ", " + a + ", " + b);
		return out_add;
	}


private:
	std::string city = { 0 }, street = { 0 };
	int house = 0; int apartment = 0;
};




int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);

	std::ifstream fin;
	fin.open("in.txt");
	if (!fin.is_open()) {
		std::cout << "Error: файл не открыт " << "in.txt" << '\n';
		return -1;
	}
	int size = 0;
	fin >> size;
	if (size <= 0)
	{
		std::cout << "Ошибка: недопустимый размер  " << size << '\n';
		return -2;
	}


	address* add = new address[size];

	std::string a;
	std::string b;
	int c;
	int d;
	std::string* result = new std::string[size];

	for (int i = 0; i < size; ++i)
	{

		fin >> a;
		fin >> b;
		fin >> c;
		fin >> d;

		result[i] = add[i].get_output_address(a, b, c, d);
	}

	fin.close();
	

	std::ofstream fout;
	fout.open("out.txt");
	if (!fout.is_open()) {
		std::cout << "Error: unable to open file " << "out.txt" << " for writing" << '\n';
		return -3;
	}
	fout << size << std::endl;

	for (int i = size-1; i >= 0; --i)
	{
		fout << result[i] << std::endl;;


	}
	fout.close();
	delete[] add;
	delete[] result;
}
