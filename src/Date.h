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
            throw Exception::undefinedDateFormat();
        }
    };
    
public:
    Date(string _format, string _date) : DateInterface(_format, _date) {};
    
    string getDate() {
        string _date = formatDateToReturn(format[0]);
        return _date;
    };

    string getDateWithTheNewFormat(string _format) {
        string _date = formatDateToReturn(_format[0]);
        return _date;
    };

    string getDateInFull() {
        string dateInFull = formatDate.formatDayInFull(day) + " de " + formatDate.formatMonthInFull(month) + " de " + formatDate.formatYearInFull(year);
        return dateInFull;
    };

    string sumYear(int years) {
        year += years;
        return getDate();
    };

    string subtractYear(int years) {
        year -= years;
        return getDate();
    };

    string sumMonth(int months) {
        month += months;
        while(month > 12) {
            year++;
            month -= 12;
        }
        return getDate();
    };

    string subtractMonth(int months) {
        month -= months;
        while(month < 1) {
            year--;
            month += 12;
        }
        return getDate();
    };

    string sumDay(int days) {
        int daysResult = day + days;
        if(month % 2 == 0) {
            if(month == 2) {
                if(!(year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) {
                    if(daysResult > 28) {
                        sumMonth(1);
                        sumDay(days - 28);
                    } else {
                        day += days;
                    }
                } else {
                    if(daysResult > 29) {
                        sumMonth(1);
                        sumDay(days - 29);
                    } else {
                        day += days;
                    }
                }
            } else if(month == 8) {
                if(daysResult > 31) {
                    sumMonth(1);
                    sumDay(days - 31);
                } else {
                    day += days;
                }
            } else {
                if(daysResult > 30) {
                    sumMonth(1);
                    sumDay(days - 30);
                } else {
                    day += days;
                }
            }
        } else {
            if(daysResult > 31) {
                sumMonth(1);
                sumDay(days - 31);
            } else {
                day += days;
            }
        }
        return getDate();
    };

    string subtractDay(int days) {
        int daysResult = day - days;
        if(month % 2 == 0) {
            if(month == 2) {
                if(!(year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) {
                    if(daysResult < 1) {
                        subtractMonth(1);
                        subtractDay(days - 29);
                    } else {
                        day -=days;
                    }
                } else {
                    if(daysResult < 1) {
                        subtractMonth(1);
                        subtractDay(days - 28);
                    } else {
                        day -=days;
                    }
                }
            } else if(month == 8) {
                if(daysResult < 1) {
                    subtractMonth(1);
                    subtractDay(days - 31);
                } else {
                    day -=days;
                }
            } else {
                if(daysResult < 1) {
                    subtractMonth(1);
                    subtractDay(days - 30);
                } else {
                    day -=days;
                }
            }
        } else {
            if(daysResult < 1) {
                subtractMonth(1);
                subtractDay(days - 31);
            } else {
                day -=days;
            }
        }
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