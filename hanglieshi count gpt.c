#include <stdio.h>

#define MAX_SIZE 10 // 最大行列式大小

// 计算行列式的递归函数
double determinant(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    double det = 0.0;

    // 基础情况：如果矩阵是1x1
    if (n == 1) {
        return matrix[0][0];
    }

    // 递归计算行列式
    for (int c = 0; c < n; c++) {
        double submatrix[MAX_SIZE][MAX_SIZE];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < c) {
                    submatrix[i - 1][j] = matrix[i][j];
                } else if (j > c) {
                    submatrix[i - 1][j - 1] = matrix[i][j];
                }
            }
        }
        det += (c % 2 == 0 ? 1 : -1) * matrix[0][c] * determinant(submatrix, n - 1);
    }

    return det;
}

int main() {
    while (1)
    {
        int n;

    printf("请输入行列式的大小 (行数和列数相同): ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("行列式大小不能超过 %d\n", MAX_SIZE);
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    printf("请输入行列式的元素:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("元素 [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    double det = determinant(matrix, n);
    printf("行列式的值为: %.2lf\n", det);
    }
    

    return 0;
}
