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
    Walker mWalker2;
    Walker mWalker3;
    Walker mWalker4;
    
    qtime::MovieWriter mMovie;
    void initMovieWriter();
    //void keyUp( KeyEvent event );
};

void NOCProjectApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize( 800, 800 );
}

void NOCProjectApp::setup(){
    gl::clear();
    mWalker = Walker( getWindowWidth() / 2, getWindowHeight() / 2 );
    mWalker2 = Walker( getWindowWidth() / 2 , getWindowHeight() / 2 );
    mWalker3 = Walker( getWindowWidth() / 2, getWindowHeight() / 2 );
    mWalker4 = Walker( getWindowWidth() / 2, getWindowHeight() / 2 );
    // mMovie = qtime::MovieWriter();
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
//void NOCProjectApp::initMovieWriter(){
////    fs::path path = getSaveFilePath();
////    if( path.empty() == false ){
//        mMovie = qtime::MovieWriter( "Users/kathleen/Desktop", getWindowWidth(), getWindowHeight() );
////    }
//}

void NOCProjectApp::update(){
}

void NOCProjectApp::draw(){
    mWalker.step();
    mWalker2.step();
    mWalker3.step();
    mWalker4.step();
    mWalker.draw();
    mWalker2.draw();
    mWalker3.draw();
    mWalker4.draw();
//    if( mMovie ){
//        mMovie.addFrame( copyWindowSurface() );
//    }
    
}

CINDER_APP_NATIVE( NOCProjectApp, RendererGl )
