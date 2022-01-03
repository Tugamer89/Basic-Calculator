#include <iostream> 
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class calcs
{
public:
    float value;

    calcs()
    {
        value = 0;
    }

    calcs(float n)
    {
        value = n;
    }


    void plus(float n) { value += n; }
    void minus(float n) { value -= n; }
    void mult(float n) { value *= n; }
    void div(float n) { value /= n; }
    void pow_(float n) { value = pow(value, n); }
    void sqrt_() { value = sqrt(value); }
    void cos_() { value = cos(value); }
    void sin_() { value = sin(value); }
    void tan_() { value = tan(value); }
    void acos_() { value = acos(value); }
    void asin_() { value = asin(value); }
    void atan_() { value = atan(value); }
    void cbrt_() { value = cbrt(value); }
    void log_() { value = log(value); }
    void log2_() { value = log2(value); }
    void log10_() { value = log10(value); }
};


void help();
bool isOperator(char a);
float doCalculus(vector <float> numbers, vector <char> operators);

int main()
{
    system("title Tuga's calculator");

    while (true)
    {
        string full, numStr = string();
        vector <float> numbers;
        vector <char> operators;

        cout << "Type the calculus (h for help): ";
        cin >> full;

        if (full[0] == 'h')
        {
            help();
            system("cls");
            continue;
        }

        for (int i = 0; i < full.length(); i++)
        {
            if (isOperator(full[i]))
            {
                operators.push_back(full[i]);
                if (numStr != string()) numbers.push_back(stof(numStr));
                numStr = string();
            }


            else if (full[i] == 'P')
            {
                if (numStr != string())
                {
                    numbers.push_back(stof(numStr));
                    operators.push_back('*');
                    numStr = string();
                }

                numbers.push_back(3.1415926535);

                if (!isOperator(full[i + 1]) && full[i + 1] != char()) operators.push_back('*');
            }

            else if (full[i] == 'E')
            {
                if (numStr != string())
                {
                    numbers.push_back(stof(numStr));
                    operators.push_back('*');
                    numStr = string();
                }

                numbers.push_back(2.7182818284);

                if (!isOperator(full[i + 1]) && full[i + 1] != char()) operators.push_back('*');
            }


            else numStr += full[i];
        }
        
        if (numStr != string()) numbers.push_back(stof(numStr));

        cout << "Result: " << doCalculus(numbers, operators) << endl;

        system("pause");
        system("cls");
    }
    
    return 0;
}

bool isOperator(char a)
{
    string operatori = "+-*/^aqcstCSTliL";

    for (int i = 0; i < operatori.length(); i++)
    {
        if (a == operatori[i]) return 1;
    }

    return 0;
}

float doCalculus(vector <float> numbers, vector <char> operators)
{
    calcs tot (numbers[0]);

    for (int i = 0; i < operators.size(); i++)
    {
        float a = numbers[i + numbers.size() - operators.size()];

        if (operators[i] == '+') tot.plus(a);
        else if (operators[i] == '-') tot.minus(a);
        else if (operators[i] == '*') tot.mult(a);
        else if (operators[i] == '/') tot.div(a);
        else if (operators[i] == '^') tot.pow_(a);
        else if (operators[i] == 'q') tot.sqrt_();
        else if (operators[i] == 'Q') tot.cbrt_();
        else if (operators[i] == 'c') tot.cos_();
        else if (operators[i] == 's') tot.sin_();
        else if (operators[i] == 't') tot.tan_();
        else if (operators[i] == 'C') tot.acos_();
        else if (operators[i] == 'S') tot.asin_();
        else if (operators[i] == 'T') tot.atan_();
        else if (operators[i] == 'l') tot.log_();
        else if (operators[i] == 'i') tot.log2_();
        else if (operators[i] == 'L') tot.log10_();

        else
        {
            cout << "Invalid operator '" << operators[i] << "', replaced with '*'" << endl;
            tot.mult(a);
        }
    }

    return tot.value;
}

void help()
{
    system("cls");

    cout << "Help sheet"
        << "\nP : PI"
        << "\nE : Nepero number"
        << "\n+ : addition"
        << "\n- : subtraction"
        << "\n* : multiplication"
        << "\n/ : division"
        << "\n^ : exponentation"
        << "\nq : square root"
        << "\nQ : cubic root"
        << "\nc : cosine"
        << "\ns : sine"
        << "\nt : tangent"
        << "\nC : arccosine"
        << "\nS : arcsine"
        << "\nT : arctangent"
        << "\nl : natural logarithm (base e)"
        << "\ni : logarithm base 2"
        << "\nL : common logarithm (base 10)";

    cout << "\n" << endl;
    system("pause");
    return;
}
