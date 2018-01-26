    #include <stdio.h>  
      
    int main()  
    {  
            printf("in linux ...\n");  
            int l_char=sizeof(char);  
            printf("char ----> %d\n",l_char);  
            int l_int=sizeof(int);  
            printf("int ----> %d\n",l_int);  
            int l_short=sizeof(short);  
            printf("short ----> %d\n",l_short);  
            int l_long=sizeof(long);  
            printf("long ----> %d\n",l_long);
            int l_long_long_int=sizeof(long long int);
            printf("long long int----> %d\n",l_long_long_int);
            int l_long_long=sizeof(long long);
            printf("long long ----> %d\n",l_long_long);
            int l_float=sizeof(float);  
            printf("float ----> %d\n",l_float);  
            int l_double=sizeof(double);  
            printf("double ----> %d\n",l_double);  
            int l_ldouble=sizeof(long double);  
            printf("long double ----> %d\n",l_ldouble);  
            return 0;  
    }  
