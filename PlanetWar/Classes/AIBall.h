//
//  AIBall.h
//  PlanetWar
//
//  Created by Xinhou Jiang on 9/11/16.
//
//

#ifndef __PlanetWar__AIBall__ 
#define __PlanetWar__AIBall__

#include "BaseBall.h"

class AIBall : public BaseBall {

/** 重写函数 **/
public:
    // 创建类对象
    static AIBall* create();
	// 对象初始化
	virtual bool init();
    // 安帧更新
    virtual void update(float time);
    // 缩放
    virtual void scale(const float scale);
    // 析构函数
    virtual ~AIBall();

/** 内部变量和函数 **/
protected:
    // 移动方向
    cocos2d::Vec2 direction = cocos2d::Vec2::ZERO;
    // 移动速度
    int speed = 0;
    // 移动间隔帧数
    double speedInterval;
    // 间隔帧数计数器
    double intervalCount;
    // 吃球数量
    int eatAINum = 0;
    int eatBaseNum = 0;
    
    cocos2d::Label *label_tag;
    
    // 通用初始化
    virtual void commenInit();
    // 移动
    virtual void thisUpdate(float delta);
    // 碰撞检测
    virtual void sharedUpdate(float delta);
    
/** 对外接口 **/
public:
    virtual void updateWeight(int addedWeight);
    void scaleSpeed(float scale){speed *= scale;};
    virtual void setLabel(const cocos2d::__String label);
    
    void setDirection(const cocos2d::Vec2 dir){direction = dir;}
    
    const cocos2d::Vec2 getDirection()const{return direction;}
    const float getSpeedInterval()const{return speedInterval;}
    const int getEatAINum()const{return eatAINum;};
    const int getEatBaseNum()const{return eatBaseNum;}
    
};

#endif /* defined(__PlanetWar__AIBall__) */
