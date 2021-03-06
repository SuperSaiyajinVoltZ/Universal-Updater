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

#include "screens/screen.hpp"

class Pong : public SCREEN
{
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;

private:
	void drawPaddle(void) const;
	void drawBall(void) const;

	void drawSubMenu(void) const;
	void drawScreen(void) const;
	void drawSelection(void) const;
	void selectionLogicPong(u32 hDown, u32 hHeld);
	void drawScoreP1(void) const;
	void drawScoreP2(void) const;

	void player1Control(u32 hDown, u32 hHeld);
	void player2Control(u32 hDown, u32 hHeld);
	void ballLogic(void);
	void stopLogic(void);

	// New Mode Stuff.
	int mode = 0;
	int points = 0;
	void drawNewMode(void) const;
	void newModeLogic(void);


	// Paddle and Ball Positions.
	int paddle1 = 90, paddle2 = 90;
	double	ballX = 200, ballY = 100,
		ballXSpd = -3, ballYSpd = 0;

	// Modes.
	int multiPlayerMode = 0;
	int speed1 = 5;
	int speed2 = -5;

	// Sub Menu.
	int subMenu = 1;
	int Selection = 0;

	// Scores.
	int scoreP1 = 0;
	int scoreP2 = 0;
};