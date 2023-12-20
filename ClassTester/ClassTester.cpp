#include <iostream>
#include "clsCrypto.h"
#include "clsCryptoEx.h"

int main()
{
    clsCryptoEx* p_lobjCryptoEx;

        // vytvořit objekt
        p_lobjCryptoEx = new clsCryptoEx();

        // otevřít soubor
        p_lobjCryptoEx->OpenFile(L"c:\\Temp\\test.txt", L"c:\\Temp\\testcrypt.txt");

        // zašifrovat
        p_lobjCryptoEx->Crypt();

        // zavřít soubor
        p_lobjCryptoEx->CloseFile();

        // otevřít soubor
        p_lobjCryptoEx->OpenFile(L"c:\\temp\\testcrypt.txt", L"c:\\temp\\testdecrypt.txt");

        // odšifrovat
        p_lobjCryptoEx->Decrypt();

        // zavřít soubor
        p_lobjCryptoEx->CloseFile();

        // zrušit objekt
        delete(p_lobjCryptoEx);
}
