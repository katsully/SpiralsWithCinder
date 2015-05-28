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
    mXMax = randInt( 40, 180 );
    mYMax = randInt( 40, 180 );
}

void Walker::setup()
{
}

void Walker::step()
{
    if( mYCount < mYMax ) {
        if( mYCount != 0 ) {
            mY += ( mPositiveY ) ? ( 1 ) : ( -1 );
            mYCount++;
        }
    } else {
        mPositiveY = !mPositiveY;
        mYCount = 0;
        mXCount = 1;
        mYMax = randInt( 40, 180 );
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
        mXMax = randInt( 40, 180 );
    }
}

void Walker::draw()
{
    gl::drawSolidCircle( Vec2f( mX, mY ), 1 );
}

