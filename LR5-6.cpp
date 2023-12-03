#include <iostream>
#include <Windows.h>
#include "Build.h"

using namespace std;

int main()
{

	//5-ая лабораторная
	//1. Пример работы с исключениями
	try
	{
		CPU ex = CPU("i5 9600k", 3400, 6, -12); //пробуем создать процессор с отрицательным числом ядер
	}
	catch (const invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}

	//2. Пример работы с одномерными и двумерными массивами
	PC pcs[3];
	for (int i = 0; i < 3; i++)
	{
		pcs[i] = PC();
		pcs[i].Out_PC();
	}
	CPU boxOfCPUs[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			try { boxOfCPUs[i][j].input_cpu(); }
			catch (const invalid_argument& boxOfCPUs)
			{
				cout << boxOfCPUs.what() << endl;
			}
		}
	cout << boxOfCPUs[0][1] << endl << endl;

	//6-ая лабораторная
	//1. Пример работы с базовыми и производными классами, а также с виртуальными методами
	HDD hdd = HDD();
	SSD ssd = SSD();
	DataStor* storage;
	storage = &hdd;
	std::cout << storage->getCompName() << std::endl;
	storage = &ssd;
	std::cout << storage->getCompName() << std::endl;
	storage = new SSD(7000, "NVME", "ssd", 2);
	std::cout << storage->getCompName() << std::endl;
	delete storage;

	//2. Перегрузка операторов = и <<
	CPU cpu = CPU("Ryzen 3 1200", 3100, 4, 4);
	CPU cpu1 = cpu;
	cout << cpu << endl << cpu1 << endl;
	
	//3. Пример работы с шаблонным классом
	string t = "Client is annoying";
	Build build = Build(PC(), "Андрей", working, t); //например, сообщение о клиенте
	cout << build << endl;
	Build build2 = Build<int>(PC(), "Андрей", working, 30); //например, время ожидания в часах
	cout << build2 << endl ;
}