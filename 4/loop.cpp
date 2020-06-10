#include <iostream>
#include <algorithm>

constexpr int INF = 1'000'000'000;

int InputGraph[5][5] = {{0, 12, 4, 12, 5},
                        {8, 0, 8, 7, 5},
                        {10, 8, 0, 6, 4},
                        {6, 5, 25, 0, 45},
                        {51, 95, 22, 47, 0}};

int c = 0;
int allScor = INF;

void makeClone(int *a, int n)
{
    int i, sum = 0;
    for (i = 0; i <= n; ++i)
    {
        sum += InputGraph[a[i % 4]][a[(i + 1) % 4]];
    }

    if (allScor > sum)
    {
        allScor = sum;
    }
}

void loop(int *a, int i, int n)
{
    if (i == n)
    {
        makeClone(a, n);
    }
    else
    {
        for (int j = i; j <= n; j++)
        {
            std::swap(*(a + i), *(a + j));
            loop(a, i + 1, n);
            // std::swap(*(a + i), *(a + j));
        }
    }
}

int main()
{
    int a[] = {0, 1, 2, 3, 4};
    loop(a, 0, 4);
    std::cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
    std::cout << "Length: " << allScor + 1 << std::endl;

    return 0;
}