// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <array>
#include <sstream>



//User inputs money, use datatype double (Ex. $1.23)
//Give change in smallest amount of coins -> Use modulous operator to first remove all whole dollars (Ex. 1.23 % 1)
//Use mod with 0.25, 0.1, 0.05, 0.01
//return type  function  name(){}
std::string change();
void testAverage();


int main()
{
    
    int counter;
    int menu;

    bool keeploop = true;
    while(keeploop){
        std::cout << "1. Changer \n2. Test Average \n0. Exit"<< std::endl;
        std::cin >> menu;
    switch(menu){
        case 0:
         keeploop = false;
         break;
        case 1:
        change();
        break;
        case 2: 
        testAverage();
        break;
        case 4:
      default:
        keeploop = false;
        break;
    }}
    /*while(counter % 2 == 0){
    std::cin >> counter;
    }*/
      //std::cin >> money;
      //std::cout<< change(money) << std::endl;
}

std::string change(){
  double money;
   std::cout << "Money Changer: \nPlease enter the amount of money you have." << std::endl;
        std::cin >> money;
    money += 0.001;
    unsigned long quarters, dimes, nickels = 0;
    quarters = dimes = nickels;
    unsigned long change = (unsigned long)((money - floor(money)) * 100);
    quarters = (change / 25);
    change = change % 25;
    dimes = (change / 10);
    change = change % 10;
    nickels = (change / 5);
    change = change % 5;
    std::string result = "Your change is " + 
    std::to_string(quarters) + " quarters, " + 
    std::to_string(dimes) + " dimes, " + 
    std::to_string(nickels) + " nickels, and " + 
    std::to_string(change) + " pennies.";
return result;
}
void testAverage(){
      int size;
    std::cout << "Test Average: \nPlease enter the number of test scores you want to average." << std::endl;
std::cin >> size;
  int arr[size];
  for(int i = 0; i < size; i++){
     std::cout << "Enter your score for Test #" << (i+1) <<  "." << std::endl;  
  std::cin >> arr[i];
  }
int average = 0;
for(int i = 0; i < size; i++){
average += arr[i];}
average /= size;
std::cout << average << std::endl;
return;
}
