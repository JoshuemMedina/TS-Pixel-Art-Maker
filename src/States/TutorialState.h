#include "State.h"

class TutorialState : public State { 
    private:
        // Asset Load
        ofImage background;
        
        // Buttons
        Button* returnButton;

        // Sizes
        int margin = 100;
        
    public:
        TutorialState();
        ~TutorialState();
        
        void update();
        void draw();
        void reset();
        void keyPressed(int key);
		void keyReleased(int key);
        void mousePressed(int x, int y, int button);
};  