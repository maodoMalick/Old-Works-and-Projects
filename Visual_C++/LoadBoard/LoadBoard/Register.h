#pragma once
#include "SignUp.h";
#include "Login.h";

namespace LoadBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
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
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  freightLogin;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  freightSignUp;


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  truckSignUp;

	private: System::Windows::Forms::Label^  truckLogin;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->freightLogin = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->freightSignUp = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->truckSignUp = (gcnew System::Windows::Forms::Label());
			this->truckLogin = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(374, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(340, 27);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to Truckload Express";
			// 
			// freightLogin
			// 
			this->freightLogin->AutoSize = true;
			this->freightLogin->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->freightLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->freightLogin->Font = (gcnew System::Drawing::Font(L"Candara", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->freightLogin->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->freightLogin->Location = System::Drawing::Point(106, 45);
			this->freightLogin->Name = L"freightLogin";
			this->freightLogin->Size = System::Drawing::Size(42, 15);
			this->freightLogin->TabIndex = 1;
			this->freightLogin->Text = L"Login    ";
			this->freightLogin->Click += gcnew System::EventHandler(this, &Register::freightLogin_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->groupBox1->Controls->Add(this->freightSignUp);
			this->groupBox1->Controls->Add(this->freightLogin);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(377, 107);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 100);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Freight Brokers";
			// 
			// freightSignUp
			// 
			this->freightSignUp->AutoSize = true;
			this->freightSignUp->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->freightSignUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->freightSignUp->Font = (gcnew System::Drawing::Font(L"Candara", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->freightSignUp->Location = System::Drawing::Point(106, 71);
			this->freightSignUp->Name = L"freightSignUp";
			this->freightSignUp->Size = System::Drawing::Size(43, 15);
			this->freightSignUp->TabIndex = 2;
			this->freightSignUp->Text = L"Sign up";
			this->freightSignUp->Click += gcnew System::EventHandler(this, &Register::freightSignUp_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->groupBox2->Controls->Add(this->truckSignUp);
			this->groupBox2->Controls->Add(this->truckLogin);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(548, 107);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(165, 100);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Trucking";
			// 
			// truckSignUp
			// 
			this->truckSignUp->AutoSize = true;
			this->truckSignUp->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->truckSignUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->truckSignUp->Font = (gcnew System::Drawing::Font(L"Candara", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->truckSignUp->Location = System::Drawing::Point(106, 71);
			this->truckSignUp->Name = L"truckSignUp";
			this->truckSignUp->Size = System::Drawing::Size(43, 15);
			this->truckSignUp->TabIndex = 1;
			this->truckSignUp->Text = L"Sign up";
			this->truckSignUp->Click += gcnew System::EventHandler(this, &Register::truckSignUp_Click);
			// 
			// truckLogin
			// 
			this->truckLogin->AutoSize = true;
			this->truckLogin->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->truckLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->truckLogin->Font = (gcnew System::Drawing::Font(L"Candara", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->truckLogin->Location = System::Drawing::Point(106, 45);
			this->truckLogin->Name = L"truckLogin";
			this->truckLogin->Size = System::Drawing::Size(44, 15);
			this->truckLogin->TabIndex = 0;
			this->truckLogin->Text = L"Login     ";
			this->truckLogin->Click += gcnew System::EventHandler(this, &Register::truckLogin_Click);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(732, 329);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Register";
			this->Text = L"Register";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Register::Register_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	// Freight Broker sign up
	private: System::Void freightSignUp_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		SignUp^ signupWin = gcnew SignUp(this);
		signupWin->ShowDialog();
	}

	// Trucking sign up
	private: System::Void truckSignUp_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		SignUp^ signupWin = gcnew SignUp(this);
		signupWin->ShowDialog();
	}

	// Freight Broker login
	private: System::Void freightLogin_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Login^ loginWin = gcnew Login(this);
		loginWin->ShowDialog();
	}

	// Trucking login
	private: System::Void truckLogin_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Login^ loginWin = gcnew Login(this);
		loginWin->ShowDialog();
	}

	// Warning Window Closure
	private: System::Void Register_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (MessageBox::Show("Do you really want to close the window?", "Loadboard Registration", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
			Application::Exit();
		}
		else{
			e->Cancel = true;
		}

	}
};
}
