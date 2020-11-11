# include <bits/stdc++.h>

using namespace std;

/* This program determines the cost of travelling on a certain road. Different times have different costs.
The main objective is to understand the date from the given format and make it compatible for calculations.
*/

struct car{
    bool good;
    int enter, exit, start, finish, times = 0;
    float price;
    string plate;
    car()
    {
        good = false;
        price = 0;
    }
};
bool comp(car vienas,car du){
    return (vienas.plate<du.plate);
}

int main ()
{
    freopen("duota.txt","r",stdin);
    int K[24]; //price for every hour
    for(int i=0; i<24; i++)
        cin >> K[i];
    cin.ignore(80, '\n');
    car C[500];
    int differentC = 0;
    while(!cin.eof())
    {
        string line, plate, time;
        getline(cin, line);
        if(line.length() < 2)
            break;
        int pos;
        pos = line.find(':');
        plate = line.substr(0, pos - 3);
        time = line.substr(pos+4, 5);
        string day, hour, minute;
        day = line.substr(pos+1, 2);
        hour = time.substr(0, 2);
        minute = time.substr(3, 2);
        int hours = stoi(hour), minutes = stoi(minute), days = stoi(day);
        bool is = false;
        for(int i=0; i<differentC; i++)
            if(C[i].plate == plate)
            {
                is = true;
                C[i].good = true;
                C[i].times++;
                if(line.substr(pos+10, 4) == "exit")
                {
                    C[i].exit = days * 24*60 + hours * 60 + minutes;
                    C[i].finish = stoi(line.substr(pos+15));
                }
                else
                {
                    C[i].enter = days * 24*60 + hours * 60 + minutes;
                    C[i].start = stoi(line.substr(pos+15));
                }
                if(C[i].times % 2 == 0) //every second mention must be an exit/entrance (depending on what we had first), so we must calculate the price of the travel
                {
                    int faretime = (C[i].enter-C[i].enter /24/60 * 24*60) / 60;
                    float priceadd = (C[i].finish - C[i].start) * K[faretime];
                    C[i].price = C[i].price + priceadd / 100 + 1;
                }

            }
        if(!is) //if that car has not yet driven
        {
            C[differentC].plate = plate;
            if(line.substr(pos+10, 4) == "exit")
            {
                C[differentC].exit = days * 24*60 + hours * 60 + minutes;
                C[differentC].finish = stoi(line.substr(pos+15));
                C[differentC].times++;
            }
            else
            {
                C[differentC].enter = days * 24*60 + hours * 60 + minutes;
                C[differentC].start = stoi(line.substr(pos+15));
                C[differentC].times++;
            }
            differentC++;
        }
    }
    sort(C, C+differentC, comp);
    for(int i=0; i<differentC; i++)
        if(C[i].good)
        {
            cout << C[i].plate <<" $"<< fixed << setprecision(2) << C[i].price + 2 <<endl;
        }

    return 0;
}
