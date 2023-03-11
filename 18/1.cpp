// 杰克是美国某小镇有名的飞盘高手。他掷飞盘的时候有一个习惯，在一叠飞盘中，从第一个飞盘（即位于顶端的飞盘）开始，
// 从上往下依次编号为1～N。当至少还有两个飞盘的时候，杰克通常会掷出一个飞盘，
// 然后把新的第一个飞盘放到所有飞盘的最后。输入N，输出每次扔掉的飞盘，以及最后剩下的飞盘。
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        queue<int> q;
        for (int j = 0; j < n; j++)
            q.push(j + 1);
        while (!q.empty())
        {
            printf("%d ", q.front());
            q.pop();
            if (q.empty())
                break;
            else
            {
                int a = q.front();
                q.pop();
                q.push(a);
            }
        }
        cout << endl;
    }
}