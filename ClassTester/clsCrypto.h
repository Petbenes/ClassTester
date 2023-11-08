#pragma once
#include <string.h>
#include "stdio.h"
class clsCrypto
{
public:
	clsCrypto();						// konstruktor
	bool OpenFile(const char* p_chName);		// otevøít soubor
	bool CloseFile();					// zavøe soubor

private:
	char* p_mchFileName; // název souboru
	FILE* p_mFile;
};

