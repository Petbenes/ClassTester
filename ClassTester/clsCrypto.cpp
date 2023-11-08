#include "clsCrypto.h"

// konstruktor
clsCrypto::clsCrypto()
{
	// nastavit, že soubor není otevøen
	p_mFileSource = NULL;
	p_mFileDest = NULL;
}

// otevøe soubor
bool clsCrypto::OpenFile(const char* p_chNameSource, const char* p_chNameDest)
{
	int lintLen;

	// kopie názvu souboru
	lintLen = strnlen_s(p_chNameSource, 1024);
	p_mchFileNameSource = new char[lintLen+1];
	strcpy_s(p_mchFileNameSource,lintLen+1, p_chNameSource);

	// otevøení souboru
	fopen_s(&p_mFileSource, p_mchFileNameSource, "r");
	
	// kopie názvu souboru
	lintLen = strnlen_s(p_chNameDest, 1024);
	p_mchFileNameDest = new char[lintLen + 1];
	strcpy_s(p_mchFileNameDest, lintLen + 1, p_chNameDest);

	// otevøení souboru
	fopen_s(&p_mFileDest, p_mchFileNameDest, "w");

	// !!! tady dodìlat test zda je otevøeno

	return false;
}

// zavøe soubor
bool clsCrypto::CloseFile()
{
	if (p_mFileSource != NULL)
	{
		fclose(p_mFileSource);
		p_mFileSource = NULL;
	}

	if (p_mFileDest != NULL)
	{
		fclose(p_mFileDest);
		p_mFileDest = NULL;
	}

	if (p_mFileSource == NULL && p_mFileDest == NULL)
	{
		return true;
	}

	return false;
}

// šifrování souboru

bool clsCrypto::Crypt()
{
	// test zda je soubor otevøen
	if (p_mFileSource == NULL || p_mFileDest == NULL)
	{
		return false;
	}



	return false;
}