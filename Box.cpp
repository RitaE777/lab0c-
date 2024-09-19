

#include "Box.h"


#define NDEBUG

using namespace std;


/*first task, class Box*/
classBox::Box::Box(int length, int width, int height, double weight, double value) {

    assert(length > 0);
    assert(width > 0);
    assert(height > 0);
    assert(weight > 0);
    assert(value >= 0);

    this->length = length;
    this->width = width;
    this->height = height;
    this->weight = weight;
    this->value = value;
    cout << "object created" << endl;

}


/*second task, class Box*/
double classBox::sumBox(Box *array, int size) {
    assert(array != nullptr);
    assert(size >= 0);

    int result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i].getValue();
    }

    return result;
}

/*third task, class Box*/
bool classBox::checkBox(Box *array, int size, int sumCheck) {
    assert(array != nullptr);
    assert(size >= 0);

    int result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i].getLength() + array[i].getHeight() + array[i].getWidth();
    }

    return sumCheck >= result;
}

/*fourth task, class Box*/
double classBox::maxWeight(Box *array, int size, double maxV) {
    assert(array != nullptr);
    assert(size >= 0);
    assert(maxV > 0);

    double maxWeightResult = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].getHeight() * array[i].getWidth() * array[i].getLength() <= maxV)
            maxWeightResult += array[i].getWeight();
    }

    return maxWeightResult;
}

/*fifth task, class Box*/
bool classBox::checkPacked(Box *array, int size) {
    assert(array != nullptr);
    assert(size >= 0);

    for (int i = 0; i + 1 < size; i++) {
        for (int j = 0; j + 1 < size - i; j++) {
            if (array[j + 1].getLength() < array[j].getLength() &&
                array[j + 1].getHeight() < array[j].getHeight() &&
                array[j + 1].getWidth() < array[j].getWidth()) {
                swap(array[j], array[j + 1]);
            }
        }
    }

    for (int i = 0; i + 1 < size; i++) {
        if (!(array[i + 1].getLength() > array[i].getLength() &&
              array[i + 1].getHeight() > array[i].getHeight() &&
              array[i + 1].getWidth() > array[i].getWidth())) {
            return false;
        }
    }

    return true;
}

/*seventh task, class Box*/
ostream &classBox::operator<<(ostream &os, const Box &box) {
    os << "length: " << box.getLength() << "\nwidth: " << box.getWidth() << "\nheight: " << box.getHeight()
       << "\nweight: " << box.getWeight() << "\nvalue: " << box.getValue();
    return os;
}

/*seventh task, class Box*/
istream &classBox::operator>>(istream &in, Box &box) {

    int length = 0;
    int width = 0;
    int height = 0;
    int value = 0;
    double weight = 0;

    while (length <= 0) {
        cout << "Input length: " << endl;
        in >> length;
        if (length <= 0) {
            cerr << "Error length!" << endl;
        }
    }

    while (width <= 0) {
        cout << "Input width: " << endl;
        in >> width;
        if (width <= 0) {
            cerr << "Error width!" << endl;
        }
    }

    while (height <= 0) {
        cout << "Input height: " << endl;
        in >> height;
        if (height <= 0) {
            cerr << "Error height!" << endl;
        }
    }

    while (value <= 0) {
        cout << "Input value: " << endl;
        in >> value;
        if (value <= 0) {
            cerr << "Error value!" << endl;

        }
    }

    while (weight <= 0) {
        cout << "Input weight: " << endl;
        in >> weight;
        if (weight <= 0) {
            cerr << "Error weight!" << endl;
        }
    }

    box.setLength(length);
    box.setWidth(width);
    box.setHeight(height);
    box.setValue(value);
    box.setWeight(weight);

    return in;
}

/*getters and setters*/
int classBox::Box::getLength() const {
    return length;
}

void classBox::Box::setLength(int length) {
    assert(length > 0 &&  "length < 0");
    this->length = length;
}

int classBox::Box::getWidth() const {
    return width;
}

void classBox::Box::setWidth(int width) {
    assert(width > 0);
    this->width = width;
}

int classBox::Box::getHeight() const {
    return height;
}

void classBox::Box::setHeight(int height) {
    assert(height > 0 );
    this->height = height;
}

double classBox::Box::getWeight() const {
    return weight;
}

