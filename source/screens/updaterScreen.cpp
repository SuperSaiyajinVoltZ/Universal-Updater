/*
*   This file is part of Universal-Manager
*   Copyright (C) 2019 VoltZ, Epicpkmn11, Flame, RocketRobz, TotallyNotGuy
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "screens/screenCommon.hpp"
#include "download/download.hpp"
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <vector>

bool updatingSelf = false;

struct ButtonPos {
	int x;
	int y;
	int w;
	int h;
	int link;
};

extern bool touching(touchPosition touch, ButtonPos button);


ButtonPos downloadFunctionButtonPos[] = {
	// TWLMenu
	{129, 48, 87, 33, -1},
	{220, 48, 87, 33, -1},
	// NDS-Bootstrap
	{129, 88, 87, 33, -1},
	{220, 88, 87, 33, -1},

	// Usrcheat.dat
	{129, 128, 87, 33, -1},

	// Universal-Manager
	{129, 48, 87, 33, -1},
	{220, 48, 87, 33, -1},
	// Luma 3DS.
	{129, 48, 87, 33, -1},
	{220, 48, 87, 33, -1},
	// GodMode9
	{129, 88, 87, 33, -1},
	// PKSM
	{129, 88, 87, 33, -1},
	// Checkpoint
	{129, 128, 87, 33, -1},
	// Check for Update!
	{0, 208, 32, 32, -1},
	// Back Icon.
	{293, 213, 27, 27, -1},

	// Themes.
	{129, 168, 87, 33, -1},

	// pkmn-chest
	{220, 88, 87, 33, -1},
};

ButtonPos downloadButtonPos[] = {
	// TWLMenu
	{129, 48, 87, 33}, 
	{220, 48, 87, 33}, 
	// NDS-Bootstrap
	{129, 88, 87, 33}, 
	{220, 88, 87, 33}, 
	// Usrcheat.dat
	{129, 128, 87, 33}, 
	// Universal-Manager
	{129, 48, 87, 33}, 
	{220, 48, 87, 33},
	// Luma 3DS
	{129, 48, 87, 33},
	{220, 48, 87, 33},

	// GodMode9
	{129, 88, 87, 33},
	// PKSM
	{129, 88, 87, 33},
	// Checkpoint
	{129, 128, 87, 33},
	// Music Player Theme.
	{129, 168, 87, 33},

	// Sub Menu.
	{38, 48, 87, 33, CFWScreen},
	{129, 48, 87, 33, TWLScreen},
	{220, 48, 87, 33, OtherScreen},

	{129, 168, 87, 33}, // ? Forgot it.
	// PKMN-Chest
	{220, 88, 87, 33},
};

bool updateAvailable[] = {
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
	false,
};


void drawUpdaterSubMenu(void) {
	Gui::DrawBGTop();
	animatedBGTop();
	Gui::chooseLayoutTop();
	DisplayTime();
	drawBatteryTop();
	Gui::staticText((i18n::localize("UPDATER_SUB_MENU")), 200, 0, 0.72f, 0.72f, WHITE, TextPosX::CENTER, TextPosY::TOP);

	Gui::DrawBGBot();
	animatedBGBot();
	Gui::chooseLayoutBotBack();

	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[13].x, downloadButtonPos[13].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[14].x, downloadButtonPos[14].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[15].x, downloadButtonPos[15].y);
	draw_text(49, 58, 0.7f, 0.7f, WHITE, "CFW");
	draw_text(140, 58, 0.7f, 0.7f, WHITE, "TWL");
	draw_text(229, 58, 0.7f, 0.7f, WHITE, "Other");
}

void updaterSubMenuLogic(u32 hDown, touchPosition touch) {
	if (hDown & KEY_B) {
		screenMode = mainScreen;
	} else if(hDown & KEY_TOUCH) {
		for(uint i=0;i<(sizeof(downloadButtonPos)/sizeof(downloadButtonPos[0]));i++) {
			if (touching(touch, downloadButtonPos[i])) {
				screenMode = downloadButtonPos[i].link;
			}
		}
/*	} else if (touching(touch, downloadFunctionButtonPos[11])) {
			if(confirmPopup("Are you sure you want to check for Updates?\nThis only works the First Time.")) {
			displayMsg("Checking for Updates.. please wait.");
			checkForUpdates();
			}
		}
*/} else if (touching(touch, downloadFunctionButtonPos[13])) {
			screenMode = mainScreen;
		}
}

