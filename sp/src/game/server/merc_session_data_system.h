#ifndef MERC_SESSION_DATA_SYSTEM
#define MERC_SESSION_DATA_SYSTEM

#include "igamesystem.h"

class CSessionDataSystem : public CAutoGameSystem
{
	typedef CAutoGameSystem BaseClass;
public:
	CSessionDataSystem();

	void LevelInitPostEntity() override;
	void LevelShutdownPreEntity() override;

private:
	char const *m_pszName;

	float m_timer_elapsed;
	float m_previous_curtime;
	int m_timer_duration;
	int m_timer_additional_time;
};

CSessionDataSystem g_SessionDataSystem;

#endif