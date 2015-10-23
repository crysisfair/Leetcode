#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

using namespace std;
char * mycpy(char * target, const char * src) {
    while(*src != '\0') {
        *target ++ = *src ++;
    }
    return target;
}
int main(void) {
    const char *p = "abcd";
    char target[30] = "this is a long sentense.";
    mycpy(target + 4, p);
    cout << target << endl;
    getchar();
    return 0;
}
