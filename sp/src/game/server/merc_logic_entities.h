#include "cbase.h"
#include "hl2_gamerules.h"

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class CMercLogicTimer : public CLogicalEntity
{
	DECLARE_CLASS(CMercLogicTimer, CLogicalEntity);

	void InputSetPauseTimer(inputdata_t &inputdata); 
	void InputTogglePauseTimer(inputdata_t &inputdata);

	DECLARE_DATADESC();
};

LINK_ENTITY_TO_CLASS(logic_merc_timer, CMercLogicTimer);

BEGIN_DATADESC(CMercLogicTimer)

// Inputs
DEFINE_INPUTFUNC(FIELD_BOOLEAN, "Set Pause Timer", InputSetPauseTimer),
DEFINE_INPUTFUNC(FIELD_VOID, "Toggle Pause Timer", InputTogglePauseTimer),

END_DATADESC()