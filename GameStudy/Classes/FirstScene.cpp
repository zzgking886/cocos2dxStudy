//
//  FirstScene.cpp
//  GameStudy
//
//  Created by Zhangzhengang on 16/12/22.
//
//

#include "FirstScene.hpp"


Scene* FirstScene::createScene()
{
    Scene *scene = Scene::create();
    
    FirstScene *firstScene = FirstScene::create();
    scene->addChild(firstScene);
    
    return scene;
}


bool FirstScene::init()
{
    Size onesize = Director::getInstance()->getVisibleSize();
    Sprite *onesprite = Sprite::create("test_bg_1.jpg");
    onesprite->setPosition(onesize.width/2, onesize.height/2);
    addChild(onesprite);
    return true;
}
