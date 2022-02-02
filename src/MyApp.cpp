#include "MyApp.h"
#include "cinder/gl/gl.h"
void MyApp::setup(){
    ci::app::App::setFullScreen(true);
}

void MyApp::update(){

}

void MyApp::draw(){
    ci::gl::color(ci::Color::white());
    ci::gl::drawSolidCircle(ci::app::getWindowCenter(),20);
}