#include "Pipe.h"

using namespace cocos2d;

Pipe::Pipe()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();
}

void Pipe::spawnPipe(cocos2d::Layer* layer)
{
	CCLOG("SPAWN PIPE");

}