#pragma once

class clsProtoCrypto // abstraktní tøída - nelze z ní udìlat instanci
{
public:
	clsProtoCrypto() {};						// konstruktor // u abstraktního konstruktoru nelze napsat =0
	bool OpenFile(const char* p_chNameSource, const char* p_chNameDest) { return false;  };	// =0, ukazuje abstraktní tøídu - není to reálný objekt
	virtual bool CloseFile() = 0;					// zavøe soubor
	virtual bool Crypt() = 0;						// šifruje
	virtual bool Decrypt() = 0;						// dešifruje
};