void drawUpdaterTWL(void) {
	Gui::DrawBGTop();
	animatedBGTop();
	Gui::chooseLayoutTop();
	DisplayTime();
	drawBatteryTop();
	Gui::staticText((i18n::localize("TWL_UPDATER_SCREEN")), 200, 0, 0.72f, 0.72f, WHITE, TextPosX::CENTER, TextPosY::TOP);
	
	// Draw the Main Bottom Screen Background.
	Gui::DrawBGBot();
	animatedBGBot();
	Gui::chooseLayoutBotBack();

	// TWL Menu Buttons.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[0].x, downloadButtonPos[0].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[1].x, downloadButtonPos[1].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 48);
	draw_text(0, 58, 0.65f, 0.65f, WHITE, "TWLMENU++");
	draw_text(140, 58, 0.7f, 0.7f, WHITE, "Release");
	draw_text(229, 58, 0.7f, 0.7f, WHITE, "Nightly");

	// NDS-Bootstrap Buttons.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[2].x, downloadButtonPos[2].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[3].x, downloadButtonPos[3].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 88);
	draw_text(0, 98, 0.65f, 0.65f, WHITE, "NDS-Bootstrap");
	draw_text(140, 98, 0.7f, 0.7f, WHITE, "Release");
	draw_text(229, 98, 0.7f, 0.7f, WHITE, "Nightly");

	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[4].x, downloadButtonPos[4].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 128);
	draw_text(0, 138, 0.7f, 0.7f, WHITE, "Extras");
	draw_text(140, 138, 0.7f, 0.7f, WHITE, "Cheats");

	// Draw The Pages and Back Icon.
	Gui::staticText((i18n::localize("CURRENT_PAGE")), 170, 0, 0.50, 0.50, WHITE, TextPosX::CENTER, TextPosY::TOP);
	draw_text(260, 4, 0.50, 0.50, BLACK, "1"); //Draw First Page Number.
	draw_text(280, 4, 0.50, 0.50, WHITE, "2"); //Draw Second Page Number.
	Gui::Draw_ImageBlend(sprites_frame_idx, 276, 2, RED);
	draw_text(300, 4, 0.50, 0.50, BLACK, "3"); //Draw Third Page Number.
}

