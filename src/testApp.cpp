#include "testApp.h"
#include "Card.h"
#include "ofxTweenzor.h"

vector<Card> digit0;
vector<Card> digit1;
vector<Card> digit2;
vector<Card> digit3;
vector<Card> digit4;
vector<Card> digit5;
int one[7] = {180,180,180,180,180,180,180};
int two[7] = {90,180,270,270,90,270,0};
int three[7] = {90,180,270,90,90,180,270};
int four[7] = {180,270,0,0,90,180,90};
int five[7] = {270,0,90,270,180,180,270};
int six[7] = {90,270,0,90,270,0,180};
int seven[7] = {180,180,90,90,180,180,180};
int eight[7] = {0,90,180,270,0,270,180};
int nine[7] = {90,180,270,0,180,90,180};
int zero[7] = {180,90,0,0,180,0,270};
int* placements[10];
int value0, value1, value2, value3, value4, value5;
int lastValue0, lastValue1, lastValue2, lastValue3, lastValue4, lastValue5;
//--------------------------------------------------------------
void testApp::setup(){
  Tweenzor::init();
  placements[0] = zero;
  placements[1] = one;
  placements[2] = two;
  placements[3] = three;
  placements[4] = four;
  placements[5] = five;
  placements[6] = six;
  placements[7] = seven;
  placements[8] = eight;
  placements[9] = nine;

  value0 = value1 = value2 = value3 = value4 = value5 = -1;
  lastValue0 = lastValue1 = lastValue2 = lastValue3 = lastValue4 = lastValue5 = -1;

  digit0.resize(7);
  int width = 100;
  int height = 80;
  digit0[0].set(100,100,width,height);
  digit0[0].baseColor.set(ofColor::black);
  digit0[0].stripeColor.set(ofColor::black);
  digit0[1].set(100,100,width,height);
  digit0[1].baseColor.set(ofColor::red);
  digit0[1].stripeColor.set(ofColor::black);
  digit0[2].set(100,100,width,height);
  digit0[2].baseColor.set(ofColor::green);
  digit0[2].stripeColor.set(ofColor::black);
  digit0[3].set(100,100,width,height);
  digit0[3].baseColor.set(ofColor::blue);
  digit0[3].stripeColor.set(ofColor::black);
  digit0[4].set(100,100+width,width,height);
  digit0[4].baseColor.set(ofColor::blue);
  digit0[4].stripeColor.set(ofColor::black);
  digit0[5].set(100,100+width,width,height);
  digit0[5].baseColor.set(ofColor::green);
  digit0[5].stripeColor.set(ofColor::black);
  digit0[6].set(100,100+width,width,height);
  digit0[6].baseColor.set(ofColor::red);
  digit0[6].stripeColor.set(ofColor::black);

  digit1.resize(7);
  digit1[0].set(100+width+2*(width-height),100,width,height);
  digit1[0].baseColor.set(ofColor::black);
  digit1[0].stripeColor.set(ofColor::black);
  digit1[1].set(100+width+2*(width-height),100,width,height);
  digit1[1].baseColor.set(ofColor::red);
  digit1[1].stripeColor.set(ofColor::black);
  digit1[2].set(100+width+2*(width-height),100,width,height);
  digit1[2].baseColor.set(ofColor::blue);
  digit1[2].stripeColor.set(ofColor::black);
  digit1[3].set(100+width+2*(width-height),100,width,height);
  digit1[3].baseColor.set(ofColor::green);
  digit1[3].stripeColor.set(ofColor::black);
  digit1[4].set(100+width+2*(width-height),100+width,width,height);
  digit1[4].baseColor.set(ofColor::blue);
  digit1[4].stripeColor.set(ofColor::black);
  digit1[5].set(100+width+2*(width-height),100+width,width,height);
  digit1[5].baseColor.set(ofColor::green);
  digit1[5].stripeColor.set(ofColor::black);
  digit1[6].set(100+width+2*(width-height),100+width,width,height);
  digit1[6].baseColor.set(ofColor::red);
  digit1[6].stripeColor.set(ofColor::black);

  digit2.resize(7);
  digit2[0].set(100+100+2*(width+2*(width-height)),100,width,height);
  digit2[0].baseColor.set(ofColor::black);
  digit2[0].stripeColor.set(ofColor::black);
  digit2[1].set(100+100+2*(width+2*(width-height)),100,width,height);
  digit2[1].baseColor.set(ofColor::red);
  digit2[1].stripeColor.set(ofColor::black);
  digit2[2].set(100+100+2*(width+2*(width-height)),100,width,height);
  digit2[2].baseColor.set(ofColor::blue);
  digit2[2].stripeColor.set(ofColor::black);
  digit2[3].set(100+100+2*(width+2*(width-height)),100,width,height);
  digit2[3].baseColor.set(ofColor::green);
  digit2[3].stripeColor.set(ofColor::black);
  digit2[4].set(100+100+2*(width+2*(width-height)),100+width,width,height);
  digit2[4].baseColor.set(ofColor::red);
  digit2[4].stripeColor.set(ofColor::black);
  digit2[5].set(100+100+2*(width+2*(width-height)),100+width,width,height);
  digit2[5].baseColor.set(ofColor::green);
  digit2[5].stripeColor.set(ofColor::black);
  digit2[6].set(100+100+2*(width+2*(width-height)),100+width,width,height);
  digit2[6].baseColor.set(ofColor::blue);
  digit2[6].stripeColor.set(ofColor::black);

  digit3.resize(7);
  digit3[0].set(100+100+3*(width+2*(width-height)),100,width,height);
  digit3[0].baseColor.set(ofColor::black);
  digit3[0].stripeColor.set(ofColor::black);
  digit3[1].set(100+100+3*(width+2*(width-height)),100,width,height);
  digit3[1].baseColor.set(ofColor::blue);
  digit3[1].stripeColor.set(ofColor::black);
  digit3[2].set(100+100+3*(width+2*(width-height)),100,width,height);
  digit3[2].baseColor.set(ofColor::green);
  digit3[2].stripeColor.set(ofColor::black);
  digit3[3].set(100+100+3*(width+2*(width-height)),100,width,height);
  digit3[3].baseColor.set(ofColor::red);
  digit3[3].stripeColor.set(ofColor::black);
  digit3[4].set(100+100+3*(width+2*(width-height)),100+width,width,height);
  digit3[4].baseColor.set(ofColor::red);
  digit3[4].stripeColor.set(ofColor::black);
  digit3[5].set(100+100+3*(width+2*(width-height)),100+width,width,height);
  digit3[5].baseColor.set(ofColor::green);
  digit3[5].stripeColor.set(ofColor::black);
  digit3[6].set(100+100+3*(width+2*(width-height)),100+width,width,height);
  digit3[6].baseColor.set(ofColor::blue);
  digit3[6].stripeColor.set(ofColor::black);

  digit4.resize(7);
  digit4[0].set(100+100+100+4*(width+2*(width-height)),100,width,height);
  digit4[0].baseColor.set(ofColor::black);
  digit4[0].stripeColor.set(ofColor::black);
  digit4[1].set(100+100+100+4*(width+2*(width-height)),100,width,height);
  digit4[1].baseColor.set(ofColor::green);
  digit4[1].stripeColor.set(ofColor::black);
  digit4[2].set(100+100+100+4*(width+2*(width-height)),100,width,height);
  digit4[2].baseColor.set(ofColor::blue);
  digit4[2].stripeColor.set(ofColor::black);
  digit4[3].set(100+100+100+4*(width+2*(width-height)),100,width,height);
  digit4[3].baseColor.set(ofColor::red);
  digit4[3].stripeColor.set(ofColor::black);
  digit4[4].set(100+100+100+4*(width+2*(width-height)),100+width,width,height);
  digit4[4].baseColor.set(ofColor::red);
  digit4[4].stripeColor.set(ofColor::black);
  digit4[5].set(100+100+100+4*(width+2*(width-height)),100+width,width,height);
  digit4[5].baseColor.set(ofColor::blue);
  digit4[5].stripeColor.set(ofColor::black);
  digit4[6].set(100+100+100+4*(width+2*(width-height)),100+width,width,height);
  digit4[6].baseColor.set(ofColor::green);
  digit4[6].stripeColor.set(ofColor::black);

  digit5.resize(7);
  digit5[0].set(100+100+100+5*(width+2*(width-height)),100,width,height);
  digit5[0].baseColor.set(ofColor::black);
  digit5[0].stripeColor.set(ofColor::black);
  digit5[1].set(100+100+100+5*(width+2*(width-height)),100,width,height);
  digit5[1].baseColor.set(ofColor::red);
  digit5[1].stripeColor.set(ofColor::black);
  digit5[2].set(100+100+100+5*(width+2*(width-height)),100,width,height);
  digit5[2].baseColor.set(ofColor::green);
  digit5[2].stripeColor.set(ofColor::black);
  digit5[3].set(100+100+100+5*(width+2*(width-height)),100,width,height);
  digit5[3].baseColor.set(ofColor::blue);
  digit5[3].stripeColor.set(ofColor::black);
  digit5[4].set(100+100+100+5*(width+2*(width-height)),100+width,width,height);
  digit5[4].baseColor.set(ofColor::red);
  digit5[4].stripeColor.set(ofColor::black);
  digit5[5].set(100+100+100+5*(width+2*(width-height)),100+width,width,height);
  digit5[5].baseColor.set(ofColor::blue);
  digit5[5].stripeColor.set(ofColor::black);
  digit5[6].set(100+100+100+5*(width+2*(width-height)),100+width,width,height);
  digit5[6].baseColor.set(ofColor::green);
  digit5[6].stripeColor.set(ofColor::black);

}

