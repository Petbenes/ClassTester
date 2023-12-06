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

	// test zda se vše otevøe
	if (p_mchFileNameSource == NULL || p_mchFileNameDest == NULL)
	{
		// zavøít soubory
		CloseFile();
		return false;
	}

	return true;
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
	unsigned char lchBuffer;
	int lintCount;
	
	// test zda je soubor otevøen
	if (p_mFileSource == NULL || p_mFileDest == NULL)
	{
		return false;
	}

	do
	{ 
		// ètení jednoho byte ze souboru
		lintCount = fread_s(&lchBuffer, 1, 1, 1, p_mFileSource);

		// jsem na konci souboru
		if (lintCount == 0) break;

		// šifrování
		lchBuffer = lchBuffer + Crypter;

		// zápis jednoho byte ze souboru
		fwrite(&lchBuffer, 1, 1, p_mFileDest);
	} while (lchBuffer != EOF); // EOF - End Of File
	

	return false;
}

bool clsCrypto::Decrypt()
{
	unsigned char lchBuffer;
	int lintCount;

	// test zda je soubor otevøen
	if (p_mFileSource == NULL || p_mFileDest == NULL)
	{
		return false;
	}

	do
	{
		// ètení jednoho byte ze souboru
		lintCount = fread_s(&lchBuffer, 1, 1, 1, p_mFileSource);

		// jsem na konci souboru
		if (lintCount == 0) break;

		// šifrování
		lchBuffer = lchBuffer - Crypter;

		// zápis jednoho byte ze souboru
		fwrite(&lchBuffer, 1, 1, p_mFileDest);
	} while (lchBuffer != EOF); // EOF - End Of File


	return false;
}