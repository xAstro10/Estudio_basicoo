#pragma once
#include <iostream>
using namespace System::Drawing;

class Bullet {
private:
	int x, y;
	int dx, dy;
	int width, height;
	char direction;
	bool visibility;

public:
	Bullet(int x, int y, int w, int h, char d) {
		width = w;
		height = h;
		direction = d;
		dx = dy = 30;
		this->x = x;
		this->y = y;
		visibility = true;
	}
	~Bullet() {}
	void draw(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.05, height * 0.05);
	}

	void move(Graphics^ g)
	{
		if (direction == 'S' && y + height * 0.05 <= g->VisibleClipBounds.Height) {
			y += dy;
		}
		if (direction == 'W' && y >= 0) {
			y -= dy;
		}
		if (direction == 'A' && x >= 0) {
			x -= dx;
		}
		if (direction == 'D' && x + width * 0.05 <= g->VisibleClipBounds.Width) {
			x += dx;
		}


	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.05, height * 0.05);
	}
	int getX() { return x; }
	int getXWidth() { return x + width * 0.03; }
	int getY() { return y; }
	int getYHeight() { return y + height * 0.03; }

	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }

};
