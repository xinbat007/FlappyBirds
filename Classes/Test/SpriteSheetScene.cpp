#include "SpriteSheetScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SpriteSheetScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SpriteSheetScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SpriteSheetScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
		
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("CityScene/cityscene.plist");
	
	cocos2d::SpriteFrame* spriteframe = spritecache->getSpriteFrameByName("background.png");
	cocos2d::Sprite* background = Sprite::createWithSpriteFrame(spriteframe);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	Vector<cocos2d::SpriteFrame*> frames = getAnimation("capguy/walk/%04d.png", 8);
	cocos2d::Sprite* sprite = Sprite::createWithSpriteFrame(frames.front());
	sprite->setPosition(50, 240);
	background->addChild(sprite);

	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));

	auto movement = MoveTo::create(20, Vec2(800, 240));
	auto resetPosition = MoveTo::create(0, Vec2(-20, 240));
	auto sequence = Sequence::create(movement, resetPosition, NULL);
	sprite->runAction(RepeatForever::create(sequence));

    return true;
}

cocos2d::Vector<cocos2d::SpriteFrame*> SpriteSheetScene::getAnimation(const char *format, int count)
{
	auto spritecache = SpriteFrameCache::getInstance();
	Vector<cocos2d::SpriteFrame*> animFrames;
	char str[100];
	for (int i = 0; i < count; i++)
	{
		sprintf(str, format, i + 1);
		cocos2d::SpriteFrame* spriteframe = spritecache->getSpriteFrameByName(str);
		animFrames.pushBack(spriteframe);
	}
	return animFrames;
}