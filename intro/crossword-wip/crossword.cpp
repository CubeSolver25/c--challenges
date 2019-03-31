#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string randomDirection();
char randomCharacter();
void insertRandomCharacterToArray(char arr[][10], char W, int x, int y);
void insertCharacterOfWordToArray(char arr[][10], string direction, string word);
void insertCharacterToArray(char arr[][10], int x, int y, char character);
bool checkBounds(char arr[][10], int x, int y, int w, int h);
bool checkIfSpaceUsed(char arr[][10], int x, int y);
int main(){
    
    srand(time(0));
    char arr[10][10];
      for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  arr[i][j] = ' ';
       }
      }
      for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  checkIfSpaceUsed(arr, i, j);
       }
}
    cout << sizeof(arr) << " " << sizeof(arr[0]) << " " << sizeof(arr[0][0]) << endl;
    int w = sizeof(arr)/sizeof(arr[0]);
    int h = sizeof(arr[0])/sizeof(arr[0][0]);
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
for(int i = 0; i < 20; i++){
randomDirection();
}
   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  insertRandomCharacterToArray(arr, randomCharacter(), i, j);
       }
}
   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
    cout << arr[i][j] << "  ";
       }
    cout << endl;   
}

 for(int i = 0; i < 3; i++){
      insertCharacterOfWordToArray(arr, randomDirection(), randomWordlist[i]);
        
    }
      for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  insertCharacterToArray(arr, i, j, 'z');
       }
}
   for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
    cout << arr[i][j] << "  ";
       }
    cout << endl;   
}
    checkBounds(arr, 0, -1, w, h);
      for(int i = 0; i < 10; i++){
       for(int j = 0; j < 10; j++){
  checkIfSpaceUsed(arr, i, j);
       }
}
    return 0;
}

string randomDirection(){
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
    cout << direction << endl;
return direction;
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
void insertCharacterOfWordToArray(char arr[][10], string direction, string word){
 int x = rand() % 10;
 int y = rand() % 10;  
    arr[x][y] = word.at(0);
    cout << word << " First Character: " << arr[x][y] << endl;
}
void insertCharacterToArray(char arr[][10], int x, int y, char character){
    arr[x][y] = character;
    cout << arr[x][y] << endl;
}
bool checkBounds(char arr[][10], int x, int y, int w, int h){
cout << w << " " << h << endl;
if( x > (w-1) || y > (h-1) || x < 0 || y < 0){
cout << "The coordinate is out of bounds." << endl;
    return true;
}
else
{
    cout << "The coordinate is inside the bounds." << endl;
  return false;  
}

}
bool checkIfSpaceUsed(char arr[][10], int x, int y){
if(arr[x][y] != ' '){
    cout << "This space is already occupied by another character." << endl;
    return true;
}
    else{
    cout << "This space is not occupied." << endl;
    return false;
    }
}
