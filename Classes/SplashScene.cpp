#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/Hit.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/Point.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/Wing.mp3");

	cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce(schedule_selector(SplashScene::goToMainScene), DISPLAY_TIME_SPLASH_SCENE);
	
	Sprite* bgsprite = Sprite::create("ipadhd/Splash Screen.png");
	bgsprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	
	this->addChild(bgsprite);
    
    return true;
}

void SplashScene::goToMainScene(float dt)
{
	Scene* scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}