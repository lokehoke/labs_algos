#include "Set.h"
#include <iostream>
#include <iomanip>

int main()
{
    int n, m, k, count;
    setlocale(LC_ALL, "Russian");
    std::cout << "Тестирование программ поддержки множества" << std::endl;
    std::cout << " Решето Эратосфена" << std::endl;
    std::cout << "Введите верхнюю границу целых значений - ";
    std::cin >> n;
    TSet s(n + 1);
    for (m = 2; m <= n; m++)
    {
        s.InsElem(m);
    }

    for (m = 2; m <= n; m++)
    {
        if (s.IsMember(m))
        {
            for (k = 2 * m; k <= n; k += m)
            {
                if (s.IsMember(k))
                {
                    s.DelElem(k);
                }
            }
        }
    }
    std::cout << std::endl
              << "Печать множества некратных чисел"
              << std::endl
              << s
              << std::endl
              << "Печать простых чисел"
              << std::endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
    {
        if (s.IsMember(m))
        {
            count++;
            std::cout << std::setw(3) << m << " ";
            if (k++ % 10 == 0)
                std::cout << std::endl;
        }
    }
    std::cout << std::endl
              << " В первых "
              << n
              << " числах "
              << count
              << " простых"
              << std::endl;

    return 0;
}