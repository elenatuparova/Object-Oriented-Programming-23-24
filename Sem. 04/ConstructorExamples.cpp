#include<iostream>

struct A {
    A() {
        std::cout << "constr of A" << std::endl;
    }

    A(int y) {
        std::cout << "param constr of A" << std::endl;
    }

    ~A() {
        std::cout << "destr of A" << std::endl;
    }
};

struct B {
    int x;

    B() : x(0) {
        std::cout << "constr of B" << std::endl;
    }

    B(int y) : x(y) {
        std::cout << "param constr of B" << std::endl;
        //x = y;
    }

    ~B() {
        std::cout << "destr of B" << std::endl;
    }
};

struct C {
    A a;
    B b;
    int x;

    C() : b(1), a(2), x(3) {
        std::cout << "Constr of c" << std::endl;
    }

    ~C() {
        std::cout << "destr of C: " << x << std::endl;
    }
};

int main() {
    //A* ptr;
    //{
    //    A a;
    //    ptr = new A;
    //}

    //B b;
    //delete ptr;

    //std::cout << std::endl;

    C arr[3];
    for (size_t i = 0; i < 3; i++)
    {
        arr[i].x = i;
    }
}