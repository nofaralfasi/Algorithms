package com.sortAlgorithms.spring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class BinarySearchImpl {

	@Autowired
	private SortAlgorithm sortAlgorithm;

	// Java implementation of recursive Binary Search
	// Returns index of x if it is present in arr[l...r], else return -1
	public int binarySearch(int[] numbers, int l, int r, int numberToSearch) {

		int[] arr = sortAlgorithm.sort(numbers, 0, numbers.length);
		System.out.println("\n***********sortAlgorithm***********\n");
		System.out.println(sortAlgorithm);
		System.out.println(arr);

		// Search the array
		if (r >= l) {
			int mid = l + (r - l) / 2;

			// If the element is present at the
			// middle itself
			if (arr[mid] == numberToSearch)
				return mid;

			// If element is smaller than mid, then
			// it can only be present in left subarray
			if (arr[mid] > numberToSearch)
				return binarySearch(arr, l, mid - 1, numberToSearch);

			// Else the element can only be present
			// in right subarray
			return binarySearch(arr, mid + 1, r, numberToSearch);
		}
		// We reach here when element is not present in array
		return -1;
	}

}
