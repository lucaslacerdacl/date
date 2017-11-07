# Date
> Project created to improve acknowledgment in object oriented programming.

The objective of this project is to create the Date class inherited from the DateInterface class provided by the documentation in the topic 2.2 in the file "POO - TP2.pdf".

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
```

## Developing

### Built With
 - iostream
 - vector
 - exception

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