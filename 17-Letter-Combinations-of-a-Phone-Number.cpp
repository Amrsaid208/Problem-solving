class Solution {
public:
    void bt(int digit , int len , vector<string> &ans ,string &temp,vector<string> &vec ,string &digits)
    {
        if(digit > digits.size()) return ;
            // cout<<temp<<\ \;
        if(temp.length() == len )
        {
            ans.push_back(temp);
            return;
        }
       // temp+=ch;
         int idx=digits[digit]-'0';
         
        string curr=vec[idx];
        for(int i=0;i<curr.length();i++)
        {
        // cout<<curr[i]<<\ \;
        temp+=curr[i];
            bt( digit + 1 ,  len ,  ans ,temp, vec,digits );
            // cout<<temp<<\ \;
            temp.pop_back();
        }
        

    }
    vector<string> letterCombinations(string digits) {
        vector<string> vec{\\,\\,\abc\,\def\,\ghi\,\jkl\,\mno\,\pqrs\,\tuv\,\wxyz\};
        vector<string> ans;
        if(!digits.size()) return {};
        string s=\\;
    
          bt(0,digits.length(),ans,s,vec,digits);
           return ans;
    }
};