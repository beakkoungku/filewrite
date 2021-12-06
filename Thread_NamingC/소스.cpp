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
#include <fstream>

using namespace std;


std::string Function()
{
	//other project logic
	char curDir[1000];
	_getcwd(curDir, 1000);
	std::string strDir(curDir);


	std::string find_str = "\\";
	int count = 0;
	for (int i = 0; i < strDir.length(); i++) {
		if (strDir.find(find_str) == -1) {
			break;
		}
		else if (strDir.find(find_str, i) <= i) {
			count += 1;
		}
	}
	size_t pos = 0, ncount = 0;
	std::string token;
	while ((pos = strDir.find(find_str)) != std::string::npos) {
		if (ncount < count)
			token += strDir.substr(0, pos) + "\\";
		strDir.erase(0, pos + find_str.length());
		ncount += 1;
	}
	token += "Release\\Thread_NamingC";
	return token;
}
int main()
{
	string filePath = Function() + ".txt";

	// write File
	ofstream writeFile(filePath.data());
	if (writeFile.is_open()) {
		writeFile << "Hello World!\n";
		writeFile << "This is C++ File Contents.\n";
		writeFile.close();
	}
	return 0;
}