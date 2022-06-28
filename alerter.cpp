#include <iostream>
#include <assert.h>
#include <functional>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok    
    if(celcius > 200) {
        return 500;
    }
    else {
        return 200;
    }
}

void alertInCelcius(float farenheit, std::function<int(float celcius)> networkAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5, networkAlertStub);
    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 1);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
