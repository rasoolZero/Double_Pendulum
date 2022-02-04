#ifndef ENVIROMENT_H
#define ENVIROMENT_H

class Enviroment{
private:
    static float gravity;
    static float damping;  // 1.0 : no damping , 0.0 : maximum damping


public:
    static float getGravity() {
    	return gravity;
    }
    static void setGravity(float _gravity = 0.9F) {
    	gravity = _gravity;
    }


    static float getDamping() {
    	return damping;
    }
    static void setDamping(float _damping = 1.0F) {
    	damping = _damping;
    }
};
#endif