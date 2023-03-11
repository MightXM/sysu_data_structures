#include <iostream>
#include <vector>
using namespace std;
int Hash(int key, int m)
{
    return key % m;
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            printf("%d#%d\n", i, v[i]);
        }
        else
        {
            printf("%d#NULL", i);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m, 0);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        int h = Hash(t, m);
        while (v[h] != 0)
        {
            h += 1;
            if (h >= m)
                h -= m;
        }
        v[h] = t;
    }
    print(v);
}