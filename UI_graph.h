#pragma once
#include "Main_page.h"

#include <vector>
#include <math.h>
#include <unordered_map>
#include <set>

namespace Реализацияраскрашиванияграфа {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Сводка для UI_graph
	/// </summary>
	public ref class UI_graph : public System::Windows::Forms::Form
	{
	public:
		UI_graph(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~UI_graph()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Button^ button_generate;

	private: System::Windows::Forms::Button^ button_create;


	private: System::Windows::Forms::Button^ btn_generate_graph;
	private: System::Windows::Forms::Button^ btn_clear_field;
	private: System::Windows::Forms::PictureBox^ pictureBox1_ShowGraph;
	private: System::Windows::Forms::DataGridView^ Adj_matrix_dataGridView1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ btn_return_to_main_page;



	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UI_graph::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->button_generate = (gcnew System::Windows::Forms::Button());
			this->btn_generate_graph = (gcnew System::Windows::Forms::Button());
			this->btn_clear_field = (gcnew System::Windows::Forms::Button());
			this->pictureBox1_ShowGraph = (gcnew System::Windows::Forms::PictureBox());
			this->Adj_matrix_dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_return_to_main_page = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_ShowGraph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Adj_matrix_dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Dubai", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(136)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(181, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Матрица Смежности";
			// 
			// button_create
			// 
			this->button_create->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->button_create->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_create->Font = (gcnew System::Drawing::Font(L"Dubai", 8));
			this->button_create->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button_create->Location = System::Drawing::Point(203, 422);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(104, 29);
			this->button_create->TabIndex = 3;
			this->button_create->Text = L"Создать";
			this->button_create->UseVisualStyleBackColor = false;
			this->button_create->Click += gcnew System::EventHandler(this, &UI_graph::button_create_Click);
			// 
			// button_generate
			// 
			this->button_generate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->button_generate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_generate->Font = (gcnew System::Drawing::Font(L"Dubai", 8));
			this->button_generate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button_generate->Location = System::Drawing::Point(313, 423);
			this->button_generate->Name = L"button_generate";
			this->button_generate->Size = System::Drawing::Size(148, 28);
			this->button_generate->TabIndex = 4;
			this->button_generate->Text = L"Сгенерировать";
			this->button_generate->UseVisualStyleBackColor = false;
			this->button_generate->Click += gcnew System::EventHandler(this, &UI_graph::button_generate_Click);
			// 
			// btn_generate_graph
			// 
			this->btn_generate_graph->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_generate_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_generate_graph->Font = (gcnew System::Drawing::Font(L"Dubai", 8));
			this->btn_generate_graph->Location = System::Drawing::Point(769, 547);
			this->btn_generate_graph->Name = L"btn_generate_graph";
			this->btn_generate_graph->Size = System::Drawing::Size(139, 31);
			this->btn_generate_graph->TabIndex = 6;
			this->btn_generate_graph->Text = L"Создать граф";
			this->btn_generate_graph->UseVisualStyleBackColor = false;
			this->btn_generate_graph->Click += gcnew System::EventHandler(this, &UI_graph::btn_generate_graph_Click);
			// 
			// btn_clear_field
			// 
			this->btn_clear_field->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_clear_field->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_clear_field->Font = (gcnew System::Drawing::Font(L"Dubai", 8));
			this->btn_clear_field->Location = System::Drawing::Point(1051, 547);
			this->btn_clear_field->Name = L"btn_clear_field";
			this->btn_clear_field->Size = System::Drawing::Size(152, 31);
			this->btn_clear_field->TabIndex = 7;
			this->btn_clear_field->Text = L"Очистить поле";
			this->btn_clear_field->UseVisualStyleBackColor = false;
			this->btn_clear_field->Click += gcnew System::EventHandler(this, &UI_graph::btn_clear_field_Click);
			// 
			// pictureBox1_ShowGraph
			// 
			this->pictureBox1_ShowGraph->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1_ShowGraph->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->pictureBox1_ShowGraph->Location = System::Drawing::Point(658, 49);
			this->pictureBox1_ShowGraph->Name = L"pictureBox1_ShowGraph";
			this->pictureBox1_ShowGraph->Size = System::Drawing::Size(659, 479);
			this->pictureBox1_ShowGraph->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1_ShowGraph->TabIndex = 8;
			this->pictureBox1_ShowGraph->TabStop = false;
			this->pictureBox1_ShowGraph->Click += gcnew System::EventHandler(this, &UI_graph::pictureBox1_ShowGraph_Click);
			// 
			// Adj_matrix_dataGridView1
			// 
			this->Adj_matrix_dataGridView1->AllowUserToOrderColumns = true;
			this->Adj_matrix_dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->Adj_matrix_dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Adj_matrix_dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->Adj_matrix_dataGridView1->Location = System::Drawing::Point(74, 90);
			this->Adj_matrix_dataGridView1->Name = L"Adj_matrix_dataGridView1";
			this->Adj_matrix_dataGridView1->RowHeadersWidth = 40;
			this->Adj_matrix_dataGridView1->RowTemplate->Height = 24;
			this->Adj_matrix_dataGridView1->Size = System::Drawing::Size(441, 312);
			this->Adj_matrix_dataGridView1->TabIndex = 9;
			this->Adj_matrix_dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UI_graph::Adj_matrix_dataGridView1_CellContentClick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->numericUpDown1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->numericUpDown1->Location = System::Drawing::Point(131, 426);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(53, 22);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &UI_graph::numericUpDown1_ValueChanged);
			// 
			// btn_return_to_main_page
			// 
			this->btn_return_to_main_page->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->btn_return_to_main_page->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_return_to_main_page->FlatAppearance->BorderSize = 0;
			this->btn_return_to_main_page->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_return_to_main_page->Font = (gcnew System::Drawing::Font(L"Dubai", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_return_to_main_page->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_return_to_main_page->Location = System::Drawing::Point(12, 12);
			this->btn_return_to_main_page->Name = L"btn_return_to_main_page";
			this->btn_return_to_main_page->Size = System::Drawing::Size(131, 33);
			this->btn_return_to_main_page->TabIndex = 11;
			this->btn_return_to_main_page->Text = L"На главную";
			this->btn_return_to_main_page->UseVisualStyleBackColor = false;
			this->btn_return_to_main_page->Click += gcnew System::EventHandler(this, &UI_graph::btn_return_to_main_page_Click);
			// 
			// UI_graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1373, 604);
			this->Controls->Add(this->btn_return_to_main_page);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->Adj_matrix_dataGridView1);
			this->Controls->Add(this->pictureBox1_ShowGraph);
			this->Controls->Add(this->btn_clear_field);
			this->Controls->Add(this->btn_generate_graph);
			this->Controls->Add(this->button_generate);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"UI_graph";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Раскрашивание графа";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1_ShowGraph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Adj_matrix_dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	List <Point>^ points; //точки по которым рисуем линию
	Pen^ pen; //перо
	Bitmap^ background;//фон
	int statePen;//Линия и круг

private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void Adj_matrix_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_generate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_clear_field_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_generate_graph_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_ShowGraph_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_return_to_main_page_Click(System::Object^ sender, System::EventArgs^ e);

	//отображение матрицы смежности:
    private: void ShowA();

	//раскраска графа:
	private: void GraphColoring(std::vector<std::vector<int>> AdjList, Graphics^ g1,int* y_first_node,int* x_first_node);


};
}
