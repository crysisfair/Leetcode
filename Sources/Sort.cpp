#include <iostream>
#include <vector>

using namespace std;

class Sort {
public:
    Sort() {}
    ~Sort() {}
    void RunQSort() {
        Sort s;
        int test_num1[] = { 23, 34, 1, 3, 50, 48, 93, 62 };
        vector<int> ns(test_num1, test_num1 + sizeof(test_num1) / sizeof(int));
        s.QSort(ns);
        for (unsigned int i = 0; i < ns.size(); i++) {
            cout << ns[i] << " ";
        }
        cout << endl;
    }

    void QSort(vector<int> &nums) {
        QSortHelper(nums, 0, nums.size() - 1);
    }
private:
    int Partiotion(vector<int> &nums, int left, int right) {
        int povit = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= povit) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= povit) left++;
            nums[right] = nums[left];
        }
        nums[left] = povit;
        return left;
    }

    void QSortHelper(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int mid = Partiotion(nums, left, right);
        QSortHelper(nums, left, mid - 1);
        QSortHelper(nums, mid + 1, right);
    }
};