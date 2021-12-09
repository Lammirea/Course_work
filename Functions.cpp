#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;

// конвертируем матрицу смежности в список смежности
std::vector<std::vector<int>> convert(std::vector<std::vector<int>> a)
{
    std::vector<std::vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}