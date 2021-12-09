#pragma once
#include "UI_graph.h"
#include "Sudolu_game.h"

namespace –еализаци€раскрашивани€графа {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// —водка дл€ Main_page
	/// </summary>
	public ref class Main_page : public System::Windows::Forms::Form
	{
	public:
		Main_page(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Main_page()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_graph_coloring;
	private: System::Windows::Forms::Button^ btn_sudoku;



	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_page::typeid));
			this->btn_graph_coloring = (gcnew System::Windows::Forms::Button());
			this->btn_sudoku = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_graph_coloring
			// 
			this->btn_graph_coloring->AutoEllipsis = true;
			this->btn_graph_coloring->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_graph_coloring->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_graph_coloring->Font = (gcnew System::Drawing::Font(L"Dubai", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_graph_coloring->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->btn_graph_coloring->Location = System::Drawing::Point(161, 211);
			this->btn_graph_coloring->Name = L"btn_graph_coloring";
			this->btn_graph_coloring->Size = System::Drawing::Size(293, 85);
			this->btn_graph_coloring->TabIndex = 1;
			this->btn_graph_coloring->Text = L"–аскраска графа";
			this->btn_graph_coloring->UseVisualStyleBackColor = false;
			this->btn_graph_coloring->Click += gcnew System::EventHandler(this, &Main_page::btn_graph_coloring_Click);
			// 
			// btn_sudoku
			// 
			this->btn_sudoku->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_sudoku->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_sudoku->Font = (gcnew System::Drawing::Font(L"Dubai", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_sudoku->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(136)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->btn_sudoku->Location = System::Drawing::Point(161, 414);
			this->btn_sudoku->Name = L"btn_sudoku";
			this->btn_sudoku->Size = System::Drawing::Size(293, 74);
			this->btn_sudoku->TabIndex = 2;
			this->btn_sudoku->Text = L"—удоку";
			this->btn_sudoku->UseVisualStyleBackColor = false;
			this->btn_sudoku->Click += gcnew System::EventHandler(this, &Main_page::btn_sudoku_Click);
			// 
			// Main_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(630, 664);
			this->Controls->Add(this->btn_sudoku);
			this->Controls->Add(this->btn_graph_coloring);
			this->Font = (gcnew System::Drawing::Font(L"Dubai", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Main_page";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"“очечки и линии";
			this->Load += gcnew System::EventHandler(this, &Main_page::Main_page_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btn_graph_coloring_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_sudoku_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Main_page_Load(System::Object^ sender, System::EventArgs^ e);
};
}
