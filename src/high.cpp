#include "high.h"

float state = 1.0;
int w,h;
//--------------------------------------------------------------
void high::setup() {
   xhighlight.load("highlight_stroke.vertex","highlight_stroke.fragment");
   img.loadImage("model.jpg");
   w=ofGetScreenWidth();
   h=ofGetScreenHeight();
   fbo.allocate(w,h, GL_RGBA);
   fbo.begin();
   ofClear(255,255,255,0);
   fbo.end();
}

//--------------------------------------------------------------
void high::update() {
   ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void high::draw() {   
   xhighlight.begin();
     xhighlight.setUniformTexture("texture", img.getTextureReference(), 2);
     xhighlight.setUniform1f("param", state);
     xhighlight.setUniform1f("summs", ofMap(mouseX,0.0,w,0.0,30.0));
        fbo.draw(0,0);
     xhighlight.end();
}

void high::keyPressed(int key){
	if(key=='1')
		state=1.0;
	if(key=='2')
		state=2.0;
	if(key=='3')
		state=3.0;
}
