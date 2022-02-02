#ifndef DOUBLEPENDULUM_H
#define DOUBLEPENDULUM_H
#include "cinder/gl/gl.h"
#include "cinder/CinderGlm.h"

class DoublePendulum{
private:
    float rodOneLength=100;
    float rodTwoLength=100;
    float massOne=10;
    float massTwo=10;
    float angle1=glm::half_pi<float>();
    float angle2=glm::quarter_pi<float>();
    ci::vec2 ball1,ball2;
    void updateBall1();
    void updateBall2();
    void drawPart1();
    void drawPart2();

public:
    void update();
    void draw();
};



#endif