//
//  Walker.h
//  NOCProject
//
//  Created by Kathleen Sullivan on 5/28/15.
//
//

class Walker {
public:
    Walker();
    Walker(int x, int y);
    void setup();
    void step();
    void update();
    void draw();
    
    int mX, mY;
    int mStepX, mStepY;
    
    int mXCount, mYCount;
    int mXMax, mYMax;
    
    bool mPosX, mPosY;
};

