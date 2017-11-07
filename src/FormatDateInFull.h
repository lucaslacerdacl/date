class FormatDateInFull {
public:
    string formatDayInFull(int day) {
        string dayInFull;
        switch (day) {
            case 1:
                dayInFull = "Primeiro";
                break;
            case 2:
                dayInFull = "Dois";
                break;
            case 3:
                dayInFull = "Três";
                break;
            case 4:
                dayInFull = "Quatro";
                break;
            case 5:
                dayInFull = "Cinco";
                break;
            case 6:
                dayInFull = "Seis";
                break;
            case 7:
                dayInFull = "Sete";
                break;
            case 8:
                dayInFull = "Oito";
                break;
            case 9:
                dayInFull = "Nove";
                break;
            case 10:
                dayInFull = "Dez";
                break;
            case 11:
                dayInFull = "Onze";
                break;
            case 12:
                dayInFull = "Doze";
                break;
            case 13:
                dayInFull = "Treze";
                break;
            case 14:
                dayInFull = "Quatorze";
                break;
            case 15:
                dayInFull = "Quinze";
                break;
            case 16:
                dayInFull = "Dezesseis";
                break;
            case 17:
                dayInFull = "Dezesete";
                break;
            case 18:
                dayInFull = "Dezoite";
                break;
            case 19:
                dayInFull = "Dezenove";
                break;
            case 20:
                dayInFull = "Vinte";
                break;
            case 21:
                dayInFull = "Vinte e um";
                break;
            case 22:
                dayInFull = "Vinte e dois";
                break;
            case 23:
                dayInFull = "Vinte e três";
                break;
            case 24:
                dayInFull = "Vinte e quatro";
                break;
            case 25:
                dayInFull = "Vinte e cinco";
                break;
            case 26:
                dayInFull = "Vinte e seis";
                break;
            case 27:
                dayInFull = "Vinte e sete";
                break;
            case 28:
                dayInFull = "Vinto e oito";
                break;
            case 29:
                dayInFull = "Vinte e nove";
                break;
            case 30:
                dayInFull = "Trinta";
                break;
            case 31:
                dayInFull = "Trinta e um";
                break;
            default:
                throw Exception::undefinedDay();
        }
        return dayInFull;
    };

    string formatMonthInFull(int month) {
        string monthInFull;
        switch (month) {
            case 1:
                monthInFull = "Janeiro";
                break;
            case 2:
                monthInFull = "Fevereiro";
                break;
            case 3:
                monthInFull = "Março";
                break;
            case 4:
                monthInFull = "Abril";
                break;
            case 5:
                monthInFull = "Maio";
                break;
            case 6:
                monthInFull = "Junho";
                break;
            case 7:
                monthInFull = "Julho";
                break;
            case 8:
                monthInFull = "Agosto";
                break;
            case 9:
                monthInFull = "Setembro";
                break;
            case 10:
                monthInFull = "Outubro";
                break;
            case 11:
                monthInFull = "Novembro";
                break;
            case 12:
                monthInFull = "Dezembro";
                break;
            default:
                throw Exception::undefinedMonth();
        }
        return monthInFull;
    };

    string formatYearInFull(int year) {
        string _year = to_string(year);
        string thousandInFull;
        switch (_year[0]) {
            case '0':
                thousandInFull = "";
                break;
            case '1':
                thousandInFull = "Mil";
                break;
            case '2':
                thousandInFull = "Dois mil";
                break;
            default:
                throw Exception::undefinedYear();
        }

        string hundredInFull;
        switch (_year[1]) {
            case '0':
                hundredInFull = "";
                break;
            case '1':
                hundredInFull = "Cento";
                break;
            case '2':
                hundredInFull = "Duzentos";
                break;
            case '3':
                hundredInFull = "Trezentos";
                break;
            case '4':
                hundredInFull = "Quatrocentos";
                break;
            case '5':
                hundredInFull = "Quinhentos";
                break;
            case '6':
                hundredInFull = "Seicentos";
                break;
            case '7':
                hundredInFull = "Setecentos";
                break;
            case '8':
                hundredInFull = "Oitocentos";
                break;
            case '9':
                hundredInFull = "Novecentos";
                break;
            default:
                throw Exception::undefinedYear();
        }
        
        string tensInFull;
        if(_year[2] == '1') {
            string lastTwoDigits;
            lastTwoDigits += _year[2];
            lastTwoDigits += _year[3];
            switch (stoi(lastTwoDigits)) {
                case 10:
                    tensInFull = "Dez";
                    break;
                case 11:
                    tensInFull = "Onze";
                    break;
                case 12:
                    tensInFull = "Doze";
                    break;
                case 13:
                    tensInFull = "Treze";
                    break;
                case 14:
                    tensInFull = "Quatorze";
                    break;
                case 15:
                    tensInFull = "Quinze";
                    break;
                case 16:
                    tensInFull = "Dezesseis";
                    break;
                case 17:
                    tensInFull = "Dezesete";
                    break;
                case 18:
                    tensInFull = "Dezoite";
                    break;
                case 19:
                    tensInFull = "Dezenove";
                    break;
                default:
                    throw Exception::undefinedYear();
            }     
            return thousandInFull + " " + hundredInFull + " e " + tensInFull;       
        } else {
            switch (_year[2]) {
                case '0':
                    tensInFull = "";
                    break; 
                case '2':
                    tensInFull = "Vinte";
                    break;
                case '3':
                    tensInFull = "Trinta";
                    break;
                case '4':
                    tensInFull = "Quarenta";
                    break;
                case '5':
                    tensInFull = "Cinquenta";
                    break;
                case '6':
                    tensInFull = "Sessenta";
                    break;
                case '7':
                    tensInFull = "Setenta";
                    break;
                case '8':
                    tensInFull = "Oitenta";
                    break;
                case '9':
                    tensInFull = "Noventa";
                    break;
                default:
                    throw Exception::undefinedYear();
            }

            string unitInFull;
            switch (_year[3]) {
                case '0':
                    unitInFull = "";
                    break; 
                case '1':
                    unitInFull = "Um";
                    break;
                case '2':
                    unitInFull = "Dois";
                    break;
                case '3':
                    unitInFull = "Três";
                    break;
                case '4':
                    unitInFull = "Quatro";
                    break;
                case '5':
                    unitInFull = "Cinco";
                    break;
                case '6':
                    unitInFull = "Seis";
                    break;
                case '7':
                    unitInFull = "Sete";
                    break;
                case '8':
                    unitInFull = "Oito";
                    break;
                case '9':
                    unitInFull = "Nove";
                    break;
                default:
                    throw Exception::undefinedYear();
            }
            
            if(tensInFull.size() == 0 && unitInFull.size() == 0) {
                return thousandInFull + " " + hundredInFull;
            } else {
                if(tensInFull.size() == 0) {
                    return thousandInFull + " " + hundredInFull + " e " + unitInFull;
                } else if(unitInFull.size() == 0) {
                    return thousandInFull + " " + hundredInFull + " e " + tensInFull;
                } else {
                    return thousandInFull + " " + hundredInFull + " e " + tensInFull + " e " + unitInFull;
                }
            }
        }
    };
};