#include <iostream>
#include <stdexcept>

using namespace std;

class Course{
private:
    int* data;
    size_t capacity, size;
public:
    Course();
    ~Course();
    Course(const Course& p);

    void rellocate();

    void pop_back();
    void push_back(const int);

    size_t get_size() const;
    size_t get_capacity() const;

    int count(const int);
    Course& insert(const int a, const size_t& index);
    void erase(const size_t& index);

    friend istream& operator>>(istream&, Course&);
    friend ostream& operator<<(ostream&, const Course&);
   
    Course& operator=(const Course& other);
    int& operator[](int a);

    Course& operator*=(const Course& vec);
    Course& operator*=(const int& a);
    Course& operator/=(const Course& vec);
    Course& operator/=(const int& a);

    Course& operator+=(const Course& vec);
    Course& operator+=(const int& a);
    Course& operator-=(const Course& vec);
    Course& operator-=(const int& a);

    friend Course operator+(const int& a, const Course& vec);
    friend Course operator-(const int& a, const Course& vec);
    friend Course operator*(const int& a, const Course& vec);
    friend Course operator/(const int& a, const Course& vec);

    Course operator*(const int& a) const;
    Course operator*(const Course& vec) const;
    Course operator/(const int& a) const;
    Course operator/(const Course& vec) const;

    Course operator+(const int& a) const;
    Course operator+(const Course& vec) const;
    Course operator-(const int& a) const;
    Course operator-(const Course& vec) const;

};

istream& operator>>(istream& input, Course& a) {
    int n;
    input >> n;
    a.capacity = n; a.size = n;
    delete[] a.data;
    a.data = new int[a.capacity];
    for (size_t i = 0; i < a.size; ++i) {
        input >> a.data[i];
    }
    return input;
}
ostream& operator<<(ostream& output, const Course& a) {
    for (size_t i = 0; i < a.size; ++i) {
        output << a.data[i] << " ";
    }
    return output;
}
int& Course::operator[](int a) {
    if (a < 0 || a >= this->size) {
        throw out_of_range("[ERROR] Index out of bounds");
    }
    else {
        return this->data[a];
    }
}
Course::Course(const Course& p) {
    capacity = p.capacity;
    size = p.size;
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = p.data[i];
}
Course& Course::operator=(const Course& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = other.data[i];
    return *this;
}
Course::Course() {
    capacity = 0; size = 0;
    data = nullptr;
}
Course::~Course() {
    delete[] data;
}


Course& Course::operator*=(const int& a) {
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] *= a;
    }
    return *this;
}
Course& Course::operator*=(const Course& vec) {
    if (this->size != vec.size) {
        throw out_of_range("[ERROR] Array sizes do not match");
    }
    for (size_t i = 0; i < vec.size; ++i) {
        this->data[i] *= vec.data[i];
    }
    return *this;
}
Course& Course::operator/=(const int& a) {
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] /= a;
    }
    return *this;
}
Course& Course::operator/=(const Course& vec) {
    if (this->size != vec.size) {
        throw out_of_range("[ERROR] Array sizes do not match");
    }
    for (size_t i = 0; i < vec.size; ++i) {
        this->data[i] /= vec.data[i];
    }
    return *this;
}
Course& Course::operator+=(const int& a) {
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] += a;
    }
    return *this;
}
Course& Course::operator+=(const Course& vec) {
    if (this->size != vec.size) {
        throw out_of_range("[ERROR] Array sizes do not match");
    }
    for (size_t i = 0; i < vec.size; ++i) {
        this->data[i] += vec.data[i];
    }
    return *this;
}
Course& Course::operator-=(const int& a) {
    for (size_t i = 0; i < this->size; ++i) {
        this->data[i] -= a;
    }
    return *this;
}
Course& Course::operator-=(const Course& vec) {
    if (this->size != vec.size) {
        throw out_of_range("[ERROR] Array sizes do not match");
    }
    for (size_t i = 0; i < vec.size; ++i) {
        this->data[i] -= vec.data[i];
    }
    return *this;
}

Course operator*(const int& k, const Course& vec) {
    Course c = vec;
    c *= k;
    return c;
}
Course operator+(const int& k, const Course& vec) {
    Course c = vec;
    c += k;
    return c;
}
Course operator/(const int& k, const Course& vec) {
    Course new_vec;
    new_vec = vec;
    for (size_t i = 0; i < vec.size; ++i) {
        vec.data[i] = vec.data[i] / k;
    }
    return new_vec;
}
Course operator-(const int& k, const Course& vec) {
    Course new_vec;
    new_vec = vec;
    for (size_t i = 0; i < vec.size; ++i) {
        vec.data[i] = vec.data[i] - k;
    }
    return new_vec;
}

Course Course::operator*(const Course& vec) const {
    Course new_vec;
    new_vec = *this;
    new_vec *= vec;
    return new_vec;
}
Course Course::operator*(const int& a) const {
    Course new_vec;
    new_vec = *this;
    new_vec *= a;
    return new_vec;
}
Course Course::operator+(const int& a) const {
    Course new_vec;
    new_vec = *this;
    new_vec += a;
    return new_vec;
}
Course Course::operator+(const Course& vec) const {
    Course new_vec;
    new_vec = *this;
    new_vec += vec;
    return new_vec;
}
Course Course::operator/(const int& a) const {
    Course new_vec;
    new_vec = *this;
    new_vec /= a;
    return new_vec;
}
Course Course::operator/(const Course& vec) const {
    Course new_vec;
    new_vec = *this;
    new_vec /= vec;
    return new_vec;
}
Course Course::operator-(const int& a) const {
    Course new_vec;
    new_vec = *this;
    new_vec -= a;
    return new_vec;
}
Course Course::operator-(const Course& vec) const{
    Course new_vec;
    new_vec = *this;
    new_vec -= vec;
    return new_vec;
}

void Course::rellocate() {
    size_t new_cap;
    if (capacity == 0) new_cap = 1;
    else new_cap = capacity * 2;
    int* new_data = new int[new_cap];
    if (data != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
    }
    data = new_data;
    capacity = new_cap;
}

void Course::pop_back() {
    if (size <= 0) size = 0;
    --size;
    int* dat = new int[size];
    for (size_t i = 0; i < size; ++i) {
        dat[i] = data[i];
    }
    delete[] data;
    data = dat;
}
void Course::push_back(const int a) {
    if (size >= capacity) {
        rellocate();
    }
    data[size] = a;
    ++size;
}

int Course::count(const int a) {
    int cnt = 0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == a) ++cnt;
    }
    if (cnt == 0) return -1;
    else return cnt;
}

Course& Course::insert(const int a, const size_t& ind) {
    if (ind > size) {
        throw out_of_range("[ERROR] Index exceeds size");
    }
    if (size >= capacity) rellocate();

    for (size_t i = size; i > ind; i--) {
        data[i] = data[i - 1];
    }
    data[ind] = a;
    ++size;
    return *this;
}
void Course::erase(const size_t& ind) {
    if (ind > size) {
        throw out_of_range("[ERROR] Index exceeds size");
    }
    for (size_t i = ind; i < size-1; ++i) {
        data[i] = data[i+1];
    }
    size--;
}

size_t Course::get_size() const {
    return size;
}
size_t Course::get_capacity() const {
    return capacity;
}
