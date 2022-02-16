#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "sorting.h"

int main(int argc, char const *argv[])
{
    Data data;
    data=Create();
    Selection_sort(&data);
    Print(&data);
    getch();
    return 0;
}
