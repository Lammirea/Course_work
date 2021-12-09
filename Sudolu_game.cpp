#include "Sudolu_game.h"

const int n = 3, sizeButton = 50,n_map=2;
int** map;


void ����������������������������::Sudolu_game::GenerateMap()
{
    cli::array<System::Windows::Forms::Button^, 2>^ buttons = gcnew cli::array<System::Windows::Forms::Button^, 2>(9, 9);

    map = new int* [n * n];
    for (int i = 0; i < n * n; i++)
    {
        map[i] = new int[n * n];
    }
    for (int i = 0; i < n*n; i++)
    {
        for (int j = 0; j < n*n; j++)
        {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < n*n; j++)
        {
            map[i][j] = (i * n + i / n + j) % (n * n) + 1;
            buttons[i, j] = gcnew Button();
        }
    }
    //MatrixTransposition();
    //SwapRowsInBlock();
    //SwapColumnsInBlock();
    //SwapBlocksInRow();
    //SwapBlocksInColumn();

    Random^ r = gcnew Random();
    //���������� �������� �� ������������� ������:
    for (int i = 0; i < 10; i++)
    {
        ShuffleMap(r->Next(0, 5));
    }
    CreateMap(/*buttons*/);
    HideSells();
}

void ����������������������������::Sudolu_game::CreateMap(/*cli::array<System::Windows::Forms::Button^, 2>^ buttons*/)
{
     //= gcnew cli::array<System::Windows::Forms::Button^, 2>(9, 9);
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            Button^ button = gcnew Button();
            //buttons[i,j] =gcnew Button();
            buttons[i,j] = button;
            button->Size = System::Drawing::Size(sizeButton, sizeButton);
            button->Text = Convert::ToString(map[i][j]);
            button->Click += gcnew EventHandler(this,&Sudolu_game::OnCellPressed);
            button->Location = Drawing::Point(j * sizeButton+20, i * sizeButton+20);
            this->Controls->Add(button);
        }
    }
    //HideSells(buttons);
}

void ����������������������������::Sudolu_game::HideSells(/*cli::array<System::Windows::Forms::Button^, 2>^ buttons*/) {
    int N = 40; //���������� ���������� ������
    Random^ r = gcnew Random();
    while (N > 0) {
        for (int i = 0; i < n * n; i++)
        {
            for (int j = 0; j < n * n; j++)
            {
                //���� ������� ������ ������
                if (!String::IsNullOrWhiteSpace(buttons[i, j]->Text)) {
                    int a = r->Next(0, 3);
                    buttons[i, j]->Text = Convert::ToString(a) == "0" ? " " : buttons[i, j]->Text;
                    //�������� ������,������� �� ����� ������:
                    buttons[i, j]->Enabled = a == 0 ? true : false;

                    if (a == 0) {
                        N--;
                    }
                    if (N <= 0) {
                        break;
                    }
                }
            }
            if (N <= 0)
                break;
        }
    }
}

void ����������������������������::Sudolu_game::ShuffleMap(int i) {
    switch (i)
    {
    case 0:
        MatrixTransposition();
        break;
    case 1:
        SwapRowsInBlock();
        break;
    case 2:
        SwapColumnsInBlock();
        break;
    case 3:
        SwapBlocksInRow();
        break;
    case 4:
        SwapBlocksInColumn();
        break;
    default:
        MatrixTransposition();
        break;
    }
}

void ����������������������������::Sudolu_game::SwapBlocksInColumn() {
    Random^ r = gcnew Random();
    auto block1 = r->Next(0, n);
    auto block2 = r->Next(0, n);
    while (block1 == block2) {
        block2 = r->Next(0, n);
    }
    block1 *= n;
    block2 *= n;
    for (int i = 0; i < n * n; i++)
    {
        auto k = block2;
        for (int j = block1; j < block1 + n; j++)
        {
            auto temp = map[i][j];
            map[i][j] = map[i][k];
            map[i][k] = temp;
            k++;
        }
    }
}

void ����������������������������::Sudolu_game::SwapBlocksInRow() {
    Random^ r = gcnew Random();
    auto block1 = r->Next(0, n);
    auto block2 = r->Next(0, n);
    while (block1 == block2) {
        block2 = r->Next(0, n);
    }
    block1 *= n;
    block2 *= n;
    for (int i = 0; i < n*n; i++)
    {
        auto k = block2;
        for (int j = block1; j < block1 + n; j++)
        {
            auto temp = map[j][i];
            map[j][i] = map[k][i];
            map[k][i] = temp;
            k++;
        }
    }
}

void ����������������������������::Sudolu_game::SwapRowsInBlock() {
    Random^ r = gcnew Random();
    auto block = r->Next(0, n);
    auto row1 = r->Next(0, n);
    auto line1 = block * n + row1;
    auto row2 = r->Next(0, n);
    while (row1 == row2) {
        row2 = r->Next(0, n);
    }
    auto line2 = block * n + row2;
    for (int i = 0; i < n*n; i++)
    {
        auto temp = map[line1][i];
        map[line1][i] = map[line2][i];
        map[line2][i] = temp;
    }
}

void ����������������������������::Sudolu_game::SwapColumnsInBlock() {
    Random^ r = gcnew Random();
    auto block = r->Next(0, n);
    auto row1 = r->Next(0, n);
    auto line1 = block * n + row1;
    auto row2 = r->Next(0, n);
    while (row1 == row2) {
        row2 = r->Next(0, n);
    }
    auto line2 = block * n + row2;
    for (int i = 0; i < n*n; i++)
    {
        auto temp = map[i][line1];
        map[i][line1] = map[i][line2];
        map[i][line2] = temp;
    }
}

void ����������������������������::Sudolu_game::MatrixTransposition() {
    int** tMap = new int*[n * n];
    for (int i = 0; i < n * n; i++)
    {
        tMap[i] = new int[n * n];
    }

    for (int i = 0; i < n*n; i++)
    {
        for (int j = 0; j < n*n; j++)
        {
            tMap[i][j] = map[j][i];
        }
    }
    map = tMap;
}

void ����������������������������::Sudolu_game::OnCellPressed(System::Object^ sender, System::EventArgs^ e) {
    Button^ pressedButton = (Button^)sender;
    String^ buttonText = pressedButton->Text;
    if (String::IsNullOrWhiteSpace(buttonText))
    {
        pressedButton->Text = "1";
    }
    else
    {
        int num = 0;
        num = Convert::ToInt16(buttonText);
        num++;
        if (num == 10) {
            num = 1;
        } 
        pressedButton->Text = Convert::ToString(num);
    }
}
System::Void ����������������������������::Sudolu_game::btn_check_answer_Click(System::Object^ sender, System::EventArgs^ e) {

    for (int i = 0; i < n*n; i++)
    {
        for (int j = 0; j < n*n; j++)
        {
            auto btnText = buttons[i, j]->Text;
            if (btnText != Convert::ToString(map[i][j])) {
                MessageBox::Show("������ ������ �������!", "���� ������������!");
                return;
            }
        }
    }
    MessageBox::Show("������ ������ �����!", "����������!");
    for (int i = 0; i < n*n; i++)
    {
        for (int j = 0; j < n*n; j++)
        {
            this->Controls->Remove(buttons[i, j]);
        }
    }
    GenerateMap();
}

System::Void ����������������������������::Sudolu_game::btn_return_to_main_page_Click(System::Object^ sender, System::EventArgs^ e) {
    Main_page^ mPage = gcnew Main_page();//������ ����� ���������
    mPage->Show();//��������� ����� � ������� ���������
    Sudolu_game::Hide();

    return System::Void();
}