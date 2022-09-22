#include <iostream>
#include <assert.h>
#include <cmath>
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

float convertFarenheitToCelcius(float farenheit) {
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, std::function<int(float celcius)> networkAlert) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount++;
    }
}

bool compareFloat(float x, float y, float epsilon = 0.01f){
   if(fabs(x - y) < epsilon) {
      return true;
   }
      return false;
}

void testConvertFarenheitToCelcius() {
    assert(compareFloat(convertFarenheitToCelcius(200), 93.3333));
}

void testAlertInCelciusWithoutFailure() {
    alertFailureCount = 0;
    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 0);
}

void testAlertInCelciusWithFailure() {
    alertFailureCount = 0;
    alertInCelcius(400.5, networkAlertStub);
    assert(alertFailureCount == 1);
    alertFailureCount = 0;
}

int main() {
    testConvertFarenheitToCelcius();
    testAlertInCelciusWithoutFailure();
    testAlertInCelciusWithFailure();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
