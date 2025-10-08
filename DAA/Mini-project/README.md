# 🧩 Mini Project: Merge Sort vs. Multithreaded Merge Sort

## 📖 Overview

This mini project implements and compares two sorting algorithms:

- **Single-threaded Merge Sort**
- **Multithreaded Merge Sort**

**Goals:**
- Measure and compare execution times.
- Analyze performance in best-case and worst-case scenarios.
- Understand how multithreading affects sorting efficiency.

---

## ⚙️ Implementation Details

### 1. Merge Sort (Single-threaded)
- Uses divide and conquer.
- Recursively splits the array into halves until each contains one element.
- Merges the halves in sorted order using `merge()`.
- Runs on a single CPU thread.

### 2. Multithreaded Merge Sort
- Extends the same merge sort logic.
- Creates separate threads to sort left and right halves concurrently.
- Threads run in parallel, utilizing multiple CPU cores.
- Merges sorted halves in the main thread.
- Uses Java’s `Thread` class (`start()` and `join()`).

---

## 🧮 How Sorting Happens

For both algorithms:
1. The array is split recursively into smaller subarrays.
2. Each half is sorted independently.
3. The sorted halves are merged into a single sorted array.

In the multithreaded version, step 2 happens **in parallel**.

---

## 🧰 How to Run

### Compile

```bash
javac MergeSort.java ParallelMergeSort.java CompareSorts.java
```

### Execute

```bash
java CompareSorts
```

---

## 📝 Sample Output

```
Single-threaded time: 44 ms
Multi-threaded time: 9 ms
```

---

## 📊 Experimental Setup

| System                | MacBook Air M4 (Apple Silicon) |
|-----------------------|--------------------------------|
| Language              | Java (JDK 25)                  |
| Array Size            | 500,000 random integers        |
| Number Range          | 0 – 1,000,000                  |

---

## 📈 Performance Analysis

### 1. Time Comparison (Observed)

| Algorithm                  | Time (ms) |
|----------------------------|-----------|
| Single-threaded Merge Sort | 44        |
| Multithreaded Merge Sort   | 9         |

**Result:** Multithreaded merge sort was approximately **5× faster** than single-threaded.

---

### ⚡ Why Multithreading Helps

- Merge sort naturally divides data into halves — perfect for parallel execution.
- Sorting halves concurrently utilizes multiple CPU cores.
- Java threads distribute work across available cores, reducing total time.
- Thread overhead means multithreading helps most for large arrays.

---

## 🧠 Theoretical Time Complexity

| Case        | Complexity | Description                                                                 |
|-------------|------------|-----------------------------------------------------------------------------|
| Best Case   | O(n log n) | Even if already sorted, merge sort still divides and merges recursively.     |
| Average     | O(n log n) | Every merge involves comparing roughly half the elements.                   |
| Worst Case  | O(n log n) | All splits and merges must occur regardless of data order.                  |

Merge sort has consistent O(n log n) complexity in all cases.

---

## 🧩 Performance Analysis by Case

### ✅ Best Case
- **Input:** Already sorted array.
- **Behavior:** Merge sort still performs all splitting and merging.
- **Time:** O(n log n)
- **Observation:** Multithreading provides smaller relative gain due to thread overhead.

### ❌ Worst Case
- **Input:** Reverse sorted or random data.
- **Behavior:** Full recursion and merging at each level.
- **Time:** O(n log n)
- **Observation:** Multithreading shows true advantage as more work is parallelized.

---

## 🧠 Conceptual Insights

| Aspect         | Single-threaded | Multithreaded                |
|----------------|-----------------|------------------------------|
| CPU Usage      | 1 core          | Multiple cores               |
| Memory Usage   | Lower           | Slightly higher (extra threads) |
| Overhead       | Minimal         | Thread creation/synchronization |
| Ideal For      | Small arrays    | Large arrays (≥ 100,000 elements) |

---

## 🏁 Example Result Summary

| Array Size | Single-threaded Time | Multithreaded Time | Speedup |
|------------|----------------------|--------------------|---------|
| 10,000     | 3 ms                 | 4 ms               | ~0.75×  |
| 100,000    | 16 ms                | 8 ms               | ~2×     |
| 500,000    | 44 ms                | 9 ms               | ~5×     |
| 1,000,000  | 96 ms                | 18 ms              | ~5.3×   |

---

## 🧾 References

- [Oracle Java Threads Documentation](https://docs.oracle.com/javase/tutorial/essential/concurrency/)
- [Merge Sort Algorithm Explanation – GeeksForGeeks](https://www.geeksforgeeks.org/merge-sort/)
- Parallel Computing Concepts

---

**Author:** Rinit Jain, Advait Joshi, Amey Kulkarni
