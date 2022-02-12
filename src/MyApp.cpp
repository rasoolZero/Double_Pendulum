#include "MyApp.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"
#include "Enviroment.h"
void MyApp::setup(){
    ci::app::App::setFullScreen(true);
    ci::app::App::setFrameRate(60.0F);
    Enviroment::setGravity(1.0F);
    setupParams();
}

void MyApp::setupParams(){
    interface = ci::params::InterfaceGl::create("Double Pendulum",
                {ci::app::getWindowWidth()/2,ci::app::getWindowHeight()});
    interface->minimize();
    interface->addText("Part one");
    setupPartOneParams();
    interface->addSeparator();
    interface->addText("Part two");
    setupPartTwoParams();
    interface->addSeparator();
    interface->addText("Enviroment");
    setupEnviromentParams();
    interface->addSeparator();
    interface->addText("Color");
    setupColorParams();
}

void MyApp::setupPartOneParams(){
    std::function<void (float)> massSetter = std::bind(&DoublePendulum::setMassOne,&dp,std::placeholders::_1);
    std::function<float()> massGetter = std::bind(&DoublePendulum::getMassOne,&dp);
    std::function<void (float)> rodLengthSetter = std::bind(&DoublePendulum::setRodOneLength,&dp,std::placeholders::_1);
    std::function<float()> rodLengthGetter = std::bind(&DoublePendulum::getRodOneLength,&dp);
    auto & mass = interface->addParam<float>("Mass One",massSetter,massGetter);
    auto & rodLength = interface->addParam<float>("Rod Length One",rodLengthSetter,rodLengthGetter);
    mass.max(100.0F);
    rodLength.max(300.0F);
    mass.min(2.0F);
    rodLength.min(10.0F);
}

void MyApp::setupPartTwoParams(){
    std::function<void (float)> massSetter = std::bind(&DoublePendulum::setMassTwo,&dp,std::placeholders::_1);
    std::function<float()> massGetter = std::bind(&DoublePendulum::getMassTwo,&dp);
    std::function<void (float)> rodLengthSetter = std::bind(&DoublePendulum::setRodTwoLength,&dp,std::placeholders::_1);
    std::function<float()> rodLengthGetter = std::bind(&DoublePendulum::getRodTwoLength,&dp);
    auto & mass = interface->addParam<float>("Mass Two",massSetter,massGetter);
    auto & rodLength = interface->addParam<float>("Rod Length Two",rodLengthSetter,rodLengthGetter);
    mass.max(100.0F);
    mass.min(2.0F);
    rodLength.max(300.0F);
    rodLength.min(10.0F);
}

void MyApp::setupEnviromentParams(){
    std::function<void (float)> gravitySetter = std::bind(&Enviroment::setGravity,std::placeholders::_1);
    std::function<float ()> gravityGetter = std::bind(&Enviroment::getGravity);
    std::function<void (float)> dampingSetter = std::bind(&Enviroment::setDamping,std::placeholders::_1);
    std::function<float ()> dampingGetter = std::bind(&Enviroment::getDamping);
    auto & gravity = interface->addParam<float>("Gravity",gravitySetter,gravityGetter);
    auto & damping = interface->addParam<float>("Damping",dampingSetter,dampingGetter);
    gravity.max(1.0F);
    gravity.min(0.0F);
    gravity.precision(1);
    gravity.step(0.1F);
    damping.max(1.0F);
    damping.min(0.0F);
    damping.precision(1);
    damping.step(0.1F);
}

void MyApp::setupColorParams(){
    std::function<void (ci::Color &)> rodOneColorSetter = std::bind(&DoublePendulum::setRodOneColor,&dp,std::placeholders::_1);
    std::function<ci::Color ()> rodOneColorGetter = std::bind(&DoublePendulum::getRodOneColor,&dp);
    std::function<void (ci::Color &)> rodTwoColorSetter = std::bind(&DoublePendulum::setRodTwoColor,&dp,std::placeholders::_1);
    std::function<ci::Color ()> rodTwoColorGetter = std::bind(&DoublePendulum::getRodTwoColor,&dp);
    
    std::function<void (ci::Color &)> ballOneColorSetter = std::bind(&DoublePendulum::setBallOneColor,&dp,std::placeholders::_1);
    std::function<ci::Color ()> ballOneColorGetter = std::bind(&DoublePendulum::getBallOneColor,&dp);
    std::function<void (ci::Color &)> ballTwoColorSetter = std::bind(&DoublePendulum::setBallTwoColor,&dp,std::placeholders::_1);
    std::function<ci::Color ()> ballTwoColorGetter = std::bind(&DoublePendulum::getBallTwoColor,&dp);
    
    std::function<void (ci::Color &)> traceColorSetter = std::bind(&DoublePendulum::setTraceColor,&dp,std::placeholders::_1);
    std::function<ci::Color ()> traceColorGetter = std::bind(&DoublePendulum::getTraceColor,&dp);

    interface->addParam<ci::Color>("Rod 1 Color",rodOneColorSetter,rodOneColorGetter);
    interface->addParam<ci::Color>("Ball 1 Color",ballOneColorSetter,ballOneColorGetter);
    interface->addParam<ci::Color>("Rod 2 Color",rodTwoColorSetter,rodTwoColorGetter);
    interface->addParam<ci::Color>("Ball 2 Color",ballTwoColorSetter,ballTwoColorGetter);
    interface->addParam<ci::Color>("Trace Color",traceColorSetter,traceColorGetter);
}

void MyApp::update(){
    dp.update();
}

void MyApp::draw(){
    ci::gl::clear();
    ci::gl::pushModelMatrix();
    ci::gl::translate(ci::app::getWindowWidth()/2.0F,ci::app::getWindowHeight()/4.0F);
    dp.draw();
    ci::gl::popModelMatrix();
    interface->draw();
}