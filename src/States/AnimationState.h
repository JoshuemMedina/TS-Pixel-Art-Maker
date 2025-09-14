#include "State.h"

class AnimationState : public State { 
    private:
        // Asset Load
        ofImage animation;

        // Animation Logic
        int x = 0;
        int frameWidth = 200;
        int imageWidth = 400;
        int frameCount = 16;

        bool doAnimation = true;

    public:
        AnimationState();
        ~AnimationState();
        
        void update();
        void draw();
        void reset();
        void keyPressed(int key);
		void keyReleased(int key);
        void mousePressed(int x, int y, int button);

        void updateSettings();
};  