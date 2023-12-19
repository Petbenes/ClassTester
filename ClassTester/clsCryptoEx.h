#pragma once
#include "clsProtoCrypto.h"
#include <Windows.h>

class clsCryptoEx : public clsProtoCrypto
{
public:
	clsCryptoEx();
	bool OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest);	
	virtual bool CloseFile();					
	virtual bool Crypt();						
	virtual bool Decrypt();
private:
	PBYTE p_mSourceFirstByte;
	HANDLE hFile, hFileMapping;
	LARGE_INTEGER pintFileSize;
	DWORD dwBytesWritten;
};
