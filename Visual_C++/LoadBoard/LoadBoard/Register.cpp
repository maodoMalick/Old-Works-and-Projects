#include "Register.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^ >^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoadBoard::Register form;
	Application::Run(%form);
}
