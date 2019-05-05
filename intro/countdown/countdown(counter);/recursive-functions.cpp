// Example program
#include <iostream>
#include <string>

void countdown(int counter);
void countdownRecursive(int counter);
void countRecursive(int counter);

int main()
{int counter;

   std::cin >> counter;
//   countdown(counter);
    //countdownRecursive(counter);
    countRecursive(counter);

}

void countdown(int counter){
 while(counter > 0){
       counter--;
       printf("%d\n", counter);
   }
}

void countdownRecursive(int counter){
    printf("%d\n", counter);
    counter--;
    if(counter > 0){
        countdownRecursive(counter);
    }
}
void countRecursive(int counter){
    i++;
    printf("%d\n", i);
    if(i < counter){
        countRecursive(counter);
    }
}

void addAllUpToN(int counter){
    if(i < counter){
      addAllUpToN(counter);
   }
}
