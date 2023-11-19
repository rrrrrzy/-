#include <iostream>
using namespace std;

// merge函数用于合并两个已排序的子数组，并计算逆序对的数量
int merge(int arr[], int left, int mid, int right) {
    int invCount = 0; // 逆序对的数量

    int n1 = mid - left + 1; // 左子数组的大小
    int n2 = right - mid;    // 右子数组的大小

    // 创建临时数组来存储左右子数组
    int *L = new int[n1];
    int *R = new int[n2];

    // 将数据复制到临时数组中
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // 合并左右子数组，并计算逆序对的数量
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            invCount += (n1 - i); // 统计逆序对的数量
        }
        k++;
    }

    // 将剩余的元素复制回原数组
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return invCount; // 返回逆序对的数量
}

// mergeSort函数用于对数组进行归并排序，并返回逆序对的数量
int mergeSort(int arr[], int left, int right) {
    int invCount = 0; // 逆序对的数量
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSort(arr, left, mid);    // 递归排序左子数组
        invCount += mergeSort(arr, mid + 1, right); // 递归排序右子数组
        invCount += merge(arr, left, mid, right);   // 合并左右子数组，并计算逆序对的数量
    }
    return invCount; // 返回逆序对的数量
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    cout  << mergeSort(arr, 0, n - 1) << endl; // 输出逆序对的数量
    return 0;
}
