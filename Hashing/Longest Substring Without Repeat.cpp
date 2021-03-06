int Solution::lengthOfLongestSubstring(string A) {
    
    if(A.size() == 1){
        return 1;
    }
    int max_len = INT_MIN;
    
    int l = 0, r = 1;
    
    unordered_map<char,int> alpha;
    
    alpha[A[l]] = l;
    
    while(r < A.size()){
        
        if(alpha.find(A[r]) != alpha.end()){
            
            if(alpha[A[r]] >= l)                //We don't need to consider the occurences of a character before l 
            {
                //cout << A.substr(l,r-l) << endl;
                max_len = max(max_len,r-l);
                l = alpha[A[r]] + 1;            //Jump to the next index of the repeated element
                alpha[A[r]] = r;                
                r++;
            }
            else{                               
                alpha[A[r]] = r;
                r++;
            }
        }
        else{
            alpha[A[r]] = r;
            r++;
        }
        //cout << max_len << " ";
    }
    max_len = max(max_len,r-l);
    return max_len;
}
