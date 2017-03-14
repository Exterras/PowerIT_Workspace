#include <stdio.h>
#include <stdlib.h>

void file_open(void);
void fault_detection(int _startCount, int _endCount);

int main(){
    file_open();
    // fault_detection(180, 280);
    return 0;
}

void file_open(){
    FILE *fp;
    double data;

    fp = fopen("Avg_D1_Normalization_ABFault.txt", "r");
    if(fp == NULL){
        printf("fail");
    }
    while((data = fgetc(fp))!= EOF){
        printf("%lf", data);
    }

    fclose(fp);
}

void fault_detection(int _startCount, int _endCount){
    int arrLength = _endCount - _startCount + 1;

    double current_a_0[arrLength];
    double current_a_45[arrLength];
    double current_a_90[arrLength];

    double current_b_0[arrLength];
    double current_b_45[arrLength];
    double current_b_90[arrLength];

    double current_c_0[arrLength];
    double current_c_45[arrLength];
    double current_c_90[arrLength];
}
