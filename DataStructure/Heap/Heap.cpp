/*
 * @Souce: 
 * @Author: Arvin Huang
 * @Date: 2020-09-16 23:27:21
 */
#include<iostream>
#include <algorithm>
#include <string>
 #include <cmath>
#include<cassert>

using namespace std;

template<typename Item>
class MinHeap{

private:
    Item * data;
    int count;
    int capacity;

    void shiftUp(int n){
        while(n>1 && data[n/2] >=data[n]){
            swap( data[n/2], data[n] );
            n /= 2;
        }
    }
    void shiftDown(int n){
       while(2*n <= count ){
           int j = 2*n;
           if(j+1 <=count && data[j+1]< data[j]){
               j++;
           }
           if(data[n] >= data[j]){
               swap(data[n],data[j]);
           }
           n = j;
       } 
    }
public:
    MinHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    ~MinHeap(){
        delete[] data;
    }
    int size(){
        return count ;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == capacity;
    }
    void pushBack(Item item){
       if(isFull()){
           cout<<"There is no space in this heap\n";
           return;
       }
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }
    Item popFront(){
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
        
    }

};


int main(){
   MinHeap<int> minHeap = MinHeap<int>(100);    
    for( int i =160 ; i >4 ; i -- ){
        minHeap.pushBack(i);
    }
    while (!minHeap.isEmpty())
    {
        cout << minHeap.popFront() << " ";
    }
    cout << endl;
    return 0;

}
