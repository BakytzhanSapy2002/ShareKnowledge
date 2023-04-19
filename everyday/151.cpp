#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<vector<char> >ss;
        bool empty_space;
        if(s[0]==' ')empty_space=true;
        if(s[0]!=' ')empty_space=false;
        vector<char>c;
        for(int i=0;i<s.length();i++){
            if(empty_space==false) c.push_back(s[i]);
            if(i<s.length()-1){
                if(empty_space==false){
                if(s[i+1]==' '){
                    if(c.size()>0){
                    ss.push_back(c);
                    c.clear();
                    empty_space=true;
                }
                } 
            }
                if(s[i+1]!=' '){
                    empty_space=false;
                }
            }
            else{
                if(s[i]!=' ') {
                    if(c.size()>0){
                    ss.push_back(c);
                    c.clear();
                    empty_space=true;
                }
                }
            }
        }
        string res="";
        for(int i=ss.size()-1; i>=0; i--){
            string word="";
            for(int j=0; j<ss[i].size();j++){
                word=word+ss[i][j];
            }
            if(i==0) res=res+word;
            else res=res+word+' ';
        }
        return res;
    }
};
int main(){
string s;
getline(cin,s);
Solution ss;
cout<<ss.reverseWords(s)<<endl;
return 0;
}