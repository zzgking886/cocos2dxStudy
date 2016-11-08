//
//  Human.hpp
//  GameStudy
//
//  Created by Zhangzhengang on 16/11/8.
//
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Human:public Sprite {
    
    public:
    virtual bool init();
    CREATE_FUNC(Human);
};

#endif /* Human_hpp */
