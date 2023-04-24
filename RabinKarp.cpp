//#include <iostream>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//long hashFunc(string text, int start, int finish) {
//    long result = 0;
//    for (int i = start; i < finish; i++) {
//        result += text[i] * pow(11, text.length() - i - 1);
//    }
//    result = result % 991;
//    return result;
//}
//
//vector<int> rabinKarp(string &text, string &searchedText) {
//    vector<int> result;
//    long searchedTextHash = hashFunc(searchedText, 0, searchedText.length() - 1);
//    for (int i = 0; i <= text.length() - searchedText.length(); i++) { // fixed the loop condition
//        if (hashFunc(text, i, i + searchedText.length()-1) == searchedTextHash) {
//            result.push_back(i);
//        }
//    }
//    return result;
//}
//
//int main(){
//    string str1 = "jirwjeorwjrlkmdwldw";
//    string str2 = "jir";
//    vector<int> res = rabinKarp(str1, str2);
//    for (int i = 0; i < res.size(); i++) {
//        cout << res[i] << " ";
//    }
//    return 0;
//}