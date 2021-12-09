#include "UI_graph.h"
#include <ctime>
#include <random>


#include "Functions.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

/*[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	����������������������������::UI_graph form;
	Application::Run(% form);
}*/
//������ 
int** a;
int n_a = 0;


System::Void ����������������������������::UI_graph::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void ����������������������������::UI_graph::Adj_matrix_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	return System::Void();
}

System::Void ����������������������������::UI_graph::button_create_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� �������
	n_a = Convert::ToInt32(numericUpDown1->Value);

	//�������� �������
	a = new int* [n_a];
	for (int i = 0; i < n_a; i++)
	{
		a[i] = new int[n_a];

	}
	if (n_a == 1) {
		MessageBox::Show("������������ ���������� ��� ���������� �����", "��������!");
		return;
	}
	//�������� ������� ������
	for (int i = 0; i < n_a; i++)
	{
		for (int j = 0; j < n_a; j++)
		{
			a[i][j] = 0;
		}
	}
	//������ �������
	Adj_matrix_dataGridView1->RowCount = n_a;
	Adj_matrix_dataGridView1->ColumnCount = n_a;

	//�������� �������:
	ShowA();

	//����������� �������:
	Adj_matrix_dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	Adj_matrix_dataGridView1->AutoResizeColumns();//�������

	return System::Void();
}

System::Void ����������������������������::UI_graph::button_generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (n_a==0)
	{
		MessageBox::Show("������� �����������!", "��������!");
		return;
	}
		//���������� �������:
		std::srand(time(NULL));
		for (int i = 0; i < n_a; i++)
		{
			for (int j = 0; j < n_a; j++)
			{
				a[i][j] = rand() % 100;
				if (i == j) {
					a[i][j] = 0;
				}
				if (a[i][j] >= 0 && a[i][j] <= 30) {
					a[i][j] = 0;
				}
				if (a[i][j] >= 31 && a[i][j] <= 100) {
					a[i][j] = 1;
				}
			}
		}

		//������� �������:
		ShowA();

		//����������� �������:
		Adj_matrix_dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
		Adj_matrix_dataGridView1->AutoResizeColumns();//�������

	return System::Void();
}

void ����������������������������::UI_graph::ShowA()
{
	//����� ������� � �������
	for (int i = 0; i < n_a; i++)
	{
		for (int j = 0; j < n_a; j++)
		{
			a[i][j] = a[j][i];
			//����� ������� ��������:
			Adj_matrix_dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);

			//����� ������� �����:
			Adj_matrix_dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

			//����� �������� �������
			Adj_matrix_dataGridView1->Rows[i]->Cells[j]->Value = a[i][j];
     
		}
	}
}

int width = 30, height = 30, BoxHeight, BoxWidth;
int* x_first_node = new int[n_a], * y_first_node = new int[n_a];

void ����������������������������::UI_graph::GraphColoring(std::vector<std::vector<int>> AdjList, Graphics^ g1,int* x_first_node,int* y_first_node) {
	///////////////////////////////////////////////////
	//���� � ������� ��� ���������� ������� � ����� ������� � ������ ������ �������� ���������� ���������� �� 2 �� 256 ����� ����� ������������ ��� ���������� ������:
	int* colorR = new int[n_a], * colorG = new int[n_a], * colorB = new int[n_a];
	for (int i = 0; i < n_a; i++)
	{
		colorR[i] = rand() % 257 + 2;
		colorG[i] = rand() % 257 + 2;
		colorB[i] = rand() % 257 + 2;
	}
	// keep track of the color assigned to each vertex
	std::unordered_map<int, int> result;

	// assign a color to vertex one by one
	for (int u = 0; u < n_a; u++)
	{
		// set to store the color of adjacent vertices of `u`
		std::set<int> assigned;

		// check colors of adjacent vertices of `u` and store them in a set
		for (int i : AdjList[u])
		{
			if (result[i]) {
				assigned.insert(result[i]);
			}
		}

		// check for the first free color
		int color = 1;
		for (auto& c : assigned)
		{
			if (color != c) {
				break;
			}
			color++;
		}

		// assign vertex `u` the first available color
		result[u] = color;
	}
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::FromArgb(5, 11, 94));
	System::Drawing::Font^ FontForWin = gcnew System::Drawing::Font("Dubai", 16, FontStyle::Regular);
	StringFormat^ drawFormat = gcnew StringFormat;
	for (int v = 0; v < n_a; v++)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(colorR[result[v]], colorG[result[v]], colorB[result[v]]));
		g1->FillEllipse(brush, x_first_node[v] + v * 30, y_first_node[v], width, height);
		String^ str_v = Convert::ToString(v + 1);
		g1->DrawString(str_v, FontForWin, drawBrush, x_first_node[v] + v * 30 + 5, y_first_node[v], drawFormat);
		/*cout << "The color assigned to vertex " << v << " is "
			<< color[result[v]] << endl;*/
	}
}

