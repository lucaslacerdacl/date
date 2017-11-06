#include <iostream>
#include <vector>

using namespace std;

#include "./UndefinedDateFormat.h"
#include "./UndefinedDay.h"
#include "./UndefinedMonth.h"
#include "./UndefinedYear.h"
#include "./FormatDateInFull.h"
#include "./DateInterface.h"
#include "./Date.h"

int main() {
    string format = "dd/mm/aaaa";
    string date = "21/06/1996";
    
    Date dateClass(format, date);
    cout << dateClass.getDate() << endl;

    cout << dateClass.getDateWithTheNewFormat("dd/mm/aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("dd-mm-aaaa") << endl;

    cout << dateClass.getDateWithTheNewFormat("mm/dd/aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("mm-dd-aaaa") << endl;

    cout << dateClass.getDateWithTheNewFormat("aaaa/mm/dd") << endl;
    cout << dateClass.getDateWithTheNewFormat("aaaa-mm-dd") << endl;

    cout << dateClass.getDateInFull() << endl;

    cout << dateClass.sumYear(1) << endl;
    cout << dateClass.subtractYear(1) << endl;

    cout << dateClass.sumMonth(1) << endl;
    cout << dateClass.subtractMonth(3) << endl;

    cout << dateClass.operator=(dateClass) << endl;

    return 0;
}