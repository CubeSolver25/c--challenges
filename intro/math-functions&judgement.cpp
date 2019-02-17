// Example program
#include <iostream>
#include <string>

//headers
int add5(int x);
int square(int n);
int distance(int a, int b);
std::string judgement(double recepY, double arrowY);
bool checker(std::string question, double answer);

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
  std::string question = "What is 100 + 2";
 double answer = 102;
 std::cout << checker(question, answer) << std::endl;
 return 1;
 std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    if (str1.compare(str2) != 0){
    std::cout << str1 << " is not " << str2;
}
else std::cout << str1 << " is " << str2;
   
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
         bool checker(std::string question, double answer)
{ double userinput;
    std::cout << question << std::endl;
        std::cin >> userinput;
        if(userinput == answer){
            return true;
        }
        else {
            return false;
        }

    

}
