// 某省自从实行了很多年的畅通工程计划后，终于修建了很多路。不过路多了也不好，每次要从一个城镇到另一个城镇时，
// 都有许多种道路方案可以选择，而某些方案要比另一些方案行走的距离要短很多。这让行人很困扰。
// 现在，已知起点和终点，请你计算出要从起点到终点，最短需要行走多少距离。
#include <iostream>
using namespace std;
int INF = 1000000;
void Floyd(int N, int **D, int **G)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            D[i][j] = G[i][j];
        }
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (D[i][k] < INF && D[k][j] < INF)
                {
                    if (D[i][k] + D[k][j] < D[i][j])
                    {
                        D[i][j] = D[i][k] + D[k][j];
                        // cout << " D[i][k] + D[k][j]" << i << ' ' << k << ' ' << j << endl;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        int **G, **D;
        G = new int *[n];
        D = new int *[n];
        for (int i = 0; i < n; i++)
        {
            G[i] = new int[n];
            D[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                G[i][j] = INF;
                if (i == j)
                    G[i][j] = 0;
            }
        for (int i = 0; i < k; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (G[a][b] > c)
                G[a][b] = c;
        }

        Floyd(n, D, G);
        int a, b;
        scanf("%d%d", &a, &b);
        if (D[a][b] < INF)
            printf("%d\n", D[a][b]);
        else
            printf("-1\n");
    }
    return 0;
}