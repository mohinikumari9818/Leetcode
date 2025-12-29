class Solution {
public:
    int pivotInteger(int n) {
        int pivot=1;
        int pivotsum=0;
        int nextsum=0;
        if(pivot>n){
            return -1;
        }
        int totalsum=(n*(n+1))/2;
        while(pivot<=n){
            pivotsum=(pivot*(pivot+1))/2;
            nextsum=totalsum - ((pivot-1)*pivot)/2;
            if(pivotsum==nextsum){
                return pivot;
            }  
            pivot++;
        }
        return -1;
    }
};