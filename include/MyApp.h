#ifndef MYAPP_H
#define MYAPP_H
#include "cinder/app/App.h"
#include "DoublePendulum.h"
#include "cinder/params/Params.h"
class MyApp : public ci::app::App{
public:
    void setup() override;
    void update() override;
    void draw() override;
private:
    DoublePendulum dp;
    float startingAngle1,startingAngle2;
    ci::params::InterfaceGlRef interface;
    void setupParams();
    void setupPartOneParams();
    void setupPartTwoParams();
    void setupEnviromentParams();
    void setupColorParams();
    void setupControls();
};




#endif