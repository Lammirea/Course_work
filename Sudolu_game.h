#pragma once
#include "Main_page.h"

#include <map>
namespace –еализаци€раскрашивани€графа {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Sudolu_game
	/// </summary>
	public ref class Sudolu_game : public System::Windows::Forms::Form
	{
	public:
		Sudolu_game(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			GenerateMap();
			//GenerateMapNew();
			//cli::array<System::Windows::Forms::Button^, 2>^ buttons=gcnew cli::array<System::Windows::Forms::Button^, 2>(9, 9);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Sudolu_game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_return_to_main_page;
	private: System::Windows::Forms::Button^ btn_check_answer;
	protected:

	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Sudolu_game::typeid));
			this->btn_return_to_main_page = (gcnew System::Windows::Forms::Button());
			this->btn_check_answer = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_return_to_main_page
			// 
			this->btn_return_to_main_page->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->btn_return_to_main_page->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_return_to_main_page->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_return_to_main_page->Font = (gcnew System::Drawing::Font(L"Dubai", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_return_to_main_page->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_return_to_main_page->Location = System::Drawing::Point(86, 608);
			this->btn_return_to_main_page->Name = L"btn_return_to_main_page";
			this->btn_return_to_main_page->Size = System::Drawing::Size(114, 32);
			this->btn_return_to_main_page->TabIndex = 0;
			this->btn_return_to_main_page->Text = L"Ќа главную";
			this->btn_return_to_main_page->UseVisualStyleBackColor = false;
			this->btn_return_to_main_page->Click += gcnew System::EventHandler(this, &Sudolu_game::btn_return_to_main_page_Click);
			// 
			// btn_check_answer
			// 
			this->btn_check_answer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->btn_check_answer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_check_answer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_check_answer->Font = (gcnew System::Drawing::Font(L"Dubai", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_check_answer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->btn_check_answer->Location = System::Drawing::Point(447, 607);
			this->btn_check_answer->Name = L"btn_check_answer";
			this->btn_check_answer->Size = System::Drawing::Size(114, 32);
			this->btn_check_answer->TabIndex = 1;
			this->btn_check_answer->Text = L"ѕроверить";
			this->btn_check_answer->UseVisualStyleBackColor = false;
			this->btn_check_answer->Click += gcnew System::EventHandler(this, &Sudolu_game::btn_check_answer_Click);
			// 
			// Sudolu_game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(648, 664);
			this->Controls->Add(this->btn_check_answer);
			this->Controls->Add(this->btn_return_to_main_page);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Sudolu_game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"—удоку";
			this->ResumeLayout(false);

		}
#pragma endregion
	//дополнительные функции:
		cli::array<System::Windows::Forms::Button^, 2>^ buttons = gcnew cli::array<System::Windows::Forms::Button^, 2>(9, 9);

		   private: void GenerateMap();
	       private: void CreateMap(/*cli::array<System::Windows::Forms::Button^, 2>^ buttons*/);
	       private: void ShuffleMap(int i);
	       private: void MatrixTransposition();
	       private: void SwapBlocksInColumn();
	       private: void SwapBlocksInRow();
	       private: void SwapRowsInBlock();
	       private: void SwapColumnsInBlock();
	       private: void HideSells(/*cli::array<System::Windows::Forms::Button^, 2>^ buttons*/);
	private: void OnCellPressed(System::Object^ sender, System::EventArgs^ e);


	private: System::Void btn_check_answer_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void btn_return_to_main_page_Click(System::Object^ sender, System::EventArgs^ e);
};
}
