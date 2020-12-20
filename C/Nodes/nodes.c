# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define MAX 10
typedef struct node
{
    int number;
    struct node *next;
} node;

void createNodes(node **first, int size)
{
    *first = (node*)malloc(sizeof(node));
    if(size < 1)
    {
        printf("Ivestas permazas dydis, sarasas nebuvo sukurtas\n");
        return;
    }
    srand (time(NULL));
    node *element;
    (*first)->number = rand() % MAX;
    if(size == 1)   // isimtinis atvejis, kai pirmas yra paskutinis
    {
        (*first)->next = NULL;
        return;
    }
    element = *first;
    for(int i = 1; i < size; ++i) //sukuriame vienu maziau nei reikia
    {
        node *next;
        next = (node*)malloc(sizeof(node));
        next->number = rand() % MAX;
        element->next = next; //musu preitas rodo i nauja sukurta
        element = next;
    }
    element->next = NULL; //paskutinis rodo i NULL
}
void printAll(node *first)
{
    node *element = first;
    while(element != NULL) //spausdiname elementus kol nera NULL elementas
    {
        printf("%d ", element->number);
        element = element->next; //pereiname prie sekancio
    }
    printf("\n");
}
void printNode(node *first, int number) //skaiciuoja nuo 0
{
    node *element = first;
    for(int i = 0; i < number; i++)
    {
        element = element->next;
        if(element == NULL) //jei pasiekiame NULL, nepasiekus savo norimo elemento
        {
            printf("Sarase yra per mazai elementu");
            return;
        }
    }
    printf("%d\n", element->number); //jei pasiekeme savo elementa, ji spausdiname
}
void deleteNode(node **first, int number)
{
    node *element;
    element = *first;
    if(number == 0)
    {
        element = element->next;
        free(*first);
        *first = element;
        return;
    }
    for(int i=0; i < number - 1; ++i)
    {
        element = element->next;
        if(element->next == NULL)
        {
            printf("Sarase yra per mazai elementu\n");
            return;
        }
    }
    node *last;
    last = element->next;
    element->next = last->next;
    free(last);
}
void clearAll(node **first)
{
    node *temp;
    temp = *first;
    while(*first != NULL) //triname elementus kol ju yra
    {
        *first = (*first)->next;
        free(temp); //pereiname prie sekancio
        temp = *first;
    }
}

