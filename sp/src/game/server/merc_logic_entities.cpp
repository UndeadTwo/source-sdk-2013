#include "cbase.h"

#include "merc_logic_entities.h"
#include "hl2_gamerules.h"

#include "tier0/memdbgon.h"

void CMercLogicTimer::InputSetPauseTimer(inputdata_t &inputdata)
{
	HL2GameRules()->SetTimerPaused(inputdata.value.Bool());
}

void CMercLogicTimer::InputTogglePauseTimer(inputdata_t &inputdata)
{
	HL2GameRules()->SetTimerPaused(!HL2GameRules()->IsTimerPaused());
}