#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
string randomDirection();
char randomCharacter();
void insertRandomCharacterToArray(char arr[][10], char W, int x, int y);
void insertCharacterOfWordToArray(char arr[][10], string direction, string word);
void insertCharacterToArray(char arr[][10], int x, int y, char character);
bool checkBounds(char arr[][10], int x, int y, int w, int h);
bool checkIfSpaceUsed(char arr[][10], int x, int y);
vector<string> readFile(string filename);
bool checkIfWordFits(char arr[][10], int y, int x, int w, int h, string direction, string word);
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
vector<string> wordlist = readFile("wordlist.txt");
/*for(int i=0; i<wordlist.size(); i++){
  std::cout << wordlist[i] << endl;
}*/
    cout << sizeof(arr) << " " << sizeof(arr[0]) << " " << sizeof(arr[0][0]) << endl;
    int w = sizeof(arr)/sizeof(arr[0]);
    int h = sizeof(arr[0])/sizeof(arr[0][0]);
    int random[3];
    string randomWordlist[3];
    
       
        for(int i = 0; i < 3; i++){
        random[i] = rand() % wordlist.size();
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
for(int i = 0; i < 3; i++){
checkIfWordFits(arr, 5, 5, w, h, randomDirection(), randomWordlist[i]);   
}
    return 0;
}

vector<string> readFile(string filename){
ifstream inFile;
    inFile.open(filename);
     //Check for Error
    if (inFile.fail()) {
        cerr << "The file could not be opened. It might not exist, or could be damaged/corrupted." << endl;
        exit(1);
    }

    string item;
    int count = 0;
    vector<string> wordlist;
    //Read a file until you've reached the end
    while (!inFile.eof()) {
        inFile >> item;
        wordlist.push_back(item);
        count++;
    }
    cout << count << " items were found in this file." << endl;
    return wordlist;
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

bool checkIfWordFits(char arr[][10], int y, int x, int w, int h, string direction, string word){
    if(direction == "up" || direction == "down"){
        if(word.length() > h){
            cout << "The word " << word << " doesn't fit because it is longer than " << h << " characters." << endl;
            return false;
        }
        if(direction == "up"){
            if(y - (word.length() - 1) < 0){
                cout << "The word " << word << " doesn't fit because it goes out of bounds when at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
            return false;
            }
            else{
                cout << "The word " << word << " fits at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
                return true;
            }
        }
          if(direction == "down"){
            if(y + (word.length() - 1) > h-1){
                cout << "The word " << word << " doesn't fit because it goes out of bounds when at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
            return false;
            }
            else{
                cout << "The word " << word << " fits at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
                return true;
            }
        }
    }
    if(direction == "left" || direction == "right"){
        if(word.length() > w){
            cout << "The word " << word << " doesn't fit because it is longer than " << w << " characters." << endl;
            return false;
        }
        if(direction == "left"){
            if(x - (word.length() - 1) < 0){
                cout << "The word " << word << " doesn't fit because it goes out of bounds when at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
            return false;
            }
            else{
                cout << "The word " << word << " fits at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
                return true;
            }
        }
          if(direction == "right"){
            if(x + (word.length() - 1) > w-1){
                cout << "The word " << word << " doesn't fit because it goes out of bounds when at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
            return false;
            }
            else{
                cout << "The word " << word << " fits at point " << x << "-" << y << " when the direction is " << direction << "." << endl;
                return true;
            }
        }
    }
}
