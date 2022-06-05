#include <iostream>
using namespace std;



bool isValid(char ch){
  if (ch >='a' && ch<='z')
    return true;
  return false;
  
}
char toLowerCase(char ch){
  if (ch>='a' && ch<='z'){
    return ch;
  }
  else{
    char chr= ch-'A'+'a';
    return chr;
  }
}
bool checkPallindrome(char name[], int n){
  int s=0;
  int e=n-1;

  while(s<e){
    if (name[s] || name[e]=='@'|| '#' || '$'|| ' '|| '*'){
      s++;e--;}
    if(toLowerCase(name[s])!=toLowerCase(name[e])){
      return 0;} 
    else if (toLowerCase(name[s])==toLowerCase(name[e]))
       s++;e--;
    }
  return 1;
      
   
  
}

void reverseString(char name[], int n){
  int s=0;
  int e= n-1;
  while(s<e){
    swap(name[s++], name[e--]);
  }
}
// char array sdont need to pass the size of array 
int getLength(char name[]){
  // will find the length of array 
  // strt from 0  got till null pointer
  int count=0;
  
  for (int i=0; name[i] !='\0';i++){
    count++;
  }
  return count;
}
int main() {
  // this is basically a way of storing string in c++
  char name[20];
  //cout<< "Enter your name"<< endl;
  cin>> name;
  //name[2]='\0';
  //cout<< name<< endl;
  // length of string 
  int j= getLength(name);
  //cout<< j;
  //reverseString(name, j);
  //cout<< name<<endl;
  cout<< checkPallindrome(name, j)<<endl;
  //cout<< toLowerCase('c')<< endl;
  //cout<< toLowerCase('D')<<endl;
  
  
  
}