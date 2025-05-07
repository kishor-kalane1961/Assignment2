import java.util.Scanner;

public class MaxHeapSortSimple {

    public static void heapSort(int[] arr) {
        int n = arr.length;

        
        for (int i = n / 2 - 1; i >= 0; i--) {
            createMaxHeap(arr, n, i);
        }
    
        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);  
            createMaxHeap(arr, i, 0);
        }
    }

    private static void createMaxHeap(int[] arr, int n, int i) {
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2; 

        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        
        if (largest != i) {
            swap(arr, i, largest);

            
            createMaxHeap(arr, n, largest);
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Original array:");
        printArray(arr);

        
        heapSort(arr);

        System.out.println("Sorted array using Max Heap Sort:");
        printArray(arr);

        sc.close(); 
    }
}