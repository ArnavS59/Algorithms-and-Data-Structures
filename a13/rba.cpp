#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int d = 256;
//Refrence: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
void Rabin_karp_algo(char txt[], char pattern[])
{
    int n = strlen(txt);
    int m = strlen(pattern);
    int prime = 101;
    int patt = 0; //hash value for pattern
    int text = 0; //hash value for text
    int hash = 1;
    int i, j;

    for (i = 0; i < m-1; i++)
        hash = (hash * d) % prime;// we do we need the d for and h a bit unsure

    for (i = 0; i < m; i++)
    {
        patt = (patt*d + pattern[i]) % prime;
        text = (text*d + txt[i]) % prime;
    }
    for (i = 0; i <= n - m; i++) // max number of shifts possible
    {
        if (patt == text)//if match found
        { /* if the hash values of the pattern and the text are the  smae yhen yes we found a posssible candiadte and then only we scan charcters and check if it is a match*/
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pattern[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        else//not found a match therefore we roll over to the next position and use the  hashing
        { 
            if (i < n - m)
            {
                text = (d * (text - txt[i] * hash) + txt[i + m]) % prime;

                if(text<0)//if the text value is negative we just make it positive by adding the prime
                text=(text+prime);
            }
        }
    }
}

int main()
{
    char text[] = "arnavie arn arnay arnav";
    char pattern[] = "arnav";
    Rabin_karp_algo(text, pattern);

    return 0;
}