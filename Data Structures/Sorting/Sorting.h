//
//   Sorting.h
//   Insertion sort, shellsort, heapsort, mergesort 
//   and quicksort realization
//
//   Created by Baldwin Lou on 09/09/2015.
//   Copyright (c) 2015 Baldwin Lou. All rights reserved.
//

#ifndef SORTING_H
#define SORTING_H

#include <iostream>


// insertion sort
template<typename T>
void insertion_sort(T A[], int N)
{
	int j, P;
	T   tmp;
	
	for( P = 1; P < N; P++)
	{
		tmp = A[P];
		for(j = P; j > 0 && A[j-1] > tmp; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}
 
// shellsort
template<typename T>
void shellsort(T A[], int N)
{
	int i, j, increment;
	T tmp;
	
	for(increment = N/2; increment > 0; increment /= 2)
		for(i = increment; i < N; i++)
		{
			tmp = A[i];
			for(j = i; j >= increment; j -= increment)
				if(tmp < A[j-increment])
					A[j] = A[j-increment];
				else
					break;
			A[j] = tmp;
		}
}

// heapsort
template<typename T>
void PercDown(T A[], int i, int N)
{
	int child;
	T tmp;
	
	for(tmp = A[i]; (2*i+1) < N; i = child)
	{
		child = 2 * i + 1;
		if(child != N-1 && A[child+1] > A[child])
			child++;
		if(tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = tmp;
}

template<typename T>
void heapsort(T A[], int N)
{
	int i, tmp;
	
	for(i = N/2; i>=0; i--)
		PercDown<T>(A, i, N);
	for(i = N-1; i > 0; i--)
	{
		tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		PercDown<T>(A, 0, i);
	}
}

// mergesort
template<typename T>
void merge(T A[], T tmpA[], int lpos, int rpos, int rightend)
{
	int i, leftend, numelements, tmppos;
	
	leftend = rpos - 1;
	tmppos = lpos;
	numelements = rightend - lpos + 1;
	
	while(lpos <= leftend && rpos <= rightend)
		if(A[lpos] <= A[rpos])
			tmpA[tmppos++] = A[lpos++];
		else
			tmpA[tmppos++] = A[rpos++];
	
	while(lpos <= leftend)
		tmpA[tmppos++] = A[lpos++];
	while(rpos <= rightend)
		tmpA[tmppos++] = A[rpos++];
		
	for(i = 0; i < numelements; i++, rightend--)
		A[rightend] = tmpA[rightend];
}

template<typename T>
void msort(T A[], T tmpA[], int left, int right)
{
	int center;
	
	if(left < right)
	{
		center = (left + right) / 2;
		msort<T>(A, tmpA, left, center);
		msort<T>(A, tmpA, center+1, right);
		merge<T>(A, tmpA, left, center+1, right);
	}
}

template<typename T>
void mergesort(T A[], int N)
{
	T tmpA[N];
	msort<T>(A, tmpA, 0, N-1);
}

// quicksort
template<typename T>
void swap(T *a, T *b)
{
	
	T tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename T>
T median3(T A[], int left, int right)
{
	int center = (left + right) / 2;
	
	if(A[left] > A[center])
		swap(&A[left], &A[center]);
	if(A[left] > A[right])
		swap(&A[left], &A[right]);
	if(A[center] > A[right])
		swap(&A[center], &A[right]);
	
	swap(&A[center], &A[right-1]);
	
	return A[right-1];
}

template<typename T>
void qsort(T A[], int left, int right)
{
	int i, j;
	int cutoff = 3;
	T pivot, tmp;

	if (left + cutoff <= right)
	{
		pivot = median3(A, left, right);
		i = left;
		j = right - 1;
		for( ; ; )
		{
			while(A[++i] < pivot) {}
			while(A[--j] > pivot) {}
			if (i < j)
			{
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			else
				break;	
		}
		tmp = A[right-1];
		A[right-1] = A[i];
		A[i] = tmp;
		
		qsort<T>(A, left, i-1);
		qsort<T>(A, i+1, right);
	}
	else
		insertion_sort(A+left, right-left+1);
}


template<typename T>
void quicksort(T A[], int N)
{
	qsort(A, 0, N-1);
}

#endif
