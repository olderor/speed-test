#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


int foo_vector(vector<int> v) {
    return 0;
}

int foo_int(int v) {
    return 0;
}

int foo_address_vector(vector<int> &v) {
    return 0;
}

int foo_address_int(int &v) {
    return 0;
}


int get_time_of_func(void(*f)(int), int parameter) {

    clock_t begin = clock();

    f(parameter);

    clock_t end = clock();

    return end - begin;
}


void test_vector(int test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_vector(v);
}

void test_int(int test_size) {

    for (int i = 0; i < test_size; ++i) {
        foo_int(i);
    }
}

void test_address_vector(int test_size) {

    vector<int> v(test_size);

    for (int i = 0; i < test_size; ++i) {
        v[i] = i;
    }

    foo_address_vector(v);
}

void test_address_int(int test_size) {

    for (int i = 0; i < test_size; ++i) {
        foo_address_int(i);
    }
}

int main() {

    int size = 1000000;

    int vector_time = get_time_of_func(test_vector, size);
    int int_time = get_time_of_func(test_int, size);

    int vector_address_time = get_time_of_func(test_address_vector, size);
    int int_address_time = get_time_of_func(test_address_int, size);

    cout << "vector test was elapsed within " << vector_time << " milliseconds." << endl;
    cout << "int test was elapsed within " << int_time << " milliseconds." << endl;
    cout << endl;
    cout << "vector address test was elapsed within " << vector_address_time << " milliseconds." << endl;
    cout << "int address test was elapsed within " << int_address_time << " milliseconds." << endl;

    cin >> size;

    return 0;
}
