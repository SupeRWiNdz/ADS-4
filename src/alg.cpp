// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = len-1; i < j; j--) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int right = len, left = 0, mid = (right + left) / 2;
    int count = 0, i = 0;
    for (int j = 0; j < len-1; j++) {
        left = j; right = len;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (arr[mid] + arr[j] == value) {
                count++;
                int mid2 = mid + 1;
                while (arr[mid2] + arr[j] == value && mid2 < right) {
                    count++;
                    mid2++;
                }
                mid2 = mid - 1;
                while (arr[mid2] + arr[j] == value && mid2 > left) {
                    count++;
                    mid2--;
                }
                break;
            }
            if (arr[mid] + arr[j] > value)
                right = mid;
            else
                left = mid;
        }
    }
    return count;
}
