class Enviroment{
private:
    static float gravity;
    static float damping;  // 1.0 : no damping , 0.0 : maximum damping


public:
    static float getGravity() {
    	return Enviroment::gravity;
    }
    static void setGravity(float gravity = 0.9F) {
    	Enviroment::gravity = gravity;
    }


    static float getDamping() {
    	return Enviroment::damping;
    }
    static void setDamping(float damping = 1.0F) {
    	Enviroment::damping = damping;
    }
};

float Enviroment::gravity = 0.9F;
float Enviroment::damping = 1.0F;