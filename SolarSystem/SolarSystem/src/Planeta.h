#pragma once
#include <ofVec2f.h>

class Planeta {
public:
	int massa;
	void SetPos(ofVec2f pos, ofVec2f astro) {
		p_pos = pos+astro;
	}

	ofVec2f GetPos() {
		return p_pos;
	}

private:
	ofVec2f p_pos = ofVec2f(500, 500);
};

