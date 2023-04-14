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

#include "c_basehlplayer.h"

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
	SetHiddenBits(HIDEHUD_PLAYERDEAD);
	SetLabelText(L"Time Remaining");
}

void CHudRemainingTime::Init() {
	Reset();
}

void CHudRemainingTime::VidInit() {
	Reset();
}

void CHudRemainingTime::Reset() {
	int m_remaining_seconds = -1;

	SetLabelText(L"Time Remaining");
	SetDisplayValue(m_remaining_seconds);
}

void CHudRemainingTime::OnThink() {
	this->UpdateTime();
}

void CHudRemainingTime::UpdateTime() {
	C_BaseHLPlayer *pPlayer = (C_BaseHLPlayer*)C_BaseHLPlayer::GetLocalPlayer();
	SetDisplayValue(pPlayer->GetRemainingSeconds());
}