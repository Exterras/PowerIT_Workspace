/**
* This is Fuzzy Program (C)
*
* by. Exterra (Tae-il Choi)
*
* "\t" is tab
*/

#include <stdio.h>
#include <stdlib.h>

// function prototype
void fuzzyOn(int *_num, int _numLength, int _degree, double _avgRate, int _highFuzzy_LowNum); // (fuzzy's degree, )
void fuzzyPrint(char* _str, double* _arrFuzzyValue, int _numLength); // fuzzy print function

// main
int main(){
    // fuzzy data and data length
    int num[] = {167, 484, 681, 486, 351, 198, 189, 471, 648, 424, 998}; // initialize value
    int numLength = sizeof(num) / sizeof(num[0]);

    // execute functions
    fuzzyOn(num, numLength, 100, 0.5, 666);
    return 0;
}

// function of bubble sort
void fuzzyOn(int *_num, int _numLength, int _degree, double _avgRate, int _highFuzzy_LowNum){
    // general variables
    int* num = _num;
    int i, j, temp; // bubble sort variables
    int highNum; // array highest number
    int lowNum; // array lowest number
    int numSum = 0; // number array sum
    double numAvg = 0.0; // number array avg
    double avgRate = _avgRate;

    // fuzzy variables
    int numLength = _numLength;
    int lowFuzzy_HighNum = 0;
    int highFuzzy_LowNum = _highFuzzy_LowNum;

    double avgFuzzyNum = 0.0;

    // fuzzy standard measure
    int degree = _degree;
    // double numFuzzyLowZero = 0.0;

    double fuzzyLow = 0.0;
    double fuzzyHigh = 0.0;
    double fuzzyLowToAvg = 0.0;
    double fuzzyAvgToHigh = 0.0;

    double avgFuzzyLow = avgRate;
    double avgFuzzyHigh = avgRate;

    double num_LowfuzzyRate = 0.0;
    double num_HighfuzzyRate = 0.0;

    double arrFuzzyLow[numLength];
    double arrFuzzyHigh[numLength];
    double arrFuzzyLowToAvg[numLength];
    double arrFuzzyAvgToHigh[numLength];

    // before bubble sort, initialize value
    printf("initialize value :\t");
    for(i = 0; i < numLength; i++){
        printf("%d ",num[i]);
    }
    printf("\n");





    /* ----- bubble sort, maxvalue, minvalue, avgvalue -----*/

    // highest, lowest value
    highNum = num[0];
    lowNum = num[0];
    for(i = 0; i < numLength; i++){
        if(num[i] > highNum){
            highNum = num[i];
        }
        if(num[i] < lowNum){
            lowNum = num[i];
        }
    }

    for (i = 0; i < numLength; i++) {
        for (j = 0; j < numLength - 1; j++) {
            if (num[j] > num[j+1]) {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    // after bubble sort (Ascending)
    printf("after B.S. (Asc.):\t");
    for(i = 0; i < numLength; i++){
        printf("%d ",num[i]);
    }
    printf("\n"); // carriage return

    // after bubble sort (Descending)
    printf("after B.S. (Desc.):\t");
    for(i = numLength-1 ; i >= 0; i--){
        printf("%d ",num[i]);
    }
    printf("\n"); // carriage return

    // num[]'s average
    for(i = 0; i < numLength; i++){
        numSum += num[i];
    } // iteration of number array adding

    numAvg = (double)numSum / (double)numLength; // number array average method
    printf("number's sum :\t\t%d\n", numSum);
    printf("number's avg :\t\t%.2lf\n", numAvg); //.2 = decimal point



    /* ----- calculation of fuzzy ----- */

    // low fuzzy 중 가장 키가 큰 변수를 골라내는 과정
    for (i = 0; i < numLength; i++) {
        if (num[i] < numAvg) {
            lowFuzzy_HighNum = num[i];
        }
    }

    // 사용자가 설정한 degree 나누기 각 소속 집단별로 최대값과 최소값를 구하여 그 차액 -> 전체 집단에서 한 눈금이 차지하는 비율
    fuzzyLow = (double)degree / (double)(lowFuzzy_HighNum - lowNum);
    fuzzyHigh = (double)degree / (double)(highNum - highFuzzy_LowNum);

    num_LowfuzzyRate = (double)lowFuzzy_HighNum - ((avgFuzzyLow * degree) / fuzzyLow);
    // Low 집단 중 Average 집단에 소속될 수 있는 최소한의 데이터
    // low 집단 중 가장 큰 데이터  - (low 집단 중 평균으로 속할 수 있는 소속도 * degree) / low 집단전체 한 눈금이 차지하는 비율

    num_HighfuzzyRate = ((avgFuzzyHigh * degree) / fuzzyHigh) + (double)highFuzzy_LowNum;
    // High 집단 중 Average 집단에 소속될 수 있는 최대한의 데이터 ==
    // (high 집단 중 평균으로 속할 수 있는 소속도 * degree) / low 집단에서 한 눈금이 차지하는 비율 + 큰 데이터를 판별하는 기준 데이터

    avgFuzzyNum = (num_HighfuzzyRate + num_LowfuzzyRate) / 2.0;
    fuzzyLowToAvg = (double)degree / (avgFuzzyNum - num_LowfuzzyRate);
    fuzzyAvgToHigh = (double)degree / (num_HighfuzzyRate - avgFuzzyNum);

    // 각 집단별 fuzzy 구하기
    for (i = 0; i < numLength; i++) {
        // 각 집단들의 퍼지 논리 (0~1 사이의 실수값) = (눈금자 * (최대범위 - 최소범위)) / degree
        // Fuzzy 값의 범위 = 0.0 ~ 1.0
        arrFuzzyLow[i] = (fuzzyLow * (double)(lowFuzzy_HighNum - num[i])) / (double)degree;
        arrFuzzyHigh[i] = (fuzzyHigh * (double)(num[i] - highFuzzy_LowNum)) / (double)degree;
        arrFuzzyLowToAvg[i] = (fuzzyLowToAvg * (double)(num[i] - num_LowfuzzyRate)) / (double)degree;
        arrFuzzyAvgToHigh[i] = (fuzzyAvgToHigh * (double)(num_HighfuzzyRate - num[i])) / (double)degree;
    }

    // fuzzy print - low
    fuzzyPrint("Low Fuzzy :\t\t", arrFuzzyLow, numLength);

    // fuzzy print - high
    fuzzyPrint("High Fuzzy :\t\t", arrFuzzyHigh, numLength);

    // fuzzy print - average
    fuzzyPrint("LowToAvg Fuzzy :\t", arrFuzzyLowToAvg, numLength);
    fuzzyPrint("AvgToHigh Fuzzy :\t", arrFuzzyAvgToHigh, numLength);
}

void fuzzyPrint(char* _str, double* _arrFuzzyValue, int _numLength){
    int i;

    printf("%s", _str);
    for(i = 0; i < _numLength; i++){
        if(_arrFuzzyValue[i] > 0.0 && _arrFuzzyValue[i] < 1.0){
            printf("%.2lf ", _arrFuzzyValue[i]);
        } else {
            printf("%.2lf ", 0.0);
        }
    // printf("%.2lf ", arrFuzzyValue[i]);
    }
    printf("\n");
}