System::Void ����������������������������::UI_graph::btn_generate_graph_Click(System::Object^ sender, System::EventArgs^ e)
{ 
	if (n_a == 0)
	{
		MessageBox::Show("����� ������� ���� ���������� ������� ���������", "��������!");
		return;
	}
	Color color = Color::FromArgb(5, 11, 94);
	TextFormatFlags flags = TextFormatFlags::Bottom | TextFormatFlags::EndEllipsis;
	System::Drawing::Font^ FontForWin = gcnew System::Drawing::Font("Dubai", 16, FontStyle::Regular);
	PictureBox^ box = pictureBox1_ShowGraph;
	Pen^ BluePen = gcnew Pen(Color::FromArgb(5, 11, 94), 2);
	SolidBrush^ drawBrush = gcnew SolidBrush(Color::FromArgb(5, 11, 94));
	Graphics^ g1 = pictureBox1_ShowGraph->CreateGraphics();
	Graphics^ g2 = pictureBox1_ShowGraph->CreateGraphics();
	Graphics^ line = pictureBox1_ShowGraph->CreateGraphics();

	// Set format of string.
	StringFormat^ drawFormat = gcnew StringFormat;
	//drawFormat->FormatFlags = StringFormatFlags::DirectionRightToLeft;

	//����� ���������� ������ ���������� ����� � ������� ������� �� ���������� ���������� ����� ������� � �������� �������
	BoxHeight = box->Height;
	BoxWidth = box->Width;
	//g1->DrawEllipse(BluePen, x_first_node, y_first_node, width, height);
	//g1->DrawString("1", FontForWin, drawBrush, BoxWidth - x_first_node + 3, BoxHeight - y_first_node - 3, drawFormat);
	
	//������������ ������� � ������:
	std::vector<std::vector<int>> arr;
	arr.resize(n_a);
	for (int i = 0; i < n_a; i++)
	{
		for (int j = 0; j < n_a; j++)
		{
			arr[i].push_back(a[i][j]);
		}
	}
	std::vector<std::vector<int>> AdjList = convert(arr);
	////////////////////////////////////////////////////////////////
	srand(time(NULL));
	for (int i = 0; i < n_a; i++)
	{	
		y_first_node[i] = rand() % (30 - BoxHeight);
		x_first_node[i] = rand() % 350 + 10;
			String^ str_i = Convert::ToString(i + 1);
			g1->DrawEllipse(BluePen, x_first_node[i] + i * 30, y_first_node[i], width, height);
			//g1->DrawString(str_i, FontForWin, drawBrush, x_first_node[i] + i * 30 + 5, y_first_node[i], drawFormat);
		/*coordinate[i][0] = (x_first_node[i] + i * 30 + y_first_node[i]) / 2;
		coordinate[i][1] = (y_first_node[i] + x_first_node[i] + i * 30) / 2;*/
		/*for (int j = 0; j < n_a; j++)
		{
			if (a[i][j]==1)
			{
				float CircleCenterX_prev = ((float)(x_first_node[i] + i * 30) + (float)y_first_node[i]) / 2;
				float CircleCenterY_prev = ((float)y_first_node[i] + (float)(x_first_node[i] + i * 30)) / 2;
				float CircleCenterX_next = ((float)(x_first_node[j] + j * 30) + (float)y_first_node[j]) / 2;
				float CircleCenterY_next = ((float)y_first_node[j] + (float)(x_first_node[j] + j * 30)) / 2;
				line->DrawLine(BluePen, CircleCenterX_next, CircleCenterY_next, CircleCenterX_prev, CircleCenterY_prev);
			}
		}*/
	}
	for (int i = 0; i < n_a; ++i)
	{
		for (int j = 0; j < n_a; ++j)
		{
			if (a[i][j] == 1)
			{
				line->DrawLine(BluePen, x_first_node[i] + i * 30, y_first_node[i], x_first_node[j] + j * 30, y_first_node[j]);
				a[j][i]=0;
			}
		}
	}
	GraphColoring(AdjList, g1, x_first_node, y_first_node);
	return System::Void();
}
System::Void ����������������������������::UI_graph::pictureBox1_ShowGraph_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	return System::Void();
}

System::Void ����������������������������::UI_graph::btn_return_to_main_page_Click(System::Object^ sender, System::EventArgs^ e)
{
	Main_page^ mPage = gcnew Main_page();//������ ����� ���������
	mPage->Show();//��������� ����� � ������� ���������
    UI_graph::Hide();

	return System::Void();
}

System::Void ����������������������������::UI_graph::btn_clear_field_Click(System::Object^ sender, System::EventArgs^ e)
{
	pictureBox1_ShowGraph->Invalidate();
	return System::Void();
}

