 #include <bits/stdc++.h>

    using namespace std;

    int main()
 {
     ifstream fd ("duota.txt");
     ofstream fr ("rezultatai.txt");
     bool first = true, neww= true, was = true;
     int n, length = 1;
     fd >> n;
     fd.ignore(80, '\n');
     string s[n], a[n];
     string z,sorted;
     for (int i=0; i < n; i++)
     {

         getline(fd, s[i]);
          a[i] = s[i];
         if (first == true)
         {
            sort(a[i].begin(), a[i].end());
             first = false;
             length++;
         }
         else for (int y=0; y<length; y++)
         {
             sorted =s[i];
             sort(sorted.begin(), sorted.end());
            if (sorted == a[y])
          {
             neww = false;
          }
         }
         if (neww == true)
         {
            a[length-1] = sorted;
             length++;
         }
         neww = true;
     }
     first = true;
     for (int i=0; i<length; i++)
     {
         for (int y=0; y<n; y++)
         {
             sorted = s[y];
             sort(sorted.begin(), sorted.end());
             if (a[i]==sorted)
                 {
                     was = true;
                     if (first == true)
                     {
                        fr << s[y];
                        first = false;
                     }
                    else
                        fr << ", " << s[y];
                 }
         }
         if (was == true)
         {
             fr << "."<<endl;
             was = false;
         }
         first = true;
     }
    fr.close();
    fd.close();



    return 0;
 }
