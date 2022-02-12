#include "DoublePendulum.h"
#include "cinder/CinderGlm.h"
#include "cinder/gl/gl.h"
#include "Enviroment.h"

DoublePendulum::DoublePendulum(){
    massOne = massTwo = 40;
    rodOneLength = rodTwoLength = 200;
    angle1 = angle2 = glm::half_pi<float>();
    trace = ci::PolyLine2();
    trace.setClosed(false);
    rodOneColor = rodTwoColor = ballOneColor = ballTwoColor = traceColor = ci::Color::white();
}
void DoublePendulum::update(){
    updateAcc1();
    updateAcc2();
    updateBall1();
    updateBall2();
    updatePolyline();
}
void DoublePendulum::updateBall1(){
    ball1.x = rodOneLength * glm::sin(angle1);
    ball1.y = rodOneLength * glm::cos(angle1);
}
void DoublePendulum::updateBall2(){
    ball2.x = ball1.x + rodTwoLength * glm::sin(angle2);
    ball2.y = ball1.y + rodTwoLength * glm::cos(angle2);
}
void DoublePendulum::updateAcc1(){
    const float m1=massOne;
    const float m2=massTwo;
    const float a1=angle1;
    const float a2=angle2;
    const float r1=rodOneLength;
    const float r2=rodTwoLength;
    const float g = Enviroment::getGravity();
    float num1 = -g * (2 * m1 + m2) * sin(a1);
    float num2 = -m2 * g * sin(a1-2*a2);
    float num3 = -2*sin(a1-a2)*m2;
    float num4 = velocity2*velocity2*r2+velocity1*velocity1*r1*cos(a1-a2);
    float den = r1 * (2*m1+m2-m2*cos(2*a1-2*a2));
    acc1 = (num1 + num2 + num3*num4) / den;
}
void DoublePendulum::updateAcc2(){
    const float m1=massOne;
    const float m2=massTwo;
    const float a1=angle1;
    const float a2=angle2;
    const float r1=rodOneLength;
    const float r2=rodTwoLength;
    const float g = Enviroment::getGravity();
    float num1 = 2 * sin(a1-a2);
    float num2 = (velocity1*velocity1*r1*(m1+m2));
    float num3 = g * (m1 + m2) * cos(a1);
    float num4 = velocity2*velocity2*r2*m2*cos(a1-a2);
    float den = r2 * (2*m1+m2-m2*cos(2*a1-2*a2));
    acc2 = (num1*(num2+num3+num4)) / den;
}
void DoublePendulum::updateAngles(){
    const float damping = ci::lmap<float>(Enviroment::getDamping(),0.0F,1.0F,0.95F,1.0F); //reducing the effect of damping
    velocity1+=acc1;
    angle1+=velocity1;
    velocity1*=damping;
    velocity2+=acc2;
    angle2+=velocity2;
    velocity2*=damping;
}
void DoublePendulum::clearTrace(){
    trace = ci::PolyLine2();
}

void DoublePendulum::updatePolyline(){
    trace.push_back(ball2);
}

void DoublePendulum::draw(bool drawDP, bool drawTrace, bool paused){
    if(drawTrace)
        drawPolyline();
    ci::gl::lineWidth(3);
    if(drawDP){
        drawPart1();
        drawPart2();
    }
    if(!paused)
        updateAngles();
}

void DoublePendulum::drawPolyline(){
    ci::gl::color(traceColor);
    ci::gl::lineWidth(0.5F);
    ci::gl::draw(trace);
}

void DoublePendulum::drawPart1(){
    const static ci::vec2 origin;
    ci::gl::color(rodOneColor);
    ci::gl::drawLine(origin,ball1);
    ci::gl::color(ballOneColor);
    ci::gl::drawSolidCircle(ball1,massOne/2);
}
void DoublePendulum::drawPart2(){
    ci::gl::color(rodTwoColor);
    ci::gl::drawLine(ball1,ball2);
    ci::gl::color(ballTwoColor);
    ci::gl::drawSolidCircle(ball2,massTwo/2);
}