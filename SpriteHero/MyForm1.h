#pragma once
#include "MyForm.h"
#include "MyForm2.h"

namespace SpriteHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
}
	/// <summary>
	/// Summary for MyForm1
	/// </summary>
public ref class MyForm1 : public System::Windows::Forms::Form
{
public:
	int n=5;
	MyForm1(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MyForm1()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::Button^ button1;
protected:
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;



private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(312, 136);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(113, 31);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Nivel 1";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(312, 173);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(113, 34);
		this->button2->TabIndex = 1;
		this->button2->Text = L"Nivel 2";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(340, 224);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(60, 13);
		this->label1->TabIndex = 2;
		this->label1->Text = L"Integrantes";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(323, 240);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(91, 13);
		this->label2->TabIndex = 3;
		this->label2->Text = L"-Sebastian Alvildo";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(339, 253);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(61, 13);
		this->label3->TabIndex = 4;
		this->label3->Text = L"-Jose Salas";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(309, 88);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(122, 13);
		this->label4->TabIndex = 5;
		this->label4->Text = L"¿Que nivel desea jugar\?";
		this->label4->Click += gcnew System::EventHandler(this, &MyForm1::label4_Click);
		// 
		// MyForm1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(678, 348);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->Name = L"MyForm1";
		this->Text = L"MyForm1";
		this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

}

private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    spriteHero::MyForm^ dif1 = gcnew spriteHero::MyForm(4);
	dif1->Show();

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	spriteHero::MyForm^ dif2 = gcnew spriteHero::MyForm(10);
	dif2->Show();
	
};
};
