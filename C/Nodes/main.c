//# include <stdio.h>
//# include <stdlib.h>
# include "nodes.h"

int main ()
{
    node *first;
    createNodes(&first, 5);
    printAll(first);
    printNode(first, 1); //skaiciuoja nuo 0
    deleteNode(&first, 4); //skaiciuoja nuo 0
    printAll(first);
    clearAll(&first);
    return 0;
}
