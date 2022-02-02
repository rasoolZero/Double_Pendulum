#include "DoublePendulum.h"
#include "cinder/CinderGlm.h"
#include "cinder/gl/gl.h"
void DoublePendulum::update(){
    updateBall1();
    updateBall2();
}
void DoublePendulum::updateBall1(){
    ball1.x = rodOneLength * glm::sin(angle1);
    ball1.y = rodOneLength * glm::cos(angle1);
}
void DoublePendulum::updateBall2(){
    ball2.x = ball1.x + rodTwoLength * glm::sin(angle2);
    ball2.y = ball1.y + rodTwoLength * glm::cos(angle2);
}

void DoublePendulum::draw(){
    ci::gl::lineWidth(3);
    drawPart1();
    drawPart2();
}

void DoublePendulum::drawPart1(){
    static ci::vec2 origin;
    ci::gl::color(ci::Color(1,0,0));
    ci::gl::drawLine(origin,ball1);
    ci::gl::drawSolidCircle(ball1,massOne);
}
void DoublePendulum::drawPart2(){
    ci::gl::color(ci::Color(0,1,0));
    ci::gl::drawLine(ball1,ball2);
    ci::gl::drawSolidCircle(ball2,massTwo);
}