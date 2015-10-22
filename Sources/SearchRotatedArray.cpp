#include <iostream>
#include <vector>

using namespace std;

class SearchRotatedArray {
public:
    SearchRotatedArray() {}
    ~SearchRotatedArray() {}

    void Run(void) {
    }

    void SplitSearch(vector<int> &nums, int start, int end, int target){

    }

    int Search(vector<int> &nums, int target) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return 1;
        int povit = 0;
        for(unsigned int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                povit = i;
                break;
            }
        }
        return 0;
    }

private:
    void test(int test_vector[], int length) {
    }
};
