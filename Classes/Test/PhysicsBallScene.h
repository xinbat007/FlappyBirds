#pragma once

#include "cocos2d.h"

USING_NS_CC;

class PhysicsBallScene : public cocos2d::Layer
{
public:

	Sprite* _ball;

	PhysicsWorld* m_world;

	void setPhyWorld(PhysicsWorld* world){ m_world = world; };

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	virtual void onAcceleration(Acceleration* acc, Event* unused_event);
	
	bool onContactBegin(PhysicsContact &contact);
	

    
    // implement the "static create()" method manually
	CREATE_FUNC(PhysicsBallScene);
};
