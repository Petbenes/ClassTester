#include "clsCryptoEx.h"

bool clsCryptoEx::Crypt(int shift) 
{
    // Šifrování textu pomocí Caesarovy šifry s danım posunutím

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // Pøesun písmena o danı poèet míst v abecedì
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + shift) % 256; // Omezení na rozsah 0-255
    }

    return true;
}

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

    // otevøení souboru
    hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    // pamìové mapování
    hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

    // namapování pohledu do souboru
    p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);

    return false;
}

bool clsCryptoEx::CloseFile()
{
    // uloení zmìn
    FlushViewOfFile(p_mSourceFirstByte, 0);

    // odmapování
    UnmapViewOfFile(p_mSourceFirstByte);

    // uzavøení handles
    CloseHandle(hFileMapping);
    CloseHandle(hFile);

    return false;
}

bool clsCryptoEx::Decrypt(int shift) {

    // Dešifrování textu pomocí Caesarovy šifry s danım posunutím

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++) 
    {
        // Pøesun písmena o danı poèet míst v abecedì (opaènı smìr ne pøi šifrování)
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - shift + 256) % 256; // Omezení na rozsah 0-255
    }

    return true;
}
