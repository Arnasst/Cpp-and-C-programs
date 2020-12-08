 #include <bits/stdc++.h>

    using namespace std;

    struct date {
    string date;
    int numt;
    float price[101];
    string thing[101];
        date()
        {
            numt = 0;
            for (int i=0; i<101; i++)
                price[i]=0;
        }
    };

    int main()
 {
     ifstream fd ("duota.txt");
     ofstream fr ("rezultatai.txt");
     int n,prekiuskc,dateNum=0;
     float daugiklis;
     float suma=0;
     bool yra = false, dateyra = false;
     date D[101];
     fd >> n;
     char p[21],dat[11];
     for (int i = 0; i<n; i++)
     {
         fd.ignore (80, '\n');
         fd.get (p, 21);
         fd.get (dat, 11);
         fd >> prekiuskc;
         for (int y=0; y<dateNum; y++)
            if (D[y].date == dat)
            {
                dateyra = true;
                for (int yy=0; yy<D[y].numt; yy++)
                {
                    if (D[y].thing[yy] == p )
                        {
                            D[y].price[yy]+= prekiuskc;
                            yra = true;
                        }
                }
            if (!yra)
            {
                D[y].thing[D[y].numt] = p;
                D[y].price[D[y].numt] = prekiuskc;
                D[y].numt++;
            }
            yra = false;
            }
            if (!dateyra)
        {
             D[dateNum].date = dat;
             D[dateNum].thing[D[i].numt] = p;
             D[dateNum].price[D[i].numt] = prekiuskc;
             D[dateNum].numt ++;
             dateNum++;
        }
     }
     fd >> n;
     for (int i=0; i<n; i++)
     {
         fd.ignore (80, '\n');
         fd.get (p, 21);
         fd >> daugiklis;
         for (int y=0; y<dateNum; y++)
            for (int yy=0; yy<D[y].numt; yy++)
            {
                if (p == D[y].thing[yy])
                {
                    D[y].price[yy] = D[y].price[yy] * daugiklis;
                    suma += D[y].price[yy];
                }
            }
     }
     for(int i=0; i<dateNum; i++)
        for(int y=i+1; y<dateNum; y++)
            if(D[i].date > D[y].date)
                swap(D[i], D[y]);

    for (int i=0; i<dateNum; i++)
        for (int y=0; y<D[i].numt; y++)
            for (int yy=y+1; yy<D[i].numt; yy++)
                if (D[i].thing[y] > D[i].thing[yy])
                {
                    swap (D[i].thing[y], D[i].thing[yy]);
                    swap (D[i].price[y], D[i].price[yy]);
                }

     for (int i=0; i<dateNum; i++)
     {
         fr << D[i].date<<endl;
         for (int y=0; y<D[i].numt; y++)
         {
             fr << D[i].thing[y]<< " " <<fixed<< setprecision(2) <<D[i].price[y] <<endl;
         }
     }
     fr <<fixed<< setprecision(2) << suma;


    fd.close();
    fr.close();

    return 0;
 }
