#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
double summ(int n, double first,...)    {
    double* p = &first;      
    double sum = 0;
    while(n){
        sum += (*p);         
        p++;             
        n--;
    }
    return sum;  
}
double summ2(int num, double first,...) {
    va_list args;
    double sum = first;
    va_start(args, first);
    while (num--) {
        printf("%f\n", sum);
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum;
}
char* strsum(char* f, char* f2) {
    char* ans = malloc((strlen(f) + strlen(f2)) * sizeof(char));
    for (int i = 0; i < strlen(f); i++) {
        ans[i]= f[i];
    }
    int k = 0;
    for (int i = strlen(f); i < strlen(f) + strlen(f2); i++){
        ans[i] = f2[k];
        k++;
    }
    ans[strlen(f) + strlen(f2)] = '\0';
    return ans;
}
char* concat(char* first, ...) {
    va_list args;
    va_start(args, first);
    char* ans = first;
    while (1) {
        char* new =va_arg(args, char*);
        ans = strsum(ans, new);
        if (new == "\0") break;
   }
    return ans;
}
int main() {
    double sum = summ(5, 0.5, 2.2, 3.1, 2.4, 1.2);
    double sum2 = summ2(5, 0.5, 2.2, 3.1, 2.4, 1.2);
    printf("sum = %f and %f\n", sum, sum2);
    char* s = concat("one ", "two ", "three ", "four s", "\0");
    printf("%s", s);
    return 0;
}