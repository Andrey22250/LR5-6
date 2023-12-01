#pragma once
#include <string>

using namespace std;

enum Status { create, working, finished };

string StatusToString(Status status);