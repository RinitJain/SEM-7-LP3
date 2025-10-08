import java.util.Random;
import java.time.Instant;
import java.time.Duration;

public class CompareSorts {
    public static void main(String[] args) {
        int n = 500000;  // Try 10000, 100000, 500000, 1000000
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        Random rand = new Random();

        for (int i = 0; i < n; i++) {
            arr1[i] = rand.nextInt(1000000);
            arr2[i] = arr1[i];
        }

        Instant start1 = Instant.now();
        MergeSort.mergeSort(arr1, 0, n - 1);
        Instant end1 = Instant.now();

        Instant start2 = Instant.now();
        ParallelMergeSort t = new ParallelMergeSort(arr2, 0, n - 1, 0);
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Instant end2 = Instant.now();

        System.out.println("Single-threaded time: " + Duration.between(start1, end1).toMillis() + " ms");
        System.out.println("Multi-threaded time: " + Duration.between(start2, end2).toMillis() + " ms");
    }
}