void classBox::Box::setWeight(double weight) {
    assert(weight > 0);
    this->weight = weight;
}

double classBox::Box::getValue() const {
    return value;
}

void classBox::Box::setValue(double value) {
    assert(value >= 0);
    this->value = value;
}

bool classBox::Box::operator==(const classBox::Box &rhs) const {
    assert(&rhs != nullptr);
    return width == rhs.width &&
           height == rhs.height &&
           length == rhs.length &&
           weight == rhs.weight &&
           value == rhs.value;
}

bool classBox::Box::operator!=(const classBox::Box &rhs) const {
    return !(rhs == *this);
}


/*first task, struct box*/

structBox::Box::Box(int length, int width, int height, double weight, double value) {

    assert(length > 0);
    assert(width > 0);
    assert(height > 0);
    assert(weight > 0);
    assert(value >= 0);

    this->length = length;
    this->width = width;
    this->height = height;
    this->weight = weight;
    this->value = value;

    cout << "object created" << endl;
}

bool structBox::Box::operator==(const structBox::Box &rhs) const {

    assert(&rhs != nullptr);

    return width == rhs.width &&
           height == rhs.height &&
           length == rhs.length &&
           weight == rhs.weight &&
           value == rhs.value;
}

bool structBox::Box::operator!=(const structBox::Box &rhs) const {
    return !(rhs == *this);
}

/*second task, struct box*/
double structBox::sumBox(Box array[], int size) {

    assert(array != nullptr);
    assert(size > 0);

    int result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i].value;
    }

    return result;
}

/*third task, struct box*/
bool structBox::checkBox(Box array[], int size, int sumCheck) {

    assert(array != nullptr);
    assert(size >= 0);
    assert(sumCheck >= 0);

    int result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i].length + array[i].height + array[i].width;
    }

    return sumCheck >= result;
}

/*fourth task, struct box*/
// найти макс коробку
double structBox::maxWeight(Box array[], int size, double maxV) {

    assert(array != nullptr);
    assert(size >= 0);
    assert(maxV >= 0);

    double maxWeightResult = 0;
    for (int i = 0; i < size; i++) {
        if (array[i].height * array[i].width * array[i].length <= maxV)
            maxWeightResult += array[i].weight;
    }
    return maxWeightResult;
}

/*task fifth, struct box*/
bool structBox::checkPacked(Box array[], int size) {

    assert(array != nullptr);
    assert(size >= 0);

    for (int i = 0; i + 1 < size; i++) {
        for (int j = 0; j + 1 < size - i; j++) {
            if (array[j + 1].length < array[j].length &&
                array[j + 1].height < array[j].height &&
                array[j + 1].width < array[j].width) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    for (int i = 0; i + 1 < size; i++) {
        if (!(array[i + 1].length > array[i].length &&
              array[i + 1].height > array[i].height &&
              array[i + 1].width > array[i].width)) {
            return false;
        }
    }
    return true;
}

/*seventh task, struct box*/
ostream& structBox::operator<<(ostream &os, const Box &box) {
    os << "length: " << box.length << "\nwidth: " << box.width << "\nheight: " << box.height
       << "\nweight: " << box.weight << "\nvalue: " << box.value << "\n";
    return os;
}

/*seventh task, struct box*/

istream& structBox::operator>>(istream &in, Box &box) {
    int length = 0;
    int width = 0;
    int height = 0;
    int value = 0;
    double weight = 0;

    while (length <= 0) {
        cout << "Input length: " << endl;
        in >> length;
        if (length <= 0) {
            cerr << "Error length!" << endl;
        }
    }

    while (width <= 0) {
        cout << "Input width: " << endl;
        in >> width;
        if (width <= 0) {
            cerr << "Error width!" << endl;
        }
    }

    while (height <= 0) {
        cout << "Input height: " << endl;
        in >> height;
        if (height <= 0) {
            cerr << "Error height!" << endl;
        }
    }

    while (value <= 0) {
        cout << "Input value: " << endl;
        in >> value;
        if (value <= 0) {
            cerr << "Error value!" << endl;

        }
    }

    while (weight <= 0) {
        cout << "Input weight: " << endl;
        in >> weight;
        if (weight <= 0) {
            cerr << "Error weight!" << endl;
        }
    }

    box.length = length;
    box.width = width;
    box.height = height;
    box.value = value;
    box.weight = weight;

    return in;
}
