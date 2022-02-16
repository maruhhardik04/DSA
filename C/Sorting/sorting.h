#ifndef SORTING_H
#define SORTING_H

typedef struct Data
{
    int Size;
    int *arr;
}Data;

Data Create();
void Print(Data *self);
void Selection_sort(Data *data);
void Bubble_sort(Data *data);
// void Two_Way_Merge_sort(Data *data);
// void Quick_sort(Data *data);
// void Heap_sort(Data *data);
void Swap(int *old,int *New);



int i,j;

/*
    Initialization of Data
    retrurning of Struct Data 
*/
Data Create()
{
    Data data;
    printf("How many Elements you want to store:");
    scanf("%d",&data.Size);

    data.arr = (int*) malloc(data.Size * sizeof(int));

    printf("\nEnter a Value:");
    for (i = 0; i < data.Size; i++)
    {
        scanf("%d",&data.arr[i]);
    }
    
    return data;
}


/*
    Printing  Struct Data
*/
void Print(Data *self){
    
    printf("\n");
    for (i = 0; i < self->Size; i++)
    {
        printf(" %d ",self->arr[i]);
    }


}


/*
    Swaping Two Values
*/
void Swap(int *old,int *new)
{

    int temp=*old;
    *old=*new;
    *new=temp;
}


/*
     Selection Sort 
*/
void Selection_sort(Data *data)
{
    printf("\nSelection Sort:\n");

    int min=0;
    for (i = 0; i < data->Size-1; i++)
    {
        min=i;
      
        for (j = i+1; j < data->Size; j++)
        {
            if(data->arr[min] > data->arr[j])
            {
                    min=j;
            }
        }
        if(min != i)
        {   
            Swap(&data->arr[i],&data->arr[min]);
        }
    
    }
}

/*
    Bubble Sort
*/
void Bubble_sort(Data *data)
{
        printf("\nBubble Sort:\n");

        for (i = 0; i < data->Size-1; i++)
        {
            for (j = 0; j < data->Size-i-1; j++)
            {
                if (data->arr[j+1] < data->arr[j])
                {
                    Swap(&data->arr[j],&data->arr[j+1]);
                }
                
            }
            
        }
}




#endif 
