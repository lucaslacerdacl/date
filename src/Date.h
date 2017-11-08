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
    void fixDifferentDaysInMonth() {
        int currentDay = day;
        if(getTheCurrentMonth() == LEAP_FEBRUARY) {
            if(day > 29) {
                day = 29;
                sumDay(currentDay - 29);
            }
        } else if(getTheCurrentMonth() == FEBRUARY) {
            if(day > 28) {
                day = 28;
                sumDay(currentDay - 28);
            }
        } else if(getTheCurrentMonth() == AUGUST) {
            if(day > 31) {
                day = 31;
                sumDay(currentDay - 31);
            }
        } else if(getTheCurrentMonth() == LESS_EXTENSIVE_MONTHS) {
            if(day > 30) {
                day = 30;
                sumDay(currentDay - 30);
            }
        } else if(getTheCurrentMonth() == MORE_EXTENSIVE_MONTHS) {
            if(day > 31) {
                day = 31;
                sumDay(currentDay - 31);
            }
        } else {
            throw Exception::invalidDate();
        }
    };
    void fixNegativeDays() {
        if(day < 0) {
            month--;
            if(getTheCurrentMonth() == LEAP_FEBRUARY) {
                day += 29;
            } else if(getTheCurrentMonth() == FEBRUARY) {
                day += 28;
            } else if(getTheCurrentMonth() == AUGUST) {
                day += 31;
            } else if(getTheCurrentMonth() == LESS_EXTENSIVE_MONTHS) {
                day += 30;
            } else if(getTheCurrentMonth() == MORE_EXTENSIVE_MONTHS) {
                day += 31;
            } else {
                throw Exception::invalidDate();
            }
        }
    };
    int convertYearToDays(int _year) {
        int totalYear = 0;
        while(_year > 0 ) {
            if((_year % 4 == 0 && _year % 100 != 0 ) || _year % 400 == 0) {
                totalYear += 366;
            } else {
                totalYear += 365;
            }
            _year--;
        }
        return totalYear;
    };
    int convertMonthToDays(int _month, int _year) {
        int totalMonth = 0;
        while(_month > 0) {
            if(_month % 2 == 0) {
                if(_month == 2) {
                    if((_year % 4 == 0 && _year % 100 != 0 ) || _year % 400 == 0) {
                        totalMonth += 29;
                    } else {
                        totalMonth += 28;
                    }
                } else if(_month == 8) {
                    totalMonth += 31;
                } else {
                    totalMonth += 30;
                }
            } else {
                totalMonth += 31;
            }
            _month--;
        }
        return totalMonth;
    };
    
public:
    Date(string _format, string _date) : DateInterface(_format, _date) {};
    
    string getDate() {
        checkDate();
        string _date = formatDateToReturn(format[0]);
        return _date;
    };

    string getDateWithTheNewFormat(string _format) {
        checkDate();
        string _date = formatDateToReturn(_format[0]);
        return _date;
    };

    string getDateInFull() {
        checkDate();
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
        fixDifferentDaysInMonth();
        return getDate();
    };

    string subtractMonth(int months) {
        month -= months;
        while(month < 1) {
            year--;
            month += 12;
        }
        fixDifferentDaysInMonth();
        return getDate();
    };

    string sumDay(int days) {
        int daysResult = day + days;
        if(getTheCurrentMonth() == LEAP_FEBRUARY) {
            if(daysResult > 29) {
                sumMonth(1);
                sumDay(days - 29);
            } else {
                day += days;
            }
        } else if(getTheCurrentMonth() == FEBRUARY) {
            if(daysResult > 28) {
                sumMonth(1);
                sumDay(days - 28);
            } else {
                day += days;
            }
        } else if(getTheCurrentMonth() == AUGUST) {
            if(daysResult > 31) {
                sumMonth(1);
                sumDay(days - 31);
            } else {
                day += days;
            }
        } else if(getTheCurrentMonth() == LESS_EXTENSIVE_MONTHS) {
            if(daysResult > 30) {
                sumMonth(1);
                sumDay(days - 30);
            } else {
                day += days;
            }
        } else if(getTheCurrentMonth() == MORE_EXTENSIVE_MONTHS) {
            if(daysResult > 31) {
                sumMonth(1);
                sumDay(days - 31);
            } else {
                day += days;
            }
        } else {
            throw Exception::invalidDate();
        }
        fixNegativeDays();
        return getDate();
    };

    string subtractDay(int days) {
        int daysResult = day - days;
        if(daysResult < 1) {
            subtractMonth(1);
            if(getTheCurrentMonth() == LEAP_FEBRUARY) {
                subtractDay(days - 29);
            } else if(getTheCurrentMonth() == FEBRUARY) {
                subtractDay(days - 28);
            } else if(getTheCurrentMonth() == AUGUST) {
                subtractDay(days - 31);
            } else if(getTheCurrentMonth() == LESS_EXTENSIVE_MONTHS) {
                subtractDay(days - 30);
            } else if(getTheCurrentMonth() == MORE_EXTENSIVE_MONTHS) {
                subtractDay(days - 31);
            } else {
                throw Exception::invalidDate();
            }
        } else {
            day -=days;
        }
        return getDate();
    };

    int differenceBetweenDates(Date date) {
        int date1 = convertYearToDays(date.getYear()) + convertMonthToDays(date.getMonth(), date.getYear()) + date.getDay();
        int date2 = convertYearToDays(year) + convertMonthToDays(month, year) + day;

        int result = date1 - date2;
        if(result < 0) {
            return result * (-1);
        } else {
            return result;
        }

    };

    bool operator=(Date date) {
        if(date.getDay() == day && date.getMonth() == month && date.getYear() == year) {
            return true;
        } else {
            return false;
        }
    };

    ~Date(){};
};