//Time Complexity - O(N)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=-hOKIfAcwzk
int Solution::solve(int A, vector<int> &B) {
    
    int n = B.size();
    long long prefix[n];
    prefix[0] = B[0];
    
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + B[i];
    }
    
    long long sum = prefix[n-1];
    
    if(sum % 3!=0){
        return 0;
    }
    
    int ans = 0, count = 0;
    
    for(int i=0; i < n-1;i++){
        
        if(3*prefix[i] == 2*sum){         //After we have got the first partition
             ans = ans + count;           //now we calculate the number of second partitions
        }                                 //corresponding to each first partition
                                              
        if(3*prefix[i] == sum ){          //Using this condition we are keeping the
                count++;                  //record of the number of first partitions
            
        }
    }
    return ans;
}
