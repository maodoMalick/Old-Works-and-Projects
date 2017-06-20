#pragma once
#include "Login.h";

namespace LoadBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	
	private: System::Windows::Forms::Form^ mainWin; // Return to main window

	public:
		SignUp(System::Windows::Forms::Form^ m)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			mainWin = m;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  sendFreight_btn;
	private: System::Windows::Forms::Button^  cancelFreight_btn;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  sendTruck_btn;
	private: System::Windows::Forms::Button^  cancelTruck_btn;
	private: System::Windows::Forms::Label^  freightComp_lbl;

	private: System::Windows::Forms::Label^  license_lbl;
	private: System::Windows::Forms::Label^  bank_lbl;
	private: System::Windows::Forms::Label^  userF_lbl;
	private: System::Windows::Forms::Label^  pwF_lbl;
	private: System::Windows::Forms::TextBox^  company_txt;
	private: System::Windows::Forms::TextBox^  license_txt;
	private: System::Windows::Forms::TextBox^  bank_txt;
	private: System::Windows::Forms::TextBox^  user_txt;
	private: System::Windows::Forms::TextBox^  pw_txt;







	private: System::Windows::Forms::Label^  truckComp_lbl;
	private: System::Windows::Forms::Label^  dot_lbl;
	private: System::Windows::Forms::Label^  fleet_lbl;


	private: System::Windows::Forms::Label^  pwT_lbl;





	private: System::Windows::Forms::Label^  userT_lbl;
	private: System::Windows::Forms::TextBox^  companyT_txt;
	private: System::Windows::Forms::TextBox^  dot_txt;
	private: System::Windows::Forms::TextBox^  fleet_txt;
	private: System::Windows::Forms::TextBox^  userT_txt;
	private: System::Windows::Forms::TextBox^  pwT_txt;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sendFreight_btn = (gcnew System::Windows::Forms::Button());
			this->cancelFreight_btn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sendTruck_btn = (gcnew System::Windows::Forms::Button());
			this->cancelTruck_btn = (gcnew System::Windows::Forms::Button());
			this->freightComp_lbl = (gcnew System::Windows::Forms::Label());
			this->license_lbl = (gcnew System::Windows::Forms::Label());
			this->bank_lbl = (gcnew System::Windows::Forms::Label());
			this->userF_lbl = (gcnew System::Windows::Forms::Label());
			this->pwF_lbl = (gcnew System::Windows::Forms::Label());
			this->company_txt = (gcnew System::Windows::Forms::TextBox());
			this->license_txt = (gcnew System::Windows::Forms::TextBox());
			this->bank_txt = (gcnew System::Windows::Forms::TextBox());
			this->user_txt = (gcnew System::Windows::Forms::TextBox());
			this->pw_txt = (gcnew System::Windows::Forms::TextBox());
			this->truckComp_lbl = (gcnew System::Windows::Forms::Label());
			this->dot_lbl = (gcnew System::Windows::Forms::Label());
			this->fleet_lbl = (gcnew System::Windows::Forms::Label());
			this->pwT_lbl = (gcnew System::Windows::Forms::Label());
			this->userT_lbl = (gcnew System::Windows::Forms::Label());
			this->companyT_txt = (gcnew System::Windows::Forms::TextBox());
			this->dot_txt = (gcnew System::Windows::Forms::TextBox());
			this->fleet_txt = (gcnew System::Windows::Forms::TextBox());
			this->userT_txt = (gcnew System::Windows::Forms::TextBox());
			this->pwT_txt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Freight Broker Registration";
			// 
			// sendFreight_btn
			// 
			this->sendFreight_btn->Location = System::Drawing::Point(63, 206);
			this->sendFreight_btn->Name = L"sendFreight_btn";
			this->sendFreight_btn->Size = System::Drawing::Size(75, 23);
			this->sendFreight_btn->TabIndex = 6;
			this->sendFreight_btn->Text = L"Send";
			this->sendFreight_btn->UseVisualStyleBackColor = true;
			this->sendFreight_btn->Click += gcnew System::EventHandler(this, &SignUp::sendFreight_btn_Click);
			// 
			// cancelFreight_btn
			// 
			this->cancelFreight_btn->Location = System::Drawing::Point(144, 206);
			this->cancelFreight_btn->Name = L"cancelFreight_btn";
			this->cancelFreight_btn->Size = System::Drawing::Size(75, 23);
			this->cancelFreight_btn->TabIndex = 7;
			this->cancelFreight_btn->Text = L"Cancel";
			this->cancelFreight_btn->UseVisualStyleBackColor = true;
			this->cancelFreight_btn->Click += gcnew System::EventHandler(this, &SignUp::cancelFreight_btn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(411, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Trucking Companies  Login";
			// 
			// sendTruck_btn
			// 
			this->sendTruck_btn->Location = System::Drawing::Point(451, 206);
			this->sendTruck_btn->Name = L"sendTruck_btn";
			this->sendTruck_btn->Size = System::Drawing::Size(75, 23);
			this->sendTruck_btn->TabIndex = 13;
			this->sendTruck_btn->Text = L"Send";
			this->sendTruck_btn->UseVisualStyleBackColor = true;
			this->sendTruck_btn->Click += gcnew System::EventHandler(this, &SignUp::sendTruck_btn_Click);
			// 
			// cancelTruck_btn
			// 
			this->cancelTruck_btn->Location = System::Drawing::Point(532, 206);
			this->cancelTruck_btn->Name = L"cancelTruck_btn";
			this->cancelTruck_btn->Size = System::Drawing::Size(75, 23);
			this->cancelTruck_btn->TabIndex = 14;
			this->cancelTruck_btn->Text = L"Cancel";
			this->cancelTruck_btn->UseVisualStyleBackColor = true;
			this->cancelTruck_btn->Click += gcnew System::EventHandler(this, &SignUp::cancelTruck_btn_Click);
			// 
			// freightComp_lbl
			// 
			this->freightComp_lbl->AutoSize = true;
			this->freightComp_lbl->Location = System::Drawing::Point(25, 54);
			this->freightComp_lbl->Name = L"freightComp_lbl";
			this->freightComp_lbl->Size = System::Drawing::Size(51, 13);
			this->freightComp_lbl->TabIndex = 0;
			this->freightComp_lbl->Text = L"Company";
			// 
			// license_lbl
			// 
			this->license_lbl->AutoSize = true;
			this->license_lbl->Location = System::Drawing::Point(25, 80);
			this->license_lbl->Name = L"license_lbl";
			this->license_lbl->Size = System::Drawing::Size(47, 13);
			this->license_lbl->TabIndex = 0;
			this->license_lbl->Text = L"License:";
			// 
			// bank_lbl
			// 
			this->bank_lbl->AutoSize = true;
			this->bank_lbl->Location = System::Drawing::Point(25, 110);
			this->bank_lbl->Name = L"bank_lbl";
			this->bank_lbl->Size = System::Drawing::Size(66, 13);
			this->bank_lbl->TabIndex = 0;
			this->bank_lbl->Text = L"Bank Name:";
			// 
			// userF_lbl
			// 
			this->userF_lbl->AutoSize = true;
			this->userF_lbl->Location = System::Drawing::Point(25, 134);
			this->userF_lbl->Name = L"userF_lbl";
			this->userF_lbl->Size = System::Drawing::Size(58, 13);
			this->userF_lbl->TabIndex = 0;
			this->userF_lbl->Text = L"Username:";
			// 
			// pwF_lbl
			// 
			this->pwF_lbl->AutoSize = true;
			this->pwF_lbl->Location = System::Drawing::Point(25, 161);
			this->pwF_lbl->Name = L"pwF_lbl";
			this->pwF_lbl->Size = System::Drawing::Size(56, 13);
			this->pwF_lbl->TabIndex = 0;
			this->pwF_lbl->Text = L"Password:";
			// 
			// company_txt
			// 
			this->company_txt->Location = System::Drawing::Point(99, 54);
			this->company_txt->Name = L"company_txt";
			this->company_txt->Size = System::Drawing::Size(120, 20);
			this->company_txt->TabIndex = 1;
			// 
			// license_txt
			// 
			this->license_txt->Location = System::Drawing::Point(99, 80);
			this->license_txt->Name = L"license_txt";
			this->license_txt->Size = System::Drawing::Size(120, 20);
			this->license_txt->TabIndex = 2;
			// 
			// bank_txt
			// 
			this->bank_txt->Location = System::Drawing::Point(99, 104);
			this->bank_txt->Name = L"bank_txt";
			this->bank_txt->Size = System::Drawing::Size(120, 20);
			this->bank_txt->TabIndex = 3;
			// 
			// user_txt
			// 
			this->user_txt->Location = System::Drawing::Point(99, 131);
			this->user_txt->Name = L"user_txt";
			this->user_txt->Size = System::Drawing::Size(120, 20);
			this->user_txt->TabIndex = 4;
			// 
			// pw_txt
			// 
			this->pw_txt->Location = System::Drawing::Point(99, 157);
			this->pw_txt->Name = L"pw_txt";
			this->pw_txt->Size = System::Drawing::Size(120, 20);
			this->pw_txt->TabIndex = 5;
			// 
			// truckComp_lbl
			// 
			this->truckComp_lbl->AutoSize = true;
			this->truckComp_lbl->Location = System::Drawing::Point(411, 54);
			this->truckComp_lbl->Name = L"truckComp_lbl";
			this->truckComp_lbl->Size = System::Drawing::Size(54, 13);
			this->truckComp_lbl->TabIndex = 0;
			this->truckComp_lbl->Text = L"Company:";
			// 
			// dot_lbl
			// 
			this->dot_lbl->AutoSize = true;
			this->dot_lbl->Location = System::Drawing::Point(411, 80);
			this->dot_lbl->Name = L"dot_lbl";
			this->dot_lbl->Size = System::Drawing::Size(56, 13);
			this->dot_lbl->TabIndex = 0;
			this->dot_lbl->Text = L"DOT No. :";
			// 
			// fleet_lbl
			// 
			this->fleet_lbl->AutoSize = true;
			this->fleet_lbl->Location = System::Drawing::Point(409, 110);
			this->fleet_lbl->Name = L"fleet_lbl";
			this->fleet_lbl->Size = System::Drawing::Size(56, 13);
			this->fleet_lbl->TabIndex = 0;
			this->fleet_lbl->Text = L"Fleet Size:";
			// 
			// pwT_lbl
			// 
			this->pwT_lbl->AutoSize = true;
			this->pwT_lbl->Location = System::Drawing::Point(411, 164);
			this->pwT_lbl->Name = L"pwT_lbl";
			this->pwT_lbl->Size = System::Drawing::Size(56, 13);
			this->pwT_lbl->TabIndex = 0;
			this->pwT_lbl->Text = L"Password:";
			// 
			// userT_lbl
			// 
			this->userT_lbl->AutoSize = true;
			this->userT_lbl->Location = System::Drawing::Point(409, 138);
			this->userT_lbl->Name = L"userT_lbl";
			this->userT_lbl->Size = System::Drawing::Size(58, 13);
			this->userT_lbl->TabIndex = 0;
			this->userT_lbl->Text = L"Username:";
			// 
			// companyT_txt
			// 
			this->companyT_txt->Location = System::Drawing::Point(487, 51);
			this->companyT_txt->Name = L"companyT_txt";
			this->companyT_txt->Size = System::Drawing::Size(120, 20);
			this->companyT_txt->TabIndex = 8;
			// 
			// dot_txt
			// 
			this->dot_txt->Location = System::Drawing::Point(487, 77);
			this->dot_txt->Name = L"dot_txt";
			this->dot_txt->Size = System::Drawing::Size(120, 20);
			this->dot_txt->TabIndex = 9;
			// 
			// fleet_txt
			// 
			this->fleet_txt->Location = System::Drawing::Point(487, 103);
			this->fleet_txt->Name = L"fleet_txt";
			this->fleet_txt->Size = System::Drawing::Size(120, 20);
			this->fleet_txt->TabIndex = 10;
			// 
			// userT_txt
			// 
			this->userT_txt->Location = System::Drawing::Point(487, 131);
			this->userT_txt->Name = L"userT_txt";
			this->userT_txt->Size = System::Drawing::Size(120, 20);
			this->userT_txt->TabIndex = 11;
			// 
			// pwT_txt
			// 
			this->pwT_txt->Location = System::Drawing::Point(487, 158);
			this->pwT_txt->Name = L"pwT_txt";
			this->pwT_txt->Size = System::Drawing::Size(120, 20);
			this->pwT_txt->TabIndex = 12;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 261);
			this->Controls->Add(this->pwT_txt);
			this->Controls->Add(this->userT_txt);
			this->Controls->Add(this->fleet_txt);
			this->Controls->Add(this->dot_txt);
			this->Controls->Add(this->companyT_txt);
			this->Controls->Add(this->userT_lbl);
			this->Controls->Add(this->pwT_lbl);
			this->Controls->Add(this->fleet_lbl);
			this->Controls->Add(this->dot_lbl);
			this->Controls->Add(this->truckComp_lbl);
			this->Controls->Add(this->pw_txt);
			this->Controls->Add(this->user_txt);
			this->Controls->Add(this->bank_txt);
			this->Controls->Add(this->license_txt);
			this->Controls->Add(this->company_txt);
			this->Controls->Add(this->pwF_lbl);
			this->Controls->Add(this->userF_lbl);
			this->Controls->Add(this->bank_lbl);
			this->Controls->Add(this->license_lbl);
			this->Controls->Add(this->freightComp_lbl);
			this->Controls->Add(this->cancelTruck_btn);
			this->Controls->Add(this->sendTruck_btn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cancelFreight_btn);
			this->Controls->Add(this->sendFreight_btn);
			this->Controls->Add(this->label1);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Button to Cancel Broker Registration
	private: System::Void cancelFreight_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		mainWin->Show(); // Go back to previous window
	}

	// Button to Cancel Truck Registration
	private: System::Void cancelTruck_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		mainWin->Show(); // Go back to previous window
	}
	
	// Send Broker Registration
	private: System::Void sendFreight_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Textfields for freight broker registration
		String^ company = company_txt->Text;
		String^ license = license_txt->Text;
		String^ bank = bank_txt->Text;
		String^ user = user_txt->Text;
		String^ pw = pw_txt->Text;

		// Connection Information
		// Multiple INSERT INTO
		try{
			String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
			MySqlConnection^ conn = gcnew MySqlConnection(constr);
			MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO register_freight(company, license, bank, user, pw) VALUES('" + company + "', '" + license + "', '" + bank + "', '" + user + "', '" + pw + "'); INSERT INTO credentials(user, password) VALUES( '" + user + "', '" + pw + "');", conn);
			conn->Open();
			MySqlDataReader^ dr = cmd->ExecuteReader();
			
			while (dr->Read()){
				if (user == dr->GetString("user")){
					MessageBox::Show("Got it!!!");
				}
			}
			conn->Close();
			
			MessageBox::Show("Thank You For Registering!\nNow You Can Login!");
		
			// Move to login window
			this->Hide();
			Login^ logWin = gcnew Login(this);
			logWin->ShowDialog();
		}
		catch(Exception^ ex) {
			MessageBox::Show(ex->Message);
			MessageBox::Show("ERROR INSERTING DATA!!!");
		}
	}

	// Send Truck Registration
	private: System::Void sendTruck_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Textfields for truck registration
		String^ companyT = companyT_txt->Text;
		String^ dot = dot_txt->Text;
		String^ fleet = fleet_txt->Text;
		String^ userT = userT_txt->Text;
		String^ pwT = pwT_txt->Text;

		// Connection Information
		// Multiple INSERT INTO
		try{
			String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
			MySqlConnection^ conn = gcnew MySqlConnection(constr);
			MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO register_truck(company, dot, fleet, user, pw) VALUES('" + companyT + "', '" + dot + "', '" + fleet + "', '" + userT + "', '" + pwT + "'); INSERT INTO credentials(user, password) VALUES( '" + userT + "', '" + pwT + "');", conn);
			conn->Open();
			MySqlDataReader^ dReader = cmd->ExecuteReader();
			
			MessageBox::Show("Data Saved!");
			conn->Close();
			// Move to login window
			this->Hide();
			Login^ logWin = gcnew Login(this);
			logWin->ShowDialog();
		}
		catch (Exception^ ex){
			MessageBox::Show(ex->Message);
			MessageBox::Show("ERROR INSERTING DATA!!!");
		}

	}


};
}
