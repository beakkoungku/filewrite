#pragma once

#include "IncludeDef.h"

class Lancher
{
public:
	/*
	Major Flow Fucntion Code
	*/
	Lancher();	
	void TheradManager();
	void DebugLog(std::string _logstring, WriteEnum::_WriteLogEnum _enumvalues = WriteEnum::_WriteLogEnum::Default);
	void Initialize();
	void Run() {
		std::vector<std::thread>threads;

			threads.emplace_back(std::thread(&Lancher::Minor_Second_Init_SetTimeStemp, this));
			threads.emplace_back(std::thread(&Lancher::TheradManager,this));

		for (auto& thread : threads)
			thread.join();
	}
	

private:
	/*
	Minor Naming Function
	*/
	void SetTimeStting();
	void WriteInitLog(bool _start);
	void Minor_Second_FunctionLog(bool _start);
	void Minor_Second_Init_SetTimeStting();
	void Minor_Second_Init_SetTimeStemp();
	
private:
	//time
	struct tm* m_st_tm_Timeinfo;
	vector<thread> m_v_TheradManager;
	DWORD m_dw_Tickckount;

};
