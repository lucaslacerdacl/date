# Date
> Project created to improve acknowledgment in object oriented programming.

The objective of this project is to create the Date class inherited from the DateInterface class provided by the documentation in the topic 2.2 in the file "POO - TP2.pdf".

### Contributors

* Lucas Leandro Costa Lacerda
* Hebert do Nascimento Amaral Costa

## Getting started

To use the Date class instantiate with the format and date as show the following code.

```c
string format = "dd/mm/aaaa";
string date = "28/02/2017";
    
Date date1(format, date);
```

The Date class receive the following kind of formats.

 - "dd/mm/aaaa"
 - "dd-mm-aaaa"
 - "mm/dd/aaaa"
 - "mm-dd-aaaa"
 - "aaaa/mm/dd"
 - "aaaa-mm-dd"

This Date class contains the following methods.

```c
// return the date
string getDate();

// return the date with a new format
string getDateWithTheNewFormat(string format);

// return the date in full
string getDateInFull();

// return the year, month or day
string getYear();
string getMonth();
string getDay();

// compare the current date with new one
bool operator=(Date date2);

// sum years, months or days
string sumYear(int days);
string sumMonth(int months);
string sumDay(int days);

// subtract years, months or days
string subtractYear(int days);
string subtractMonth(int months);
string subtractDay(int days);

// difference between dates
int differenceBetweenDates(Date date);
```

#### Exceptions
```c
// Format other than specification 
Exception::undefinedDateFormat
// Non existent day
Exception::undefinedDay
// Non existent month
Exception::undefinedMonth
// Non existent year
Exception::undefinedYear
// February 29 in non-leap year
Exception::leapYear
// Invalid values from year, month and/or day
Exception::invalidDate
// Invalid values from yeary
Exception::invalidYear
// Invalid values from month
Exception::invalidMonth
// Invalid values from day
Exception::invalidDay
```

## Developing

### Built With
 - iostream
 - vector
 - exception

## Style guide

 - The Data class receives the date and performs all functions on the current day, month, and year provided.
 - When the interface should add a month on January 31 or remove a month on March 31, the program adds 3 days when the year is not leap year and 2 days when the year is leap year (PHP works the same way).

### Setting up Example

To run the example file, use the code bellow:

```shell
git clone https://github.com/LucasLacerdaCL/date.git
cd date/src
g++ main.cpp -o main
./main
```

## Licensing

Released under the MIT license.