/*
 * MainMenu.h
 *
 *  Created on: 10.11.2012
 *      Author: Denis Zagayevskiy
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "Menu.h"
#include "graphics/ui/controls/RectButton.h"
#include "graphics/ui/controls/Label.h"

class MainMenu: public Menu {
public:
	MainMenu(float maxX, float maxY, GLuint vHandle, GLuint tHandle){
		float indentX =  maxX / 30.0f;
		float size = (maxX - indentX*(Art::LEVELS_ON_SIDE_COUNT + 1)) / Art::LEVELS_ON_SIDE_COUNT ;
		float indentY = (maxY - size*Art::LEVELS_ON_SIDE_COUNT) / (Art::LEVELS_ON_SIDE_COUNT + 1);
		RectButton* button;

		for(int i = 0; i < Art::LEVELS_ON_SIDE_COUNT; ++i){
			for(int j = 0; j < Art::LEVELS_ON_SIDE_COUNT; ++j){
				GLfloat* texCoords = Art::getLevelTexCoords(i*Art::LEVELS_ON_SIDE_COUNT + j);
				if(texCoords != NULL){
					button = new RectButton(j*(size + indentX) + indentX, i*(size + indentY) + indentY, size, size);
					button->initGraphics(Art::getTexture(Art::TEXTURE_ALL_LEVELS), texCoords, NULL, vHandle, tHandle);
					button->setActionEvent(ACTION_UP, EVENT_PLAY);
					controls.pushTail(button);
				}
			}
		}

		Label* label = new Label(0.05, 0.05, "Pacman", vHandle, tHandle, 0.09);
		controls.pushTail(label);

	}

	int getLevelToLoadNumber() const {return lastActingControlNumber != LAST_CONTROL_NONE ? lastActingControlNumber : 0;};

	virtual ~MainMenu();
};

#endif /* MAINMENU_H_ */
