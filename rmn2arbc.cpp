// Roman number to Arabic number conversion
// Copyright(c)-2006 by Abhishek Kumar. All rights reserved.

#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

class Roman_Arabic
{
 public:
  int roman_digit_value(int ch);
  int is_roman_digit(int ch);
  int roman2arabic(char* s);
  char* chrcat(char* s, int ch);
};

int Roman_Arabic::roman_digit_value(int ch)
{
    switch (ch) {
        case 'M':
            return (1000);
        case 'D':
            return (500);
        case 'C':
            return (100);
        case 'L':
            return (50);
        case 'X':
            return (10);
        case 'V':
            return (5);
        case 'I':
            return (1);
        default:
            return (0);
    }
}

int Roman_Arabic::is_roman_digit(int ch)
{
    return (roman_digit_value(ch));
}

int Roman_Arabic::roman2arabic(char* s)
{
    int arabic=0;
    int ch;
    int ch_val, prev_val=0;

    for (int i=0; (ch = toupper(s[i])) != '\0'; i++) {
        if (is_roman_digit(ch)) {
            ch_val = roman_digit_value(ch);
            if (prev_val && (ch_val > prev_val)) {
                // XIV
                //   ^
                // Subtract 'I', add 'V':
                arabic -= 2*prev_val;
            }
            // XIV
            //   ^
            // Add 'V':
            arabic += ch_val;
        } else {
            arabic = 0;
            break;
        }
        prev_val = roman_digit_value(ch);
    }

    return (arabic);
}

char* Roman_Arabic::chrcat(char* s, int ch)
{
    int len = strlen(s);

    s[len] = ch;
    s[len+1] = '\0';

    return (s);
}

int main()
{
    Roman_Arabic roman_to_arabic;
    char roman[20];

    ifstream in;
    ofstream out;
    out.open("output.txt");
    if(!out) out<<"Can not write in file!";
    in.open("input.txt");
    if(!in) out<<"File does not exist!";
    in.getline(roman,50);

    cin.width(sizeof(roman)-1);
    if(in)
     out<<roman_to_arabic.roman2arabic(roman);

    in.close();
    out.close();

    return 0;
}
