#include "clsCryptoEx.h"

clsCryptoEx::clsCryptoEx()
{

}

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

	// otev¯enÌ souboru
	hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	// pamÏùovÈ mapov·nÌ
	hFileMapping=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

	// namapov·nÌ pohledu do souboru
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);



	return false;
}

bool clsCryptoEx::CloseFile()
{
	// uloûenÌ zmÏn
	FlushViewOfFile(p_mSourceFirstByte, 0);
	
	// odmapov·nÌ
	UnmapViewOfFile(p_mSourceFirstByte);

	// uzav¯enÌ handles
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	
	return false;
}

bool clsCryptoEx::Crypt()
{
	
	return false;
}

bool clsCryptoEx::Decrypt()
{
	return false;
}
