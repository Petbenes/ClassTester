#pragma once
#include <string.h>
#include "stdio.h"
class clsCrypto
{
public:
	clsCrypto();						// konstruktor
	bool OpenFile(const char* p_chName);		// otev��t soubor
	bool CloseFile();					// zav�e soubor

private:
	char* p_mchFileName; // n�zev souboru
	FILE* p_mFile;
};

