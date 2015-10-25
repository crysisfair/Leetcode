#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(void) {
    int calendar[12][31];
    int (*month)[31];
    for(month = calendar; month < &calendar[12]; month++) {
        for(int *day = *month, i = 1; day < &(*month)[31]; day++, i++) {
            *day = i;
        }
    }
    getchar();
    return 0;
}
