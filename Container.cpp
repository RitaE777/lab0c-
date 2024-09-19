
#include <cassert>
#include "Container.h"

using namespace classBox;

class ContainerException {

private:

    std::string message;

public:

    ContainerException(std::string message) : message{message} {};

    std::string getMessage() const { return message; }
};



/*First task*/
classContainer::Container::Container(int length, int width, int height, double maxWeight, vector<Box> &boxes) {

    assert(length > 0);
    assert(width > 0);
    assert(height > 0);
    assert(maxWeight > 0);

    double checkWeight = 0;
    for(classBox::Box box: boxes){
        checkWeight += box.getWeight();

    }
    assert(maxWeight >= checkWeight);
    assert(&boxes != nullptr);
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight = maxWeight;
    this->containerBox = boxes;

}

/*second task*/
int classContainer::Container::addBox(Box &addBox) {

    assert(&addBox != nullptr);
    if (maxWeight >= sumMaxWeight() + addBox.getWeight()) {

        containerBox.push_back(addBox);

        return containerBox.size();

    } else {
        throw ContainerException{"maxWeight < weight all containerBox(addBox)"};
    }
}

/*second task*/
Box classContainer::Container::deleteBoxFromIndex(int index) {

    assert(index >= 0 ||index < containerBox.size());
    Box box = getBoxFromIndex(index-1);
    auto iter = containerBox.cbegin();
    containerBox.erase(iter + index - 1);
    return box;
}

/*third task*/
int classContainer::Container::quantityBox() {
    return containerBox.size() ;
}

/*fourth task*/
double classContainer::Container::sumMaxWeight() {

    double sumMaxWeight = 0;

    for (int i = 0; i < containerBox.size(); i++) {
        sumMaxWeight += Container::getBoxFromIndex(i).getWeight();
    }

    return sumMaxWeight;
}

/*fifth task*/
double classContainer::Container::sumValueBoxes() {

    double result = 0;
    for (int i = 0; i < containerBox.size(); i++) {
        result+= Container::getBoxFromIndex(i).getValue();
    }
    return result;
}

/*sixth task*/
Box classContainer::Container::getBoxFromIndex(int index) {

    assert(index >= 0 && index <= containerBox.size());

    return containerBox[index];
}

ostream& classContainer::operator<<(ostream &os, const Container &container) {

    os << "length: " << container.getLength() << " width: " << container.getWidth() << " height: " << container.getHeight()
       << " maxWeight: " << container.getMaxWeight() << " containerBox: ";

    for (const Box &box: container.getContainer()) {
        os << box;
    }

    return os;
}

std::istream& classContainer::operator>>(std::istream &in, Container &container) {

    int length = 0;
    int width = 0;
    int height = 0;
    double maxWeight = 0;
    int numBoxes = 0;

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
    while (maxWeight <= 0){
        cout << "Input maxWeight: " << endl;
        in >> maxWeight;
        if(maxWeight<=0){
            cerr << "Error maxWeight!" << endl;
        }
    }
    while(numBoxes <= 0){
        cout << "Input quantity boxes: " << endl;
        in >> numBoxes;
        if(numBoxes < 0){
            cerr << "Error numBoxes!";
        }
    }
    container.setLength(length);
    container.setWidth(width);
    container.setHeight(height);
    container.setMaxWeight(maxWeight);

    return in;
}

Box& classContainer::Container::operator[](int index) {

    assert(index > 0 && index < containerBox.size());

    return containerBox[index];
}

int classContainer::Container::getLength() const {
    return length;
}

void classContainer::Container::setLength(int length) {

    assert(length > 0);

    Container::length = length;
}

int classContainer::Container::getWidth() const {
    return width;
}

void classContainer::Container::setWidth(int width) {

    assert(width > 0);

    Container::width = width;
}

int classContainer::Container::getHeight() const {
    return height;
}

void classContainer::Container::setHeight(int height) {

    assert(height > 0);

    Container::height = height;
}

double classContainer::Container::getMaxWeight() const {
    return maxWeight;
}

void classContainer::Container::setMaxWeight(double maxWeight) {

    assert(maxWeight > 0);

    Container::maxWeight = maxWeight;
}
//delete
const vector<Box> &classContainer::Container::getContainer() const {
    return containerBox;
}

void classContainer::Container::setContainer(const vector<Box> &container) {
    assert(&container != nullptr);
    Container::containerBox = container;
}

bool classContainer::Container::operator==(const classContainer::Container &rhs) const {

    assert(&rhs != nullptr);
    return length == rhs.length &&
           width == rhs.width &&
           height == rhs.height &&
           maxWeight == rhs.maxWeight &&
           containerBox == rhs.containerBox;
}

bool classContainer::Container::operator!=(const classContainer::Container &rhs) const {
    return !(rhs == *this);
}




