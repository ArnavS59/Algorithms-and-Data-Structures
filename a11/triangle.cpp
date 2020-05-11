#include <iostream>
using namespace std;
#define N 1000

int maxpathsum(int tri[][N], int m, int n) //loop for bottomup calculation
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (tri[i + 1][j] > tri[i + 1][j + 1])
            {
                tri[i][j] += tri[i + 1][j]; //checking if the number to the below is greater and the adding it
            }
            else
            {
                tri[i][j] += tri[i + 1][j + 1]; ////checking if the number to the right is greater and the adding it
            }
        }
    }
    return tri[0][0];
}

void SUMhelp(int data[][N], int sums[][N], int i, int j, int n)
{
    if (i + 1 >= n or j + 1 >= n)
    {
        cout << data[i][j];
    }
    else
    {
        cout << data[i][j];
        if (sums[i + 1][j] > sums[i + 1][j + 1])
        {
            SUMhelp(data, sums, i + 1, j, n);
        } //if left child is max
        else
        {
            //if right child is max
            SUMhelp(data, sums, i + 1, j + 1, n);
        }
    }
}

void SUMPATH(int data[][N], int sums[][N], int n)
{

    SUMhelp(data, sums, 0, 0, n);
}

void showpath1(int tri[][N], int m, int n)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((tri[i + 1][j] > tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j]) > tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j] << " ";
            }
            else if ((tri[i + 1][j] > tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j]) < tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j + 1] << " ";
            }
            else if ((tri[i + 1][j] < tri[i + 1][j + 1]) && ((tri[i][j] += tri[i + 1][j + 1]) > tri[i][j + 1]))
            {
                cout << " " << tri[i + 1][j] << " ";
            }
            else
            {
                cout << " " << tri[i + 1][j + 1] << " ";
            }
        }
    }
}

int main()
{
    int tri[N][N] = {{7, 0, 0, 0, 0},
                     {3, 8, 0, 0, 0},
                     {8, 1, 0, 0, 0},
                     {2, 7, 4, 4, 0},
                     {4, 5, 2, 6, 5}};

    int sums[N][N] = {{7, 0, 0, 0, 0},
                      {3, 8, 0, 0, 0},
                      {8, 1, 0, 0, 0},
                      {2, 7, 4, 4, 0},
                      {4, 5, 2, 6, 5}};

    cout << maxpathsum(sums, 4, 4) << endl;
    SUMPATH(tri, sums, 5);
    cout<<endl;
    return 0;
}