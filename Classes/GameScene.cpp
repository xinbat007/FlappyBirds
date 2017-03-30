#include "GameScene.h"
#include "Definitions.h"
#include "Pipe.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
	cocos2d::Scene* scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
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
	cocos2d::Node* edgeNode = Node::create();
	edgeNode->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);

	this->schedule(schedule_selector(GameScene::spawnPipe), PIPE_SPAWN_FREQUENCY *
							visibleSize.width);

    return true;
}

void GameScene::spawnPipe(float dt)
{
	pipe.spawnPipe(this);
}