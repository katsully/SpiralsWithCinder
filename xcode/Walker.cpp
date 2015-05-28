//
//  Walker.cpp
//  NOCProject
//
//  Created by Kathleen Sullivan on 5/28/15.
//
//

#include "Walker.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;

Walker::Walker(){
    
}

Walker::Walker(int x, int y){
    mX = x;
    mY = y;
    mPosX = true;
    mPosY = true;
    mXCount = 0;
    mYCount = 0;
    mStepX = 0;
    mStepY = 1;
    mXMax = randInt(40, 180);
    mYMax = randInt(40, 180);
}

void Walker::setup()
{
}

void Walker::step()
{
    if (mYCount < mYMax) {
        if(mStepY != 0){
            mY += ( mPosY ) ? ( 1 ) : ( -1 );
            mYCount++;
        }
    } else {
        mStepY = 0;
        mStepX = 1;
        mPosY = !mPosY;
        mYCount = 0;
        mYMax = randInt(40, 180);
    }
    if( mXCount < mXMax){
        if(mStepX != 0){
            mX += ( mPosX ) ? ( 1 ) : ( -1 );
            mXCount++;
        }
    } else {
        mStepX = 0;
        mStepY = 1;
        mPosX = !mPosX;
        mXCount = 0;
        mXMax = randInt(40, 180);
    }
}

void Walker::draw()
{
    gl::drawSolidCircle( Vec2f(mX, mY), 1);
}

