

#include "Box.h"
#include "cassert"


void static testStructBox(){

    structBox::Box firstBox(3,3,3,1,0);
    structBox::Box secondBox(5, 5, 5, 2, 100);
    structBox::Box thirdBox(10, 10, 10, 4, 200);
    structBox::Box fourthBox(5,5,3,1,400);
    structBox::Box fifthBox(3,3,3,1,0);

    structBox::Box arrayForFifthTask[]{firstBox, secondBox, thirdBox, fourthBox};
    structBox::Box arrayBoxes[]{firstBox, secondBox, thirdBox};

    /*tests function struct Box*/
    std::cout << "Test function(struct Box):\n";
    assert(300 == structBox::sumBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0])));
    std::cout << "sumBox: ok\n";

    assert(true == structBox::checkBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 80));
    std::cout << "checkBox: ok(true)\n";
    assert(false == structBox::checkBox(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 53));
    std::cout << "checkBox: ok(false)\n";

    assert(3 == structBox::maxWeight(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 125));
    std::cout << "maxWeight: ok\n";
    assert(0 == structBox::maxWeight(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0]), 10));
    std::cout << "maxWeight: ok\n";

    assert(true == structBox::checkPacked(arrayBoxes, sizeof(arrayBoxes) / sizeof(arrayBoxes[0])));
    std::cout << "checkPacked: ok(true)\n";
    assert(false == structBox::checkPacked(arrayForFifthTask, sizeof(arrayForFifthTask) / sizeof(arrayForFifthTask[0])));
    std::cout << "checkPacked: ok(false)\n";

    assert(true == (firstBox != secondBox));
    std::cout << "Operator '!=' : ok(true)\n";
    assert(true == (firstBox == fifthBox));
    std::cout << "Operator '==' : ok(true)\n";

    std::cout << "Test operator '>>'\nEnter box:\n";
    structBox::Box enteredBox(1,1,1,1,1);
    std::cin >> enteredBox;

    std::cout <<"Test operator '<<'\nthe box you entered:\n";
    std::cout << enteredBox;
    std::cout << "TestStructBox.cpp passed the tests!\n\n";
}