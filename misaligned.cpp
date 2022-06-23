#include <iostream>
#include <assert.h>
#include <sstream>
#include <vector>
#include <iomanip>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

struct colorPairLineItem {
    colorPairLineItem(int index_, const std::string &majorColor_, const std::string &minorColor_)
    : index(index_), majorColor(majorColor_), minorColor(minorColor_)
    {

    }
    int index;
    std::string majorColor;
    std::string minorColor;
};

std::vector<colorPairLineItem> constructColorMap(const char *majorColor[], size_t majorColorSize, const char *minorColor[], size_t minorColorSize) {
    std::vector<colorPairLineItem> list;
    for(size_t i = 0; i < majorColorSize; i++) {
        for(size_t j = 0; j < minorColorSize; j++) {
            list.push_back(colorPairLineItem(i * 5 + j, majorColor[i], minorColor[i]));
        }
    }
    return list;
}

std::string colorPairToString(colorPairLineItem item) {
    std::stringstream colorPairItem;
    colorPairItem << item.index << " | " << item.majorColor << " | " << item.minorColor << "\n";
    return colorPairItem.str();
}

void printData(const std::string &data) {
    std::cout << data;
}

int main() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    auto list = constructColorMap(majorColor, 5, minorColor, 5);
    auto listItem = list.front();


    assert(listItem.index == 1);
    std::stringstream str;
    str << std::setw(2) << listItem.index
        << std::setw(6) << listItem.majorColor
        << std::setw(6) << listItem.minorColor
        << "\n";
    assert(colorPairToString(listItem) == str.str());

    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
