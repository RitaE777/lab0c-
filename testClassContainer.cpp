
#include <cassert>
#include "Container.h"

void static testClassContainer(){

    classBox::Box firstBox(3,3,3,1,0);
    classBox::Box secondBox(5, 5, 5, 2, 100);
    classBox::Box thirdBox(10, 10, 10, 4, 200);

    vector<Box> boxes{firstBox,secondBox,thirdBox};
    vector<Box> boxesForComparison{firstBox,secondBox,thirdBox,firstBox};

    classContainer::Container firstContainer(50, 50, 50, 100, boxes);
    classContainer::Container firstContainerForComparison(50,50,50,100,boxes);
    classContainer::Container secondContainerForComparison(50,50,50,100,boxesForComparison);

    assert(true == (firstContainerForComparison == firstContainer));

    std::cout << "\ntests functions class Container:\n";

    firstContainer.addBox(firstBox);
    assert(true == (secondContainerForComparison == firstContainer));
    std::cout << "addBox passed the test\n";
    assert(firstBox == firstContainer.deleteBoxFromIndex(4));
    assert(true ==(firstContainerForComparison == firstContainer));
    std::cout <<"deleteBoxFromIndex passed the test\n";

    assert(3 == firstContainer.quantityBox());
    std::cout << "quantity passed the test\n";

    assert(7 == firstContainer.sumMaxWeight());
    std::cout << "sumMaxWeight passed the test\n";

    assert(300 == firstContainer.sumValueBoxes());
    std::cout << "sumValueBoxes passed the test\n";

    assert(firstBox == firstContainer.getBoxFromIndex(0));
    std::cout << "getBoxFromIndex passed the test\n";

     std::cout << "test operator '>>'\nEnter container:\n";
     classContainer::Container enteredContainer(1,1,1,100,boxes);

     std::cin >> enteredContainer;

     std::cout << "test operator '<<'\nthe container you entered:\n";
     std::cout << enteredContainer;

    std::cout << "\nTestClassContainer.cpp passed the tests!\n";
}