void testApp::goToNumber(vector<Card>* digit, int* placement, float duration){
  for (int i =0; i < 7; i++){
    Tweenzor::add(&(*(digit))[i].angle, (*(digit))[i].angle, placement[i], 0.f, duration);
  }
}

//--------------------------------------------------------------
void testApp::update(){
  Tweenzor::update( ofGetElapsedTimeMillis() );
  //digit0[0].angle += 0.1;
    value0 = ofGetHours()/10;
    value1 = ofGetHours()%10;
    value2 = ofGetMinutes()/10;
    value3 = ofGetMinutes()%10;
    value4 = ofGetSeconds()/10;
    value5 = ofGetSeconds()%10;
    if (value0 != lastValue0)
      goToNumber(&digit0,placements[value0],10);
    if (value1 != lastValue1)
      goToNumber(&digit1,placements[value1],5);
    if (value2 != lastValue2)
      goToNumber(&digit2,placements[value2],4);
    if (value3 != lastValue3)
      goToNumber(&digit3,placements[value3],2);
    if (value4 != lastValue4)
      goToNumber(&digit4,placements[value4],0.8);
    if (value5 != lastValue5)
      goToNumber(&digit5,placements[value5],0.8);
    lastValue0 = ofGetHours()/10;
    lastValue1 = ofGetHours()%10;
    lastValue2 = ofGetMinutes()/10;
    lastValue3 = ofGetMinutes()%10;
    lastValue4 = ofGetSeconds()/10;
    lastValue5 = ofGetSeconds()%10;



}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackgroundGradient(ofColor::white, ofColor::gray);
  for (int i =0; i < 7; i++){
    digit0[i].draw();
    digit1[i].draw();
    digit2[i].draw();
    digit3[i].draw();
    digit4[i].draw();
    digit5[i].draw();
  }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if (key == 'a' || key == '1'){
    goToNumber(&digit0,one);
  }
  if (key == 'z' || key == '2'){
    goToNumber(&digit0,two);
  }
  if (key == 'e' || key == '3'){
    goToNumber(&digit0,three);
  }
  if (key == 'r' || key == '4'){
    goToNumber(&digit0,four);
  }
  if (key == 't' || key == '5'){
    goToNumber(&digit0,five);
  }
  if (key == 'y' || key == '6'){
    goToNumber(&digit0,six);
  }
  if (key == 'u' || key == '7'){
    goToNumber(&digit0,seven);
  }
  if (key == 'i' || key == '8'){
    goToNumber(&digit0,eight);
  }
  if (key == 'o' || key == '9'){
    goToNumber(&digit0,nine);
  }
  if (key == 'p' || key == '0'){
    goToNumber(&digit0,placements[0]);
  }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
