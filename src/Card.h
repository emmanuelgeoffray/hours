#pragma once

#include "ofMain.h"

class Card : public ofRectangle{

	public:
		void draw(){
      ofPushMatrix();
      ofTranslate(x,y);
      ofSetColor(ofColor::white);
      ofTranslate(height/2 + (width-height),height/2);
      ofRotate(angle);
      ofTranslate(-(height/2 + (width-height)),-height/2);
      ofSetColor(stripeColor);
      ofRect(0,0,width,height);
      ofSetColor(baseColor);
      ofRect(width-height,0,height,height);
      ofPopMatrix();
    }

    float angle;
    ofColor baseColor;
    ofColor stripeColor;
		
};
