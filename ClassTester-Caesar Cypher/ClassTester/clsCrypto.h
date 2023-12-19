#pragma once
#include <string.h>
#include "stdio.h"
#include "clsProtoCrypto.h";
#define Crypter -10

class clsCrypto: public clsProtoCrypto // tøída clsCrypto dìdí funkce z tøídy clsProtoCrypto
{
public:
	clsCrypto();						// konstruktor
	bool OpenFile(const char* p_chNameSource, const char* p_chNameDest);		// otevøít soubor
	bool CloseFile();					// zavøe soubor
	bool Crypt();						// šifruje
	bool Decrypt();						// dešifruje

private:
	char* p_mchFileNameSource; // název souboru odkud
	FILE* p_mFileSource;
	char* p_mchFileNameDest; // název souboru cíle
	FILE* p_mFileDest;
};


