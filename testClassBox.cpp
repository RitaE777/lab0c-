

#include "Box.h"
#include "cassert"


void static testClassBox(){

    classBox::Box firstBox(3,3,3,1,0);
    classBox::Box secondBox(5, 5, 5, 2, 100);
    classBox::Box thirdBox(10, 10, 10, 4, 200);
    classBox::Box fourthBox(5,5,3,1,400);
    classBox::Box fifthBox(3,3,3,1,0);

    classBox::Box arrayForFifthTask[]{firstBox, secondBox, thirdBox, fourthBox};
    classBox::Box arrayBoxes[]{firstBox, secondBox, thirdBox};

    /*tests function class Box*/
    std::cout << "Test function(class Box):\n";
    assert(300 == classBox::sumBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0])));
    std::cout << "sumBox: ok\n";

    assert(true == classBox::checkBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 80));
    std::cout << "checkBox: ok(true)\n";
    assert(false == classBox::checkBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 53));
    std::cout << "checkBox: ok(false)\n";

    assert(3 == classBox::maxWeight(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 125));
    std::cout << "maxWeight: ok\n";
    assert(0 == classBox::maxWeight(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 10));
    std::cout << "maxWeight: ok\n";

    assert(true == classBox::checkPacked(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0])));
    std::cout << "checkPacked: ok(true)\n";
    assert(false == classBox::checkPacked(arrayForFifthTask, sizeof(arrayForFifthTask) / sizeof(arrayForFifthTask[0])));
    std::cout << "checkPacked: ok(false)\n";

    assert(true == (firstBox != secondBox));
    std::cout << "Operator '!=' : ok(true)\n";
    assert(true == (firstBox == fifthBox));
    std::cout << "Operator '==' : ok(true)\n";

    std::cout << "Test operator '>>'\nEnter box:\n";
    classBox::Box enteredBox(1,1,1,1,1);
    std::cin >> enteredBox;

    std::cout <<"Test operator '<<'\nthe box you entered:\n";
    std::cout << enteredBox;

    std::cout << "TestClassBox.cpp passed the tests\n\n";


}
