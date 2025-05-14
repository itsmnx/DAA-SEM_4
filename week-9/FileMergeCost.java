import java.util.PriorityQueue;
import java.util.Scanner;

public class FileMergeCost {

    // Function to compute minimum merge cost
    public static int minMergeCost(int[] files) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Add all file sizes to the min-heap
        for (int size : files) {
            minHeap.add(size);
        }

        int totalCost = 0;

        // Keep merging the two smallest files
        while (minHeap.size() > 1) {
            int first = minHeap.poll();   // smallest
            int second = minHeap.poll();  // next smallest

            int merged = first + second;
            totalCost += merged;

            minHeap.add(merged);  // add merged file back
        }

        return totalCost;
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Ask for number of files
        System.out.print("Enter number of files: ");
        int n = sc.nextInt();

        int[] files = new int[n];

        // Ask user to enter sizes of files
        System.out.println("Enter sizes of files:");
        for (int i = 0; i < n; i++) {
            System.out.print("File " + (i + 1) + ": ");
            files[i] = sc.nextInt();
        }

        // Calculate and print the result
        int result = minMergeCost(files);
        System.out.println("Minimum total computation cost: " + result);

        sc.close();
    }
}
