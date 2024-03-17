#include "long_number.hpp."
#include <iostream>
#include <cmath>

namespace AAntonian {
    LongNumber::LongNumber() {
        numbers = nullptr;
        length = 0;
        sign = POSITIVE;
    }

    LongNumber::LongNumber(const char* const str) {
        length = get_length(str);
        numbers = new int[length];
        sign = POSITIVE;

        int i = 0;
        int k = 0;
        if (str[0] == MINUS) {
            sign = NEGATIVE;
            i++;
            k++;
        }

        for (; i < length + k; i++) {
            numbers[i - k] = str[i] - '0';
        }

        numbers[length] = END;
    }

    LongNumber::LongNumber(const LongNumber& x) {
        length = x.length;
        numbers = new int[length + 1];
        sign = x.sign;

        for (int i = 0; i <= length; i++) {
            numbers[i] = x.numbers[i];
        }
    }

    LongNumber::LongNumber(LongNumber&& x) {
        numbers = x.numbers;
        length = x.length;
        sign = x.sign;

        x.numbers = nullptr;
        x.length = 0;
        x.sign = POSITIVE;

    }

    LongNumber::~LongNumber() {
        delete[] numbers;
    }

    LongNumber& LongNumber::operator = (const char* const str) {
        delete[] numbers;
        length = get_length(str);
        numbers = new int[length];
        sign = POSITIVE;

        int i = 0;
        int k = 0;
        if (str[0] == MINUS) {
            sign = NEGATIVE;
            i++;
            k++;
        }

        for (; i < length; i++) {
            numbers[i - k] = str[i] - '0';
        }

        numbers[length] = END;
        return *this;
    }

    LongNumber& LongNumber::operator = (const LongNumber& x) {
        delete[] numbers;

        length = x.length;
        numbers = new int[length + 1];
        sign = x.sign;

        for(int i = 0; i <= length; ++i){
            numbers[i] = x.numbers[i];
        }
        return *this;
    }

    LongNumber& LongNumber::operator = (LongNumber&& x) {
        delete[] numbers;

        length = x.length;
        numbers = new int[length + 1];
        sign = x.sign;

        for(int i = 0; i <= length; ++i){
            numbers[i] = x.numbers[i];
        }

        x.numbers = nullptr;
        x.length = 0;
        //x.sign = POSITIVE;
        return *this;
    }

    bool LongNumber::operator == (const LongNumber& x) const {
        bool flag = false;
        if (length != x.length){
            return flag;
        }else{
            for (int i = 0; i <= length; i++){
                if (numbers[i] != x.numbers[i]){
                    flag = false;
                    break;
                }else{
                    flag = true;
                }
            }
            return flag;
        }
    }

    bool LongNumber::operator > (const LongNumber& x) const{
        if (sign != x.sign) {
            return sign == POSITIVE;
        }

        if (length != x.length) {
            return length > x.length;
        }
        for (int i = 0; i <= length; i++) {
            if (numbers[i] != x.numbers[i]) {
                return numbers[i] > x.numbers[i];
            }
        }
    }

    bool LongNumber::operator < (const LongNumber& x) const {
        if (sign != x.sign) {
            return sign == NEGATIVE;
        }

        if (length != x.length) {
            return length < x.length;
        }

        for (int i = 0; i <= length; i++) {
            if (numbers[i] != x.numbers[i]) {
                return numbers[i] < x.numbers[i];
            }
        }
    }

    LongNumber LongNumber::operator + (const LongNumber& x) const{
        LongNumber result;

        if(sign == x.sign){
            result.length = fmax(length, x.length) + 1;
            result.numbers = new int[result.length];
            result.sign = sign;
            bool flag = false;
            if (*this > x){
                flag = true;
            }

            for (int i = 0; i < result.length; i++){
                result.numbers[i] = 0;
            }
            int i = flag ? length - 1 : x.length - 1;
            int j = flag ? x.length -1 : length - 1;
            int k = result.length - 1;
            while (i >= 0 && j >= 0){
                result.numbers[k] += numbers[flag ? i : j] + x.numbers[flag ? j : i];
                if (result.numbers[k] >= 10){
                    result.numbers[k - 1] += 1;
                    result.numbers[k] = result.numbers[k] - 10;
                }
                i--;
                j--;
                k--;
            }

            while (i >= 0 && k >= 0){
                result.numbers[k] += flag ? numbers[i] : x.numbers[i];
                if (result.numbers[k] >= 10){
                    result.numbers[k - 1] += 1;
                    result.numbers[k] = result.numbers[k] - 10;
                }
                i--;
                j--;
                k--;
            }
            if (result.numbers[0] == 0){
                int *copy = new int [result.length - 1];
                for (int i = 0; i < result.length - 1; i++){
                    copy[i] = result.numbers[1 + i];
                }
                delete[] result.numbers;
                result.numbers = new int[result.length - 1];
                for (int i = 0; i < result.length - 1; i++){
                    result.numbers[i] = copy[i];
                }
                result.length -= 1;
                delete [] copy;
            }
        }
        else{
            result.length = fmax(length, x.length);
            result.numbers = new int[result.length];
            bool flag = true;
            if(abs(*this) < abs(x)){
                flag = false;
            }

            int i = flag ? length - 1 : x.length - 1;
            int j = flag ? x.length -1 : length - 1;
            int k = result.length - 1;

            for (int q = 0; q < result.length; q++){
                result.numbers[q] = 0;
            }

            while(k >= 0){

                if(i < 0){
                    flag ? numbers[i] = 0 : x.numbers[i] = 0;
                }else if(j < 0){
                    flag ? x.numbers[j] = 0 : numbers[j] = 0;
                }
                result.numbers[k] += flag ? numbers[i] - x.numbers[j] : x.numbers[i] - numbers[j];
                if(result.numbers[k] < 0){
                    result.numbers[k] += 10;
                    result.numbers[k - 1] -= 1;
                }
                --i;
                --j;
                --k;
            }

            result.sign = flag ? sign : x.sign;

            if (result.numbers[0] == 0){
                int *copy = new int [result.length - 1];
                for (int i = 0; i < result.length - 1; i++){
                    copy[i] = result.numbers[1 + i];
                }
                delete[] result.numbers;
                result.numbers = new int[result.length - 1];
                for (int i = 0; i < result.length - 1; i++){
                    result.numbers[i] = copy[i];
                }
                result.length -= 1;
                delete [] copy;
            }
        }
        return result;
    }

