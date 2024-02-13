import java.util.Scanner;
import java.util.Stack;

public class celebrityproblem {

    static boolean[][] input;

    static boolean knows(int a, int b) {
        return input[a][b];
    }

    static int findCelebrity(int n) {
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        while (s.size() > 1) {
            int first = s.pop();
            int second = s.pop();

            if (knows(first, second)) {
                s.push(second);
            } else {
                s.push(first);
            }
        }

        int celebrity = s.pop();
        return celebrity;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the matrix: ");
        int n = scanner.nextInt();
        input = new boolean[n][n];

        System.out.println("Enter the matrix elements (0/1):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                input[i][j] = scanner.nextInt()==1;
            }
        }

        scanner.close();

        System.out.println("The celebrity is at index: " + findCelebrity(n));
    }
}
