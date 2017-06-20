#pragma once
#include "LoadBoardDisplay.h";

namespace LoadBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	
	private: System::Windows::Forms::Form^ mainWin; // Return to main window

	public:
		Login(System::Windows::Forms::Form^ m)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			mainWin = m;
			pw_txt->PasswordChar = '*';
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  send_btn;
	private: System::Windows::Forms::Button^  cancel_btn;
	private: System::Windows::Forms::Label^  user_lbl;
	private: System::Windows::Forms::Label^  pw_lbl;
	private: System::Windows::Forms::TextBox^  user_txt;
	private: System::Windows::Forms::TextBox^  pw_txt;
	private: System::Windows::Forms::Label^  Error_lbl;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->send_btn = (gcnew System::Windows::Forms::Button());
			this->cancel_btn = (gcnew System::Windows::Forms::Button());
			this->user_lbl = (gcnew System::Windows::Forms::Label());
			this->pw_lbl = (gcnew System::Windows::Forms::Label());
			this->user_txt = (gcnew System::Windows::Forms::TextBox());
			this->pw_txt = (gcnew System::Windows::Forms::TextBox());
			this->Error_lbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(206, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CENTRAL LOGIN";
			// 
			// send_btn
			// 
			this->send_btn->Location = System::Drawing::Point(209, 152);
			this->send_btn->Name = L"send_btn";
			this->send_btn->Size = System::Drawing::Size(75, 23);
			this->send_btn->TabIndex = 3;
			this->send_btn->Text = L"Send";
			this->send_btn->UseVisualStyleBackColor = true;
			this->send_btn->Click += gcnew System::EventHandler(this, &Login::send_btn_Click);
			// 
			// cancel_btn
			// 
			this->cancel_btn->Location = System::Drawing::Point(290, 152);
			this->cancel_btn->Name = L"cancel_btn";
			this->cancel_btn->Size = System::Drawing::Size(75, 23);
			this->cancel_btn->TabIndex = 4;
			this->cancel_btn->Text = L"Cancel";
			this->cancel_btn->UseVisualStyleBackColor = true;
			this->cancel_btn->Click += gcnew System::EventHandler(this, &Login::cancel_btn_Click);
			// 
			// user_lbl
			// 
			this->user_lbl->AutoSize = true;
			this->user_lbl->Location = System::Drawing::Point(127, 67);
			this->user_lbl->Name = L"user_lbl";
			this->user_lbl->Size = System::Drawing::Size(56, 13);
			this->user_lbl->TabIndex = 0;
			this->user_lbl->Text = L"username:";
			// 
			// pw_lbl
			// 
			this->pw_lbl->AutoSize = true;
			this->pw_lbl->Location = System::Drawing::Point(127, 104);
			this->pw_lbl->Name = L"pw_lbl";
			this->pw_lbl->Size = System::Drawing::Size(55, 13);
			this->pw_lbl->TabIndex = 0;
			this->pw_lbl->Text = L"password:";
			// 
			// user_txt
			// 
			this->user_txt->Location = System::Drawing::Point(209, 67);
			this->user_txt->Name = L"user_txt";
			this->user_txt->Size = System::Drawing::Size(159, 20);
			this->user_txt->TabIndex = 1;
			// 
			// pw_txt
			// 
			this->pw_txt->Location = System::Drawing::Point(209, 104);
			this->pw_txt->Name = L"pw_txt";
			this->pw_txt->Size = System::Drawing::Size(159, 20);
			this->pw_txt->TabIndex = 2;
			// 
			// Error_lbl
			// 
			this->Error_lbl->AutoSize = true;
			this->Error_lbl->Location = System::Drawing::Point(207, 152);
			this->Error_lbl->Name = L"Error_lbl";
			this->Error_lbl->Size = System::Drawing::Size(0, 13);
			this->Error_lbl->TabIndex = 5;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(668, 261);
			this->Controls->Add(this->Error_lbl);
			this->Controls->Add(this->pw_txt);
			this->Controls->Add(this->user_txt);
			this->Controls->Add(this->pw_lbl);
			this->Controls->Add(this->user_lbl);
			this->Controls->Add(this->cancel_btn);
			this->Controls->Add(this->send_btn);
			this->Controls->Add(this->label1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//String^ constr = "server=localhost";

	// Cancel Login btn
	private: System::Void cancel_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	// Login to LoadBoard
	private: System::Void send_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		// info from textfields
		String^ uid = user_txt->Text;
		String^ pwd = pw_txt->Text;

		// Connecting to server
		try{
			String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
			MySqlConnection^ conn = gcnew MySqlConnection(constr);
			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM credentials WHERE user = '" + uid + "' AND password = '" + pwd + "'; ", conn);
			conn->Open();
			MySqlDataReader^ myReader = cmd->ExecuteReader();
			int count = 0;
			
			while (myReader->Read()){
				count++;
			}

			if (count == 1){
				Error_lbl->Text = "Success!";
				MessageBox::Show("You're logged in!");
				this->Hide();
				LoadBoardDisplay^ loadBoardWin = gcnew LoadBoardDisplay();
				loadBoardWin->ShowDialog();
			}
			else{
				Error_lbl->Text = "Error: incorrect username or password!";
				MessageBox::Show("LOGIN ERROR!!!");
				user_txt->Text = "";
				pw_txt->Text = "";
			}
			conn->Close();

		}
		catch (Exception^ ex){
			MessageBox::Show(ex->Message);
		}
		
		
	}
};
}
