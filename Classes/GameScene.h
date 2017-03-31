#pragma once

#include "cocos2d.h"
#include "Pipe.h"
#include "Bird.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	void spawnPipe(float dt);
	void setPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void stopFlying(float dt);
	void update(float dt);
	cocos2d::PhysicsWorld* sceneWorld;
	Pipe pipe;
	Bird* bird;
	unsigned int score;
	cocos2d::Label* scoreLabel;
};
