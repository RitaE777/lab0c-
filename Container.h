
#ifndef CLIONPROJECT_CONTAINER_H
#define CLIONPROJECT_CONTAINER_H

#include <iostream>
#include <vector>
#include "Box.h"

using namespace std;
using namespace classBox;

namespace classContainer {

    class Container {

    private:

        int length;
        int width;
        int height;
        double maxWeight;
        vector<Box> containerBox;
        Container();

    public:


        Container(int length, int width, int height, double maxWeight, vector<Box> &boxes);

        int addBox(Box &addBox);

        Box deleteBoxFromIndex(int index);

        int quantityBox();

        double sumMaxWeight();

        double sumValueBoxes();

        Box getBoxFromIndex(int index);

        bool operator==(const Container &rhs) const;

        bool operator!=(const Container &rhs) const;

        Box &operator[](int index);

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getMaxWeight() const;

        void setMaxWeight(double maxWeight);

        void setContainer(const vector<Box> &container);

        const vector<Box> &getContainer() const;
    };

    istream &operator>>(istream &is, Container &container);

    ostream &operator<<(ostream &os, const Container &container);


}

#endif //CLIONPROJECT_CONTAINER_H
