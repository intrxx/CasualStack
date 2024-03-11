#include <stdio.h>
#include <malloc.h>

typedef struct StackElement {
    int Data;
    struct StackElement* Last;
} StackElementType;

// Podwójny wskaźnik po to żeby StackElementType** wskazywał na wskaźnik (a nie na dane) przez co mógł go edytować
void Push(StackElementType** Top, int Number);
int Pop(StackElementType** Top);
void Peek(StackElementType** Top);
void MainLoop();

int main()
{
    MainLoop();

    return 0;
}

void Push(StackElementType** Top, int Number)
{
    if(*Top == NULL)
    {
        *Top = (StackElementType*) malloc(sizeof(StackElementType));
        (*Top)->Data = Number;
        (*Top)->Last = NULL;
    }
    else
    {
        StackElementType* NewElement;
        NewElement = (StackElementType*) malloc(sizeof(StackElementType));
        NewElement->Data = Number;
        NewElement->Last = *Top;
        *Top = NewElement;
    }
}

int Pop(StackElementType** Top)
{
    int DataToPop = 0;

    if(*Top != NULL)
    {
        DataToPop = (*Top)->Data;

        StackElementType* Temp = NULL;
        Temp = (*Top)->Last;
        free(*Top);
        *Top = Temp;
    }

    return DataToPop;
}

void Peek(StackElementType** Top)
{
    if(*Top != NULL)
    {
        printf("Element from the top of the stack: %i \n", (*Top)->Data);
    }
    else
    {
        printf("The stack is empty");
    }
}

void MainLoop()
{
    StackElementType* Top;
    Top = NULL;

    int Option = -1;
    int Number = -1;

    while(Option != 0)
    {
        printf("1. Push element to the stack \n");
        printf("2. Pop element from the stack \n");
        printf("3. Print element from the stack \n");
        printf("0. Exit \n");

        scanf("%i", &Option);

        switch(Option)
        {
            case 0:
                return;
                break;
            case 1:
                printf("Pleas provide a integer: \n");
                scanf("%i", &Number);
                Push(&Top, Number);
                break;
            case 2:
                Pop(&Top);
                break;
            case 3:
                Peek(&Top);
                break;
            default:
                printf("Choose a proper option \n");
                break;
        }
    }
}
