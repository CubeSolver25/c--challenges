// Example program
#include <iostream>
#include <string>

//headers
int add5(int x);
int square(int n);
int distance(int a, int b);
std::string judgement(double recepY, double arrowY);

int main(){
 int x = 45353;
 int n = 100;
 
 int a, b;
 a = 24;
 b = 30;
 double recepY, arrowY;
 recepY = 110;
 arrowY = 80;
 std::cout << add5(x) << std::endl; //prints 25
 std::cout << square(n) << std::endl; //prints 10000
 std::cout << distance(a, b) << std::endl; //prints 5
 std::cout << judgement(recepY, arrowY); // 
 
 return 1;
}

int add5(int x){
    return x+5;
};
int square(int n){
    return n*n;
};
int distance(int a, int b){
    return abs(a-b);
};
std::string judgement(double recepY, double arrowY){
    std::string judge;
    double x = abs(recepY-arrowY);
    if( x <= 25 ){
        if( x <= 20){
              if( x <= 10){
                    if( x <= 5){
                        judge = "Perfect!!";
                        }
                         else {judge = "Great!";
                    }}
                    else {judge = "Good";
                    }}
           else {judge = "Boo";}    
           return judge;
           }
      else{
       return "Out of Range.";
      }
    };
         
