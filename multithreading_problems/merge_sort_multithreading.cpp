#include <bits/stdc++.h>
#include <thread>

using namespace std;

int temp[100000];
void merge(int start,int mid,int end, int *arr){
    int i = start;
    int k = mid + 1;
    int j = 0;

    int n = end - start + 1;
    vector<int> temp(end - start + 1);

    while(i <= mid && k <= end){
        if(arr[i] <= arr[k]){
            temp[j++] = arr[i++];
        }
        else {
            temp[j++] = arr[k++];
        }
    }

    while(i <= mid){
        temp[j++] = arr[i++];
    }

    while(k <= end){
        temp[j++] = arr[k++];
    }

    for(int l=start;l<=end;l++){
        arr[l] = temp[l-start];
    }

    return;
}

void mergeSort(int i,int j,int *arr){
    if(i >= j) return;

    int mid = (i + j) / 2;
    mergeSort(i,mid,arr);
    mergeSort(mid+1,j,arr);
    
    merge(i,mid,j,arr);

}

void mergeSort_threaded(int i,int j,int *arr){
    if(i >= j) return;

    int mid = (i + j) / 2;
    thread t1(mergeSort,i,mid,ref(arr));
    thread t2(mergeSort,mid+1,j,ref(arr));

    t1.join();
    t2.join();
    
    merge(i,mid,j,arr);
}

int* createArray(int n){
    int *arr = new int[n];
    for(int i=0;i<n;i++) arr[i] = n - i;
    return arr;
}

template <typename Function, typename... Args>
void measureExecutionTime(Function func, Args&&... args) {
    auto start_time = chrono::high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    cout << "Execution time: " << elapsed.count() << " seconds" << endl;
}

int main(){

    int n = 1000000;
    int *arr1 = createArray(n);
    int *arr2 = createArray(n);

    auto startRec = std::chrono::high_resolution_clock::now();
    mergeSort(0,n-1,arr1);

    auto endRec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRec = endRec - startRec;
    std::cout << "Time taken by function: " << durationRec.count() << " seconds" << std::endl;

    auto startThreaded = std::chrono::high_resolution_clock::now();
    mergeSort_threaded(0,n-1,arr2);

    auto endThreaded = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationThreaded = endThreaded - startThreaded;
    std::cout << "Time taken by threaded function: " << durationThreaded.count() << " seconds" << std::endl;

    return 0;
}