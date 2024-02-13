import java.util.Scanner;

class towerofhanoi {
    
    static void ToH(int n, char A, char B, char C) {
        if (n == 1) {
            System.out.println("Move 1 from " + A + " to " + C);
            return;
        }
        ToH(n - 1, A, C, B);
        System.out.println("Move " + n + " from " + A + " to " + C);
        ToH(n - 1, B, A, C);
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int n = scanner.nextInt();
        scanner.close();
        
        ToH(n, 'A', 'B', 'C');
    }
}