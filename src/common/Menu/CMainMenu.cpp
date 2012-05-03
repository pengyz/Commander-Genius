/*
 * CMainMenu.cpp
 *
 *  Created on: 19.02.2012
 *      Author: gerstrong and pizza2004
 */

#include "CMainMenu.h"
#include "common/Menu/CMenuController.h"
#include "common/Menu/CSettingsMenu.h"
#include "common/Menu/CLoadMenu.h"
#include "common/Menu/CSaveMenu.h"
#include "common/Menu/CHelpMenu.h"
#include "engine/infoscenes/CHighScores.h"
#include "common/CBehaviorEngine.h"
#include "gui/CGUIButton.h"
#include "core/mode/CGameMode.h"


CMainMenu::CMainMenu( const bool openedGamePlay ) :
CBaseMenu( CRect<float>(0.25f, 0.23f, 0.5f, 0.5f) )
{

	CGUIButton *button = new CGUIButton( "New Game", new StartGameplayEvent() );
	mpMenuDialog->addControl( button );


	CGUIButton *loadButton = new CGUIButton( "Load",
										new OpenMenuEvent( new CLoadMenu() ) );
	mpMenuDialog->addControl( loadButton );

	CGUIButton *saveButton = new CGUIButton( "Save",
									new OpenMenuEvent( new CSaveMenu() ) );
	mpMenuDialog->addControl( saveButton );
	saveButton->mEnabled = openedGamePlay;

	mpMenuDialog->addControl(new CGUIButton( "Settings",
												new OpenMenuEvent( new CSettingsMenu() ) ) );

	mpMenuDialog->addControl(new CGUIButton( "High Scores",
												new StartInfoSceneEvent( new CHighScores ) ) );

	mpMenuDialog->addControl(new CGUIButton( "Info",
												new OpenMenuEvent( new CHelpMenu() ) ) );

	mpMenuDialog->addControl(new CGUIButton( "Quit", new GMQuit() ) );

	setMenuLabel("MAINMENULABEL");
}