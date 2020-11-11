# include <bits/stdc++.h>

using namespace std;
/* Program that calculates the probability of dying, when someone must draw cards and there are some damaging cards
*/

int main ()
{
    //freopen("duota.txt","r",stdin);
    double a, b, c;
    double probability = 0, last = 1;
    cin >> a >> b >> c;
    if( c > b*5 )
        probability = 1;
    else
        while(b > 0 && c > 0)
        {
            probability += (1- b/a) * last;
            last *= b / a;
            b--;
            a--;
            c -= 5;
        }
    if(probability != 1)
        cout << fixed << setprecision(9) << probability;
    else
        cout <<probability;

    return 0;
}

