#include "KeyboardScene.h"

using namespace cocos2d;

Scene* KeyboardScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = KeyboardScene::create();
	scene->addChild(layer);
	return scene;
}

bool KeyboardScene::init()
{
	if (!Layer::init())
		return false;
	Sprite* sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	this->addChild(sprite, 0);

	EventListenerKeyboard* eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->setPosition(--loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->setPosition(++loc.x, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->setPosition(loc.x, --loc.y);
			break;
		}
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);

	return true;
}