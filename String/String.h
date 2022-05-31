#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

class String {
private:
    size_t ln = 0;
    size_t num_of_data = 0;
    char* str = nullptr;
    void growing_of_array_length() {
        if(ln >= num_of_data) {
            num_of_data = 2 * ln + 1;
            char* str2 = new char[num_of_data];
            memcpy(str2, str, ln);
            delete[] str;
            str = str2;
        }
    }

    String reverse() const {
        String temp_str = *this;
        for(size_t pos = 0; pos < ln; pos++) {
            temp_str[pos] = str[ln - 1 - pos];
        }
        return temp_str;
    }

    String(const char* arr_of_chr, size_t len):ln(len), num_of_data(len * 2 + 1), str(new char[2 * len + 1]) {
        memcpy(str, arr_of_chr, len);
    }

public:

    String(const String& Str): String(Str.str, Str.ln) {}

    String(size_t n, char chr): ln(n), num_of_data(2 * n + 1), str(new char[2*n + 1]) {
        memset(str, chr, n);
    }

    String(const char* arr_of_chr): ln(std::strlen(arr_of_chr)), num_of_data(2 * std::strlen(arr_of_chr) + 1),
    str(new char[2 * std::strlen(arr_of_chr) + 1]) {
        memcpy(str, arr_of_chr, ln);
    }

    String() = default;

    String& operator=(const String& str0);

    char& operator[](size_t pos) { return str[pos]; }

    const char& operator[](size_t pos) const { return str[pos]; }

    size_t length() const { return ln; }

    String& operator+=(char chr) { push_back(chr); return *this; }

    char& front() { return str[0]; }

    char front() const { return str[0]; }

    char back() const { return str[ln - 1]; }

    char& back() { return str[ln - 1]; }

    bool empty() const { return !static_cast<bool>(ln); }

    String& operator+=(const String& chr);

    bool operator==(const String& str0) const;

    String operator+(const String& c1);

    String operator+(char chr);

    void swap(String& str0);

    void push_back(const char chr);

    void pop_back();

    size_t rfind(const String& str2) const;

    size_t find(const String& str2) const;

    String substr(size_t start, size_t count) const;

    void  clear();

    ~String() { delete[] str; }

};

    bool String::operator==(const String& str0) const {
        if(ln != str0.ln)
            return false;
        for(size_t pos = 0; pos < ln; pos++) {
            if(str[pos] != str0.str[pos])
                return false;
        }
        return true;
    }

    String String::operator+(const String& c1) {
        String sum = *this;
        sum += c1;
        return sum;
    }

    String String::operator+(char chr) {
        String sum = *this;
        sum += chr;
        return sum;
    }

    void String::swap(String& str0) {
        std::swap(str, str0.str);
        std::swap(ln, str0.ln);
        std::swap(num_of_data, str0.num_of_data);
    }

    void String::push_back(const char chr) {
        growing_of_array_length();
        str[ln] = chr;
        ln++;
    }

    void String::pop_back() {
        ln--;
        if(ln <= num_of_data / 4) {
            num_of_data = (num_of_data / 2) + 1;
            char *str2 = new char[num_of_data];
            memcpy(str2, str, ln);
            delete[] str;
            str = str2;

        }
    }

    size_t String::rfind(const String& str2) const {
        return ln - str2.ln - reverse().find(str2.reverse());
    }

    size_t String::find(const String& str2) const {
        for(size_t pos = 0; pos < ln - str2.ln + 1; ++pos) {
            bool suits = true;
            for(size_t a_pos = 0; a_pos < str2.ln; ++a_pos) {
                if(str[pos + a_pos] != str2.str[a_pos]) {
                    suits = false;
                    break;
                }
            }
            if(suits) {
                return pos;
            }
        }
        return ln;
    }

    void String::clear() {
        ln = 0;
        num_of_data = 0;
    }

    String String::substr(size_t start, size_t count) const {
        String chr(count, 'a');
        for(size_t pos = start; pos < start + count; ++pos) {
            chr.str[pos - start] = str[pos];
        }
        return chr;
    }

    String& String::operator+=(const String& chr) {
        size_t prev_len = ln;
        ln += chr.ln;
        growing_of_array_length();

        for(size_t pos = prev_len; pos < ln; pos++) {
            str[pos] = chr.str[pos - prev_len];
        }

        return *this;
    }

    String& String::operator=(const String& str0) {
        String str1 = str0;
        swap(str1);
        return *this;
    }

    std::ostream& operator<<(std::ostream& cout, const String& str0) {
        for(size_t pos = 0; pos < str0.length(); ++pos) {
            cout << str0[pos];
        }
        return cout;
    }

    String operator+(char chr, const String& str0) {
        return String(1, chr) + str0;
    }

    std::istream& operator>>(std::istream& cin, String& str0) {
        str0.clear();
        char chr;
        while (cin.get(chr)) {
            if(std::isspace(chr)) return cin;
            str0.push_back(chr);
        }
        return cin;
    }

#endif
