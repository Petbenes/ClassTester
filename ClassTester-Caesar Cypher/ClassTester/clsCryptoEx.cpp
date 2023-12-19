#include "clsCryptoEx.h"

bool clsCryptoEx::Crypt(int shift) 
{
    // �ifrov�n� textu pomoc� Caesarovy �ifry s dan�m posunut�m

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // P�esun p�smena o dan� po�et m�st v abeced�
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + shift) % 256; // Omezen� na rozsah 0-255
    }

    return true;
}

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

    // otev�en� souboru
    hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    // pam�ov� mapov�n�
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

bool clsCryptoEx::Decrypt(int shift) {

    // De�ifrov�n� textu pomoc� Caesarovy �ifry s dan�m posunut�m

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++) 
    {
        // P�esun p�smena o dan� po�et m�st v abeced� (opa�n� sm�r ne� p�i �ifrov�n�)
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - shift + 256) % 256; // Omezen� na rozsah 0-255
    }

    return true;
}
