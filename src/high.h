#pragma once

#include "ofMain.h"

class high : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

                ofShader xhighlight;
                ofImage img;
                ofFbo fbo;
};
