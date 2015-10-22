#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class YanghuiTriangle {
    public:
        static void Triangle(int n) {
            int *p = NULL, *prev = NULL;
            for(int size = 0; size <= n; size++) {
                p = (int *)malloc(size + 1);
                memset(p, 0, size + 1);
                *p = 1;
                for(int j = 1; j < size; j++) {
                    if(prev != NULL) *(p + j) = prev[j - 1] + prev[j];
                }
                *(p + size) = 1;
                if(size != 0) free(prev);
                prev = p;
                PrintLine(p, size + 1);
            }
        }

        void Run(void) {
            Triangle(5);
        }
    private:
        static void PrintLine(int * nums, int length) {
            for(int i = 0; i < length; i++) {
                cout << *(nums + i) <<  "\t";
            }
            cout << endl;
        }
};
