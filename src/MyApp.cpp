#include "MyApp.h"
#include "cinder/gl/gl.h"
#include "Enviroment.h"
void MyApp::setup(){
    ci::app::App::setFullScreen(true);
    ci::app::App::setFrameRate(60.0F);
    Enviroment::setGravity(1.0F);
}

void MyApp::update(){
    dp.update();
}

void MyApp::draw(){
    ci::gl::clear();
    ci::gl::pushModelMatrix();
    ci::gl::translate(ci::app::getWindowCenter());
    dp.draw();
    ci::gl::popModelMatrix();
}