# include <bits/stdc++.h>
using namespace std;

char R[101][101];
int n, m;

    void Naikinti (int i, int y);

	int main()
{
   ifstream fd ("duota.txt");
   ofstream fr ("rezultatai.txt");
   int k=0;
   fd >> n >> m;
   fd.ignore (80, '\n');
   char R[n][m];
   for (int i=0; i<n; i++)
    for (int y=0; y<m; y++)
       {
           fd >> R[i][y];
            cout<<R[i][y]<<endl;
       }

   for (int i=0; i<n; i++)
    for (int y=0; y<m; y++)
        if (R[i][y] == 1)
           {cout << " a";
               Naikinti(i, y);
               k++;
           }
   fr << k;
   cout << R[0][0];



return 0;
}

void Naikinti (int i, int y){

    R[i][y]=0;
    if (R[i+1][y]==1 && i<n-1)
        Naikinti(i+1, y);
    if (R[i-1][y]==1 && i>0)
        Naikinti(i-1, y);
    if (R[i][y+1]==1 && y<m-1)
        Naikinti(i, y+1);
    if (R[i][y-1]==1 && y>0)
        Naikinti(i, y-1);
}

