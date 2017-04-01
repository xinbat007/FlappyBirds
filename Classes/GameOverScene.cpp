#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

unsigned int score;

Scene* GameOverScene::createScene(unsigned int tempScore)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

	score = tempScore;
    
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
    
	UserDefault *def = UserDefault::getInstance();
	auto highscore = def->getIntegerForKey("HIGHSCORE FLAPPY", 0);
	if (score > highscore)
	{
		highscore = score;
		def->setIntegerForKey("HIGHSCORE FLAPPY", highscore);
	}
	def->flush();

	__String *tempScore = __String::createWithFormat("%i", score);
	auto currentScore = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf",
		visibleSize.height * SCORE_FONT_SIZE);
	currentScore->setPosition(visibleSize.width * 0.25,
		visibleSize.height / 2);
	this->addChild(currentScore);

	__String *tempHighScore = __String::createWithFormat("%i", score);
	auto highScoreLabel = Label::createWithTTF(tempHighScore->getCString(), "fonts/Marker Felt.ttf",
		visibleSize.height * SCORE_FONT_SIZE);
	highScoreLabel->setColor(Color3B::YELLOW);
	highScoreLabel->setPosition(visibleSize.width * 0.75,
		visibleSize.height / 2);
	this->addChild(highScoreLabel);

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