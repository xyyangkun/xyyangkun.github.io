#include <stdio.h>
int print(int seq[], int size);
static void swap(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
void bubble(int seq[], int size)
{
   int seq_nu1;
   int seq_nu2;
   for(seq_nu1 = 0; seq_nu1 < size-1; seq_nu1++)
   {
       for(seq_nu2 =0; seq_nu2 < size -1 - seq_nu1 ; seq_nu2++)
       {
           if(seq[seq_nu2] > seq[seq_nu2+1])
           {
               swap(&seq[seq_nu2], &seq[seq_nu2+1]);
           }
           
       }
       print(seq, size-seq_nu1);
   }
}
int print(int seq[], int size)
{
    int seq_nu;
    for(seq_nu = 0; seq_nu < size; seq_nu++)
    {
        printf("%d\t", seq[seq_nu]);
    }
    printf("\n");
    return 0;
}
int seq[]={1,3,5,2,1,4};
int main()
{
    print(seq, sizeof(seq)/sizeof(int));
    bubble(seq, sizeof(seq)/sizeof(int));
    print(seq, sizeof(seq)/sizeof(int));
}
