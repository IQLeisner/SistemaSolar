#pragma once
#include <ofVec2f.h>
#include <time.h>

class Asteroide {
public:

	int massa = 1;
	ofVec2f p_pos;
	ofVec2f velo;

	Asteroide(int m, ofVec2f pos, ofVec2f vel) {
		massa = m;
		p_pos = pos;
		velo = vel;
	}

	void SetPos(ofVec2f g1, ofVec2f g2, ofVec2f g3) {
		velo.normalize();
		g1 = -g1.normalize()*0.001;
		g2 = -g2.normalize()*0.001;
		g3 = -g3.normalize()*0.001;
		p_pos += velo += g1 += g2 += g3;
	}

	ofVec2f GetPos() {
		return p_pos;
	}
};