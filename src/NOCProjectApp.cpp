#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Walker.h"
#include "cinder/qtime/MovieWriter.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOCProjectApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
    void update();
	void draw();
    
    vector<float> mRandomCounts;
    Walker mWalker;
    
    qtime::MovieWriter mMovie;
    void initMovieWriter();
    //void keyUp( KeyEvent event );
};

void NOCProjectApp::prepareSettings(Settings *settings) {
    settings->setWindowSize(800, 800);
}

void NOCProjectApp::setup()
{
    //mRandomCounts.resize(20);
    gl::clear();
    mWalker = Walker(getWindowWidth()/2, getWindowHeight()/2);
    mMovie = qtime::MovieWriter();
    //initMovieWriter();
}

//void NOCProjectApp::keyUp( KeyEvent event ){
//    if( mMovie ){
//        mMovie = qtime::MovieWriter();
//    } else {
//        initMovieWriter();
//    }
//}
//
void NOCProjectApp::initMovieWriter(){
    fs::path path = getSaveFilePath();
    if( path.empty() == false ){
        mMovie = qtime::MovieWriter( path, getWindowWidth(), getWindowHeight() );
    }
}

void NOCProjectApp::update()
{
}

void NOCProjectApp::draw()
{
    mWalker.step();
    mWalker.draw();
//    // pick a random number and increase the count
//    int index = randInt( mRandomCounts.size());
//    mRandomCounts[index]++;
//    
//    // Draw a rectanlge to graph results
//    int w = getWindowWidth() / mRandomCounts.size();
//    for (int i=0; i<mRandomCounts.size(); i++){
//        float x = (i*w);
//        float y = getWindowHeight() - mRandomCounts[i];
//        Rectf box = Rectf( x, y, x + w-1, y + mRandomCounts[i]);
//        gl::color( .5, .5, .5 );
//        gl::drawSolidRect( box );
//        gl::color(0, 0, 0);
//        gl::drawStrokedRect( box );
//    }
//    if( mMovie ){
//        mMovie.addFrame( copyWindowSurface() );
//    }
    
}

CINDER_APP_NATIVE( NOCProjectApp, RendererGl )
