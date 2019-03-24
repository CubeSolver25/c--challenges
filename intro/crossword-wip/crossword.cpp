#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int randomDirection();
char randomCharacter();
void insertRandomCharacterToArray(char arr[][10], char W, int x, int y);
int main(){
    srand(time(0));
    char arr[10][10];
    int random[3];
    string randomWordlist[3];
    ifstream inFile;
    inFile.open("wordlist.txt");
     //Check for Error
    if (inFile.fail()) {
        cerr << "The file could not be opened. It might not exist, or could be damaged/corrupted." << endl;
        exit(1);
    }

    string item;
    int count = 0;
    string wordlist[7776];
    //Read a file until you've reached the end
    while (!inFile.eof()) {
        inFile >> item;
        wordlist[count] = item;
        count++;
    }
    cout << count << " items were found in this file." << endl;
       
        for(int i = 0; i < 3; i++){
        random[i] = rand() % count;
        randomWordlist[i] = wordlist[random[i]];
        cout << random[i] << endl;
        cout << randomWordlist[i] << endl;
    }

   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  insertRandomCharacterToArray(arr, randomCharacter(), i, j);
       }
}
   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
    cout << arr[i][j] << " ";
       }
    cout << endl;   
}


    return 0;
}

int randomDirection(){
     int random;
     string direction;
        random = rand() % 4;
    switch(random){
        case 0:
        direction = "up";
        break;
        case 1:
        direction = "down";
        break;
        case 2: 
        direction = "left";
        break;
        case 3: 
        direction = "right";
        break;
      default:
        break;
    }
    
return 0;
}

char randomCharacter(){
    int a = rand() % (26) + 65;
    char W = static_cast<char>(a);
    cout << W << endl;
    return W;
}

void insertRandomCharacterToArray(char arr[][10], char W, int x, int y){
    //int i = rand() % 10;
    //int a = rand() % 10;
    arr[x][y] = W;
    cout << x << "-" << y << " Array Character: " << arr[x][y] << endl;
    return;
}