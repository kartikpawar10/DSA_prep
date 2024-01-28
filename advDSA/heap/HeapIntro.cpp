#include<iostream>
using namespace std;

class heap{
	public:
		int arr[100];
		int size = 0;

//INSERTION
		void insert(int val){
			size = size + 1;
			int index = size;
			arr[index] = val;

			while(index > 1){
				int parent = index/2;

				if(arr[parent] < arr[index]){
					swap(arr[parent],arr[index]);
					index = parent;
				} 
				else{
					return;
				}
			}
		}
// DELETION

		/*
			STEP 01: WE ALWAYS DLT ROOT AKA HEAD
			STEP 02: SWAP 
			OR PLACE VALOF(LASTNODE) IN ROOT OR ARR[1] = ARR[SIZE]
			STEP 03: DECREAE SIZE-- SO UNACCESSIBLE A[SIZE] BCZ DLTION
			STEP 04: CHECK ROOT -> LEFT CHILD AND RIGHT CHILD FOR MAKING THE ALL
					CONDTION FOR HEAP TRUE
		*/

		void deletefromHeap(){
			if(size == 0){ 
				cout<<"No Broski"<<endl;
				return;
			}
			int i = 1;
			arr[i] = arr[size];
			size--;

			while(i<size){
				int leftIndex = 2*i;
				int rightIndex = 2*i+1;
				if(leftIndex < size && arr[leftIndex] > arr[i]){
					swap(arr[leftIndex],arr[i]);
					i = leftIndex;
				}
				if(rightIndex < size && arr[rightIndex] > arr[i]){
					swap(arr[rightIndex],arr[i]);
					i = rightIndex;
				}
				else{
					return;
				}
			}
		}

		void print(){
			for(int i=1;i<=size;i++){
				cout<<arr[i]<<" ";
			}cout<<endl;
		}

};

void heapify(int *arr,int size,int i){
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;

	if(left <= size && arr[left] > arr[largest]){
		largest = left;
	}
	if(right <= size && arr[right] > arr[largest]){
		largest = right;
	} 

	if(largest != i){
		swap(arr[largest],arr[i]);
		heapify(arr,size,largest);
	}
} 

void heapSort(int heap[],int size){
	while(size > 1){
		swap(heap[1],heap[size]);
		size--;
		heapify(heap,size,1);
	}
}
int main(){
	// Already a Heap
	heap h;
	h.insert(60);
	h.insert(50);
	h.insert(40);
	h.insert(30);
	h.insert(20);
	h.insert(55);
	cout<<endl;
	// Heapified Array
	int arr[6] = {-1,56,68,67,23,12};
	for(int i=5/2 ; i>0 ; i--){
		heapify(arr,5,i);
	}
	// HeapSort
	heapSort(arr,5);
	for(int i=1;i<6;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}