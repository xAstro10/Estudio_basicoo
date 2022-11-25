#pragma once
using namespace System::Drawing;
class Persona {
private:
	int x, y; // ubicacion
	int dx, dy; // movimiento
	int idX, idY; // index x e y
	int width, height;
	char direction;
	int vida=3;
public:
	Persona(int w,int h){
		width = w;
		height = h;
		dx = dy = 10;
		x = 70;
		y = 70;
		idX = idY = 0;
		direction = 'S';
    }
	
	
	void Persona:: draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

	void move(Graphics^ g, char i) {
		switch (i)
		{
		case 'A':
			if (x > 0) {
				idY = 1;
				x -= dx;
				direction = 'A';
			}
			break;
		case 'D':
			if (x + width*1.0 < g->VisibleClipBounds.Width) {
				idY = 2;
				x += dx;
				direction = 'D';
			}
			break;
		case 'W':
			if (y > 0) {
				idY = 3;
				y -= dy;
				direction = 'W';
			}
			break;
		case 'S':
			if (y + height*1.0 < g->VisibleClipBounds.Height) {
				idY = 0;
				y += dy;
				direction = 'S';
			}
			break;
		}
		idX++;
		if (idX > 3) idX = 0;
	}
	char getDirection() { return direction; }
	int getX() { return x; }
	int getY() { return y; }
	void bajarVida() {
		vida--;
	}
	void Reset() {
		x = 70;
		y = 70;
		System::Threading::Thread::Sleep(10);
	};
	
};
