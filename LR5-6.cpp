#include <iostream>
#include <Windows.h>
#include "Build.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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
			boxOfCPUs[i][j].input_cpu();
	cout << boxOfCPUs[0][1] << endl << endl;

	//6-ая лабораторная
	//1. Пример работы с базовыми и производными классами, а также с виртуальными методами
	HDD hdd = HDD();
	SSD ssd = SSD();
	DataStorage* storage;
	storage = &hdd;
	std::cout << storage->getComponentName() << std::endl;
	storage = &ssd;
	std::cout << storage->getComponentName() << std::endl;
	storage = new SSD(DataTransferInterface::NVME);
	std::cout << storage->toString() << std::endl;
	delete storage;

	//2. Перегрузка операторов = и <<
	Display display1 = Display(1920, 1080, 60);
	Display display2 = display1;
	std::cout << display1 << std::endl << display2 << std::endl;

	//3. Пример работы с шаблонным классом
	std::string t = "Client is annoying";
	Order order = Order(Laptop(), StatusType::FINISHED, t); //например, сообщение о клиенте
	std::cout << order << std::endl;
	Order<int> order2 = Order<int>(Laptop(), StatusType::FINISHED, 9999); //например, цена покупки
	std::cout << order2 << std::endl;
}