import java.util.Arrays;

class ParallelMergeSort extends Thread {
    private int[] arr;
    private int left, right;
    private int depth;

    public ParallelMergeSort(int[] arr, int left, int right, int depth) {
        this.arr = arr;
        this.left = left;
        this.right = right;
        this.depth = depth;
    }

    @Override
    public void run() {
        if (left >= right) return;
        int mid = (left + right) / 2;

        // Limit thread creation depth to avoid overhead
        if (depth < 3) {
            ParallelMergeSort t1 = new ParallelMergeSort(arr, left, mid, depth + 1);
            ParallelMergeSort t2 = new ParallelMergeSort(arr, mid + 1, right, depth + 1);
            t1.start();
            t2.start();
            try {
                t1.join();
                t2.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else {
            MergeSort.mergeSort(arr, left, mid);
            MergeSort.mergeSort(arr, mid + 1, right);
        }

        MergeSort.merge(arr, left, mid, right);

    }
}