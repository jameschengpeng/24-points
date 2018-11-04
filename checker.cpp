#include <iostream>
#include <vector>
using namespace std;

double calculate ( double a, double b, int operate )
{
    if ( operate == 1 )
    {
        return a+b;
    }
    else if ( operate == 2 )
    {
        return a-b;
    }
    else if ( operate == 3 )
    {
        return a*b;
    }
    else if ( operate == 4 )
    {
        return a/b;
    } else return 0;
}

bool test1 (double i, double j, double m, double n)
{
    int a = 1, b = 1, c = 1, d = 0;
    for ( a = 1; a <= 4 && d == 0; a++ )
    {
        int temp1 = calculate(i, j, a);
        for ( b = 1; b <= 4 && d == 0; b++ )
        {
            int temp2 = calculate(temp1, m, b);
            for ( c = 1; c <= 4 && d == 0; c++ )
            {
                int result = calculate(temp2, n, c);
                if ( result == 24 || result == -24 )
                {
                    d = 1;
                } else continue;
            }
        }
    }
    if ( d == 1 ) return true;
    else return false;
}

bool test2 (double i, double j, double m, double n)
{
    int a = 1, b = 1, c = 1, d = 0;
    for ( a = 1; a <= 4 && d == 0; a++ )
    {
        int temp1 = calculate(i, j, a);
        for ( b = 1; b <= 4 && d == 0; b++ )
        {
            int temp2 = calculate(n, m, b);
            for ( c = 1; c <= 4 && d == 0; c++ )
            {
                int result = calculate(temp1, temp2, c);
                if ( result == 24 || result == -24 )
                {
                    d = 1;
                } else continue;
            }
        }
    }
    if ( d == 1 ) return true;
    else return false;
}

bool test ( vector<double> vec )
{
    int d = 0;
    for ( int i = 0; i < 4 && d == 0; i++ )
    {
        for ( int j = i+1; j < i+4 && d == 0; j++ )
        {
            if (j-i == 1){
                bool result1 = test1(vec[i], vec[j], vec[i+2], vec[i+3]);
                bool result2 = test2(vec[i], vec[j], vec[i+2], vec[i+3]);
                bool result3 = test1(vec[i], vec[j], vec[i+3], vec[i+2]);
                bool result4 = test2(vec[i], vec[j], vec[i+3], vec[i+2]);
                if ( result1==true || result2==true || result3==true || result4==true ){
                    d = 1;
                }
            } else if (j-i == 2){
                bool result1 = test1(vec[i], vec[j], vec[i+1], vec[i+3]);
                bool result2 = test2(vec[i], vec[j], vec[i+1], vec[i+3]);
                bool result3 = test1(vec[i], vec[j], vec[i+3], vec[i+1]);
                bool result4 = test2(vec[i], vec[j], vec[i+3], vec[i+1]);
                if ( result1==true || result2==true || result3==true || result4==true ){
                    d = 1;
                }
            } else {
                bool result1 = test1(vec[i], vec[j], vec[i+1], vec[i+2]);
                bool result2 = test2(vec[i], vec[j], vec[i+1], vec[i+2]);
                bool result3 = test1(vec[i], vec[j], vec[i+2], vec[i+1]);
                bool result4 = test2(vec[i], vec[j], vec[i+2], vec[i+1]);
                if ( result1==true || result2==true || result3==true || result4==true ){
                    d = 1;
                }
            }
        }
    }
    if ( d == 1 ) return true;
    else return false;
}

int main()
{
    vector<double> vec;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    if ( test(vec) == true ){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}
