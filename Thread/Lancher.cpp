#include "Lancher.h"

/*
Major Function
Lancher create
*/
Lancher::Lancher()
{
	Initialize();
}
//초기화
void Lancher::Initialize() {
	SetTimeStting();
	WriteInitLog(mTrue);
	WriteInitLog(mFalse);
}

/*
Major Function
Thread Manager
*/
//therad 선언
void Lancher::TheradManager()
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
	size_t pos = 0,ncount = 0;
	std::string token;
	while ((pos = strDir.find(find_str)) != std::string::npos) {
		if(ncount < count)
			token += strDir.substr(0, pos) + "\\";
		strDir.erase(0, pos + find_str.length());
		ncount += 1;
	}
	std::string tokenA = token + "Release\\Thread_NamingA.exe";
	std::string tokenB = token + "Release\\Thread_NamingB.exe";
	std::string tokenC = token + "Release\\Thread_NamingC.exe";
	std::string tokenD = token + "Release\\Thread_NamingD.exe";
	std::string tokenE = token + "Release\\Thread_NamingE.exe";
	
	int a =0, b=0, c=0, d=0, e=0;
	for (int uu = 0; uu < 4; uu++)
	{
		a += system(tokenA.c_str());
		b += system(tokenB.c_str());
		c += system(tokenC.c_str());
		d += system(tokenD.c_str());
		
	}
	e = a + b + c + d;

	if (e == 0)
	{
		system(tokenE.c_str());
	}
	else
	{
		
	}
}

/*
Major Function
Write DebugLog
*/
void Lancher::DebugLog(std::string _logstring, WriteEnum::_WriteLogEnum _enumvalues)
{
#ifdef DEBUGLOG
	switch (_enumvalues)
	{
	case WriteEnum::_WriteLogEnum::Lancher_Init:
		cout << "Lancher_Init ";
		break;
	case WriteEnum::_WriteLogEnum::Lancher_SetTime:
		cout << "Lancher_SettimeStting ";
		break;

	case WriteEnum::_WriteLogEnum::Default:
	default:
		cout << "Not Convert Enum Values ";
		break;
	}
	cout << _logstring << " " << asctime(m_st_tm_Timeinfo);
#endif
}




/*
Minor First Function
*/

void Lancher::SetTimeStting() {
	Minor_Second_Init_SetTimeStting();

}

void Lancher::WriteInitLog(bool _start)
{
	Minor_Second_FunctionLog(_start);
}

/*
Minor Second Function
*/

void Lancher::Minor_Second_FunctionLog(bool _start)
{
	if (_start)
	{
		DebugLog("##################",	WriteEnum::_WriteLogEnum::Lancher_Init);
		DebugLog("Lancher INIT",		WriteEnum::_WriteLogEnum::Lancher_Init);
		DebugLog("##################",	WriteEnum::_WriteLogEnum::Lancher_Init);
	}
	else
	{
		DebugLog("##################",	WriteEnum::_WriteLogEnum::Lancher_Init);
		DebugLog("Lancher INIT End",	WriteEnum::_WriteLogEnum::Lancher_Init);
		DebugLog("##################",	WriteEnum::_WriteLogEnum::Lancher_Init);
	}
}

void Lancher::Minor_Second_Init_SetTimeStting()
{
	srand(32323);
	const time_t t = time(NULL);
	m_st_tm_Timeinfo = localtime(&t);
	DebugLog("Minor_Second_Init_SetTimeStting Start", WriteEnum::_WriteLogEnum::Lancher_SetTime);

	m_dw_Tickckount = GetTickCount64();
	DebugLog("Minor_Second_Init_SetTimeStting End", WriteEnum::_WriteLogEnum::Lancher_SetTime);
}

void Lancher::Minor_Second_Init_SetTimeStemp() {
	while (mTrue) {
		const time_t t = time(NULL); 
		m_st_tm_Timeinfo = localtime(&t);
		DWORD currentTickCount = GetTickCount64();
		if (currentTickCount - m_dw_Tickckount >= MIN)
		{
			m_dw_Tickckount = currentTickCount;
			DebugLog("Minor_Second_Init_SetTimeStemp", WriteEnum::_WriteLogEnum::Lancher_SetTime);
		}
	}
	
}