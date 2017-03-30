#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
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

	cocos2d::Sprite* titlesprite = Sprite::create("ipadhd/Title.png");
	titlesprite->setPosition(visibleSize.width / 2, visibleSize.height -
		titlesprite->getContentSize().height);
	this->addChild(titlesprite);

	static cocos2d::MenuItemImage* playItem = MenuItemImage::create("ipadhd/Play Button.png",
		"ipadhd/Play Button Clicked.png", CC_CALLBACK_1(MainMenuScene::gotoGameScene, this));
	playItem->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	static cocos2d::Menu* menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
    
    return true;
}

void MainMenuScene::gotoGameScene(cocos2d::Ref* sender) const
{
	cocos2d::Scene* scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}