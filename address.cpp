// address.cpp :
//nazaroveg@yandex.ru

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>



class address
{
public:
	address(std::string, std::string, int, int)  { city, street, house, apartment; }        //сюда только,  точное кол-во аргументов и точный тип.*
	address(){}																				//конструктор по умолчанию сюда можено передавать объекты класса.любые. при оъявлении в main+-
	std::string get_output_address(std::string ci, std::string st, int hou, int apart)     //* как пот здесь
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


	address* add = new address[size];  //создаем динамический массив класса

	std::string a;
	std::string b;
	int c;
	int d;
	std::string* result = new std::string[size];   //создаем динам массив string

	for (int i = 0; i < size; ++i)
	{

		fin >> a;                      //читаем данные и переводим из " c И d" в string
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
