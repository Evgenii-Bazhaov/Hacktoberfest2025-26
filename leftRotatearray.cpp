#include <iostream>
using namespace std;

void rotateArrayByOne(int arr[], int n) {
    int first = arr[0]; // store first element
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // shift elements left
    }
    arr[n - 1] = first; // place first element at the end
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    rotateArrayByOne(arr, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1)
            cout << ",";
    }

    return 0;
}
