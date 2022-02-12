#ifndef DOUBLEPENDULUM_H
#define DOUBLEPENDULUM_H
#include "cinder/gl/gl.h"
#include "cinder/CinderGlm.h"

class DoublePendulum{
private:
    float rodOneLength;
    float rodTwoLength;
    float massOne;
    float massTwo;
    float velocity1=0.0F;
    float velocity2=0.0F;
    float acc1;
    float acc2;
    float angle1;
    float angle2;
    ci::Color rodOneColor;
    ci::Color rodTwoColor;
    ci::Color ballOneColor;
    ci::Color ballTwoColor;
    ci::Color traceColor;


    ci::vec2 ball1,ball2;
    ci::PolyLine2 trace;
    void updateBall1();
    void updateBall2();
    void updateAcc1();
    void updateAcc2();
    void updateAngles();
    void updatePolyline();
    void drawPart1();
    void drawPart2();
    void drawPolyline();

public:
    DoublePendulum();
    void update();
    void draw(bool drawDP,bool drawTrace, bool paused);
    void clearTrace();

    float getRodOneLength() {
    	return this->rodOneLength;
    }
    void setRodOneLength(float rodOneLength) {
    	this->rodOneLength = rodOneLength;
    }


    float getRodTwoLength() {
    	return this->rodTwoLength;
    }
    void setRodTwoLength(float rodTwoLength) {
    	this->rodTwoLength = rodTwoLength;
    }


    float getMassOne() {
    	return this->massOne;
    }
    void setMassOne(float massOne) {
    	this->massOne = massOne;
    }


    float getMassTwo() {
    	return this->massTwo;
    }
    void setMassTwo(float massTwo) {
    	this->massTwo = massTwo;
    }


    float getVelocity1() {
    	return this->velocity1;
    }
    void setVelocity1(float velocity1) {
    	this->velocity1 = velocity1;
    }


    float getVelocity2() {
    	return this->velocity2;
    }
    void setVelocity2(float velocity2) {
    	this->velocity2 = velocity2;
    }


    float getAcc1() {
    	return this->acc1;
    }
    void setAcc1(float acc1) {
    	this->acc1 = acc1;
    }


    float getAcc2() {
    	return this->acc2;
    }
    void setAcc2(float acc2) {
    	this->acc2 = acc2;
    }


    float getAngle1() {
    	return this->angle1;
    }
    void setAngle1(float angle1) {
    	this->angle1 = angle1;
    }


    float getAngle2() {
    	return this->angle2;
    }
    void setAngle2(float angle2) {
    	this->angle2 = angle2;
    }

    ci::Color getRodOneColor() {
    	return this->rodOneColor;
    }
    void setRodOneColor(ci::Color & rodOneColor) {
    	this->rodOneColor = rodOneColor;
    }


    ci::Color getRodTwoColor() {
    	return this->rodTwoColor;
    }
    void setRodTwoColor(ci::Color & rodTwoColor) {
    	this->rodTwoColor = rodTwoColor;
    }


    ci::Color getBallOneColor() {
    	return this->ballOneColor;
    }
    void setBallOneColor(ci::Color & ballOneColor) {
    	this->ballOneColor = ballOneColor;
    }


    ci::Color getBallTwoColor() {
    	return this->ballTwoColor;
    }
    void setBallTwoColor(ci::Color & ballTwoColor) {
    	this->ballTwoColor = ballTwoColor;
    }


    ci::Color getTraceColor() {
    	return this->traceColor;
    }
    void setTraceColor(ci::Color & traceColor) {
    	this->traceColor = traceColor;
    }
};



#endif