void updaterTWLLogic(u32 hDown, touchPosition touch) {
	if (hDown & KEY_B) {
		screenMode = updaterSubMenu;
	} else if (hDown & KEY_L) {
		screenMode = CFWScreen;
	} else if (hDown & KEY_R) {
		screenMode = OtherScreen;
	} else if (hDown & KEY_TOUCH) {
		if (touching(touch, downloadFunctionButtonPos[0])) {
			if(confirmPopup((i18n::localize("TWLMENU_RELEASE")))) {
			updateTWiLight(false);
			}
		} else if (touching(touch, downloadFunctionButtonPos[1])) {
			if(confirmPopup((i18n::localize("TWLMENU_NIGHTLY")))) {
			updateTWiLight(true);
			}
		} else if (touching(touch, downloadFunctionButtonPos[2])) {
			if(confirmPopup((i18n::localize("NDS_BOOTSTRAP_RELEASE")))) {
			updateBootstrap(false);
			}
		} else if (touching(touch, downloadFunctionButtonPos[3])) {
			if(confirmPopup((i18n::localize("NDS_BOOTSTRAP_NIGHTLY")))) {
			updateBootstrap(true);
			}
			} else if (touching(touch, downloadFunctionButtonPos[4])) {
			if(confirmPopup((i18n::localize("USRCHEAT_DAT")))) {
			updateCheats();
			}
		} else if (touching(touch, downloadFunctionButtonPos[13])) {
			screenMode = updaterSubMenu;
		}
	}
}
	/*	
		} else if (touching(touch, downloadFunctionButtonPos[11])) {
			if(confirmPopup("Are you sure you want to check for Updates?\nThis only works the First Time.")) {
			displayMsg("Checking for Updates.. please wait.");
			checkForUpdates();
			}
		}
	}
}

*/void drawUpdaterOther(void) {
	Gui::DrawBGTop();
	animatedBGTop();
	Gui::chooseLayoutTop();
	DisplayTime();
	drawBatteryTop();
	Gui::staticText((i18n::localize("OTHER_UPDATER_SCREEN")), 200, 0, 0.72f, 0.72f, WHITE, TextPosX::CENTER, TextPosY::TOP);
	
	// Draw the Main Bottom Screen Background.
	Gui::DrawBGBot();
	animatedBGBot();
	Gui::chooseLayoutBotBack();

		// Universal-Manager Buttons.

	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[5].x, downloadButtonPos[5].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[6].x, downloadButtonPos[6].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 48);
	draw_text(0, 58, 0.65f, 0.65f, WHITE, "UNIV-Manager");
	draw_text(140, 58, 0.7f, 0.7f, WHITE, "Release");
	draw_text(229, 58, 0.7f, 0.7f, WHITE, "Nightly");

	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[10].x, downloadButtonPos[10].y);
	// PKSM Buttons.
	Gui::sprite(sprites_TitleButton_idx, 0, 88);
	draw_text(0, 98, 0.7f, 0.7f, WHITE, "PKSM");
	draw_text(140, 98, 0.7f, 0.7f, WHITE, "Release");
	// Checkpoint Buttons.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[11].x, downloadButtonPos[11].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 128);
	draw_text(0, 138, 0.65f, 0.65f, WHITE, "Checkpoint");
	draw_text(140, 138, 0.7f, 0.7f, WHITE, "Release");

	// Themes Download Button.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[16].x, downloadButtonPos[16].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 168);
	draw_text(0, 178, 0.7f, 0.7f, WHITE, "Extras");
	draw_text(140, 178, 0.7f, 0.7f, WHITE, "Themes");

	// PKMN-Chest.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[17].x, downloadButtonPos[17].y);
	draw_text(226, 98, 0.7f, 0.7f, WHITE, "PK-Chest");
	

	// Draw The Pages and Back Icon.
	Gui::staticText((i18n::localize("CURRENT_PAGE")), 170, 0, 0.50, 0.50, WHITE, TextPosX::CENTER, TextPosY::TOP);
	draw_text(260, 4, 0.50, 0.50, BLACK, "1"); //Draw First Page Number.
	draw_text(280, 4, 0.50, 0.50, BLACK, "2"); //Draw Second Page Number.
	draw_text(300, 4, 0.50, 0.50, WHITE, "3"); //Draw Third Page Number.
	Gui::Draw_ImageBlend(sprites_frame_idx, 296, 2, RED);
}

