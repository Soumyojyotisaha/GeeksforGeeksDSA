#include<bits/stdc++.h>
using namespace std;
struct CoordinatePair{
 int xPos;
 int yPos;
};
void insertFiller(string &text, int n){
 string filledText = "";
 for(int i = 0; i <= n; i++){
 filledText += text[i];
 }
 filledText += 'X';
 for(int i = n + 1; i < text.length(); i++){
 filledText += text[i];
 }
 text = filledText;
}
void adjustText(string &text){
 for(int i = 0; i < text.length() - 1; i++){
 if(text[i] == text[i + 1]){
 insertFiller(text, i);
 }
 }
 if(text.length() % 2 != 0){
 text += 'Z';
 }
}
vector<string> divideIntoPairs(string text){
 vector<string> pairs;
 for(int i = 0; i < text.length(); i += 2){
 pairs.push_back(text.substr(i, 2));
 }
 return pairs;
}
bool characterExists(char val, string text){
 for(int i = 0; i < text.length(); i++){
 if(text[i] == val){
 return false;
 }
 }
 return true;
}
string pairEncryption(string text, char matrix[][5]){
 for(int i = 0; i < 2; i++){
 if(text[i] == 'J'){
 text[i] = 'I';
 }
 }
 CoordinatePair word1, word2;
 for(int i = 0; i < 5; i++){
 for(int j = 0; j < 5; j++){
 if(text[0] == matrix[i][j]){
 word1.xPos = i;
 word1.yPos = j;
 }
 }
 }
 for(int i = 0; i < 5; i++){
 for(int j = 0; j < 5; j++){
 if(text[1] == matrix[i][j]){
 word2.xPos = i;
 word2.yPos = j;
 }
 }
 }
 string result = "";
 if(word1.yPos == word2.yPos){
 result += matrix[(word1.xPos + 1) % 5][word1.yPos];
 result += matrix[(word2.xPos + 1) % 5][word2.yPos];
 return result;
 }
 else if(word1.xPos == word2.xPos){
 result += matrix[word1.xPos][(word1.yPos + 1) % 5];
 result += matrix[word2.xPos][(word2.yPos + 1) % 5];
 return result;
 }
 else{
 result += matrix[word1.xPos][word2.yPos];
 result += matrix[word2.xPos][word1.yPos];
 return result;
 }
}
string completeEncryption(vector<string> textPairs, string key){
 string workingString = "";
 for(int i = 0; i < key.length(); i++){
 if(key[i] == 'J'){
 key[i] = 'I';
 }
 }
 for(int i = 0; i < key.length(); i++){
 if(characterExists(key[i], workingString)){
 workingString += key[i];
 }
 }
 char a = 'A';
 while(workingString.length() != 25){
 if(a == 'J'){
 a++;
 continue;
 }
 if(characterExists(a, workingString)){
 workingString += a;
 }
 a++;
 }
 char matrix[5][5];
 int counter = 0;
 for(int i = 0; i < 5; i++){
 for(int j = 0; j < 5; j++){
 matrix[i][j] = workingString[counter];
 counter++;
 }
 }
 for(int i = 0; i < 5; i++){
 for(int j = 0; j < 5; j++){
 cout << matrix[i][j] << " ";
 }
 cout << endl;
 }
 workingString = "";
 for(int i = 0; i < textPairs.size(); i++){
 string result = pairEncryption(textPairs[i], matrix);
 workingString += result;
 }
 return workingString;
}
int main(){
 string key, text;
 cout << "Enter the key: ";
 cin >> key;
 cout << "Enter the text: ";
 cin >> text;
 string originalText = text;
 adjustText(text);
 auto dividedPairs = divideIntoPairs(text);
 cout << "Splitting of the plain text: ";
 for(int i = 0; i < dividedPairs.size(); i++){
 cout << dividedPairs[i] << " ";
 }
 cout << endl;
 cout << "Key Matrix: " << endl;
 auto encryptedText = completeEncryption(dividedPairs, key);
 cout << endl << "Encrypted Text: " << encryptedText << endl;
 cout << "Decrypted Text: " << originalText;
}