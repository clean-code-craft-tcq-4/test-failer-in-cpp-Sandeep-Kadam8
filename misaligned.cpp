#include <iostream>
#include <assert.h>
#include <sstream>
#include <vector>
#include <iomanip>

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
            list.push_back(colorPairLineItem(i * 5 + (j + 1), majorColor[i], minorColor[i]));
        }
    }
    return list;
}

std::string colorPairToString(colorPairLineItem item) {
    std::stringstream colorPairItem;
    colorPairItem << std::setw(2) << item.index << " | "
        << std::setw(6) << item.majorColor << " | "
        << std::setw(6) << item.minorColor << " | "
        << "\n";
    return colorPairItem.str();
}

void printData(const std::string &data) {
    std::cout << data;
}

int printColorMap(const std::vector<colorPairLineItem> &list) {
    int count = 0;
    for(const auto &item:list) {
        printData(colorPairToString(item));
        count++;
    }

   return count;
}

int main() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    auto list = constructColorMap(majorColor, 5, minorColor, 5);
    auto listItem = list.front();


    assert(listItem.index == 1);
    std::stringstream str;
    str << std::setw(2) << listItem.index << " | "
        << std::setw(6) << listItem.majorColor << " | "
        << std::setw(6) << listItem.minorColor << " | "
        << "\n";
    assert(colorPairToString(listItem) == str.str());

    int result = printColorMap(list);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
