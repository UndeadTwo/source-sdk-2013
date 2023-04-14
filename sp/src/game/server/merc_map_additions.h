#ifndef MERC_MAP_ADDITIONS__H
#define MERC_MAP_ADDITIONS__H

#include "cbase.h"

class CMapAdditions
{
public:
	CMapAdditions();
	~CMapAdditions();

	bool LoadFromFile(char* filename);
	void LoadFromBuffer(CUtlBuffer buffer);

private:
	DECLARE_CLASS_NOBASE(CMapAdditions);
};


bool CMapAdditions::LoadFromFile(char* filename)
{
	CUtlBuffer buffer;

	if (!filesystem->ReadFile(filename, "GAME", buffer))
	{
		return false;
	}

	LoadFromBuffer(buffer);
	return true;
}

void CMapAdditions::LoadFromBuffer(CUtlBuffer buffer)
{

}

#endif