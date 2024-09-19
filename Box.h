
#ifndef CLIONPROJECT_BOX_H
#define CLIONPROJECT_BOX_H

#include "iostream"
#include <cassert>

namespace classBox {

    class Box {

    private:

        int width;
        int height;
        int length;
        double weight;
        double value;
        Box();

    public:

        Box(int length, int width, int height, double weight, double value);

        bool operator==(const Box &rhs) const;

        bool operator!=(const Box &rhs) const;

        int getLength() const;

        void setLength(int length);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

        double getWeight() const;

        void setWeight(double weight);

        double getValue() const;

        void setValue(double value);



    };
    std::ostream &operator<<(std::ostream &os, const Box &box);

    std::istream &operator>>(std::istream &is, Box &box);

    double sumBox(Box *array, int size);

    bool checkBox(Box *array, int size, int sumCheck);

    double maxWeight(Box *array, int size,  double maxV);

    bool checkPacked(Box *array, int size);

}

namespace structBox {

    struct Box {

        int width;
        int height;
        int length;
        double weight;
        double value;

        Box(int length, int width, int height, double weight, double value);

        Box();

        bool operator==(const Box &rhs) const;

        bool operator!=(const Box &rhs) const;


    };

    std::ostream &operator<<(std::ostream &os, const Box &box);

    std::istream &operator>>(std::istream &is, Box &box);

    double sumBox(Box * array, int size);

    bool checkBox(Box *array, int size, int sumCheck);

    double maxWeight(Box *array, int size, double maxV);

    bool checkPacked(Box *array, int size);

}
#endif //CLIONPROJECT_BOX_H
