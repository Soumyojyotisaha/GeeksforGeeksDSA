
import java.util.Arrays;
import java.util.Scanner;

class stockspan {
  
    static void calculateSpan(int price[], int n, int S[]) {
  
        S[0] = 1;

        for (int i = 1; i < n; i++) {
            S[i] = 1; 
            for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
                S[i]++;
        }
    }

    static void printArray(int arr[]) {
        System.out.print(Arrays.toString(arr));
    }

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
