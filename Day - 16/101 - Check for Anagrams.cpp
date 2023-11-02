/*CodeStudio solution*/

bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1 == str2)
        return true;
    if(str1.size() != str2.size())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1 == str2)
        return true;
    return false;
}

/*Leetcode solution*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t)
            return true;
        if(s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t)
            return true;
        return false;
    }
};

