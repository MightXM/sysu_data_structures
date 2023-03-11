#include <iostream>
#include <string.h>
using namespace std;
bool srcContaindst1(char src[], char des[])
{
    if (*src == NULL || *des == NULL || strlen(src) == 0 || strlen(des) == 0 || strlen(src) < strlen(des))
        return false;
    int srclen = strlen(src);
    for (int i = 0; i < srclen; i++)
    {
        char firstChar = src[0];
        for (int j = 0; j < srclen - 1; j++)
        {
            src[j] = src[j + 1];
        }
        src[srclen - 1] = firstChar;
        if (strstr(src, des) != NULL)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    char a1[100], a2[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a1);
        scanf("%s", a2);
        if (srcContaindst1(a1, a2))
            cout << "True" << endl;
        else if (!srcContaindst1(a1, a2))
            cout << "False" << endl;
    }
}