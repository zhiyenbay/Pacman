/*
 * WinMenu.cpp
 *
 *  Created on: 26.11.2012
 *      Author: Denis Zagayevskiy
 */

#include "WinMenu.h"

WinMenu::WinMenu() {
}

void WinMenu::initGraphics(float maxX, float maxY, GLuint vertexHandle, GLuint textureHandle){
	free();

	float indent = maxX / 30.0;
	float buttonSize = (maxX - indent*4.0)/3.0;
	RectButton* button;

	button = new RectButton(indent, maxY/2 - buttonSize / 2, buttonSize, buttonSize);
	button->initGraphics(Art::getTexture(Art::TEXTURE_BUTTONS), Art::TEX_COORDS_BUTTON_NEXT, NULL, vertexHandle, textureHandle);
	button->setActionEvent(ACTION_UP, EVENT_NEXT_LEVEL);
	controls.pushTail(button);

	button = new RectButton(indent*2 + buttonSize, maxY/2 - buttonSize / 2, buttonSize, buttonSize);
	button->initGraphics(Art::getTexture(Art::TEXTURE_BUTTONS), Art::TEX_COORDS_BUTTON_RETRY, NULL, vertexHandle, textureHandle);
	button->setActionEvent(ACTION_UP, EVENT_RETRY);
	controls.pushTail(button);

	button = new RectButton(indent*3 + buttonSize*2, maxY/2 - buttonSize / 2, buttonSize, buttonSize);
	button->initGraphics(Art::getTexture(Art::TEXTURE_BUTTONS), Art::TEX_COORDS_BUTTON_LIST, NULL, vertexHandle, textureHandle);
	button->setActionEvent(ACTION_UP, EVENT_MAINMENU);
	controls.pushTail(button);

}

WinMenu::~WinMenu() {
}

