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

#include "utils/settings.hpp"
#include "inifile.h"
#include "colors.hpp"

#include <unistd.h>
#include <string>
using std::string;
using std::wstring;

#include <3ds.h>

static CIniFile settingsini( "sdmc:/Universal-Manager/Settings.ini" );

int Config::barColor, Config::bgColor, Config::musicMode, Config::percentDisplay, Config::layout, Config::layoutBG; // [UI]
int Config::animation, Config::animationColor; // [ANIMATED]
int Config::Citra; // [Citra]
int Config::selectedText, Config::unselectedText; // [TEXTCOLOR]

void Config::loadConfig() {
	// [UI]
	Config::barColor = settingsini.GetInt("UI", "BARS", BARCOLOR);
	Config::bgColor = settingsini.GetInt("UI", "BG", GRAY);
	Config::musicMode = settingsini.GetInt("UI", "MUSIC", 0);
	Config::percentDisplay = settingsini.GetInt("UI", "BATTERY", 0);
	Config::layout = settingsini.GetInt("UI", "LAYOUT", 0);
	Config::layoutBG = settingsini.GetInt("UI", "LAYOUTBG", 0);
	// [ANIMATED]
	Config::animation = settingsini.GetInt("ANIMATED", "ENABLE", 1);
	Config::animationColor = settingsini.GetInt("ANIMATED", "COLOR", BLUE);
	// [CITRA]
	Config::Citra = settingsini.GetInt("CITRA", "ENABLED", 0);
	// [TEXTCOLOR]
	Config::selectedText = settingsini.GetInt("TEXTCOLOR", "SELECTED", BLUE);
	Config::unselectedText = settingsini.GetInt("TEXTCOLOR", "UNSELECTED", BLACK);
}

void Config::saveConfig() {
	// [UI]
	settingsini.SetInt("UI", "BARS", Config::barColor);
	settingsini.SetInt("UI", "BG", Config::bgColor);
	settingsini.SetInt("UI", "MUSIC", Config::musicMode);
	settingsini.SetInt("UI", "BATTERY", Config::percentDisplay);
	settingsini.SetInt("UI", "LAYOUT", Config::layout);
	settingsini.SetInt("UI", "LAYOUTBG", Config::layoutBG);
	// [ANIMATED]
	settingsini.SetInt("ANIMATED", "ENABLE", Config::animation);
	settingsini.SetInt("ANIMATED", "COLOR", Config::animationColor);

	// [CITRA]
	settingsini.SetInt("CITRA", "ENABLED", Config::Citra);

	// [TEXTCOLOR]
	settingsini.SetInt("TEXTCOLOR", "SELECTED", Config::selectedText);
	settingsini.SetInt("TEXTCOLOR", "UNSELECTED", Config::unselectedText);

	settingsini.SaveIniFile("sdmc:/Universal-Manager/Settings.ini");
}

