#include "cbase.h"
#include "merc_session_data_system.h"
#include "hl2_gamerules.h"

CSessionDataSystem::CSessionDataSystem() : BaseClass("CSessionDataSystem")
{
	
}

void CSessionDataSystem::LevelInitPostEntity()
{
	ConMsg("Level setup - after entities... \n");

	if (gpGlobals->eLoadType == MapLoad_Transition)
	{
		CHalfLife2* pGamerules = HL2GameRules();

		if ( pGamerules != NULL )
		{
			pGamerules->SetTimerElapsed(m_timer_elapsed);
			pGamerules->SetTimerDuration(m_timer_duration);
			pGamerules->SetTimerAdditionalTime(m_timer_additional_time);
		}
	}
}

void CSessionDataSystem::LevelShutdownPreEntity()
{
	ConMsg("Level teardown - pre entities... \n");

	CHalfLife2* pGamerules = HL2GameRules();

	if (pGamerules != NULL)
	{
		m_timer_elapsed = pGamerules->GetTimerElapsed();
		m_timer_duration = pGamerules->GetTimerDuration();
		m_timer_additional_time = pGamerules->GetAdditionalTime();
	}
}