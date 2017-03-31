#include "Bird.h"
#include "Definitions.h"

using namespace cocos2d;

Bird::Bird(cocos2d::Layer* layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
	flappyBird = Sprite::create("ipadhd/Ball.png");
	flappyBird->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	auto flappyBody = PhysicsBody::createCircle(flappyBird->getContentSize().width / 2);
	flappyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	flappyBody->setContactTestBitmask(true);

	flappyBird->setPhysicsBody(flappyBody);
	layer->addChild(flappyBird, 100);

	isFalling = true;
}

void Bird::Fall()
{
	if (true == isFalling)
	{
		flappyBird->setPositionX(visibleSize.width / 2);
		flappyBird->setPositionY(flappyBird->getPositionY() -
			(BIRD_FALLING_SPEED * visibleSize.height));
	}
	else
	{
		flappyBird->setPositionX(visibleSize.width / 2);
		flappyBird->setPositionY(flappyBird->getPositionY() +
			(BIRD_FLYING_SPEED * visibleSize.height));
	}
}