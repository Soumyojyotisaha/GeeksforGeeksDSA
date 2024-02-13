import java.util.Arrays;
import java.util.Scanner;

class stockspan {
    // method to calculate stock span values
    static void calculateSpan(int price[], int n, int S[]) {
        // Span value of first day is always 1
        S[0] = 1;

        // Calculate span value of remaining days by
        // linearly checking previous days
        for (int i = 1; i < n; i++) {
            S[i] = 1; // Initialize span value

            // Traverse left while the next element on left
            // is smaller than price[i]
            for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
                S[i]++;
        }
    }

    // A utility function to print elements of array
    static void printArray(int arr[]) {
        System.out.print(Arrays.toString(arr));
    }

    // Driver code
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of days: ");
        int n = scanner.nextInt();

        int price[] = new int[n];
        System.out.println("Enter the stock prices for each day:");
        for (int i = 0; i < n; i++) {
            price[i] = scanner.nextInt();
        }
        scanner.close();

        int S[] = new int[n];

        // Fill the span values in array S[]
        calculateSpan(price, n, S);

        // print the calculated span values
        printArray(S);
    }
}
