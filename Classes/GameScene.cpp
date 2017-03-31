#include "GameScene.h"
#include "Definitions.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	cocos2d::Scene* scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    
    // 'layer' is an autorelease object
	GameScene* layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
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

	cocos2d::PhysicsBody* edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3.0f);
	edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);

	cocos2d::Node* edgeNode = Node::create();
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	this->schedule(schedule_selector(GameScene::spawnPipe), PIPE_SPAWN_FREQUENCY *
							visibleSize.width);
	bird = new Bird(this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
		touchListener, this);

	score = 0;
	__String *tempScore = __String::createWithFormat("%i", score);
	scoreLabel = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf",
		visibleSize.height * SCORE_POINT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(visibleSize.width / 2,
		visibleSize.height * 0.75);

	this->addChild(scoreLabel, 1000);
	this->scheduleUpdate();

    return true;
}

void GameScene::spawnPipe(float dt)
{
	pipe.spawnPipe(this);
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();
	if ((BIRD_COLLISION_BITMASK == a->getCollisionBitmask() &&
		OBSTACLE_COLLISION_BITMASK == b->getCollisionBitmask()) ||
		(BIRD_COLLISION_BITMASK == b->getCollisionBitmask() &&
		OBSTACLE_COLLISION_BITMASK == a->getCollisionBitmask()))
	{
		auto scene = GameOverScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create
			(TRANSITION_TIME, scene));
	}
	else if ((BIRD_COLLISION_BITMASK == a->getCollisionBitmask() &&
		POINT_COLLISION_BITMASK == b->getCollisionBitmask()) ||
		(BIRD_COLLISION_BITMASK == b->getCollisionBitmask() &&
		POINT_COLLISION_BITMASK == a->getCollisionBitmask()))
	{
		score++;
		__String *tempScore = __String::createWithFormat("%i", score);
		scoreLabel->setString(tempScore->getCString());
	}
	return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	bird->Fly();
	this->scheduleOnce(schedule_selector(GameScene::stopFlying), BIRD_FLY_DURATION);
	return true;
}

void GameScene::stopFlying(float dt)
{
	bird->StopFlying();
}

void GameScene::update(float dt)
{
	bird->Fall();
}