    LongNumber LongNumber::operator - (const LongNumber& x) const{
        LongNumber result;
        int size = fmax(length, x.length);
        int *buffer = new int[size];
        int index_max = fmax(length - 1, x.length - 1);
        int index_min = fmin(length - 1, x.length - 1);
        if (abs(*this) > (x)){
            result.sign = POSITIVE;
            for (int i = size - 1; i >= 0; i--){
                buffer[i] = numbers[i] - (index_min >= 0 ? x.numbers[index_min] : 0);
                index_min--;
            }
        } else{
            result.sign = NEGATIVE;
            for (int i = size - 1; i >= 0; i--){
                buffer[i] = x.numbers[i] - (index_min >= 0 ? numbers[index_min] : 0);
                index_min--;
            }
        }
        for(int i = size - 1; i >= 0; i--){
            if (buffer[i] < 0){
                buffer[i - 1] -= 1;
                buffer[i] += 10;
            }
        }
        if (buffer[0] == 0 && size != 1){
            result.numbers = new int[size - 1];
            result.length = size - 1;
            for(int i = 1; i < size; i++){
                result.numbers[i - 1] = buffer[i];
            }
            if (result.numbers[0] == 0){
                delete[] result.numbers;
                result.numbers = new int[size - 2];
                result.length = size - 2;
                for(int i = 2; i < size; i++){
                    result.numbers[i - 2] = buffer[i];
                }
            }
            return result;
        }else{
            result.numbers = new int[size];
            result.length = size;
            for(int i = 0; i < size; i++){
                result.numbers[i] = buffer[i];
            }
            return result;
        }
    }

    LongNumber LongNumber::abs(const LongNumber& x) const{
        LongNumber result = x;
        result.sign = POSITIVE;
        return result;
    }

    LongNumber LongNumber::operator * (const LongNumber& x) const{
        LongNumber result;
        bool flag = abs(*this) > abs(x);
        int maxLength = fmax(length, x.length);
        int minLength = fmin(length, x.length);
        LongNumber *a = new LongNumber[minLength];
        for (int i = minLength - 1; i >= 0; i--){
            a[i].numbers = new int[maxLength + minLength - 1 - i + 1];
            a[i].length = maxLength + minLength - 1 - i + 1;
            for (int j = 0; j < maxLength + minLength - 1 - i + 1; j++){
                a[i].numbers[j] = 0;
            }
        }
        for (int i = minLength - 1; i >= 0; --i){
            for (int j = maxLength - 1; j>= 0; --j) {
                a[i].numbers[j + 1] += flag ? numbers[j] * x.numbers[i] : x.numbers[j] * numbers[i];
                int rad = a[i].numbers[j + 1];
                if (rad >= 10){
                    a[i].numbers[j] += rad / 10;
                    a[i].numbers[j + 1] = rad % 10;
                }
            }
            result = result + a[i];
        }
        if (sign != x.sign){
            result.sign = NEGATIVE;
        } else{
            result.sign = POSITIVE;
        }
        if (result.numbers[0] == 0){
            int *copy = new int[result.length - 1];
            for (int i = 0; i < result.length - 1; i++){
                copy[i] = result.numbers[i + 1];
            }
            delete[] result.numbers;
            result.numbers = new int[result.length - 1];
            for (int i = 0; i < result.length - 1; i++){
                result.numbers[i] = copy[i];
            }
            delete[] copy;
            result.length -= 1;
        }
        return result;
    }

    LongNumber LongNumber::operator / (const LongNumber& x) const{
        LongNumber result = "-1";
        LongNumber k = *this;
        LongNumber adin = "1";
        LongNumber abs_x = abs(x);
        LongNumber abs_k = abs(k);
        while (abs_k>"0") {
            abs_k = abs_k - abs_x;
            result = result + adin;
        }
        if (abs_k + abs_x == abs_x){
            result = result + "1";
        }
        result.sign = sign == x.sign ? POSITIVE : NEGATIVE;
        return result;
    }



    LongNumber LongNumber::operator % (const LongNumber& x) const{
        LongNumber result;

        result = *this - (*this/x)*x;
        return result;
    }

    int LongNumber::get_digits_number() const {
        return length;
    }

    bool LongNumber::is_positive() const {
        if (sign == POSITIVE){
            return true;
        } else{
            return false;
        }
    }

    int LongNumber::get_length(const char* const str) const {
        int length = 0;
        if (str[0] == MINUS) {
            length = -1;
        } else{
            length = 0;
        }
        int i = 0;
        while (str[i] != END){
            i++;
            length++;
        }
        return length;
    }
    std::ostream& operator << (std::ostream &os, const LongNumber& x) {
        if (!x.is_positive()){
            os << '-';
        }
        for (int i = 0; i < x.length; i++){
            os << x.numbers[i];
        }
        return os;
    }
}
