// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len && arr[i] < value; i++) {
        for (int j = 0; j < i && arr[j] < value; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int right = len, left = 0, mid = (right + left) / 2;
    int count = 0;
    for (int j = 0; j < len; j++) {
        left = j; right = len;  mid = (right + left) / 2;
        while (right - left > 1) {
            mid = (right + left) / 2;
            if (arr[mid] + arr[j] > value)
                right = mid;
            else if (arr[mid] + arr[j] < value)
                left = mid;
            else if (arr[mid] + arr[j] == value)
            {
                count++;
            }
        }
    }
    return count;
}
