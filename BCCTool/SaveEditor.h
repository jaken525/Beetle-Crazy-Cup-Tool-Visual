#pragma once
#include "saver.h"
#include <msclr\marshal_cppstd.h>

namespace BCCTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	namespace fs = std::filesystem;

	/// <summary>
	/// —водка дл€ SaveEditor
	/// </summary>
	public ref class SaveEditor : public System::Windows::Forms::Form
	{
	public:
		se::Saver^ save = gcnew se::Saver;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::CheckBox^ checkBox2;

	public:

	public:
		std::string* path;

		SaveEditor(std::string path)
		{
			InitializeComponent();

			this->path = new std::string{ path };
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SaveEditor()
		{
			if (components)
			{
				delete components;
			}

			delete path;
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::ComboBox^ modeComboBox;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label12;

	private: System::Windows::Forms::Label^ label14;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBox17;

	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::ComboBox^ comboBox7;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::ComboBox^ comboBox9;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::ComboBox^ comboBox8;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;


private: System::Windows::Forms::ComboBox^ comboBox11;
private: System::Windows::Forms::TextBox^ textBox22;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::ComboBox^ comboBox10;
private: System::Windows::Forms::TextBox^ textBox23;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Label^ label34;
private: System::Windows::Forms::TextBox^ textBox24;
private: System::Windows::Forms::Label^ label35;
private: System::Windows::Forms::GroupBox^ groupBox8;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::ComboBox^ comboBox12;
private: System::Windows::Forms::GroupBox^ groupBox9;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::GroupBox^ groupBox10;
private: System::Windows::Forms::ComboBox^ comboBox14;
private: System::Windows::Forms::ComboBox^ comboBox13;
private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::TextBox^ textBox25;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::TextBox^ textBox28;
private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::TextBox^ textBox27;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::TextBox^ textBox26;
private: System::Windows::Forms::Label^ label42;


private: System::Windows::Forms::Button^ button3;


private: System::Windows::Forms::GroupBox^ groupBox12;
private: System::Windows::Forms::Label^ label47;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::TextBox^ textBox31;
private: System::Windows::Forms::TextBox^ textBox32;
private: System::Windows::Forms::TextBox^ textBox33;
private: System::Windows::Forms::GroupBox^ groupBox11;


	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SaveEditor::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->modeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox14 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox12->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load profile";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SaveEditor::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(95, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Create new profile";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SaveEditor::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(208, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Profile Name: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(287, 15);
			this->textBox1->MaxLength = 15;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 20);
			this->textBox1->TabIndex = 4;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox6);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->textBox9);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(13, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 804);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Beetle Challenge Save";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->textBox24);
			this->groupBox6->Controls->Add(this->label35);
			this->groupBox6->Controls->Add(this->groupBox7);
			this->groupBox6->Controls->Add(this->button8);
			this->groupBox6->Controls->Add(this->textBox19);
			this->groupBox6->Controls->Add(this->label25);
			this->groupBox6->Controls->Add(this->textBox18);
			this->groupBox6->Controls->Add(this->label24);
			this->groupBox6->Controls->Add(this->textBox16);
			this->groupBox6->Controls->Add(this->label23);
			this->groupBox6->Controls->Add(this->comboBox6);
			this->groupBox6->Controls->Add(this->label22);
			this->groupBox6->Location = System::Drawing::Point(6, 496);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(327, 302);
			this->groupBox6->TabIndex = 20;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Player Cars";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(187, 124);
			this->textBox24->MaxLength = 2;
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(32, 20);
			this->textBox24->TabIndex = 36;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(7, 127);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(157, 13);
			this->label35->TabIndex = 35;
			this->label35->Text = L"Count Of Cars You Have in QR:";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->comboBox10);
			this->groupBox7->Controls->Add(this->textBox23);
			this->groupBox7->Controls->Add(this->label31);
			this->groupBox7->Controls->Add(this->label34);
			this->groupBox7->Controls->Add(this->comboBox11);
			this->groupBox7->Controls->Add(this->textBox22);
			this->groupBox7->Controls->Add(this->label32);
			this->groupBox7->Controls->Add(this->label33);
			this->groupBox7->Controls->Add(this->comboBox9);
			this->groupBox7->Controls->Add(this->textBox21);
			this->groupBox7->Controls->Add(this->label29);
			this->groupBox7->Controls->Add(this->label30);
			this->groupBox7->Controls->Add(this->comboBox8);
			this->groupBox7->Controls->Add(this->textBox20);
			this->groupBox7->Controls->Add(this->button9);
			this->groupBox7->Controls->Add(this->label27);
			this->groupBox7->Controls->Add(this->label26);
			this->groupBox7->Controls->Add(this->label28);
			this->groupBox7->Controls->Add(this->comboBox7);
			this->groupBox7->Location = System::Drawing::Point(6, 146);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(315, 150);
			this->groupBox7->TabIndex = 34;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Cars";
			// 
			// comboBox10
			// 
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Beetle", L"Rodster", L"Manx", L"Beetle Monster",
					L"Beetle Jump", L"Beetle Cross", L"Speedster", L"Karmann Jump", L"Buggy", L"Van", L"Karmann Monster", L"Towd", L"Thing", L"Speedster Jump",
					L"Baja", L"Pickup Van", L"New Beetle", L"Beetle Chafado"
			});
			this->comboBox10->Location = System::Drawing::Point(191, 94);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(111, 21);
			this->comboBox10->TabIndex = 47;
			this->comboBox10->Text = L"Unknown Car";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(104, 121);
			this->textBox23->MaxLength = 1;
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(32, 20);
			this->textBox23->TabIndex = 46;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 124);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(89, 13);
			this->label31->TabIndex = 44;
			this->label31->Text = L"Bonus Car Color: ";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(142, 124);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(43, 13);
			this->label34->TabIndex = 45;
			this->label34->Text = L"Car ID: ";
			// 
			// comboBox11
			// 
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Beetle", L"Rodster", L"Manx", L"Beetle Monster",
					L"Beetle Jump", L"Beetle Cross", L"Speedster", L"Karmann Jump", L"Buggy", L"Van", L"Karmann Monster", L"Towd", L"Thing", L"Speedster Jump",
					L"Baja", L"Pickup Van", L"New Beetle", L"Beetle Chafado"
			});
			this->comboBox11->Location = System::Drawing::Point(191, 120);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(111, 21);
			this->comboBox11->TabIndex = 43;
			this->comboBox11->Text = L"Unknown Car";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(104, 95);
			this->textBox22->MaxLength = 1;
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(32, 20);
			this->textBox22->TabIndex = 42;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(6, 98);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(75, 13);
			this->label32->TabIndex = 40;
			this->label32->Text = L"QR Car Color: ";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(142, 98);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(43, 13);
			this->label33->TabIndex = 41;
			this->label33->Text = L"Car ID: ";
			// 
			// comboBox9
			// 
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Beetle", L"Rodster", L"Manx", L"Beetle Monster",
					L"Beetle Jump", L"Beetle Cross", L"Speedster", L"Karmann Jump", L"Buggy", L"Van", L"Karmann Monster", L"Towd", L"Thing", L"Speedster Jump",
					L"Baja", L"Pickup Van", L"New Beetle", L"Beetle Chafado"
			});
			this->comboBox9->Location = System::Drawing::Point(191, 68);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(111, 21);
			this->comboBox9->TabIndex = 39;
			this->comboBox9->Text = L"Unknown Car";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(104, 69);
			this->textBox21->MaxLength = 1;
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(32, 20);
			this->textBox21->TabIndex = 38;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(6, 72);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(92, 13);
			this->label29->TabIndex = 36;
			this->label29->Text = L"Market Car Color: ";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(142, 72);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(43, 13);
			this->label30->TabIndex = 37;
			this->label30->Text = L"Car ID: ";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Beetle", L"Rodster", L"Manx", L"Beetle Monster",
					L"Beetle Jump", L"Beetle Cross", L"Speedster", L"Karmann Jump", L"Buggy", L"Van", L"Karmann Monster", L"Towd", L"Thing", L"Speedster Jump",
					L"Baja", L"Pickup Van", L"New Beetle", L"Beetle Chafado"
			});
			this->comboBox8->Location = System::Drawing::Point(191, 41);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(111, 21);
			this->comboBox8->TabIndex = 32;
			this->comboBox8->Text = L"Unknown Car";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(104, 41);
			this->textBox20->MaxLength = 1;
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(32, 20);
			this->textBox20->TabIndex = 31;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(255, 11);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(54, 23);
			this->button9->TabIndex = 35;
			this->button9->Text = L"Save";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &SaveEditor::button9_Click);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(6, 45);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(81, 13);
			this->label27->TabIndex = 29;
			this->label27->Text = L"Your Car Color: ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(6, 16);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(69, 13);
			this->label26->TabIndex = 34;
			this->label26->Text = L"Car Number: ";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(142, 45);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(43, 13);
			this->label28->TabIndex = 30;
			this->label28->Text = L"Car ID: ";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15"
			});
			this->comboBox7->Location = System::Drawing::Point(81, 13);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(64, 21);
			this->comboBox7->TabIndex = 35;
			this->comboBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox7_SelectedIndexChanged);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(267, 18);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(54, 23);
			this->button8->TabIndex = 29;
			this->button8->Text = L"Save";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &SaveEditor::button8_Click);
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(187, 98);
			this->textBox19->MaxLength = 2;
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(32, 20);
			this->textBox19->TabIndex = 33;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(7, 101);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(141, 13);
			this->label25->TabIndex = 32;
			this->label25->Text = L"Count Of Cars You Can Buy:";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(187, 72);
			this->textBox18->MaxLength = 2;
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(32, 20);
			this->textBox18->TabIndex = 31;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(7, 75);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(172, 13);
			this->label24->TabIndex = 30;
			this->label24->Text = L"Count Of Cars You Have In Bonus:";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(187, 46);
			this->textBox16->MaxLength = 2;
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(32, 20);
			this->textBox16->TabIndex = 29;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(7, 49);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(169, 13);
			this->label23->TabIndex = 26;
			this->label23->Text = L"Count Of Cars You Have In Mode:";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Speed", L"Monster", L"Cross", L"Jump", L"Buggy" });
			this->comboBox6->Location = System::Drawing::Point(49, 19);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(64, 21);
			this->comboBox6->TabIndex = 25;
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox6_SelectedIndexChanged);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(7, 22);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(37, 13);
			this->label22->TabIndex = 24;
			this->label22->Text = L"Mode:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBox2);
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->textBox13);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->textBox12);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->comboBox3);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->modeComboBox);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Location = System::Drawing::Point(6, 229);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(327, 261);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Mode Settings";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->comboBox5);
			this->groupBox5->Controls->Add(this->textBox17);
			this->groupBox5->Controls->Add(this->label21);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Controls->Add(this->button7);
			this->groupBox5->Controls->Add(this->comboBox4);
			this->groupBox5->Controls->Add(this->label19);
			this->groupBox5->Location = System::Drawing::Point(6, 180);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(315, 75);
			this->groupBox5->TabIndex = 23;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Opponent Cars";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
				L"Beetle", L"Rodster", L"Manx", L"Beetle Monster",
					L"Beetle Jump", L"Beetle Cross", L"Speedster", L"Karmann Jump", L"Buggy", L"Van", L"Karmann Monster", L"Towd", L"Thing", L"Speedster Jump",
					L"Baja", L"Pickup Van", L"New Beetle", L"Beetle Chafado"
			});
			this->comboBox5->Location = System::Drawing::Point(137, 43);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(111, 21);
			this->comboBox5->TabIndex = 28;
			this->comboBox5->Text = L"Unknown Car";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(50, 44);
			this->textBox17->MaxLength = 1;
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(32, 20);
			this->textBox17->TabIndex = 27;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(7, 47);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(37, 13);
			this->label21->TabIndex = 26;
			this->label21->Text = L"Color: ";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(88, 47);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(43, 13);
			this->label20->TabIndex = 26;
			this->label20->Text = L"Car ID: ";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(255, 15);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(54, 23);
			this->button7->TabIndex = 26;
			this->button7->Text = L"Save";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &SaveEditor::button7_Click);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"8", L"7", L"6", L"5", L"4", L"3", L"2", L"1" });
			this->comboBox4->Location = System::Drawing::Point(113, 17);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(39, 21);
			this->comboBox4->TabIndex = 24;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox4_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(7, 20);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(100, 13);
			this->label19->TabIndex = 0;
			this->label19->Text = L"Opponent Number: ";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->textBox15);
			this->groupBox4->Controls->Add(this->label18);
			this->groupBox4->Controls->Add(this->textBox14);
			this->groupBox4->Controls->Add(this->label17);
			this->groupBox4->Location = System::Drawing::Point(6, 124);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(315, 49);
			this->groupBox4->TabIndex = 22;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Map";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(255, 15);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(54, 23);
			this->button6->TabIndex = 23;
			this->button6->Text = L"Save";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &SaveEditor::button6_Click);
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(139, 17);
			this->textBox15->MaxLength = 1;
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(32, 20);
			this->textBox15->TabIndex = 25;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(83, 20);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(50, 13);
			this->label18->TabIndex = 24;
			this->label18->Text = L"Number: ";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(45, 17);
			this->textBox14->MaxLength = 1;
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(32, 20);
			this->textBox14->TabIndex = 23;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(7, 20);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(32, 13);
			this->label17->TabIndex = 0;
			this->label17->Text = L"Tag: ";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(267, 96);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(54, 23);
			this->button5->TabIndex = 20;
			this->button5->Text = L"Save";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &SaveEditor::button5_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(153, 70);
			this->textBox11->MaxLength = 10;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(168, 20);
			this->textBox11->TabIndex = 11;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(6, 73);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(141, 13);
			this->label16->TabIndex = 10;
			this->label16->Text = L"Money For Record Passing: ";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(181, 96);
			this->textBox13->MaxLength = 1;
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(32, 20);
			this->textBox13->TabIndex = 21;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(153, 44);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(168, 20);
			this->textBox10->TabIndex = 9;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(100, 96);
			this->textBox12->MaxLength = 1;
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(36, 20);
			this->textBox12->TabIndex = 20;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 47);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(132, 13);
			this->label15->TabIndex = 8;
			this->label15->Text = L"Money For Level Passing: ";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->comboBox3->Location = System::Drawing::Point(162, 17);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(39, 21);
			this->comboBox3->TabIndex = 3;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox3_SelectedIndexChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(119, 20);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(39, 13);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Level: ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(7, 99);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(92, 13);
			this->label13->TabIndex = 4;
			this->label13->Text = L"Count Of Racers: ";
			// 
			// modeComboBox
			// 
			this->modeComboBox->FormattingEnabled = true;
			this->modeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Monster", L"Cross", L"Speed", L"Buggy", L"Jump",
					L"WBC", L"Bonus"
			});
			this->modeComboBox->Location = System::Drawing::Point(49, 17);
			this->modeComboBox->Name = L"modeComboBox";
			this->modeComboBox->Size = System::Drawing::Size(64, 21);
			this->modeComboBox->TabIndex = 1;
			this->modeComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::modeComboBox_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(142, 99);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(36, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Laps: ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(7, 20);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Mode:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(234, 203);
			this->textBox9->MaxLength = 5;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(99, 20);
			this->textBox9->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(143, 206);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(85, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Count Of Saves:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(10, 205);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(127, 17);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"Open Final Challenge";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(70, 122);
			this->textBox5->MaxLength = 3;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(67, 20);
			this->textBox5->TabIndex = 9;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Location = System::Drawing::Point(6, 148);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(327, 48);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Jump Distance";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(249, 16);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(72, 23);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Save";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &SaveEditor::button4_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(133, 18);
			this->textBox8->MaxLength = 9;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(110, 20);
			this->textBox8->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 20);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Jump Level:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1", L"2", L"3", L"4", L"WBC", L"QR" });
			this->comboBox2->Location = System::Drawing::Point(76, 17);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(51, 21);
			this->comboBox2->TabIndex = 15;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox2_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 125);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Trials:";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(266, 122);
			this->textBox7->MaxLength = 3;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(67, 20);
			this->textBox7->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(148, 125);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(112, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Time Attack Seconds:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(267, 96);
			this->textBox6->MaxLength = 3;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(66, 20);
			this->textBox6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(148, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Open Bonuses:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(55, 96);
			this->textBox4->MaxLength = 9;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(82, 20);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(7, 99);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Points:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(96, 70);
			this->textBox3->MaxLength = 19;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(237, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Time and Date:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(96, 44);
			this->textBox2->MaxLength = 15;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(237, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Save Name:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->comboBox1->Location = System::Drawing::Point(96, 17);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(51, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Save Number: ";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &SaveEditor::timer1_Tick);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(631, 15);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(67, 23);
			this->button10->TabIndex = 8;
			this->button10->Text = L"Save File";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &SaveEditor::button10_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->comboBox12);
			this->groupBox8->Controls->Add(this->label36);
			this->groupBox8->Location = System::Drawing::Point(359, 43);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(339, 47);
			this->groupBox8->TabIndex = 9;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Championship Save";
			// 
			// comboBox12
			// 
			this->comboBox12->FormattingEnabled = true;
			this->comboBox12->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"1", L"2", L"3" });
			this->comboBox12->Location = System::Drawing::Point(119, 16);
			this->comboBox12->Name = L"comboBox12";
			this->comboBox12->Size = System::Drawing::Size(38, 21);
			this->comboBox12->TabIndex = 1;
			this->comboBox12->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox12_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(7, 20);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(105, 13);
			this->label36->TabIndex = 0;
			this->label36->Text = L"Past Championships:";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->groupBox12);
			this->groupBox9->Controls->Add(this->groupBox11);
			this->groupBox9->Controls->Add(this->button3);
			this->groupBox9->Controls->Add(this->textBox25);
			this->groupBox9->Controls->Add(this->label41);
			this->groupBox9->Controls->Add(this->groupBox10);
			this->groupBox9->Controls->Add(this->label38);
			this->groupBox9->Controls->Add(this->label37);
			this->groupBox9->Location = System::Drawing::Point(359, 97);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(339, 332);
			this->groupBox9->TabIndex = 10;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Records Save";
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->label47);
			this->groupBox12->Controls->Add(this->label48);
			this->groupBox12->Controls->Add(this->label49);
			this->groupBox12->Controls->Add(this->textBox31);
			this->groupBox12->Controls->Add(this->textBox32);
			this->groupBox12->Controls->Add(this->textBox33);
			this->groupBox12->Location = System::Drawing::Point(7, 225);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(327, 101);
			this->groupBox12->TabIndex = 40;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Lap Time Record";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(6, 22);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(50, 13);
			this->label47->TabIndex = 29;
			this->label47->Text = L"Minutes: ";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(6, 48);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(55, 13);
			this->label48->TabIndex = 31;
			this->label48->Text = L"Seconds: ";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(6, 74);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(70, 13);
			this->label49->TabIndex = 33;
			this->label49->Text = L"Milliseconds: ";
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(272, 19);
			this->textBox31->MaxLength = 3;
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(48, 20);
			this->textBox31->TabIndex = 30;
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(272, 45);
			this->textBox32->MaxLength = 3;
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(48, 20);
			this->textBox32->TabIndex = 32;
			// 
			// textBox33
			// 
			this->textBox33->Location = System::Drawing::Point(272, 71);
			this->textBox33->MaxLength = 3;
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(48, 20);
			this->textBox33->TabIndex = 34;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->label42);
			this->groupBox11->Controls->Add(this->label43);
			this->groupBox11->Controls->Add(this->label44);
			this->groupBox11->Controls->Add(this->textBox26);
			this->groupBox11->Controls->Add(this->textBox27);
			this->groupBox11->Controls->Add(this->textBox28);
			this->groupBox11->Location = System::Drawing::Point(6, 118);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(327, 101);
			this->groupBox11->TabIndex = 39;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Total Time Record";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(6, 22);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(50, 13);
			this->label42->TabIndex = 29;
			this->label42->Text = L"Minutes: ";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(6, 48);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(55, 13);
			this->label43->TabIndex = 31;
			this->label43->Text = L"Seconds: ";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(6, 74);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(70, 13);
			this->label44->TabIndex = 33;
			this->label44->Text = L"Milliseconds: ";
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(272, 19);
			this->textBox26->MaxLength = 3;
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(48, 20);
			this->textBox26->TabIndex = 30;
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(272, 45);
			this->textBox27->MaxLength = 3;
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(48, 20);
			this->textBox27->TabIndex = 32;
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(272, 71);
			this->textBox28->MaxLength = 3;
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(48, 20);
			this->textBox28->TabIndex = 34;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(279, 14);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(54, 23);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &SaveEditor::button3_Click);
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(100, 92);
			this->textBox25->MaxLength = 20;
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(233, 20);
			this->textBox25->TabIndex = 28;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(7, 95);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(41, 13);
			this->label41->TabIndex = 27;
			this->label41->Text = L"Name: ";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->comboBox14);
			this->groupBox10->Controls->Add(this->comboBox13);
			this->groupBox10->Controls->Add(this->label39);
			this->groupBox10->Controls->Add(this->label40);
			this->groupBox10->Location = System::Drawing::Point(6, 39);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(327, 49);
			this->groupBox10->TabIndex = 26;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Map";
			// 
			// comboBox14
			// 
			this->comboBox14->FormattingEnabled = true;
			this->comboBox14->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->comboBox14->Location = System::Drawing::Point(147, 17);
			this->comboBox14->Name = L"comboBox14";
			this->comboBox14->Size = System::Drawing::Size(40, 21);
			this->comboBox14->TabIndex = 26;
			this->comboBox14->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox14_SelectedIndexChanged);
			// 
			// comboBox13
			// 
			this->comboBox13->FormattingEnabled = true;
			this->comboBox13->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"1", L"2", L"3", L"4", L"5", L"6", L"7" });
			this->comboBox13->Location = System::Drawing::Point(45, 17);
			this->comboBox13->Name = L"comboBox13";
			this->comboBox13->Size = System::Drawing::Size(40, 21);
			this->comboBox13->TabIndex = 25;
			this->comboBox13->Tag = L"";
			this->comboBox13->SelectedIndexChanged += gcnew System::EventHandler(this, &SaveEditor::comboBox13_SelectedIndexChanged);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(91, 20);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(50, 13);
			this->label39->TabIndex = 24;
			this->label39->Text = L"Number: ";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(7, 20);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(32, 13);
			this->label40->TabIndex = 0;
			this->label40->Text = L"Tag: ";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(79, 20);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(90, 13);
			this->label38->TabIndex = 1;
			this->label38->Text = L"No Map Selected";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(7, 20);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(65, 13);
			this->label37->TabIndex = 0;
			this->label37->Text = L"Map Name: ";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(358, 432);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(325, 182);
			this->label46->TabIndex = 11;
			this->label46->Text = resources->GetString(L"label46.Text");
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(207, 19);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(90, 17);
			this->checkBox2->TabIndex = 21;
			this->checkBox2->Text = L"Level Passed";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// SaveEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 859);
			this->Controls->Add(this->label46);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SaveEditor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Profile Editor";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->Text = L"";

		if (save->LoadProfile())
		{
			LoadData();

			if (save->loaded) 
			{
				comboBox1->SelectedIndex = 0;
				comboBox2->SelectedIndex = 0;
				comboBox3->SelectedIndex = 0;
				modeComboBox->SelectedIndex = 0;
				comboBox4->SelectedIndex = 0;
				comboBox5->SelectedIndex = 0;
				comboBox6->SelectedIndex = 0;
				comboBox7->SelectedIndex = 0;
				comboBox13->SelectedIndex = 0;
				comboBox14->SelectedIndex = 0;
			}
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (save->loaded)
		{
			save->LoadBCSaveFile(comboBox1->SelectedIndex + 1);

			LoadData();
		}
	}

	private: void LoadData()
	{
		textBox1->Text = msclr::interop::marshal_as<String^>(save->localProfile->profileName);
		textBox2->Text = msclr::interop::marshal_as<String^>(save->localProfile->saveName);
		textBox3->Text = msclr::interop::marshal_as<String^>(save->localProfile->saveDate);
		textBox4->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->points));
		textBox5->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->passedTrials));
		textBox6->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->countOfOpenBonus));
		textBox7->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->timeAttackSeconds));
		textBox8->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->jumpDistances[comboBox2->SelectedIndex]));
		textBox9->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->countOfSaves));
		checkBox1->Checked = save->localProfile->openFinalChallenge;
		checkBox2->Checked = save->localProfile->modes[modeComboBox->SelectedIndex].levelPassed[comboBox3->SelectedIndex];
		textBox12->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].countOfRacers[comboBox3->SelectedIndex]));
		textBox13->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].laps[comboBox3->SelectedIndex]));
		textBox10->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].moneyForLevelPassing[comboBox3->SelectedIndex]));
		textBox11->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].moneyForRecordPassing[comboBox3->SelectedIndex]));
		textBox14->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].tag));
		textBox15->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].number));
		textBox17->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].color));
		textBox16->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouHaveInModes[comboBox6->SelectedIndex] + 1));
		textBox18->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouHaveInBonus[comboBox6->SelectedIndex] + 1));
		textBox19->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouCanBuy[comboBox6->SelectedIndex] + 1));
		comboBox12->SelectedIndex = save->localChampionshipProfile->championshipLevels;
	}

	private: void UpdateModeData()
	{
		textBox12->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].countOfRacers[comboBox3->SelectedIndex]));
		textBox13->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].laps[comboBox3->SelectedIndex]));
		textBox10->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].moneyForLevelPassing[comboBox3->SelectedIndex]));
		textBox11->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].moneyForRecordPassing[comboBox3->SelectedIndex]));
		textBox14->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].tag));
		textBox15->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].number));
	}

	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (save->localProfile != NULL)
			textBox8->Text = msclr::interop::marshal_as<String^>(std::to_string(save->localProfile->jumpDistances[comboBox2->SelectedIndex]));
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		save->recordProfile->levels[comboBox13->SelectedIndex].playerName[comboBox14->SelectedIndex] = msclr::interop::marshal_as<std::string>(textBox25->Text);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox26->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox26->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox26->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].minutes = std::stoi(msclr::interop::marshal_as<std::string>(textBox26->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox27->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox27->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox27->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].seconds = std::stoi(msclr::interop::marshal_as<std::string>(textBox27->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox28->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox28->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox28->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].milliseconds = std::stoi(msclr::interop::marshal_as<std::string>(textBox28->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox31->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox31->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox31->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].minutes = std::stoi(msclr::interop::marshal_as<std::string>(textBox31->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox32->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox32->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox32->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].seconds = std::stoi(msclr::interop::marshal_as<std::string>(textBox32->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox33->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox33->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox33->Text)) < 256)
				save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].milliseconds = std::stoi(msclr::interop::marshal_as<std::string>(textBox33->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (se::isFloat(msclr::interop::marshal_as<std::string>(textBox8->Text)))
			save->localProfile->jumpDistances[comboBox2->SelectedIndex] = std::stof(msclr::interop::marshal_as<std::string>(textBox8->Text));
		else
			MessageBox::Show
			(
				"The information you entered is not a floating point value.",
				"Warning",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
	}

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox20->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox20->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox20->Text)) < 4)
				save->localProfile->cars[comboBox6->SelectedIndex].yourCars[comboBox7->SelectedIndex].color = std::stoi(msclr::interop::marshal_as<std::string>(textBox20->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox21->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox21->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox21->Text)) < 4)
				save->localProfile->cars[comboBox6->SelectedIndex].marketCars[comboBox7->SelectedIndex].color = std::stoi(msclr::interop::marshal_as<std::string>(textBox21->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox22->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox22->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox22->Text)) < 4)
				save->localProfile->cars[comboBox6->SelectedIndex].quickRaceCars[comboBox7->SelectedIndex].color = std::stoi(msclr::interop::marshal_as<std::string>(textBox22->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox23->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox23->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox23->Text)) < 4)
				save->localProfile->cars[comboBox6->SelectedIndex].bonusCars[comboBox7->SelectedIndex].color = std::stoi(msclr::interop::marshal_as<std::string>(textBox23->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		save->localProfile->cars[comboBox6->SelectedIndex].yourCars[comboBox7->SelectedIndex].id = comboBox8->SelectedIndex;
		save->localProfile->cars[comboBox6->SelectedIndex].marketCars[comboBox7->SelectedIndex].id = comboBox9->SelectedIndex;
		save->localProfile->cars[comboBox6->SelectedIndex].quickRaceCars[comboBox7->SelectedIndex].id = comboBox10->SelectedIndex;
		save->localProfile->cars[comboBox6->SelectedIndex].bonusCars[comboBox7->SelectedIndex].id = comboBox11->SelectedIndex;
	}

	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox16->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox16->Text)) > 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox16->Text)) < 16)
				save->localProfile->countOfCarsYouHaveInModes[comboBox6->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox16->Text)) - 1;
			else
				MessageBox::Show("The value must be from 1 to 15.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox18->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox18->Text)) > 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox18->Text)) < 16)
				save->localProfile->countOfCarsYouHaveInBonus[comboBox6->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox18->Text)) - 1;
			else
				MessageBox::Show("The value must be from 1 to 15.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox19->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox19->Text)) > 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox19->Text)) < 16)
				save->localProfile->countOfCarsYouCanBuy[comboBox6->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox19->Text)) - 1;
			else
				MessageBox::Show("The value must be from 1 to 15.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox24->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox24->Text)) > 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox24->Text)) < 16)
				save->localProfile->countOfCarsYouHaveInQuickRaceMode[comboBox6->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox24->Text)) - 1;
			else
				MessageBox::Show("The value must be from 1 to 15.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox17->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox17->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox17->Text)) < 4)
				save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].color = std::stoi(msclr::interop::marshal_as<std::string>(textBox17->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].id = comboBox5->SelectedIndex;
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox14->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox14->Text)) > 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox14->Text)) < 8)
				save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].tag = std::stoi(msclr::interop::marshal_as<std::string>(textBox14->Text));
			else
				MessageBox::Show("The value must be from 1 to 7.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox15->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox15->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox15->Text)) < 10)
				save->localProfile->modes[modeComboBox->SelectedIndex].maps[comboBox3->SelectedIndex].number = std::stoi(msclr::interop::marshal_as<std::string>(textBox15->Text));
			else
				MessageBox::Show("The value must be from 0 to 9.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox2->Checked)
			save->localProfile->modes[modeComboBox->SelectedIndex].levelPassed[comboBox3->SelectedIndex] = 1;
		else
			save->localProfile->modes[modeComboBox->SelectedIndex].levelPassed[comboBox3->SelectedIndex] = 0;

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox10->Text)))
			save->localProfile->modes[modeComboBox->SelectedIndex].moneyForLevelPassing[comboBox3->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox10->Text));
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox11->Text)))
			save->localProfile->modes[modeComboBox->SelectedIndex].moneyForRecordPassing[comboBox3->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox11->Text));
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox12->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox12->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox12->Text)) <= 8)
				save->localProfile->modes[modeComboBox->SelectedIndex].countOfRacers[comboBox3->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox12->Text));
			else
				MessageBox::Show("The value must be from 0 to 8.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox13->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox13->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox13->Text)) <= 3)
				save->localProfile->modes[modeComboBox->SelectedIndex].laps[comboBox3->SelectedIndex] = std::stoi(msclr::interop::marshal_as<std::string>(textBox13->Text));
			else
				MessageBox::Show("The value must be from 0 to 3.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		groupBox1->Enabled = save->loaded;
		groupBox8->Enabled = save->loaded;
		groupBox9->Enabled = save->loaded;
		button10->Enabled = save->loaded;
		label46->Enabled = save->loaded;
	}

	private: System::Void modeComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (save->localProfile != NULL)
		{
			UpdateModeData();
			checkBox2->Checked = save->localProfile->modes[modeComboBox->SelectedIndex].levelPassed[comboBox3->SelectedIndex];
		}
	}

	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (save->localProfile != NULL)
		{
			UpdateModeData();
			checkBox2->Checked = save->localProfile->modes[modeComboBox->SelectedIndex].levelPassed[comboBox3->SelectedIndex];
		}
	}

	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (save->localProfile != NULL)
		{
			textBox17->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].color));
			
			if (save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].id != 19)
				comboBox5->SelectedIndex = save->localProfile->modes[modeComboBox->SelectedIndex].opponentCar[comboBox3->SelectedIndex].carModes[comboBox4->SelectedIndex].id;
			else
			{
				comboBox5->SelectedIndex = -1;
				comboBox5->Text = "Unknown Car";
			}
		}
	}

	private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		textBox16->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouHaveInModes[comboBox6->SelectedIndex] + 1));
		textBox18->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouHaveInBonus[comboBox6->SelectedIndex] + 1));
		textBox19->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouCanBuy[comboBox6->SelectedIndex] + 1));
		textBox24->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->countOfCarsYouHaveInQuickRaceMode[comboBox6->SelectedIndex] + 1));

		comboBox7->SelectedIndex = 1;
		comboBox7->SelectedIndex = 0;
	}

	private: System::Void comboBox7_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		textBox20->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->cars[comboBox6->SelectedIndex].yourCars[comboBox7->SelectedIndex].color));
		textBox21->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->cars[comboBox6->SelectedIndex].marketCars[comboBox7->SelectedIndex].color));
		textBox22->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->cars[comboBox6->SelectedIndex].quickRaceCars[comboBox7->SelectedIndex].color));
		textBox23->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->localProfile->cars[comboBox6->SelectedIndex].bonusCars[comboBox7->SelectedIndex].color));
	
		if (save->localProfile->cars[comboBox6->SelectedIndex].yourCars[comboBox7->SelectedIndex].id != 255)
			comboBox8->SelectedIndex = save->localProfile->cars[comboBox6->SelectedIndex].yourCars[comboBox7->SelectedIndex].id;
		else
		{
			comboBox8->SelectedIndex = -1;
			comboBox8->Text = "Empty Slot";
		}

		if (save->localProfile->cars[comboBox6->SelectedIndex].marketCars[comboBox7->SelectedIndex].id != 255)
			comboBox9->SelectedIndex = save->localProfile->cars[comboBox6->SelectedIndex].marketCars[comboBox7->SelectedIndex].id;
		else
		{
			comboBox9->SelectedIndex = -1;
			comboBox9->Text = "Empty Slot";
		}

		if (save->localProfile->cars[comboBox6->SelectedIndex].quickRaceCars[comboBox7->SelectedIndex].id != 255)
			comboBox10->SelectedIndex = save->localProfile->cars[comboBox6->SelectedIndex].quickRaceCars[comboBox7->SelectedIndex].id;
		else
		{
			comboBox10->SelectedIndex = -1;
			comboBox10->Text = "Empty Slot";
		}

		if (save->localProfile->cars[comboBox6->SelectedIndex].bonusCars[comboBox7->SelectedIndex].id != 255)
			comboBox11->SelectedIndex = save->localProfile->cars[comboBox6->SelectedIndex].bonusCars[comboBox7->SelectedIndex].id;
		else
		{
			comboBox11->SelectedIndex = -1;
			comboBox11->Text = "Empty Slot";
		}
	}

	private: System::Void comboBox12_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		save->localChampionshipProfile->championshipLevels = comboBox12->SelectedIndex;
	}
	
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		save->localProfile->saveName = msclr::interop::marshal_as<std::string>(textBox2->Text);
		save->localProfile->saveDate = msclr::interop::marshal_as<std::string>(textBox3->Text);

		if (se::isFloat(msclr::interop::marshal_as<std::string>(textBox4->Text)))
			save->localProfile->points = stof(msclr::interop::marshal_as<std::string>(textBox4->Text));
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox6->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox6->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox6->Text)) < 5)
				save->localProfile->countOfOpenBonus = std::stoi(msclr::interop::marshal_as<std::string>(textBox6->Text));
			else
				MessageBox::Show("The value must be from 0 to 4.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox5->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox5->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox5->Text)) <= 255)
				save->localProfile->passedTrials = std::stoi(msclr::interop::marshal_as<std::string>(textBox5->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox7->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox7->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox7->Text)) <= 255)
				save->localProfile->timeAttackSeconds = std::stoi(msclr::interop::marshal_as<std::string>(textBox7->Text));
			else
				MessageBox::Show("The value must be from 0 to 255.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		if (se::isInteger(msclr::interop::marshal_as<std::string>(textBox9->Text)))
			if (std::stoi(msclr::interop::marshal_as<std::string>(textBox9->Text)) >= 0 && std::stoi(msclr::interop::marshal_as<std::string>(textBox9->Text)) <= 65536)
				save->localProfile->countOfSaves = std::stoi(msclr::interop::marshal_as<std::string>(textBox9->Text));
			else
				MessageBox::Show("The value must be from 0 to 65536.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else
			MessageBox::Show("The information you entered is not a integer value.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		save->localProfile->openFinalChallenge = checkBox1->Checked;

		if (textBox1->Text != "")
			if (textBox1->Text == msclr::interop::marshal_as<String^>(save->localProfile->profileName))
			{
				save->SaveBCSaveFile(comboBox1->SelectedIndex + 1);
				save->SaveChampionshipSaveFile();
				save->SaveRecordsFile();
			}
			else
				if (MessageBox::Show("Are you sure you want to change the name of the save?", "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					std::string newName = msclr::interop::marshal_as<std::string>(textBox1->Text);

					if (!fs::exists(*save->filePath + newName + ".usr"))
					{
						fs::rename(*save->filePath + *save->fileName + ".usr", *save->filePath + newName + ".usr");
						fs::rename(*save->filePath + *save->fileName, *save->filePath + newName);

						save->localProfile->profileName = newName;
						save->ChangeFileName(newName);

						save->SaveBCSaveFile(comboBox1->SelectedIndex + 1);
						save->SaveChampionshipSaveFile();
						save->SaveRecordsFile();
					}
					else
					{
						MessageBox::Show("This name already exists. Try entering another one.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						textBox1->Text = msclr::interop::marshal_as<String^>(save->localProfile->profileName);
					}
				}
				else
					textBox1->Text = msclr::interop::marshal_as<String^>(save->localProfile->profileName);
		else
			MessageBox::Show("It is not possible to save a file with this profile name.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void comboBox13_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		label38->Text = msclr::interop::marshal_as<String^>(se::GetMapName(comboBox13->SelectedIndex, comboBox14->SelectedIndex));
		
		try 
		{
			if (save->loaded)
			{
				textBox25->Text = msclr::interop::marshal_as<String^>(save->recordProfile->levels[comboBox13->SelectedIndex].playerName[comboBox14->SelectedIndex]);
				textBox26->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].minutes));
				textBox27->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].seconds));
				textBox28->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].milliseconds));

				textBox31->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].minutes));
				textBox32->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].seconds));
				textBox33->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].milliseconds));
			}
		}
		catch (...)
		{
			MessageBox::Show("Error. Try load again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void comboBox14_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		label38->Text = msclr::interop::marshal_as<String^>(se::GetMapName(comboBox13->SelectedIndex, comboBox14->SelectedIndex));

		try
		{
			if (save->loaded)
			{
				textBox25->Text = msclr::interop::marshal_as<String^>(save->recordProfile->levels[comboBox13->SelectedIndex].playerName[comboBox14->SelectedIndex]);
				textBox26->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].minutes));
				textBox27->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].seconds));
				textBox28->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].totalTime[comboBox14->SelectedIndex].milliseconds));

				textBox31->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].minutes));
				textBox32->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].seconds));
				textBox33->Text = msclr::interop::marshal_as<String^>(std::to_string((int)save->recordProfile->levels[comboBox13->SelectedIndex].lapTime[comboBox14->SelectedIndex].milliseconds));
			}
		}
		catch (...)
		{
			MessageBox::Show("Error. Try load again.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (textBox1->Text != "")
			if (MessageBox::Show("Are you sure you want to create new profile?", "Information", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				std::string newName = msclr::interop::marshal_as<std::string>(textBox1->Text);

				try 
				{
					if (!fs::exists(*path + "\\Users\\" + newName + ".usr"))
					{
						fs::create_directory(*path + "\\Users\\" + newName);
						save->CreateNewProfile(*path + "\\Users\\", newName);

						MessageBox::Show("The profile has been created successfully! Have a nice game.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

						if (save->LoadProfile(*path + "\\Users\\" + newName + ".usr"))
						{
							LoadData();

							if (save->loaded)
							{
								comboBox1->SelectedIndex = 0;
								comboBox2->SelectedIndex = 0;
								comboBox3->SelectedIndex = 0;
								modeComboBox->SelectedIndex = 0;
								comboBox4->SelectedIndex = 0;
								comboBox5->SelectedIndex = 0;
								comboBox6->SelectedIndex = 0;
								comboBox7->SelectedIndex = 0;
								comboBox13->SelectedIndex = 0;
								comboBox14->SelectedIndex = 0;
							}
						}
					}
					else
						MessageBox::Show("This name already exists. Try entering another one.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				catch (...)
				{
					MessageBox::Show("The corresponding path was not found. Put the program file in the folder with the executable file of the game and try again.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		else
			MessageBox::Show("It is not possible to save a file with this profile name.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
};
}