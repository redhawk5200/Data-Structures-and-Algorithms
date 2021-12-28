#include<bits/stdc++.h>
using namespace std;

class hashing{
    public:
        int sizeofhashtable;
        list<int> *hashtable;

    hashing(int n){
        sizeofhashtable=n;
        hashtable=new list<int>[sizeofhashtable];
    }

    int hashfunction(int key){
        return key%sizeofhashtable;
    }

    void insertion(int key){
        int index=hashfunction(key);
        hashtable[index].push_back(key);
    }

    void search(int key){
        int index=hashfunction(key);
        int count=1;
        for(auto it=hashtable[index].begin();it!=hashtable[index].end();it++){
            if(*it==key){
                cout<<"Key found at index: "<<index<<" and node: "<<count<<endl;
                break;
            }
            count++;
        }
    }

    void delete_(int key){
        int index=hashfunction(key);
        for(auto it=hashtable[index].begin();it!=hashtable[index].end();it++){
            if(*it==key){
                hashtable[index].erase(it);
                break;
            }
        }
    }

    void print(){
        for(int i=0;i<sizeofhashtable;i++){
            cout<<i<<"->";
            for(auto it=hashtable[i].begin();it!=hashtable[i].end();it++){
                cout<<(*it)<<"-->";
            }
            cout<<endl;
        }
    }
};

int main(){
	hashing h(7);
	int array[7]={11,12,21,14,15,34,89};
	for(int i=0;i<7;i++){
		h.insertion(array[i]);
	}
    h.print();
	h.search(89);

	h.delete_(11);
	h.print();
}
