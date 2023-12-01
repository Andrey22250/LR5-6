#pragma once
#include <iostream>
#include <string>
#include "PC.h"
#include "Status.h"

class Build
{
public:
	Build();
	Build(string client);
	Build(PC pc, string client, Status status);
	~Build();

	bool CheckCor(PC pc, string client, Status status);

	static int GetNumBuild();
	PC GetPC();
	string GetClient();
	Status GetStatus();
	void input_build();
	void out_build();
	void ChangeStatus(Status newstatus);
	void SetPC(PC pc);
	void SetBuild(PC pc, string client, Status status);
private:
	static int numberBuild;
	int number;
	PC pc;
	string client;
	Status status;
};