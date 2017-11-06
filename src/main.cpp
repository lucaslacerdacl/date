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

    string differentFormat = "mm/dd/aaaa";
    string differentDate = "12/25/1800";
    
    Date dateClass(format, date);
    Date differenteDateClass(differentFormat, differentDate);

    cout << dateClass.operator=(differenteDateClass) << endl;

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

    return 0;
}