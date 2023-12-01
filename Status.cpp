#include "Status.h"

string StatusToString(Status status)
{
	string strStatus;

	switch (status)
	{
	case create:
		strStatus = "создан";
		break;
	case working:
		strStatus = "в сборке";
		break;
	case finished:
		strStatus = "готов к выдаче";
		break;
	default:
		break;
	}
	return strStatus;
}