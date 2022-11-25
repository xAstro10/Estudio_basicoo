#pragma once
#include "Persona.h"
#include "Controller.h"
#include <ctime>

namespace spriteHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for frmMain
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	
		MyForm(int n)
		{
			InitializeComponent();
			srand(time(NULL));
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpHero = gcnew Bitmap("ash_sprite.png");
			bmpEnemy = gcnew Bitmap("grimer.png");
			bmpMap = gcnew Bitmap("FondoPokemon.jpg");
			bmpBullet = gcnew Bitmap("inyeccion1.png");
			hero = new Persona(bmpHero->Width / 4, bmpHero->Height / 4);
			controller = new Controller(n, false);
			controller->createEnemies(bmpEnemy->Width / 4, bmpEnemy->Height / 4);
			

		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pnlCanvas;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpHero;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpMap;
		Bitmap^ bmpBullet;
		Persona* hero;
		Controller* controller;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pnlCanvas
			// 
			this->pnlCanvas->Location = System::Drawing::Point(12, 12);
			this->pnlCanvas->Name = L"pnlCanvas";
			this->pnlCanvas->Size = System::Drawing::Size(480, 487);
			this->pnlCanvas->TabIndex = 0;
			this->pnlCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pnlCanvas_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 506);
			this->Controls->Add(this->pnlCanvas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::presionar);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//collision
		controller->collision(buffer->Graphics);

		//move para el personaje se hara con teclas
		controller->moveEveryThing(buffer->Graphics);
		//draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 1.0, bmpMap->Height * 1.0);
		controller->drawEveryThing(buffer->Graphics, bmpEnemy, bmpBullet);
		hero->draw(buffer->Graphics, bmpHero);
		
		/*for (int i = 0; i < controller->enemies.size(); i++)
		{
			if (hero->getX() == controller->enemies[i]->getX() && hero->getY() == controller->enemies[i]->getY())
			{
				hero->bajarVida();
				hero->Reset();
			}
		}
		*/

		//Render
		/*buffer->Render(g);*/

	}

	private: System::Void presionar(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			hero->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			hero->move(buffer->Graphics, 'D'); break;
		case Keys::S:
			hero->move(buffer->Graphics, 'S'); break;
		case Keys::W:
			hero->move(buffer->Graphics, 'W'); break;
		case Keys::Space:
			Bullet* b = new Bullet(hero->getX(), hero->getY(), bmpBullet->Width, bmpBullet->Height,hero->getDirection());
			controller->addBullet(b);

		}

	}
	private: System::Void pnlCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
