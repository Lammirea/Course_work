#include "Main_page.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;


[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	����������������������������::Main_page formMain;
	Application::Run(% formMain);
}


System::Void ����������������������������::Main_page::btn_graph_coloring_Click(System::Object^ sender, System::EventArgs^ e)
{
	UI_graph^ Graph = gcnew UI_graph();//������ ����� ���������
	Graph->Show();//��������� ����� � ���������� �����
	Main_page::Hide();//����������� ����������

	return System::Void();
}

System::Void ����������������������������::Main_page::btn_sudoku_Click(System::Object^ sender, System::EventArgs^ e)
{
	Sudolu_game^ Sudoku = gcnew Sudolu_game();
	Sudoku->Show();
	Main_page::Hide();

	return System::Void();
}

System::Void ����������������������������::Main_page::Main_page_Load(System::Object^ sender, System::EventArgs^ e)
{
  
    return System::Void();
}
