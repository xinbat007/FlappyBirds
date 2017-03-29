#include "GraphicsScene.h"

using namespace cocos2d;

Scene* GraphicsScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = GraphicsScene::create();
	scene->addChild(layer);
	return scene;
}

bool GraphicsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Sprite* sprite = Sprite::create("deception.png");
	Sprite* sprite2 = Sprite::create("autobot.png");
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite2->setAnchorPoint(Vec2(0, 0));

	sprite->addChild(sprite2);

	sprite->setPosition(100, 100);
	sprite2->setPosition(0, 0);
	this->addChild(sprite, 0);
	return true;
}