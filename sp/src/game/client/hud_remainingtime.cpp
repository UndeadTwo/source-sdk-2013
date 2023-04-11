//=============================================================================//
//
// Purpose: Time remaining in level
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "hud.h"
#include "hud_macros.h"
#include "view.h"

#include "hl2_gamerules.h"

#include "iclientmode.h"

#include <KeyValues.h>
#include <vgui/ISurface.h>
#include <vgui/ISystem.h>
#include <vgui_controls/AnimationController.h>

#include <vgui/ILocalize.h>

using namespace vgui;

#include "hudelement.h"
#include "hud_numericdisplay.h"

#include "convar.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CHudRemainingTime : public CHudNumericDisplay, public CHudElement
{
	DECLARE_CLASS_SIMPLE(CHudRemainingTime, CHudNumericDisplay);

public:
	CHudRemainingTime(const char *pElementName);

	void Init();
	void VidInit();
	void Reset();

protected:
	void OnThink();
	void UpdateTime();
};

DECLARE_HUDELEMENT(CHudRemainingTime)

CHudRemainingTime::CHudRemainingTime(const char *pElementName) : CHudElement(pElementName), CHudNumericDisplay(null, "HudRemainingTime") {
	//No need to show you what's left when you're dead.
	SetHiddenBits(HIDEHUD_PLAYERDEAD);
	
	CGMsg(1, CON_GROUP_MAPBASE_MISC, "Mercenaries: What the fuck why and how");

	//SetMinutes(0);
	//SetSeconds(0);
	SetLabelText(L"Time Remaining");
}

void CHudRemainingTime::Init() {
	//HOOK_HUD_MESSAGE() Dubious if this is needed, will have to check once up and running.
	Reset();
}

void CHudRemainingTime::VidInit() {
	Reset();
}

void CHudRemainingTime::Reset() {
	int m_remaining_seconds = -1;
	//m_bitsDamage = 0;

	//wchar_t *tempString = g_pVGuiLocalize->Find("#Valve_Hud_HEALTH");

	SetLabelText(L"Time Remaining");
	SetDisplayValue(m_remaining_seconds);
}

void CHudRemainingTime::OnThink() {
	this->UpdateTime();
}

void CHudRemainingTime::UpdateTime() {
	CHalfLife2 *gameRules = HL2GameRules();
	SetDisplayValue(gameRules->GetRemainingSeconds());
}