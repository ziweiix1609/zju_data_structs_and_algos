/**
 * Heap sort (unstable):
 * Wrost: Tw = 2NlogN - O(NloglogN) (better than NlogN)
 * 
 * Note: but in fact, it's not that useful, Sedgewick sequence 
 * Shell sort normally is better.
 */
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

/* Re-organize N elements in array A[] to be a MaxHeap(A[p] as root) */
void PercDown(ElementType A[], int p, int N)
{
	int Parent, Child;
	ElementType X;

	X = A[p];	/* Fetch the value from root */
	for (Parent = p; (Parent*2+1) < N; Parent=Child) {
		Child = Parent * 2 + 1;
		if ((Child != N-1) && (A[Child] < A[Child+1]) )
			Child++;	/* Child points to the larger one */
		if (X >= A[Child]) break;	/* Spot the right place */
		else	/* Percolate X down */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], int N) 
{
	int i;

	for (i = N/2-1; i >= 0; i--)	/* Build MaxHeap to avoid extra space */
		PercDown(A, i, N);

	for (i = N-1; i > 0; i--) {
		Swap(&A[0], &A[i]);		/* Delete the top element from MaxHeap */
		PercDown(A, 0, i);
	}
}

