#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


//[STAThread]
//void Main(array<String^>^ args)
/*void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Visual_calculator::MyForm form;
	Application::Run(%form);
}*/

#include <Windows.h>
using namespace Visual_calculator;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}