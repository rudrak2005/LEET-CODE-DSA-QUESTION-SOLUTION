class Solution {
public:
    string multiply(string num1, string num2) {
      if(num1 == "0" || num2 == "0")
                return "0";
        int n = num1.size();
        int m =num2.size();

        vector<int> result(n + m, 0);
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int a= num1[i]-'0';
                int b = num2[j]-'0';
                int product= a*b;
                int p2 = i+j+1;
                int p1 = i+j;
                int sum = result[p2]+product;

                result[p2]= sum %10;
                result[p1] += sum/ 10;
            }
        }
        string ans ="";
        int i =0;
        while(i<result.size() && result[i] == 0)
        i++;
        while(i<result.size()){
            ans +=char(result[i] + '0');
            i++;
        }  
        return ans;
    }
};