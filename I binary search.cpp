# include <bits/stdc++.h>

using namespace std;
/* Program that has to quess the number from 1 to 1000 depending on the answers to the quess. I implemented binary search for it to be efficient
*/

int main ()
{
    string s = "";
    int quess = 500, maks = 1000, mini = 1;
    while(s != "correct")
    {
        cout << quess << endl;
        cout.flush();
        cin >> s;
        if(s == "lower")
        {
            maks = quess - 1;
            quess = floor((maks + mini) / 2) ;
        }
        if(s == "higher")
        {
            mini = quess + 1;
            quess = floor((mini + maks) / 2);
        }
    }

    return 0;
}
