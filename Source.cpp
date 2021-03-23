#include <iostream>
#include <cmath>
#define N 3
#define T 4
using namespace std;

class triangle
{
private:

    int* M;
    double square;
  

public:
    triangle() {
        M = new int[N];
        M[0] = 0;
        M[1] = 0;
        M[2] = 0;
        square = 0;
      
    }

    triangle(int a, int b, int c)
    {
        M = new int[N];
        M[0] = a;
        M[1] = b;
        M[2] = c;
        square = 0;
      
    }
    triangle(const triangle& obj) //конструктор копіювання
    {
        M = new int[N];
        for (int i = 0; i < N; ++i)
            M[i] = obj.M[i];
        square = obj.square;
       
        //cout << "Викликався конструктор копіювання\n";
    }

    int SetSides(int* M)
    {
        for (int i = 0; i < N; ++i)
            M[i] = this->M[i];
    }

    int GetA() { return M[0]; }
    int GetB() { return M[1]; }
    int GetC() { return M[2]; }

    ~triangle()
    {
        delete[]M;
    }

    double Square(int a, int b, int c)
    {
        int p;
        double s;

        p = a + b + c;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
    double Square()
    {
        int p;
        double s;

        p = M[0] + M[1] + M[2];
        s = sqrt(p * (p - M[0]) * (p - M[1]) * (p - M[2]));
        return s;
    }


    triangle operator= (const triangle& tr)
    {
        delete[] M;
        M = new int[N];
        M[0] = tr.M[0];
        M[1] = tr.M[1];
        M[2] = tr.M[2];
        return *this;
    }

    bool operator>= (triangle& tr)
    {
        return this->Square() >= tr.Square();
    }

    friend istream& operator>>(istream& g, triangle& ob) //перегрузка введення
    {
        ob.M = new int[N];
        g >> ob.M[0];
        g >> ob.M[1];
        g >> ob.M[2];
        double p;
        p = (ob.M[0] + ob.M[1] + ob.M[2]) / 2;
        ob.square = sqrt(p * (p - ob.M[0]) * (p - ob.M[1]) * (p - ob.M[2]));
        return g;
    }

    friend ostream& operator<<(ostream& h, triangle& ob) // перегрузка виведення
    {
        h << ob.M[0] << " " << ob.M[1] << " " << ob.M[2] << "  Square : " << ob.Square(ob.M[0], ob.M[1], ob.M[2]);
        return h;
    }
};

triangle operator+ (triangle& tr, int n)
{
    int a = tr.GetA() + n;
    int b = tr.GetB() + n;
    int c = tr.GetC() + n;
    return triangle(a, b, c);
}

void Sort(triangle* arr)
{
    triangle change;
    for (int i = 0; i < T - 1; i++)
    {
        for (int n = 0; n < T - i - 1; n++)
        {
            if (arr[n + 1] >= arr[n])
            {
                change = arr[n];
                arr[n] = arr[n + 1];
                arr[n + 1] = change;
            }
        }
    }
}

void Print();
triangle* arr = new triangle[T]; //масив обєктів


int main()
{
    int numb;
    system("chcp 1251");
    cout << "U need to input 5 different triangles\n";
    cout << "Input large of sides : (space)\n";
    for (int i = 0; i < T; i++)
    {
        cin >> arr[i];
    }
    cout << "\nInputed array of triangles : \n";
    Print();
    Sort(arr);
    cout << "\nSorted array of triangles : \n";
    Print();
    cout << "\n Input number what u want to add to sides :";
    cin >> numb;
    arr[T - 1] = (arr[T - 1] + numb);
    /*Sort(arr);*/
    cout << "\n Changed array :\n";
    Print();
    return 0;
}

void Print()
{
    cout << "\n======================================\n";
    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "======================================\n";
}