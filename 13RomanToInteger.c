#include <stdio.h>

int romanToInt(char* s)
{
    int n = 0;
    int i = 0;

    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case 'M': n += 1000; break;
            case 'D': n += 500; break;
            case 'C': 
                n += 100;
                if(s[i + 1] == 'M'){n += 800; i++;}
                else if(s[i + 1] == 'D'){n += 300; i++;}
                break;
            case 'L': n += 50; break;
            case 'X': 
                n += 10;
                if(s[i + 1] == 'C'){n += 80; i++;}
                else if(s[i + 1] == 'L'){n += 30; i++;}
                break;
            case 'V': n += 5; break;
            case 'I': 
                n += 1;
                if(s[i + 1] == 'X'){n += 8; i++;}
                else if(s[i + 1] == 'V'){n += 3; i++;}
                break;
        }

        i++;
    }

    return n;
}

int main()
{
    printf("%d\n", romanToInt("MCMXCV"));
    printf("%d\n", romanToInt("MMMCMXCIX"));
    printf("%d\n", romanToInt("XV"));
    printf("%d\n", romanToInt("I"));
    printf("%d\n", romanToInt("XIII"));

    return 0;
}