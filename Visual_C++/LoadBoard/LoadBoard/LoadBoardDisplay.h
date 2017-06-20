#pragma once

namespace LoadBoard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Web;
	using namespace System::Net::Mail;

	/// <summary>
	/// Summary for LoadBoardDisplay
	/// </summary>
	public ref class LoadBoardDisplay : public System::Windows::Forms::Form
	{
	public:
		LoadBoardDisplay(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			loadData(); // display loads on table
			//timer1->Start(); // date & time
			loadComboBox(); // load list in combo box
			timer1->Start();
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoadBoardDisplay()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  title_lbl;
	protected:

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::Label^  time_lbl;
	private: System::Windows::Forms::Label^  from_lbl;


	private: System::Windows::Forms::Label^  origin_lbl;
	private: System::Windows::Forms::TextBox^  from_txt;
	private: System::Windows::Forms::TextBox^  to_txt;












	private: System::Windows::Forms::Button^  send_btn;
	private: System::Windows::Forms::ComboBox^  loadList;
	private: System::Windows::Forms::Label^  request_lbl;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::Button^  exit_btn;
	private: System::Windows::Forms::TextBox^  selection_txt;
	private: System::Windows::Forms::Label^  selection_lbl;

	private: System::Windows::Forms::TextBox^  msg_txt;










	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->title_lbl = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->time_lbl = (gcnew System::Windows::Forms::Label());
			this->from_lbl = (gcnew System::Windows::Forms::Label());
			this->origin_lbl = (gcnew System::Windows::Forms::Label());
			this->from_txt = (gcnew System::Windows::Forms::TextBox());
			this->to_txt = (gcnew System::Windows::Forms::TextBox());
			this->send_btn = (gcnew System::Windows::Forms::Button());
			this->loadList = (gcnew System::Windows::Forms::ComboBox());
			this->request_lbl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->exit_btn = (gcnew System::Windows::Forms::Button());
			this->selection_txt = (gcnew System::Windows::Forms::TextBox());
			this->selection_lbl = (gcnew System::Windows::Forms::Label());
			this->msg_txt = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// title_lbl
			// 
			this->title_lbl->AutoSize = true;
			this->title_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_lbl->Location = System::Drawing::Point(8, 34);
			this->title_lbl->Name = L"title_lbl";
			this->title_lbl->Size = System::Drawing::Size(128, 16);
			this->title_lbl->TabIndex = 0;
			this->title_lbl->Text = L"Freight Database";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(11, 59);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(516, 261);
			this->dataGridView1->TabIndex = 0;
			// 
			// time_lbl
			// 
			this->time_lbl->AutoSize = true;
			this->time_lbl->Location = System::Drawing::Point(191, 37);
			this->time_lbl->Name = L"time_lbl";
			this->time_lbl->Size = System::Drawing::Size(0, 13);
			this->time_lbl->TabIndex = 0;
			// 
			// from_lbl
			// 
			this->from_lbl->AutoSize = true;
			this->from_lbl->Location = System::Drawing::Point(540, 67);
			this->from_lbl->Name = L"from_lbl";
			this->from_lbl->Size = System::Drawing::Size(36, 13);
			this->from_lbl->TabIndex = 0;
			this->from_lbl->Text = L"From :";
			// 
			// origin_lbl
			// 
			this->origin_lbl->AutoSize = true;
			this->origin_lbl->Location = System::Drawing::Point(540, 92);
			this->origin_lbl->Name = L"origin_lbl";
			this->origin_lbl->Size = System::Drawing::Size(26, 13);
			this->origin_lbl->TabIndex = 0;
			this->origin_lbl->Text = L"To :";
			// 
			// from_txt
			// 
			this->from_txt->Location = System::Drawing::Point(582, 59);
			this->from_txt->Name = L"from_txt";
			this->from_txt->Size = System::Drawing::Size(150, 20);
			this->from_txt->TabIndex = 1;
			// 
			// to_txt
			// 
			this->to_txt->Location = System::Drawing::Point(582, 86);
			this->to_txt->Name = L"to_txt";
			this->to_txt->Size = System::Drawing::Size(150, 20);
			this->to_txt->TabIndex = 2;
			// 
			// send_btn
			// 
			this->send_btn->Location = System::Drawing::Point(577, 297);
			this->send_btn->Name = L"send_btn";
			this->send_btn->Size = System::Drawing::Size(75, 23);
			this->send_btn->TabIndex = 5;
			this->send_btn->Text = L"Send Load";
			this->send_btn->UseVisualStyleBackColor = true;
			this->send_btn->Click += gcnew System::EventHandler(this, &LoadBoardDisplay::send_btn_Click);
			// 
			// loadList
			// 
			this->loadList->FormattingEnabled = true;
			this->loadList->Location = System::Drawing::Point(405, 35);
			this->loadList->Name = L"loadList";
			this->loadList->Size = System::Drawing::Size(121, 21);
			this->loadList->TabIndex = 0;
			this->loadList->Text = L"Select a Load";
			this->loadList->SelectedIndexChanged += gcnew System::EventHandler(this, &LoadBoardDisplay::loadList_SelectedIndexChanged);
			// 
			// request_lbl
			// 
			this->request_lbl->AutoSize = true;
			this->request_lbl->BackColor = System::Drawing::SystemColors::Control;
			this->request_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->request_lbl->Location = System::Drawing::Point(614, 35);
			this->request_lbl->Name = L"request_lbl";
			this->request_lbl->Size = System::Drawing::Size(84, 15);
			this->request_lbl->TabIndex = 0;
			this->request_lbl->Text = L"Load Request";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &LoadBoardDisplay::timer1_Tick);
			// 
			// exit_btn
			// 
			this->exit_btn->Location = System::Drawing::Point(658, 297);
			this->exit_btn->Name = L"exit_btn";
			this->exit_btn->Size = System::Drawing::Size(75, 23);
			this->exit_btn->TabIndex = 6;
			this->exit_btn->Text = L"Exit";
			this->exit_btn->UseVisualStyleBackColor = true;
			this->exit_btn->Click += gcnew System::EventHandler(this, &LoadBoardDisplay::exit_btn_Click);
			// 
			// selection_txt
			// 
			this->selection_txt->Location = System::Drawing::Point(543, 132);
			this->selection_txt->Name = L"selection_txt";
			this->selection_txt->Size = System::Drawing::Size(189, 20);
			this->selection_txt->TabIndex = 3;
			// 
			// selection_lbl
			// 
			this->selection_lbl->AutoSize = true;
			this->selection_lbl->Location = System::Drawing::Point(543, 116);
			this->selection_lbl->Name = L"selection_lbl";
			this->selection_lbl->Size = System::Drawing::Size(76, 13);
			this->selection_lbl->TabIndex = 13;
			this->selection_lbl->Text = L"Load Selected";
			// 
			// msg_txt
			// 
			this->msg_txt->Location = System::Drawing::Point(543, 158);
			this->msg_txt->Multiline = true;
			this->msg_txt->Name = L"msg_txt";
			this->msg_txt->Size = System::Drawing::Size(189, 133);
			this->msg_txt->TabIndex = 4;
			this->msg_txt->Text = L"Type Your Message Here";
			// 
			// LoadBoardDisplay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 341);
			this->Controls->Add(this->msg_txt);
			this->Controls->Add(this->selection_lbl);
			this->Controls->Add(this->selection_txt);
			this->Controls->Add(this->exit_btn);
			this->Controls->Add(this->request_lbl);
			this->Controls->Add(this->loadList);
			this->Controls->Add(this->send_btn);
			this->Controls->Add(this->to_txt);
			this->Controls->Add(this->from_txt);
			this->Controls->Add(this->origin_lbl);
			this->Controls->Add(this->from_lbl);
			this->Controls->Add(this->time_lbl);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->title_lbl);
			this->Name = L"LoadBoardDisplay";
			this->Text = L"LoadBoardDisplay";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoadBoardDisplay::LoadBoardDisplay_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Closing the window safely
	private: System::Void LoadBoardDisplay_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (MessageBox::Show("Do you really want to close this application?", "Freight Database", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
			Application::Exit();
		}
		else {
			e->Cancel = true;
		}
	}
	
	// Display date and time
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		DateTime senTime = DateTime::Now;
		this->time_lbl->Text = senTime.ToString();
	}
			 
	// Load data from database
	private:void loadData(void){	
		try{
			String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
			MySqlConnection^ conn = gcnew MySqlConnection(constr);
			MySqlDataAdapter^ adaptor = gcnew MySqlDataAdapter("SELECT * FROM loadboard;", conn);
			DataTable^ dTable = gcnew DataTable();
			adaptor->Fill(dTable);
			bindingSource1->DataSource = dTable;
			dataGridView1->DataSource = bindingSource1;
		}
		catch (Exception^ ex){
			MessageBox::Show(ex->Message);
		}
	}

	// Drop-down
	private: void loadComboBox(){
		String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
		MySqlConnection^ conn = gcnew MySqlConnection(constr);
		MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM loadboard;", conn);
		conn->Open();
		MySqlDataReader^ myReader = cmd->ExecuteReader();
		while (myReader->Read()){
			String^ vName = myReader->GetString("Origin");
			loadList->Items->Add(vName);
		}
		conn->Close();
	}

	// Populate textfields if comboBox is clicked
	private: System::Void loadList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		String^ comboVal = loadList->Text;
		
		String^ constr = "server=a2plcpnl0953.prod.iad2.secureserver.net; port=3306; username=davis1; password=waxande17; database=transportations";
		MySqlConnection^ conn = gcnew MySqlConnection(constr);
		MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM loadboard WHERE Origin= '"+comboVal+"';", conn);
		conn->Open();
		MySqlDataReader^ dr = cmd->ExecuteReader();
		
		while (dr->Read()){
			String^ vId = dr->GetInt32("id").ToString();
			String^ vOrig = dr->GetString("Origin");
			String^ vDest = dr->GetString("Destination");
			String^ vShip = dr->GetString("Ship Date");
			String^ vDel = dr->GetString("Del Date");
			String^ vWeight = dr->GetDouble("Weight").ToString();
			String^ vMiles = dr->GetInt32("Mileage").ToString();
			
			/*loadSelectList->Items->Add(vId + " " + vOrig + " " + vDest + " " + vShip + " " + vDel + " " + vWeight + " " + vMiles);*/
			selection_txt->Text = "Load# " + vId + " - " + vOrig + " " + vDest;
		}
		conn->Close();
	}

	// Send Load Selection
	private: System::Void send_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		// Set text fields
		String^ from = from_txt->Text;
		String^ to = to_txt->Text;
		String^ select = selection_txt->Text;
		String^ msg = msg_txt->Text;
		
		MailMessage^ myMail = gcnew MailMessage(from, to, select, msg);
		SmtpClient^ myClient = gcnew SmtpClient("smtp.yahoo.com");
		myClient->Port = 587;
		myClient->Credentials = gcnew System::Net::NetworkCredential("webjobs755@yahoo.com ", "joloff_86");
		myClient->EnableSsl = true;
		myClient->Send(myMail);

		from_txt->Text = " ";
		to_txt->Text = " ";
		selection_txt->Text = " ";
		msg_txt->Text = " ";
		
		MessageBox::Show("THANK YOU! \nYOUR LOAD REQUEST WILL BE PROCESSED. \nONE OF OUR DISPATCHERS WILL CONTACT YOU SOON.");
	}

	// Exit Program
	private: System::Void exit_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
