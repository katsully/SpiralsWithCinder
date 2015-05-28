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
        Walker( int x, int y );
        void setup();
        void step();
        void draw();
    
        int mX;
        int mY;
        int mXCount;
        int mYCount;
        int mXMax;
        int mYMax;
    
        bool mPositiveX;
        bool mPositiveY;
};

