#ifndef DOUBLEPENDULUM_H
#define DOUBLEPENDULUM_H

class DoublePendulum{
private:
    float rodOneLength=100;
    float rodTwoLength=100;
    float massOne=10;
    float massTwo=10;

public:
    void update();
    void draw();
};



#endif