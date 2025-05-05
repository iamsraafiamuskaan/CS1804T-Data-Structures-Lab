#include <cstdio>

int findmin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void processtest() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* arr = new int[n]; // Use dynamic array allocation
    printf("Enter the positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the members in a row:\n");
    while (q--) {
        int y;
        scanf("%d", &y);

        int result = findmin(arr[0] - 1, y);
        printf("%d\n", result); 
    }

    delete[] arr; 
}

int main() {
    int cases;
    printf("Enter the number of test cases: ");
    scanf("%d", &cases);

    while (cases--) {
        processtest();
    }
    return 0;
}
