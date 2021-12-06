#pragma once

//include 
#include <Windows.h>
#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <stdlib.h>
#include <filesystem>
#include <direct.h>

//namespace
using namespace std;
using std::thread;


namespace WriteEnum {
	enum class _WriteLogEnum {
		Lancher_Init = 0,
		Lancher_SetTime,
		Default = 999
	};
}

//pragma warning
#pragma warning(disable:4996)

//defint
#define DEBUGLOG
#define mTrue 1
#define mFalse 0
#define MIN 1000