void updaterOtherLogic(u32 hDown, touchPosition touch) {
	if (hDown & KEY_B) {
		screenMode = updaterSubMenu;
	} else if (hDown & KEY_L) {
		screenMode = TWLScreen;
	} else if (hDown & KEY_TOUCH) {
		if (touching(touch, downloadFunctionButtonPos[5])) {
			if(confirmPopup((i18n::localize("UNIVERSAL_MANAGER_RELEASE")))) {
			updateUniversalManager(false);
			}
		} else if (touching(touch, downloadFunctionButtonPos[6])) {
			if(confirmPopup((i18n::localize("UNIVERSAL_MANAGER_NIGHTLY")))) {
			//updateUniversalManager(true); -> After the first Build appears, comment this out.
			notImplemented();
			}
		} else if (touching(touch, downloadFunctionButtonPos[10])) {
			if(confirmPopup((i18n::localize("PKSM_RELEASE")))) {
			updatePKSM();
			}
		} else if (touching(touch, downloadFunctionButtonPos[11])) {
			if(confirmPopup((i18n::localize("CHECKPOINT_RELEASE")))) {
			updateCheckpoint();
			}
		} else if (touching(touch, downloadFunctionButtonPos[13])) {
			screenMode = updaterSubMenu;
		} else if (touching(touch, downloadFunctionButtonPos[14])) {
			downloadThemes();
		} else if (touching(touch, downloadFunctionButtonPos[15])) {
			if(confirmPopup((i18n::localize("PKMN_CHEST_RELEASE")))) {
			updatePKMNChestRelease(); 
			}
		}
}
}

void drawUpdaterCFW(void) {
	Gui::DrawBGTop();
	animatedBGTop();
	Gui::chooseLayoutTop();
	DisplayTime();
	drawBatteryTop();
	Gui::staticText((i18n::localize("CFW_UPDATER_SCREEN")), 200, 0, 0.72f, 0.72f, WHITE, TextPosX::CENTER, TextPosY::TOP);
	
	// Draw the Main Bottom Screen Background.
	Gui::DrawBGBot();
	animatedBGBot();
	Gui::chooseLayoutBotBack();

	// Luma 3DS Buttons.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[7].x, downloadButtonPos[7].y);
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[8].x, downloadButtonPos[8].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 48);
	draw_text(0, 58, 0.65f, 0.65f, WHITE, "Luma3DS");
	draw_text(140, 58, 0.7f, 0.7f, WHITE, "Release");
	draw_text(229, 58, 0.7f, 0.7f, WHITE, "Nightly");

	 // GodMode9 Buttons.
	Gui::sprite(sprites_updaterButton_idx, downloadButtonPos[9].x, downloadButtonPos[9].y);
	Gui::sprite(sprites_TitleButton_idx, 0, 88);
	draw_text(0, 98, 0.65f, 0.65f, WHITE, "GodMode9");
	draw_text(140, 98, 0.7f, 0.7f, WHITE, "Release");

	// Draw The Pages and Back Icon.
	Gui::staticText((i18n::localize("CURRENT_PAGE")), 170, 0, 0.50, 0.50, WHITE, TextPosX::CENTER, TextPosY::TOP);
	draw_text(260, 4, 0.50, 0.50, WHITE, "1"); //Draw First Page Number.
	Gui::Draw_ImageBlend(sprites_frame_idx, 256, 2, RED);
	draw_text(280, 4, 0.50, 0.50, BLACK, "2"); //Draw Second Page Number.
	draw_text(300, 4, 0.50, 0.50, BLACK, "3"); //Draw Third Page Number.
}

void updaterCFWLogic(u32 hDown, touchPosition touch) {
	if (hDown & KEY_B) {
		screenMode = updaterSubMenu;
	} else if (hDown & KEY_R) {
		screenMode = TWLScreen;
	} else if (touching(touch, downloadFunctionButtonPos[7])) {
			if(confirmPopup((i18n::localize("LUMA3DS_RELEASE")))) {
			updateLuma(false);
			}
		} else if (touching(touch, downloadFunctionButtonPos[8])) {
			if(confirmPopup((i18n::localize("LUMA3DS_NIGHTLY")))) {
			updateLuma(true);
			}
		} else if (touching(touch, downloadFunctionButtonPos[9])) {
			if(confirmPopup((i18n::localize("GODMODE9_RELEASE")))) {
			downloadGodMode9();
			}
		} else if (touching(touch, downloadFunctionButtonPos[13])) {
			screenMode = updaterSubMenu;
		}
		}