#include "MyForm1.h"
using namespace SpriteHero;
using namespace System::Windows::Forms;
using namespace System;

int main() {
	
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm1());
	return 0;

}
