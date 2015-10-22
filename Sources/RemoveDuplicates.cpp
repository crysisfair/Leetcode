#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class RemoveDuplicates {
public:
    RemoveDuplicates() {}
    ~RemoveDuplicates() {}

    void Run(void) {
        int test1[] = {1, 1, 1};
        int test2[] = {1, 2};
        int test3[] = {3, 2, 1};
        int test4[] = {1, 2, 2, 3, 4, 5, 6, 7};
        test(test1, 3);
        test(test2, 2);
        test(test3, 3);
        test(test4, 8);
    }

    int removeDuplicates(vector<int> &nums) {
        if(nums.size() <= 1) return nums.size();
        unsigned int last = 0;
        for(unsigned int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[last]) {
                if(last < i - 1) nums[++last] = nums[i];
            }
        }
        return last + 1;
    }

private:
    void test(int test_vector[], int length){
        vector<int> test1(test_vector, test_vector + length);
        int r = removeDuplicates(test1);
        cout << "length: " << r << endl;
        for(int i = 0; i < r; i++) printf("%d,", test1[i]);
        cout << endl;
    }
};
