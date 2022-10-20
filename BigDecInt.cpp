#include "BigDecInt.h"


BigDecimalInt::BigDecimalInt (int decInt){
    vector<int> v;
    string temp;
    int x, y, z, c= 1;
    for ( int i = 0 ; i < c ; i++){
        y = decInt % 10 ;
        decInt = decInt / 10 ;
        temp += char(y) + '0' ;
        if (decInt == 0 ){
            break ;
        }
        c++ ;
    }
    for (int i = 0 ; i < temp.length() ; i++){
        x = temp[i] - 48  ;
        v.push_back(x) ;
    }
    for (int i = (v.size()-1) ; i > -1 ; i--){
        vec.push_back(v[i]) ;
    }
}


BigDecimalInt::BigDecimalInt (string decStr){
    vector<int> v;
    int x;
    for (int i = 0 ; i < decStr.length() ; i++){
        if(i == 0) {
            if (!isdigit(decStr[0])) {
                s = decStr[0];
            } else {
                s = '+';
                x = decStr[i] - 48;
                v.push_back(x);
            }
        }
        else{
            x = decStr[i] - 48;
            v.push_back(x);
        }
    }
    vec = v;
}





void BigDecimalInt::setVec (vector <int> v){
    vec = v ;
}

vector<int> BigDecimalInt::getVector (){
    return vec;
}

void BigDecimalInt::setS(char sign){
    s = sign;
}

char BigDecimalInt::getS(){
    return s;
}

void BigDecimalInt::checkSize(vector <int>& v1,vector <int>& v2){
    int z = 0;
    if (v1.size() > v2.size() ) {
        vector<int> v3 = v2;
        z = (v1.size() - v2.size());
        v2.clear();
        for (int i = 0; i < z; i++) {
            v2.push_back(0);
        }
        for (int i = 0; i < v3.size(); i++) {
            v2.push_back(v3[i]);
        }
    }
    else if(v1.size() < v2.size()){
        vector<int> v3 = v1;
        z = (v2.size() - v1.size());
        v1.clear();
        for (int i = 0; i < z; i++) {
            v1.push_back(0);
        }
        for (int i = 0; i < v3.size(); i++) {
            v1.push_back(v3[i]);
        }
    }
}

bool BigDecimalInt::operator> (BigDecimalInt b) {
    checkSize(vec, b.vec);
    if (s == '-' && b.s == '+') {
        return false;
    }
    else if (s == '+' && b.s == '-') {
        return true;
    }
    else if(s == '+' && b.s == '+') {
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] > b.vec[j]) {
                return true;
            }
            else if (vec[j] < b.vec[j]) {
                return false;
            }
        }
    }
    if(s == '-' && b.s == '-'){
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] > b.vec[j]) {
                return false;
            }
            else if (vec[j] < b.vec[j]) {
                return true;
            }
        }
    }
}

bool BigDecimalInt::operator== (BigDecimalInt b){
    checkSize(vec, b.vec);
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i] != b.vec[i]){
            return false;
        }
    }
    return true;
}

bool BigDecimalInt::operator= (BigDecimalInt b){
    vec = b.vec;
}

int BigDecimalInt::size(){
    return vec.size();
}

char BigDecimalInt::sign(){
    return s;
}

ostream& operator<< (ostream& out, BigDecimalInt a){
    for(int i = 0 ; i < a.vec.size() ; i++){
        out << a.vec[i];
    }
    return out ;
}
