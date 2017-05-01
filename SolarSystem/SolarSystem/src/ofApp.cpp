#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	srand(::time(NULL));
	terra->massa = 5;
	lua->massa = 1;
}

//--------------------------------------------------------------
void ofApp::update() {

	angle1 += ofDegToRad(72 * ofGetLastFrameTime());

	if (angle1 >= 2 * PI)
		angle1 = 0;

	angle2 += ofDegToRad(360 * ofGetLastFrameTime());

	if (angle2 >= 2 * PI)
		angle2 = 0;


	orbit1 = ofVec2f(cos(angle1) * 200, sin(angle1) * 200);
	orbit2 = ofVec2f(cos(angle2) * 50, sin(angle2) * 50);

	terra->SetPos(orbit1, ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2));
	lua->SetPos(orbit2, terra->GetPos());

	if (asterTela == false) {
		int ran = (rand() % 600) + 200;
		if (ran > 500) {
			ran2 = (rand() % 25);
		}
		else
			ran2 = -(rand() % 25);
		aster = new Asteroide(10, ofVec2f(0, ran), ofVec2f(100, ran2));
		asterTela = true;
		timer = 0;
	}

	if (asterTela == true) {
		dist1y = aster->GetPos().y - ofGetWindowHeight()/2;
		dist2y = aster->GetPos().y - terra->GetPos().y;
		dist3y = aster->GetPos().y - lua->GetPos().y;

		ofVec2f g1 = Gravity(dist1y, 100, aster->massa);
		ofVec2f g2 = Gravity(dist2y, terra->massa, aster->massa);
		ofVec2f g3 = Gravity(dist3y, lua->massa, aster->massa);

		aster->SetPos(g1, g2, g3);
	}

	if (aster->GetPos().x > ofGetWindowWidth() ||
		aster->GetPos().x < 0 ||
		aster->GetPos().y > ofGetWindowHeight() ||
		aster->GetPos().y < 0) {
		asterTela = false;
	}

	timer++;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(220, 220, 0);
	ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 50);
	ofSetColor(20, 20, 200);
	ofDrawCircle(terra->GetPos(), 20);
	ofSetColor(255, 255, 255);
	ofDrawCircle(lua->GetPos(), 10);

	if (asterTela == true){
		ofSetColor(255, 0, 0);
		ofDrawCircle(aster->GetPos(), 10);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
