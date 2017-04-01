#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Bird
{
public:
	Bird(cocos2d::Layer*);
	void Fall();
	void Fly() {
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/Wing.mp3");
		isFalling = false;
	}
	void StopFlying() { isFalling = true; }

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* flappyBird;
	bool isFalling;
};