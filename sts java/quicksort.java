import java.util.Scanner;

class quicksort {
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[low]; // Use first element as pivot
        int i = high + 1;
        for (int j = high; j > low; j--) {
            if (arr[j] > pivot) {
                i--;
                swap(arr, i, j);
            }
        }
        swap(arr, i - 1, low);
        return (i - 1);
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int N = scanner.nextInt();
        int[] arr = new int[N];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        quickSort(arr, 0, N - 1);
        System.out.println("Sorted array:");
        printArr(arr);

        scanner.close();
    }
}
