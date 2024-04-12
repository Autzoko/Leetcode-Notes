#include <string>
using namespace std;

class EditDistance {
public:
    int minDistance(string word1, string word2) {
        word1 = " " + word1;
        word2 = " " + word2;

        int **matrix = new int*[word1.size()];
        for(int i = 0; i < word1.size(); i++) {
            matrix[i] = new int[word2.size()];
            fill_n(matrix[i], word2.size(), 0);
        }

        for(int i = 0; i < word1.size(); i++) {
            for(int j = 0; j < word2.size(); j++) {
                if(_min_(i, j) == 0) matrix[i][j] = _max_(i, j);
                else {
                    if(word1[i] == word2[j]) {
                        matrix[i][j] = matrix[i - 1][j - 1];
                    } else {
                        matrix[i][j] = _trimin_(
                            matrix[i - 1][j - 1],
                            matrix[i][j - 1],
                            matrix[i - 1][j]
                        ) + 1;
                    }
                }
            }
        }
        return matrix[word1.size() - 1][word2.size() - 1];
    }

private:
    int _min_(int i, int j) {
        return i < j ? i : j;
    }
    int _max_(int i, int j) {
        return i > j ? i : j;
    }
    int _trimin_(int x, int y, int z) {
        return _min_(x, y) < _min_(y, z) ? _min_(x, y) : _min_(y, z);
    }
};