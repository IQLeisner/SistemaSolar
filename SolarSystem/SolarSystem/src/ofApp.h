#pragma once
#include "Planeta.h"
#include <math.h>
#include "ofMain.h"
#include <time.h>
#include <vector>
#include "Asteroide.cpp"


class ofApp : public ofBaseApp{

public:
		void setup();
		void update();
		void draw();

		float time;
		float angle1 = 0, angle2 = 0;
		ofVec2f orbit1, orbit2;

		int dist1y, dist2y, dist3y;

		Planeta* terra = new Planeta();
		Planeta* lua = new Planeta();
		
		int timer = 0;

		Asteroide* aster;
		int ran2 = 0;
		bool asterTela = false;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int Module(ofVec2f i, ofVec2f j) {
			int k = sqrt((i.x - j.x)*(i.x - j.x) + (i.y - j.y)*(i.y - j.y));
			return k;
		}

		ofVec2f Gravity(int dist, int m1, int m2) {
			if (dist == 0)
				dist = 1;
			int resulty = 2 * m1*m2 / dist*dist;
			if (dist < 0) {
				resulty = -resulty;
			}
			ofVec2f result = ofVec2f(0, resulty);
			return result;
		}
};
