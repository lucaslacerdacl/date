class Date : public DateInterface{
private:
    FormatDateInFull formatDate;
    string formatDateToReturn(char _format) {
        if(_format == yearFormat) {
            return to_string(year) + separator + to_string(month) + separator + to_string(day);
        } else if(_format == dayFormat) {
            return to_string(day) + separator + to_string(month) + separator + to_string(year);
        } else if(_format == monthFormat) {
            return to_string(month) + separator + to_string(day) + separator + to_string(year);
        } else {
            throw UndefinedDateFormat();
        }
    };
    void fixLeapYear() {
        if(!(year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) {
            if(month == 2 && day == 29) {
                month = 3;
                day = 1;
            }
        }
    };

public:
    Date(string _format, string _date) : DateInterface(_format, _date) {};
    
    string getDate() {
        fixLeapYear();
        string _date = formatDateToReturn(format[0]);
        return _date;
    };

    string getDateWithTheNewFormat(string _format) {
        fixLeapYear();
        string _date = formatDateToReturn(_format[0]);
        return _date;
    };

    string getDateInFull() {
        fixLeapYear();
        string dateInFull = formatDate.formatDayInFull(day) + " de " + formatDate.formatMonthInFull(month) + " de " + formatDate.formatYearInFull(year);
        return dateInFull;
    };

    string sumYear(int years) {
        year = year + years;
        return getDate();
    };

    string subtractYear(int years) {
        year = year - years;
        return getDate();
    };

    bool operator=(Date date) {
        if(date.getDay() == day && date.getMonth() == month && date.getYear() == year) {
            return true;
        } else {
            return false;
        }
    }

    ~Date(){};
};