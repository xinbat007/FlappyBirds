#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
	}
	cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = Director::getInstance()->getVisibleOrigin();

	cocos2d::Sprite* bgsprite = Sprite::create("ipadhd/Background.png");
	bgsprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bgsprite);

	auto retryItem = MenuItemImage::create("ipadhd/Retry Button.png",
		"ipadhd/Retry Button Clicked.png",
		CC_CALLBACK_1(GameOverScene::gotoGameScene, this));
	retryItem->setPosition(visibleSize.width / 2,
		visibleSize.height / 4 * 3);
	
	auto mainMenuItem = MenuItemImage::create("ipadhd/Menu Button.png",
		"ipadhd/Menu Button Clicked.png",
		CC_CALLBACK_1(GameOverScene::gotoMainMenuScene, this));
	mainMenuItem->setPosition(visibleSize.width / 2,
		visibleSize.height / 4);

	auto menu = Menu::create(retryItem, mainMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
    
    return true;
}

void GameOverScene::gotoMainMenuScene(cocos2d::Ref* sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(
		TRANSITION_TIME, scene));
}

void GameOverScene::gotoGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(
		TRANSITION_TIME, scene));
}