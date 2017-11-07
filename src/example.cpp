void runExamples() {
    string format = "dd/mm/aaaa";
    string date = "21/01/2017";

    string differentFormat = "mm/dd/aaaa";
    string differentDate = "12/25/1800";
    
    Date dateClass(format, date);

    Date differenteDateClass(differentFormat, differentDate);

    cout << "\n1 - Is 21/01/2017(dd/mm/aaaa) equals 12/25/1800(mm/dd/aaaa)?\n" << endl;
    cout << dateClass.operator=(differenteDateClass) << endl;

    cout << "\n2 - Print the date\n" << endl;
    cout << dateClass.getDate() << endl;

    cout << "\n3 - Accepted formats\n" << endl;
    cout << dateClass.getDateWithTheNewFormat("dd/mm/aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("dd-mm-aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("mm/dd/aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("mm-dd-aaaa") << endl;
    cout << dateClass.getDateWithTheNewFormat("aaaa/mm/dd") << endl;
    cout << dateClass.getDateWithTheNewFormat("aaaa-mm-dd") << endl;

    cout << "\n4 - Print the date in full\n" << endl;
    cout << dateClass.getDateInFull() << endl;

    cout << "\n5 - Add one year and remove one year\n" << endl;
    cout << dateClass.sumYear(1) << endl;
    cout << dateClass.subtractYear(1) << endl;

    cout << "\n6 - Add months and remove months\n" << endl;
    cout << dateClass.sumMonth(10) << endl;
    cout << dateClass.sumMonth(2) << endl;
    cout << dateClass.sumMonth(11) << endl;
    cout << dateClass.sumMonth(12) << endl;
    cout << dateClass.sumMonth(15) << endl;
    cout << dateClass.subtractMonth(15) << endl;
    cout << dateClass.subtractMonth(12) << endl;
    cout << dateClass.subtractMonth(11) << endl;
    cout << dateClass.subtractMonth(2) << endl;
    cout << dateClass.subtractMonth(10) << endl;

    cout << "\n7 - Add days and remove days\n" << endl;
    cout << dateClass.sumDay(10) << endl;
    cout << dateClass.sumDay(11) << endl;
    cout << dateClass.sumDay(30) << endl;
    cout << dateClass.sumDay(60) << endl;
    cout << dateClass.sumDay(365) << endl;
    cout << dateClass.subtractDay(365) << endl;
    cout << dateClass.subtractDay(60) << endl;
    cout << dateClass.subtractDay(30) << endl;
    cout << dateClass.subtractDay(11) << endl;
    cout << dateClass.subtractDay(10) << endl;
}