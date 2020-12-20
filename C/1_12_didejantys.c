# include <stdio.h>
# include <stdlib.h>

int main ()
{
    float first;
    float second;
    char *again = 'y'; //string, kad zmogus ivedes daugiau nei viena raide nesukeltu nemalonumu
    while(again == 'y')
    {
        system("cls"); //nuvalo ekrana
        int amountOfNumbers = 2; //pradiniai du skaiciai yra musu seka
        printf("Iveskite didejanciu skaiciu seka: (noredami ja uzbaigti iveskite mazesni skaiciu) \n");
        while(scanf("%f", &first)!= 1) //jeigu iveda neskaiciu, suka kol ives skaiciu
        {
            printf("Netinkama ivestis, iveskite skaiciu, jog testumete\n");
            scanf("%*[^\n]"); //pravalo scanf, kad nebutu infinite loop
        }
        while(scanf("%f", &second)!= 1) //tas pats su antru skaiciumi
        {
            printf("Netinkama ivestis, iveskite skaiciu, jog testumete\n");
            scanf("%*[^\n]");
        }
        float sum = first + second; //suma gauta is pirmu dvieju skaiciu
        for(;second > first;) //jei antras skaicius didesnis leidziame vesti ir toliau
        {
            int temp;
            temp = second;
            while(scanf("%f", &second)!= 1)//tikrina ar naujas skaicius yra skaicius
            {
                printf("Netinkama ivestis, iveskite skaiciu, jog testumete\n");
                scanf("%*[^\n]");
            }
            amountOfNumbers++; //padidiname sekos nariu skaiciu
            sum += second; //pridedame skaiciu prie sumos
            first = temp; //isimename antra skaitmeni ir pamirstame pirma
        }
        float average;
        average = sum / amountOfNumbers; //randame aritmetini vidurki
        printf("Aritmetinis vidurkis: %0.3f, o nariu skaicius %d\n", average, amountOfNumbers); //spausdinimas aritmetinio vidurkio, 3skc po kablelio ir nariu skaiciaus
        printf("Jei norite ivesti dar viena didejanciu skaiciu seka rasykite 'y', noredami iseiti parasykite kita simboli \n");
        scanf("%s", &again); //suzino ar nori zaisti dar karta
    }

    return 0;
}
