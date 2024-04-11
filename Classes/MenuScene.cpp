/****************************************************************************
Copyright (c) 2024 zahann.ru

http://www.zahann.ru

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "MenuScene.h"

MenuLayer::MenuLayer()
{
}

MenuLayer::~MenuLayer()
{
}

bool MenuLayer::init()
{
    if (!Layer::init()) return false;

	setKeypadEnabled(true);

	auto director = Director::getInstance();
	auto visibleOrigin = director->getVisibleOrigin();
	auto visibleSize = director->getVisibleSize();

	auto logo = Sprite::create("HelloWorld.png");
	logo->setPosition(visibleOrigin + visibleSize / 2);
	addChild(logo);

	auto closeButton = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		ax_menu_selector(MenuLayer::onClose, this)
	);

	closeButton->setPosition(
		visibleOrigin.x + visibleSize.width - closeButton->getContentSize().width / 2,
		visibleOrigin.y + closeButton->getContentSize().height / 2);
	
	auto menu = Menu::createWithItem(closeButton);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

    return true;
}

void MenuLayer::onClose(Object* sender)
{
	keyBackClicked();
}

void MenuLayer::keyBackClicked()
{
	Director::getInstance()->end();
}