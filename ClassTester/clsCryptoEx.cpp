#include "clsCryptoEx.h"

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

    // otev�en� souboru
    hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    // pam�?ov� mapov�n�
    hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

    // namapov�n� pohledu do souboru
    p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);

    return false;
}

bool clsCryptoEx::CloseFile()
{
    // ulo�en� zm�n
    FlushViewOfFile(p_mSourceFirstByte, 0);

    // odmapov�n�
    UnmapViewOfFile(p_mSourceFirstByte);

    // uzav�en� handles
    CloseHandle(hFileMapping);
    CloseHandle(hFile);

    return false;
}

bool clsCryptoEx::Crypt()
{
    // posunut�
    int shift = 3;

    // z�sk�n� velikosti souboru
    GetFileSizeEx(hFile, &pintFileSize);

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // za�ifrov�n� textu pomoc� Caesarovy �ifry s dan�m posunut�m
    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // p�esun p�smena o dan� po�et m�st
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + shift);
    }

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // zaps�n� souboru
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

    return true;
}

bool clsCryptoEx::Decrypt()
{
    // posunut�
    int shift = 3;

    // z�sk�n� velikosti souboru
    GetFileSizeEx(hFile, &pintFileSize);

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // de�ifrov�n� textu pomoc� Caesarovy �ifry s dan�m posunut�m
    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // posun p�smena zp�t o dan� po�et m�st
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - shift);
    }

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // zaps�n� souboru
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

    return true;
}
