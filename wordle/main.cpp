#include<bits/stdc++.h>
#include "all_function.cpp"
using namespace std;

int main(){
    vector<string>all_words;
    read_words(all_words,"input.txt");
    srand(time(0));
    string word = random_word(),result;
    cout<<word<<" Enter its value "<<endl;
    int cnt_times=5,hints=0;
    while(cnt_times--){
        cin>>result;
        if(isMatch(result)){
            cout<<"Congratulations!!!"<<endl;
            return 0;
        }
        hints=(hints|anyHints(result));
        if(hints==false){
            next_word(all_words,result,word);
            word = random_word();
            cout<<word<<" Enter its value "<<endl;
            continue;
        }
        word = next_word(all_words,result,word);
        if(word=="no word matched"){
            cout<<word<<endl;
        }
        cout<<word<<" Enter its value "<<endl;
    }
}