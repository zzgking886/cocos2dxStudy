//
//  FirstScene.hpp
//  GameStudy
//
//  Created by Zhangzhengang on 16/12/22.
//
//

#ifndef FirstScene_hpp
#define FirstScene_hpp
#include <cocos2d.h>

#include <stdio.h>

USING_NS_CC;

class FirstScene : public cocos2d::Layer
{
public:
    virtual bool init();
    static Scene * createScene();
    CREATE_FUNC(FirstScene);
};

#endif /* FirstScene_hpp */
