/*
*   This file is part of Universal-Manager-NX
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

#include <stdlib.h>
#include <stdio.h>
#include <switch.h>
#include "colors.hpp"
#include "screens/screenCommon.hpp"
#include <algorithm>
#include <dirent.h>
#include <malloc.h>
#include <sstream>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

extern "C" {
	#include "SDL_helper.h"
	#include "textures.h"
}

struct ButtonPos {
    int x;
    int y;
    int w;
    int h;
	int link;
};

int screenMode = 0;
static touchPosition touch;
u32 touch_count = hidTouchCount();

bool touching(touchPosition touch, ButtonPos button) {
	if (touch.px >= button.x && touch.px <= (button.x + button.w) && touch.py >= button.y && touch.py <= (button.y + button.h))
		return true;
	else
		return false;
}

static Result servicesInit(void)
{
    Result res = 0;
    romfsInit();

    SDL_Initialize();
	Textures_Load();

    return 0;
}

static void servicesExit(void)
{
//    nsExit();
	SDL_Terminate();
//    plExit();
    romfsExit();
    Textures_Free();
}

int main(void)
{
    Result res = servicesInit();
    if (R_FAILED(res)) {
        servicesExit();
        return res;
    }

        while (appletMainLoop() && !(hidKeysDown(CONTROLLER_P1_AUTO) & KEY_PLUS)) {
        hidScanInput();
        u64 hDown = hidKeysDown(CONTROLLER_P1_AUTO);
        hidTouchRead(&touch, touch_count);
        SDL_ClearScreen(BLUE);

		// Draws a screen based on screenMode
		switch(screenMode) {
//#########################################################################################################
			case mainScreen:
				drawMainMenu();
				break;
        }

		// Scans inputs for the current screen
		switch(screenMode) {
//#########################################################################################################
			case mainScreen:
				MainMenuLogic(hDown, touch);
				break;
        }
        SDL_RenderScreen();
        }

    servicesExit();
    return 0;
}