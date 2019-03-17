// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <array>
#include <iostream>
#include <string>
#include <math.h>
#include <array>




//User inputs money, use datatype double (Ex. $1.23)
//Give change in smallest amount of coins -> Use modulous operator to first remove all whole dollars (Ex. 1.23 % 1)
//Use mod with 0.25, 0.1, 0.05, 0.01
//return type  function  name(){}
std::string change();
void testAverage();
int averageFromArray(int arr[], int size);
void classTestAverage();

int main()
{
    
    int counter;
    int menu;

    bool keeploop = true;
    while(keeploop){
        std::cout << "1. Changer \n2. Test Average \n3. Class Test Average \n0. Exit"<< std::endl;
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
          case 3: 
        classTestAverage();
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
    std::cout << result << std::endl;
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

void classTestAverage(){
    int arr[10][5];
    int average[10];
    int count = 0;
    int classAverage = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            //std::cout << count++ << std::endl;
            arr[i][j] = rand() % 101;
            //std::cout << arr[i][j] << std::endl;
        }  
    }

    //int newArr[] = {2, 3, 5, 10, 11, 67, 89};
    int size = (sizeof(arr)/sizeof(arr[0]));
   //printf("my average: %d\n", averageFromArray(newArr,size));

    for(int y = 0; y < size; y++){
    average[y] = averageFromArray(arr[y], (sizeof(arr[y])/sizeof(arr[y][0])));
    }
    for(int y = 0; y < size; y++){
        std::cout << average[y] << " ";
    }
    classAverage = averageFromArray(average, size);
    std::cout << "Class Average: " << classAverage << std::endl;
    return;
}

int averageFromArray(int arr[], int size){
    //TODO takes array gives back average of that array
    //make an int, add each index of array, then divide by 5.
   int average = 0;
   
    for(int i = 0; i < size; i++){
        average += arr[i];
    }

    average = average/size;
    

    return average;
}

