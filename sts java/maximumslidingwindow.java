import java.util.Scanner;

public class maximumslidingwindow {

    // Method to find the maximum for
    // each and every contiguous
    // subarray of size k.
    static void printKMax(int[] arr, int n, int k) {
        int j, max;

        for (int i = 0; i <= n - k; i++) {
            max = arr[i];
            for (j = 1; j < k; j++) {
                if (arr[i + j] > max)
                    max = arr[i + j];
            }
            System.out.print(max + " ");
        }
    }

    // Driver code
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();
        int[] arr = new int[size];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();

        System.out.println("Maximum elements in all subarrays of size " + k + " are:");
        printKMax(arr, size, k);

        scanner.close();
    }
}
