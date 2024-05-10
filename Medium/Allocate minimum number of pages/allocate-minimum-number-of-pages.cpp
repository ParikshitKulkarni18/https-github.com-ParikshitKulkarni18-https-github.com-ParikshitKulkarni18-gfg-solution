//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossiblesol(int A[],int N,int M,int sol){
        int pagesum =0;  // gives current sum
        int countStud =1;  //  how many we have allocated to student
        for(int i=0;i<N;i++){
            if(A[i]> sol ){
                return false;
                
            }
           if(pagesum+A[i]>sol){
               countStud ++; // help to give the book to the next student as sum is greater than ans/ mid
              pagesum =A[i];
              if (countStud > M ){
                  return false;
              }
               
           }
           else {
               pagesum +=A[i];
           }
           
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if (M>N){
            return -1;
        }
        int start =0;
        int end = accumulate(A,A+N,0);// stl librarry ued to find sum 1 parameter as array start,end of array ,initail sum =0
        int ans =-1;
         // finding search space
        while(start <= end){
            int mid = (start+ end)>>1;
            if (isPossiblesol(A,N,M,mid)){
                ans = mid;
                end = mid -1;
                
            }
            else {
                start = mid +1;
                 
            }
        }
         return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends