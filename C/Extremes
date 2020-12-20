# include <stdio.h>
# include <stdlib.h>
/*Įvesti sveiką skaičių N. Įvesti N sveikų skaičių, kurie sudarys vektorių. Rasti
didžiausią atstumą (matuojant elementų pozicijomis) tarp šio vektoriaus ekstremumų.
Ekstremumu laikomas toks vektoriaus elementas, iki kurio yra didėjanti seka, o po jo yra
mažėjanti seka, arba, atvirkščiai, iki jo yra mažėjanti seka, o po jo yra didėjanti seka.
Programa turėtų išvesti elementų numerius ir atstumą tarp jų.
*/
void scanArray(int n, int **vector);
int findExtremes(int *first, int *second, int *maxLength, int *vector, int n);

int main ()
{
    int n;
    scanf("%d", &n);
    int *vector, numberOfExtremes = 0;
    int maxLength = 0, first, second;
    scanArray(n, &vector);
    numberOfExtremes = findExtremes(&first, &second, &maxLength, vector, n);
    if(numberOfExtremes < 2)
        printf("Per mazai ekstremumu, kad butu galima apskaiciuoti didziausia atstuma tarp ju\n");
    else
        printf("Ekstremumai %d ir %d ir atstumas tarp ju yra %d\n", first, second, maxLength);
    free(vector);
    return 0;
}

void scanArray(int n, int **vector)
{
    *vector = (int*)malloc(sizeof(int)* n);
    for(int i=0; i<n; ++i)
        scanf("%d", &(*vector)[i]);
}

int findExtremes(int *first, int *second, int *maxLength, int *vector, int n)
{
    int *extreme, numberOfExtremes = 0;
    extreme = (int*)malloc(sizeof(int)* n/2);
    int isGrowing = 0, isShrinking = 0, last, firstTime = 1;
    for(int i=1; i<n; ++i)
    {
        last = vector[i-1];
        if(vector[i] > last && !isGrowing)
        {
            isGrowing = 1;
            isShrinking = 0;
            if(!firstTime)
            {
                extreme[numberOfExtremes] = i;
                if(numberOfExtremes >= 1)
                {
                    int difference = extreme[numberOfExtremes] - extreme[numberOfExtremes-1];
                    if(difference > *maxLength)
                    {
                        *maxLength = difference;
                        *first = extreme[numberOfExtremes-1];
                        *second = extreme[numberOfExtremes];
                    }
                }
                numberOfExtremes++;
            }
            else
                firstTime = 0;
        }
        if(vector[i] < last && !isShrinking)
        {
            isGrowing = 0;
            isShrinking = 1;
            if(!firstTime)
            {
                extreme[numberOfExtremes] = i;
                if(numberOfExtremes >= 1)
                {
                    int difference = extreme[numberOfExtremes] - extreme[numberOfExtremes-1];
                    if(difference > *maxLength)
                    {
                        *maxLength = difference;
                        *first = extreme[numberOfExtremes-1];
                        *second = extreme[numberOfExtremes];
                    }
                }
                numberOfExtremes++;
            }
            else
                firstTime = 0;
        }
    }
    free(extreme);
    return numberOfExtremes;
}
