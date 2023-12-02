#include "Build.h"

inline void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

Build::Build()
{
	this->number = numberBuild++;
	pc = PC();
	status = create;
}

Build::Build(string client)
{
	this->number = numberBuild++;
	pc = PC();
	status = create;
}

Build::Build(PC pc, string client, Status status)
{
	if (CheckCor(pc, client, status))
	{
		this->number = numberBuild++;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}

Build::~Build()
{
}

bool Build::CheckCor(PC pc, string client, Status status)
{
	if (size(client) != 0 && (status >= create && status <= finished))
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

int Build::GetNumBuild()
{
	return numberBuild;
}

PC Build::GetPC()
{
	return pc;
}

string Build::GetClient()
{
	return client;
}

Status Build::GetStatus()
{
	return status;
}

void Build::input_build()
{
	string client;
	printf("Ввод данных заказа\n\n");
	printf("Введите имя клиента: ");
	getline(cin, client);
	Status status;
	do
	{
		printf("Введите статус заказа, где\n0 - Заказ создан\n1 - Заказ в работе\n2 - Заказ выполнен\nВаш выбор: ");
		scanf("%d", &status);
		clean();
	} while (status < 0 && status > 2);
	pc.input_pc();
	SetBuild(pc, client, status);
}

void Build::out_build()
{
	printf("\nИнформация о заказе:\n\n");
	printf("Номер заказа: %d\n", GetNumBuild());
	printf("Клиент - %s\n", GetClient().c_str());
	printf("Статус - %s\n", StatusToString(GetStatus()).c_str());
	pc.Out_PC();
}

void Build::ChangeStatus(Status newstatus)
{
	if (newstatus >= create && newstatus <= finished) {
		this->status = newstatus;
		printf("Состояние заказа успешно изменено!\n");
	}
	else {
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

void Build::SetPC(PC pc)
{
	this->pc = pc;
}

void Build::SetBuild(PC pc, string client, Status status)
{
	if (CheckCor(pc, client, status))
	{
		this->number = numberBuild;
		this->pc = pc;
		this->client = client;
		this->status = status;
	}
}

int Build::numberBuild = 0;