double sqrt(double);            // Declaration

class Vector {
public:
    Vector(int s);              // Declaration of constructor
    double& operator[](int i);  // Declaration of subscript operator
    int size();                 // Declaration of size function
private:
    double* elem;
    int sz;
};

double sqrt(double d)
{
    // ..algorithm as found in math textbook..
}

Vector::Vector(int s) : elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i) // definition of subscript operator
{
    return elem[i];
}

int Vector::size()  // definition of size member function
{
    return sz;
}
