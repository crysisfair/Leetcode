#include <iostream>
#include <vector>

using namespace std;

class SpiralMatrix {
public:
    SpiralMatrix() {}
    ~SpiralMatrix(){}

    void Run(void) {
        cout << "please input N:" << endl;
        int n = 0;
        cin >> n;
        vector<vector<int> > matrix = GetSpiralMatrix(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    vector<vector<int> > GetSpiralMatrix(int n){
        vector<vector<int> > matrix(n, vector<int>(n));
        int begin = 0, end = n - 1;
        int num = 0;
        while(begin < end) {
            for(int i = begin; i < end; i++) matrix[begin][i] = num ++;
            for(int i = begin; i < end; i++) matrix[i][end] = num ++;
            for(int i = end; i > begin; i--) matrix[end][i] = num ++;
            for(int i = end; i > begin; i--) matrix[i][begin] = num ++;
            begin ++;
            end --;
        }
        if ((n % 2) != 0) matrix[n / 2][n/ 2] = n* n- 1;
        return matrix;
    }
};

