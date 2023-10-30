/*CodeStudio solution*/

int atoi(string str) {
    // Write your code here.
    int sign=1;
    int i=0;
    int ans=0;
    if(str[i]=='-'){
        sign=-1;
        i++;
    }
    for(;i<str.length();i++){
        if(str[i]-'0'>=0 && str[i]-'0'<=9){
            ans=ans*10+str[i]-'0';
        }
    }
    return ans*sign;
}

int strStr(string a, string b){
	//Write your code here
    if(b.find(a)<b.size())
        return b.find(a);
    else
        return -1;
}


/*Leetcode solution*/

class Solution {
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
public:
    int myAtoi(string s) {
        trim(s);
        const int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        long num = 0;

        for (const char c : s) {
            if (!isdigit(c))
                break;
            num = num * 10 + (c - '0');
            if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
        }

        return sign * num;
    }

    int strStr(string haystack, string needle) {
        if(haystack.find(needle) < haystack.size())
            return haystack.find(needle);
        else
            return -1;
    }

