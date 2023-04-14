#ifndef MERC_HOURGLASS__H
#define MERC_HOURGLASS__H

#ifdef _WIN32
#pragma once
#endif

#include "items.h"

enum EMercHourglassTypes
{
	HOURGLASS_SMALL,
	HOURGLASS_LARGE,
	HOURGLASS_CUTSCENE
};

class CMercHourglass : public CItem
{
public:
	DECLARE_CLASS(CMercHourglass, CItem);

	void Spawn(void);
	void Precache(void);
	bool MyTouch(CBasePlayer *pPlayer);

	void InputSetHourglassType(inputdata_t &inputdata);


	float GetItemAmount(void);

	void SetHourglassType(EMercHourglassTypes type) { m_type = type; }

	DECLARE_DATADESC();
private:
	EMercHourglassTypes m_type;
};

#endif