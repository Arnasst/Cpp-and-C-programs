# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int Change_line(char *line, char newLine[], FILE *duomenys);

int main(int argc, char *argv[])
{
    printf("Si programa duotame tekste keleta is eiles einanciu vienodu simboliu (isskyrus tarpus)\npakeicia vienu tokiu simboliu, $ ir skaiciumi buvusiu simboliu\n\n");
    FILE *duomenys;
    FILE *rezultatai;
    char *dataName, *rezName;
    dataName = argv[1];
    rezName = argv[2];
    duomenys = fopen(dataName, "r");
    rezultatai = fopen(rezName, "w");
    //duomenys = fopen("duota.txt", "r");
    //rezultatai = fopen("rezultatai.txt", "w");
    if(ferror(duomenys))
    {
        printf("Problema su duomenu failu");
        return 5;
    }
    if(ferror(rezultatai))
    {
        printf("Problema su rezultatu failu");
        return 6;
    }
    char *line = NULL;
    line = (char*) malloc(sizeof(char)*256);
    while(1)
    {
        fgets(line, 256, duomenys); //paima 255 charakterius
        char newLine[256] = "";
        int notend = Change_line(line, newLine, duomenys);  // jei yra 0 reiskia pasiekta failo pabaiga
        fprintf(rezultatai, "%s", newLine);//spausdiname nauja line
        if(!notend)
            break;
    }
    free(line);
    fclose(duomenys);
    fclose(rezultatai);

    return 0;
}

int Change_line(char line[], char newLine[], FILE *duomenys)
{
    int times = 1, newLength = 0;
    char last = line[0]; //pirmas simbolis nustatomas kaip last
    for(int i=1; i<=strlen(line); ++i)
    {
        if(last == line[i]) //jei tas pats elementas pridedame prie pasikartojimu
            times++;
        else
        {
            newLine[newLength] = last;//jei nebesikartoja irasome simboli i nauja line
            newLength++;
            if(times > 1 && last != ' ') //jei kartojosi daugiau nei karta
            {
                newLine[newLength] = '$';
                newLength++;
                char kartai[4] = "";
                itoa(times, kartai, 10); //pavercia pasikartojimus is int i char, nes gali buti ne vienazenklis skaicius
                for(int y = 0; y<strlen(kartai); ++newLength, ++y)
                    newLine[newLength] = kartai[y];
            }
            last = line[i]; //pakeiciame paskutini simboli ir pasikartojimu skaiciu
            times = 1;
            }
    }
    //newLine[newLength] = '\0'; //pazymime naujos eilutes pabaiga
    if(feof(duomenys)) //jei baigiasi duomenys iseiname
        return 0;
    return 1;
}

