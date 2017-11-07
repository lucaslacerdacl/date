class DateInterface {
protected:
    int day;
    int month;
    int year;
    string format;
    char separator;
    const static char dayFormat = 'd';
    const static char monthFormat = 'm';
    const static char yearFormat = 'a';
private:
    void checkDate() {
        if(!((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) && (month == 2 && day == 29)) {
            throw Exception::leapYear();
        }
        if(year < 0 || month < 0 || day < 0) {
            throw Exception::invalidDate();
        }
        if(year > 9999) {
            throw Exception::invalidYear();
        }
        if(month > 12) {
            throw Exception::invalidMonth();
        }
        if(day > 31) {
            throw Exception::invalidDay();
        }
    };
    void formatDateToParams(string _date, int postions[8]) {
        string tempDay, tempMonth, tempYear;
        tempYear.push_back(_date[postions[0]]);
        tempYear.push_back(_date[postions[1]]);
        tempYear.push_back(_date[postions[2]]);
        tempYear.push_back(_date[postions[3]]);
        tempMonth.push_back(_date[postions[4]]);
        tempMonth.push_back(_date[postions[5]]);
        tempDay.push_back(_date[postions[6]]);
        tempDay.push_back(_date[postions[7]]);
        year = stod(tempYear);
        month = stod(tempMonth);
        day = stod(tempDay);
        checkDate();
    };
public:
    DateInterface(string _format, string _date) {
        format = _format;
        if(_format[0] == yearFormat) {
            int positions[8] = {0,1,2,3,5,6,8,9};
            separator = _date[4];
            formatDateToParams(_date, positions);
        } else if(_format[0] == dayFormat) {
            int positions[8] = {6,7,8,9,3,4,0,1};
            separator = _date[2];
            formatDateToParams(_date, positions);
        } else if(_format[0] == monthFormat) {
            int positions[8] = {6,7,8,9,0,1,3,4};
            separator = _date[2];
            formatDateToParams(_date, positions);
        } else {
            throw Exception::undefinedDateFormat();
        }
    };

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }
    
    virtual string getDate() = 0;
    virtual string getDateWithTheNewFormat(string format) = 0;
    virtual string getDateInFull() = 0;
    virtual string sumYear(int days) = 0;
    virtual string subtractYear(int days) = 0;
    virtual string sumMonth(int months) = 0;
    virtual string subtractMonth(int months) = 0;
    virtual string sumDay(int days) = 0;
    virtual string subtractDay(int days) = 0;
    ~DateInterface() {};
};