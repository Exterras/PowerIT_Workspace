#include <stdio.h>

struct data_box{
    int a;
    int b;
};

int main(void){

    // test01();
    // test02();
    exec_swap(10, 20);
    return 0;
}

void test01(){
    int a;
    int *pa;

    pa = &a;
    *pa = 10;

    printf("%d\n", *pa);
    printf("%d\n", a);
    printf("%d\n", pa);
    printf("%d\n", &a);.
}

void test02(){
    int a=10, b=15, tot = 0;
    double avg = 0.0;
    int *pa, *pb;
    int *pt = &tot;
    double *pg = &avg;

    pa = &a;
    pb = &b;

    *pt = *pa + *pb;
    *pg = *pt / 2.0;

    printf("%d, %d\n", *pa, *pb);
    printf("%d\n", *pt);
    printf("%.1lf\n", *pg);
}

void exec_swap(int a, int b){
    para_swap(&a, &b);
    printf("a:%d, b:%d\n", a, b);
}

void para_swap(int *pa, int *pb){
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

