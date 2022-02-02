#include "MyApp.h"
#include "cinder/gl/gl.h"
void MyApp::setup(){
    ci::app::App::setFullScreen(true);
    ci::app::App::setFrameRate(60.0F);
}

void MyApp::update(){
    
}

void MyApp::draw(){
    ci::gl::color(ci::Color::white());
    ci::gl::drawSolidCircle(ci::app::getWindowCenter(),20);
}