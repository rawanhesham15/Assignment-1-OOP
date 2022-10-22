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


BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec){
    BigDecimalInt b1, b2;
    int a, b, c = 0, i, z = 0;
    b1.vec = vec;
    b2.vec = anotherDec.vec;
    if (s =='+' && anotherDec.s=='+' ){
        checkSize(b1.vec, b2.vec);
        addition(b1.vec,b2.vec);
        return b1;
    }
    else if (s =='-' && anotherDec.s=='+'){
        checkSize(b1.vec, b2.vec);
        for (int j = 0; j < vec.size(); ++j)
        {
            if (b1.vec[j] > b2.vec[j])
            {
                subtraction(b1.vec,b2.vec);
                cout<<"-";
                return b1;
            }
            else if (b1.vec[j] < b2.vec[j])
            {
                subtraction(b2.vec,b1.vec);
                return b2;
            }
        }
        return 0;
    }
    
    
    else if (s =='+' && anotherDec.s=='-'){
        if(b1.vec.size() > b2.vec.size()){
            checkSize(b1.vec, b2.vec);
            subtraction(b1.vec,b2.vec);
            return b1;
        }
        else if(b1.vec.size() < b2.vec.size() ){
            checkSize(b1.vec, b2.vec);
            cout<<"-";
            subtraction(b2.vec,b1.vec);
            return b2;
        }
        else{
            for (int j = 0; j < vec.size(); ++j) {
                if (b1.vec[j] > b2.vec[j]) {
                    subtraction(b1.vec,b2.vec);
                    return b1;
                }
                else if (b1.vec[j] < b2.vec[j]){
                    cout<<"-";
                    subtraction(b2.vec,b1.vec);
                    return b2;
                }
            }
            return 0;
        }
    }
    else if(s =='-' && anotherDec.s=='-'){
        checkSize(b1.vec, b2.vec);
        addition(b1.vec,b2.vec);
        cout <<"-";
        return b1;
    }
}


BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
    BigDecimalInt b1, b2;
    int a, b, c = 0, i, z = 0;
    b1.vec = vec;
    b2.vec = anotherDec.vec;
    if (s =='+' && anotherDec.s=='+' )
    {
         checkSize(b1.vec, b2.vec);
          for (int j = 0; j < vec.size(); ++j) {
              if (b1.vec[j] > b2.vec[j])
                {
                    subtraction(b1.vec,b2.vec);
                    return b1;
                }
                else if (b1.vec[j] < b2.vec[j])
                {
                    cout<<"-";
                    subtraction(b2.vec,b1.vec);
                    return b2;
                }
            }
            return 0;
    }
    else if (s =='-' && anotherDec.s=='+'){
        checkSize(b1.vec, b2.vec);
        addition(b1.vec,b2.vec);
        cout <<"-";
        return b1;
    }
    else if (s =='+' && anotherDec.s=='-'){
        checkSize(b1.vec, b2.vec);
        addition(b1.vec,b2.vec);
        return b1;
    }
    else if(s =='-' && anotherDec.s=='-'){
       checkSize(b1.vec, b2.vec);
            for (int j = 0; j < vec.size(); ++j)
            {
                if (b1.vec[j] > b2.vec[j])
                {
                    subtraction(b1.vec,b2.vec);
                    cout<<"-";
                    return b1;
                }
                else if (b1.vec[j] < b2.vec[j])
                {
                    subtraction(b2.vec,b1.vec);
                    return b2;
                }
            }
            return 0;
        }
    }
}

void BigDecimalInt::subtraction(vector <int>& v1,vector <int>& v2){
    int a, b, c = 0, i, z = 0;
    for (i = vec.size()-1  ; i > -1 ; i-- ){
        a = v1[i] - v2[i]  ;
        if(a<0){
            b=a+10;
            v1[i-1]-=1;
        }
        else{
            b=a;
        }
        v1[i]=b;
    }
}

void BigDecimalInt::addition(vector <int>& v1,vector <int>& v2){
    int a, b, c = 0, i, z = 0;
    for (i = vec.size()-1  ; i > -1 ; i-- ){
        a = v1[i] + v2[i] + c ;
        if (a > 9){
            b = a - 10 ;
            c = 1 ;
        }
        else{
            b = a ;
            c = 0 ;
        }
        v1[i] = b ;
        if (i==0){
            v1[i] = a ;
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


bool BigDecimalInt::operator< (BigDecimalInt b) {
    checkSize(vec, b.vec);
    if (s == '-' && b.s == '+') {
        return true;
    }
    else if (s == '+' && b.s == '-') {
        return false;
    }
    else if(s == '+' && b.s == '+') {
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] > b.vec[j]) {
                return false;
            }
            else if (vec[j] < b.vec[j]) {
                return true;
            }
        }
    }
    else if(s == '-' && b.s == '-'){
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] > b.vec[j]) {
                return true;
            }
            else if (vec[j] < b.vec[j]) {
                return false;
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
