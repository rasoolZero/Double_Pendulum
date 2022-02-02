#ifndef MYAPP_H
#define MYAPP_H
#include "cinder/app/App.h"
#include "DoublePendulum.h"
class MyApp : public ci::app::App{
public:
    void setup() override;
    void update() override;
    void draw() override;
private:
    DoublePendulum dp;
};




#endif