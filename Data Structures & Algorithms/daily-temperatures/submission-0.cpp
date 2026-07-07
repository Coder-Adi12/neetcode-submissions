class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st; 
        int size = temperatures.size();
        vector<int>result(size);
        int count;
        for(int i = 0 ; i< temperatures.size() ; i++)
        {    
            count = 0 ;
            for(int j =i+1 ; j<temperatures.size() ; j++){
            if(temperatures[j]>temperatures[i])
            {
                count = j -i;
                break;
            }
            
            
        }
        result[i]=count;

        }
        return result;
    }
};
