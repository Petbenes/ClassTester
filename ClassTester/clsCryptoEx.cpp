#include "clsCryptoEx.h"

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

    // otevøení souboru
    hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    // pamì?ové mapování
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

bool clsCryptoEx::Crypt()
{
    // posunutí
    int shift = 3;

    // získání velikosti souboru
    GetFileSizeEx(hFile, &pintFileSize);

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // zašifrování textu pomocí Caesarovy šifry s danım posunutím
    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // pøesun písmena o danı poèet míst
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + shift);
    }

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // zapsání souboru
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

    return true;
}

bool clsCryptoEx::Decrypt()
{
    // posunutí
    int shift = 3;

    // získání velikosti souboru
    GetFileSizeEx(hFile, &pintFileSize);

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // dešifrování textu pomocí Caesarovy šifry s danım posunutím
    for (int i = 0; p_mSourceFirstByte[i] != 0; i++)
    {
        // posun písmena zpìt o danı poèet míst
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - shift);
    }

    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // zapsání souboru
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

    return true;
}
