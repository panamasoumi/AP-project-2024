#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay, currentHour, currentMinute, currentSecond;

    time_t t = time(0);
    tm* now = localtime(&t);

    currentYear = now->tm_year + 1900;
    currentMonth = now->tm_mon + 1;
    currentDay = now->tm_mday;
    currentHour = now->tm_hour;
    currentMinute = now->tm_min;
    currentSecond = now->tm_sec;

    cout << "Please enter your birth year: ";
    cin >> birthYear;
    cout << "Please enter your birth month: ";
    cin >> birthMonth;
    cout << "Please enter your birth day: ";
    cin >> birthDay;

    // Calculate age
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--; // هنوز تولد نشده است
    }

    // Calculate time passed since birth
    int passedYears = currentYear - birthYear;
    int passedMonths = currentMonth - birthMonth;
    int passedDays = currentDay - birthDay;
    int passedHours = currentHour;
    int passedMinutes = currentMinute;
    int passedSeconds = currentSecond;

    if (passedDays < 0) {
        passedMonths--;
        passedDays += 30; // تقریبی برای ماه 30 روزه
    }

    if (passedMonths < 0) {
        passedYears--;
        passedMonths += 12; // 12 ماه در سال
    }

    cout << "Your age is: " << age << " years old." << endl;
    cout << "Time passed since your birth: " << passedYears << " years, " << passedMonths << " months, "
         << passedDays << " days, " << passedHours << " hours, " << passedMinutes << " minutes, " << passedSeconds
         << " seconds." << endl;

    return 0;
}
