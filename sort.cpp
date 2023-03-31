
#include <string>
#include <iostream>
using namespace std;


//////////////////// rev ///////////////////////////

template <typename T>
bool isRev(T a[],int size){
    bool flag=true;
    for(int i=1;i<size;i++)
        if(a[i] > a[i-1]){flag=false;break;}
    return flag;
}

template <typename T>
void RevSort(T a[],int size){
        for(int i=0;i<=size/2;i++)swap(a[i],a[size-1-i]);
    
}



///////////////////// Sorted /////////////////////////

template <typename T>
bool Sorted(T a[],int size){
    bool flag=true;
    for(int i=1;i<size;i++)
        if(a[i] < a[i-1]){flag=false;break;}
    return flag;
}


///////////////////// PIPE ///////////////////////////
//this function returns true when -> organ pipe / semi1 / maybe sometimes semi2
template <typename T>
bool isPipe(T a[],int size){
    bool flag=true;
    for(int i=1;i<size/2;i++)
        if(a[i] < a[i-1]){flag=false;break;}
    return flag;
}


//////////////////// SHUFFLE /////////////////////////

template <typename T>
void Shuffle(T a[],int size){
    for(int i=0;i<size;i++){
        int r=rand()%size;
        swap(a[i],a[r]);
    }
    
}

//////////////////// INSERTION ///////////////////////
//from data structures slides

template <typename T>
void insertion(T a[],int size){
    
    for(int i=1; i < size; i++){
        T key=a[i];
        int j;
        for(j=i-1; j >= 0; j--){
            if(a[j] > key)a[j+1]=a[j];
            else break;
        }
        a[j+1]=key;
    }
    
}


//////////////////// IF 0's AND 1's //////////////////

template <typename T>
bool ZerosOnes(T a[],int size){
    
    bool flag=true;
    for(int i=0;i<size;i++)
        if(a[i]!=0 && a[i]!= 1){flag=false;break;}
    return flag;
    
}


template <typename T>
void MySort(T a[],int first,int last){

    int i=first-1, j=last+1;
    while(true){
        do{i++;}while(a[i]==0 && i<j);
        do{j--;}while(a[j]==1 && j>i);
    
        if(i>=j)break;
        else swap(a[i],a[j]);
    }
    
}


////////////////////// MEDIAN OF 3 ////////////////////

template <typename T>
T ChoosePivot(T a[], int first, int last){
    int mid= first+(last-first)/2;
 
    T median= max(min(a[first],a[mid]),min(max(a[first],a[mid]),a[last])); //this line is taken from stackoverflow
    
    if(median == a[mid]) 
        swap(a[first],a[mid]);
        
    else if(median == a[last])
        swap(a[first],a[last]); 
        
    return a[first];
}

//////////////////////   QUICKSORT //////////////////////
//taken from algo slides

template <typename T>
int partition(T a[],int first,int last){
    T pivot = ChoosePivot(a,first,last);
    int i=first, j=last+1;
    while(true){
        do{i++;}while(i<last && a[i]<pivot);
        do{j--;}while(j>first && a[j]>pivot);
    
        if(i>=j)break;
        else swap(a[i],a[j]);
    }
    
    swap(a[first],a[j]);
    return j;
}

template <typename T>
void QuickSort(T a[],int first, int last){
    if(last - first + 1 < 17 )return;
    int p= partition(a,first,last);
    QuickSort(a,first,p-1);
    QuickSort(a,p+1,last);
}


template <class T>
void my_sort(T a[], int size) {

    if(isRev(a,size)){RevSort(a,size);}
    else if(ZerosOnes(a,size))MySort(a,0,size-1);
    else if(Sorted(a,size)){}
    //ispipe function returns true when -> organ pipe / semi1 / maybe sometimes semi2
    else if(isPipe(a,size)){Shuffle(a,size);QuickSort(a,0,size-1);insertion(a,size);}
    else{QuickSort(a,0,size-1);insertion(a,size);}

}