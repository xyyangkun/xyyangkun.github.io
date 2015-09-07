#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void print(int *p, int size);
static void bubble_soft(int *array, int size);
static void select_soft(int *array, int size);
static void insert_soft(int *array, int size);
static void quick_soft(int *array, int size);
static void usage(char *name);
#define SWAP(A, B) (A)=(A)^(B),(B)=(A)^(B),(A)=(A)^(B)
//判断是不是阿拉伯数字
#define ISA(chr) ((unsigned char)chr <='9' && (unsigned char)chr >= '0')
//判断字符串是不是全是字
static inline int IS_NUM(unsigned char *numstr) ;

typedef void (*fun)(int *array, int size);

typedef struct myfun
{
    fun fp;//fun poting
    const char *fname;
}mf;

#define INIT_MY(FUNNAME) {FUNNAME##_soft, #FUNNAME}
fun soft[]={bubble_soft, select_soft};

mf alg[]={INIT_MY(bubble), INIT_MY(select), INIT_MY(insert), INIT_MY(quick)};

int main(int argc, char *argv[])
{
    
    int no;
    //int array[] = {1000 ,201, 100, 5, 10, 5, 20, 100};
    int array[] = {1 ,201, 100, 5, 8, 8, 9, 10, 5, 20, 100};
    int parm;
    if (argc !=2 || ! IS_NUM((unsigned char *)(argv[1])))
    {
        usage(argv[0]);
        return -1;
    }
    else
    {
        //printf("debug: %s  %d",argv[1], atoi(argv[1]));
        parm = atoi(argv[1]);
        if(parm <0 || parm >= (int)(sizeof(alg)/sizeof(mf))+1)
        {
            usage(argv[0]);
            return -1;
        }
    }

    if (parm==0)
    {
        int size = sizeof(array);
        int *array_copy=(int *)malloc(size);
        for(no = 0; no < (int)(sizeof(alg)/sizeof(mf)); no++)
        {
            memset(array_copy, 0, size);
            memcpy(array_copy, array, size);
            printf("algorithm %s:\n", alg[no].fname);
            printf("Before soft:\n");
            print(array_copy, size/sizeof(int));
            //调用函数
            alg[no].fp(array_copy, sizeof(array)/sizeof(int));
            printf("After soft:\n");
            print(array_copy, size/sizeof(int));
            printf("\n");
        }
        free(array_copy);
        array_copy = NULL;
    }
    else if(parm >=1 && parm <= (int)(sizeof(alg)/sizeof(mf))+1)
    {
        printf("algorithm %s:\n", alg[parm-1].fname);
        printf("Before soft:\n");
        print(array, sizeof(array)/sizeof(int));
        //调用函数
        alg[parm-1].fp(array, sizeof(array)/sizeof(int));
        printf("After soft:\n");
        print(array, sizeof(array)/sizeof(int));
        printf("\n");
    }
    else
    {
        //程序不会走到这，是哪出错了。
        printf("error!!!!!!!!!!!!!\n");
        printf("some bugs !!!");
        return -1;
    }

    return 0;
}

static void usage(char *name)
{
#define SOFTSTR "soft algorithm"
    int no;
    printf("%s\tparm\n", name);
    printf("example:\n");
    printf("%s\t%d run %s %s\n",name, 0, " all ", SOFTSTR);
    for(no = 0; no < (int)(sizeof(alg)/sizeof(mf)); no++)
    {
       printf("%s\t%d run %s %s\n",name, no+1, alg[no].fname, SOFTSTR);
    }

}
//返回 0是数字 1不是数字
static inline int IS_NUM(unsigned char *numstr) 
{
    int no;
    for(no=0; no < (int)strlen((const char *)numstr); no++)
    {
        //不能大于最大长度                           最大长度不大于16 要是数字字符
        if ( no > 16 || ! ISA(numstr[no]))
        {
            //printf("debug--%10s---%2d--%2c--\n",numstr, no, numstr[no]);
            return 0;
        }
    }
    return 1;
}

void print(int *p, int size)
{
    int no;
    //printf("print the mem:\n");
    for(no = 0; no < size; no++)
    {
        printf("%4d", p[no]);
        if(size <= 7 && no==7)
            continue;
        if(no !=0 && no % 7==0)
            printf("\n");
        else
            printf("\t");
    }
    printf("\n");
}
static void bubble_soft(int *array, int size)
{
    int no1, no2;
    for(no1 = 0; no1 < size; no1++)
    {
        //printf("no1:%d\n", no1);
        for(no2 = 0; no2 < size- 1 -no1; no2++)
        {
            //printf("no2:%d\n", no2);
            //最大的放到最后
            if(array[no2] > array[no2+1])
                SWAP(array[no2] ,array[no2+1]);
            //print(array, size);
        }
    }
}

void select_soft(int *array, int size)
{
   int min_mark;//当前处理的位置
   int no1, no2;

   for(no1 = 1; no1 < size; no1++)
   {
       min_mark = no1 - 1;
       for (no2 = no1; no2 < size; no2++)
       {
           if ( array[min_mark] > array[no2] )
           {
               min_mark = no2;
           }
       }
       if ( min_mark != no1-1 )
       {
           SWAP(array[no1-1], array[min_mark]);
       }
   }
}

static void insert_soft(int *array, int size)
{
    int no1, no2;
    int tmp;
    int mark;
    for(no1 = 1; no1 < size; no1++)
    {
        //printf("no1=%d\n", no1);
        //选择第一个值
        tmp = array[no1];
        mark = 0;
        for(no2 = no1; no2 > 0; no2--)
        {
           //printf("no2=%d\n", no2);
           //print(array, size);
           //把最大的放右边 
           if (array[no2-1] > tmp )
           {
               array[no2] = array[no2-1];
           }
           else
           {
               break;
           }
           array[no2-1]=tmp;
        }
        //print(array, size);
    }
}

static void quick_soft(int *array, int size)
{
    int pivotindex=0;   //set first element as pivot
    int storeindex = pivotindex + 1; 
    int no;
    for(no = storeindex; no < size; no++)
    {
        printf("no:%d  piv:%d\n", array[no], array[pivotindex]);
        if (array[no] < array[pivotindex])
        {
            SWAP(array[no], array[pivotindex]);
            storeindex++;
        }
    }
    SWAP(array[pivotindex], array[storeindex - 1]);
    pivotindex++;
    printf("debug: pivotindex:%d   storeindex:%d\n", pivotindex, storeindex);
    if(pivotindex >= storeindex)
    {
        return ;
    }
    quick_soft(&array[pivotindex], storeindex -1);
    quick_soft(&array[storeindex + 1], size-(storeindex-pivotindex));

}
