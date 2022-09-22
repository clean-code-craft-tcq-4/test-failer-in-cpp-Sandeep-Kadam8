#include <iostream>
#include <assert.h>
#include <functional>
#include <vector>

bool isSmall(int cms, char &sizeName) {
    if(cms < 38) {
        sizeName = 'S';
        return true;
    }
    return false;
}

bool isMedium(int cms, char &sizeName) {
    if(cms >= 38 && cms < 42) {
        sizeName = 'M';
        return true;
    }
    return false;
}

bool isLarge(int cms, char &sizeName) {
    if(cms >= 42 && cms < 46) {
        sizeName = 'L';
        return true;
    }
    return false;
}

std::vector<std::function<bool(int, char &)>> sizeCheckList = {isSmall, isMedium, isLarge};

char size(int cms) {
    char sizeName = '\0';
    for(auto &itr: sizeCheckList) {
        if(itr(cms, sizeName)) {
            break;
        }
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(38) == 'M');
    assert(size(42) == 'L');
    assert(size(50) == '\0');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
