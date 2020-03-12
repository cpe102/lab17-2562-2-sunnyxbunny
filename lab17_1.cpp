//Write your code here

#include <iostream>
#include <cstring> 
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;
int main(){
    ifstream fin("name_score.txt");
    string s,rule,fix,fix2;
    vector<string> a;
    vector<string> grade;
    char name[100],point[100];
    int na,nb,nc,nd = 0;
    int count=0,check =0,check2 =0;
    
    while(getline(fin,s)){
        a.push_back(s);
        count++;
    }
    
    for(int i=0;i<count;i++){
        const char *c = a[i].c_str();
        char format[] = "%[^:]: %d %d %d";
        sscanf(c,format,name,&na,&nb,&nc);
        nd = na+nb+nc;
        a.at(i)=name;
        grade.push_back(nd >= 80 ? "A": nd >= 70 ? "B" : nd >= 60 ? "C" : nd >= 50 ? "D" :"F");
    }
    string command;
    
    for(;;){
        cout << "---------------------------------\n";
        cout << "Please input your command: ";
        getline(cin,command);
        cout << "---------------------------------\n";
        rule = command.substr(0,5);
        if(rule == "name "){
            command = command.erase(0,5);
            for(int i=0;i<count;i++){
                fix = a[i];
                for(int j=0;j<fix.size();j++){
                    fix[j]=toupper(fix[j]); 
                }
                for(int k=0;k<command.size();k++){
                    command[k]=toupper(command[k]); 
                }
                if(command == fix){
                    cout << a[i] << "'s grade = " << grade[i] << "\n" ;
                    check2++;
                }
            }
            if(check2 ==0){
                cout <<"Cannot found.\n";
            }
        }else if(rule == "grade"){
            command = command.erase(0,6);
            for(int i=0;i<count;i++){
                for(int k=0;k<command.size();k++){
                    command[k]=toupper(command[k]); 
                }
                if(command == grade[i]){
                    cout << a[i] << "\n";
                    check++;
                }
            }
            if(check ==0){
                cout <<"Cannot found.\n";
            }
        }else if(rule == "exit"){
            break;
        }else{
            cout << "Invalid command\n";
        }
    }
}