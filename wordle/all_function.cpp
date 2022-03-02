#include<bits/stdc++.h>
#include<fstream>
using namespace std;
map<char,bool>ache,ignored;
map<string,bool>igonre_word;
vector<pair<int,char>>val_with_pos,not_fixed;
bool isItIgnorable(string s);
bool isUnique(string s){
    set<char>st;
    for(auto to:s)st.insert(to);
    return (st.size()==5);
    //01713656631
}
void read_words(vector<string>&vs,string file_path){
    fstream file;
    file.open(file_path.c_str());
    if(file.is_open()==false){
        cout<<"occur error while file openning"<<endl;
        return;
    }
    string s,tmp;
    while(file>>s){
        vs.push_back(s);
    }
}
string random_word(){
    vector<string>vs;
    read_words(vs,"unique.txt");
    srand(time(0));
    while(1){
        int pos = rand()%vs.size();
        if(isItIgnorable(vs[pos])==false)
            return vs[pos];
    }
}
bool result_checker(string s){
    if(s.size()!=5)return false;
    for(auto to:s){
        if(to!='y' and to!='g' and to!='b')return false;
    }
    return true;
}
bool isMatch(string s){
    return (count(s.begin(),s.end(),'g')==5);
}
bool anyHints(string s){
    return (count(s.begin(),s.end(),'b')!=5);
}
bool jaraThakarKothaTaraAche(string s){
    int cnt=0;
    for(auto to:ache){
        for(auto t:s){
            if(to.first==t){
                cnt++;break;
            }
        }
    }
    if(cnt==ache.size())return true;
    return false;
}
bool isItIgnorable(string s){
    if(igonre_word[s])return true;
    for(auto to:s){
        if(ignored[to])return true;
    }
    return false;
}
bool jaygaMotoAcheKina(string s){
    for(auto to:val_with_pos){
        if(s[to.first]!=to.second)return false;
    }
    return true;

}
bool vulJaygayAcheKina(string s){
    for(auto to:not_fixed){
            if(s[to.first]==to.second)return true;
        }
        return false;
}
string next_word(vector<string>&vs,string result, string word, int print=0){
    for(int j=0; j<5; j++){
        if(result[j]=='g'){
            val_with_pos.push_back({j,word[j]});
            ache[word[j]]=1;
        }
        if(result[j]=='y'){
            not_fixed.push_back({j,word[j]});
            ache[word[j]]=1;
        }
    }
    for(int j=0; j<5; j++){
        if(ache.find(word[j])==ache.end())ignored[word[j]]=1;
    }
    vector<string>ans;
    for(auto check_string:vs){
        if(isItIgnorable(check_string))continue;
        if(jaraThakarKothaTaraAche(check_string)==false)continue;
        if(jaygaMotoAcheKina(check_string)==false)continue;
        if(vulJaygayAcheKina(check_string))continue;
        ans.push_back(check_string);
    }
    if(ans.size()>0){
        srand(time(0));
        int pos = rand()%ans.size();
        if(print){
            
        for(auto to:ans)cout<<to<<" ";
        cout<<" finished"<<endl;
        }
        return ans[pos];
    }
    return "no word matched";
}
string first_word(){
    string s="aeiou";
    vector<string>ans;
    do{
        ans.push_back(s);
    }
    while(next_permutation(s.begin(),s.end()));
    srand(time(0));
    return ans[rand()%ans.size()];
}
int letter_find(){
    return ache.size();
}
void all_clear(){
    ache.clear(),ignored.clear();
    val_with_pos.clear(),not_fixed.clear();
}
void set_ignore(string s){
    igonre_word[s]=1;
}