#include <stdio.h>

// 定義陣列的大小
#define ARRAY_SIZE 5

int main() {
    // 要寫入檔案的三個陣列
    int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    double array2[ARRAY_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char array3[ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e'};

    // 開啟檔案以寫入二進制資料
    FILE *file = fopen("a.bin", "wb");

    // 檢查檔案是否成功開啟
    if (file == NULL) {
        perror("無法開啟檔案");
        return 1; // 程式結束並回傳錯誤碼
    }

    // 將三個陣列寫入檔案
    fwrite(array1, sizeof(int), ARRAY_SIZE, file);
    fwrite(array2, sizeof(double), ARRAY_SIZE, file);
    fwrite(array3, sizeof(char), ARRAY_SIZE, file);

    // 關閉檔案
    fclose(file);

    // 開啟檔案以讀取二進制資料
    file = fopen("a.bin", "rb");

    // 檢查檔案是否成功開啟
    if (file == NULL) {
        perror("無法開啟檔案");
        return 1; // 程式結束並回傳錯誤碼
    }

    // 讀取檔案中的三個陣列
    int readArray1[ARRAY_SIZE];
    double readArray2[ARRAY_SIZE];
    char readArray3[ARRAY_SIZE];

    fread(readArray1, sizeof(int), ARRAY_SIZE, file);
    fread(readArray2, sizeof(double), ARRAY_SIZE, file);
    fread(readArray3, sizeof(char), ARRAY_SIZE, file);

    // 關閉檔案
    fclose(file);

    // 輸出三個陣列的內容
    printf("陣列1: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", readArray1[i]);
    }

    printf("\n陣列2: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%.2lf ", readArray2[i]);
    }

    printf("\n陣列3: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%c ", readArray3[i]);
    }

    printf("\n");

    return 0; // 程式結束並回傳正確碼
}
