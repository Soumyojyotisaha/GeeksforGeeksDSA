import java.util.Scanner;
import java.util.Stack;

public class stackpermutation {
    public static boolean isStackPermutation(int[] original, int[] target) {
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        for (int element : original) {
            stack.push(element);
            while (!stack.isEmpty() && stack.peek() == target[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the original array: ");
        int n = scanner.nextInt();
        int[] original = new int[n];

        System.out.println("Enter the elements of the original array:");
        for (int i = 0; i < n; i++) {
            original[i] = scanner.nextInt();
        }

        System.out.print("Enter the size of the target array: ");
        int m = scanner.nextInt();
        int[] target = new int[m];

        System.out.println("Enter the elements of the target array:");
        for (int i = 0; i < m; i++) {
            target[i] = scanner.nextInt();
        }
        scanner.close();
        boolean result = isStackPermutation(original, target);
        System.out.println( result);

       
    }
}
