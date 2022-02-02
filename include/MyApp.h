#ifndef MYAPP_H
#define MYAPP_H
#include "cinder/app/App.h"
class MyApp : public ci::app::App{
public:
    void setup() override;
    void update() override;
    void draw() override;
private:

};




#endif