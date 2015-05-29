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

Walker::Walker( int x, int y ){
    mX = x;
    mY = y;
    mPositiveX = true;
    mPositiveY = true;
    mXCount = 0;
    mYCount = 1;
    mXMax = montecarlo();
    mYMax = montecarlo();
}

void Walker::setup(){
}

void Walker::step(){
    if( mYCount < mYMax ) {
        if( mYCount != 0 ) {
            mY += ( mPositiveY ) ? ( 1 ) : ( -1 );
            mYCount++;
        }
    } else {
        mPositiveY = !mPositiveY;
        mYCount = 0;
        mXCount = 1;
        mYMax = montecarlo();
    }
    if( mXCount < mXMax ) {
        if( mXCount != 0 ) {
            mX += ( mPositiveX ) ? ( 1 ) : ( -1 );
            mXCount++;
        }
    } else {
        mPositiveX = !mPositiveX;
        mXCount = 0;
        mYCount = 1;
        mXMax = montecarlo();
    }
}

void Walker::draw(){
    gl::drawSolidCircle( Vec2f( mX, mY ), 1 );
}

float Walker::montecarlo(){
    while (true) {
        float random1 = randFloat(40, 250);
        float probability = random1 * random1;
        float random2 = randFloat(40, 250);
        
        if( random2 < probability ){
            return random1;
        }
    }
}

