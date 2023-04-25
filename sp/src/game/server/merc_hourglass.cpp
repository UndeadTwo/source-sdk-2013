
#include "cbase.h"
#include "gamerules.h"

#include "player.h"
#include "hl2_player.h"

#include "in_buttons.h"
#include "hl2_gamerules.h"
#include "engine/IEngineSound.h"

#include "merc_hourglass.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

ConVar sk_merc_hourglass_small("sk_merc_hourglass_small", "0"); 
ConVar sk_merc_hourglass_large("sk_merc_hourglass_large", "0"); 
ConVar sk_merc_hourglass_cutscene("sk_merc_hourglass_cutscene", "0");

LINK_ENTITY_TO_CLASS(item_merc_hourglass, CMercHourglass);
PRECACHE_REGISTER(item_merc_hourglass);

BEGIN_DATADESC(CMercHourglass)

DEFINE_KEYFIELD(m_type, FIELD_INTEGER, "HourglassType"),
DEFINE_INPUTFUNC(FIELD_INTEGER, "SetHourglassType", InputSetHourglassType),

END_DATADESC()

void CMercHourglass::Spawn(void)
{
	Precache();
	SetModel("models/items/hourglass.mdl");
	
	BaseClass::Spawn();
}

void CMercHourglass::Precache(void)
{
	PrecacheModel("models/items/hourglass.mdl");

	PrecacheScriptSound("HealthKit.Touch");
}

bool CMercHourglass::MyTouch(CBasePlayer *pPlayer)
{
	ConMsg("Merc Hourglass was worth %u seconds \n", GetItemAmount());

	CHalfLife2* pGamerules = HL2GameRules();
	pGamerules->AddTimerDuration(Floor2Int(GetItemAmount()));
	
	CPASAttenuationFilter filter(pPlayer, "HealthKit.Touch");
	EmitSound(filter, pPlayer->entindex(), "HealthKit.Touch");

	UTIL_Remove(this);

	return true;
}

//void CMercHourglass::

float CMercHourglass::GetItemAmount(void)
{
	int returnValue = 0;

	switch (m_type)
	{
	case HOURGLASS_CUTSCENE:
	{
		returnValue = sk_merc_hourglass_cutscene.GetInt();
		break;
	}
	case HOURGLASS_LARGE:
	{
		returnValue = sk_merc_hourglass_large.GetInt();
		break;
	}
	default:
	{
		returnValue = sk_merc_hourglass_small.GetInt();
		break;
	}
	}

	return (float)returnValue;
}

void CMercHourglass::InputSetHourglassType(inputdata_t &inputdata)
{
	m_type = (EMercHourglassTypes)inputdata.value.Int();
}