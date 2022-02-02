#include "MyApp.h"
#include "cinder/app/RendererGl.h"
int main(){
	cinder::app::RendererRef renderer(new ci::app::RendererGl); 
	cinder::app::AppMsw::main<MyApp>(renderer, "Double Pendulum");
	return 0;
}