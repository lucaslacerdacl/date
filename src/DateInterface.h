class DataInterface
{
protected:
    int dia;
    int mes;
    int ano;
    string formato;
    char separador = '/';

public:
    DataInterface(string p_formato, string p_data) : formato(p_formato) {
        int i = 0;
        string sDia, sMes, sAno;
        while ((i < p_data.size()) && (p_data[i] != separador)) {
            sDia.push_back(p_data[i]);
            i++;
        }
        dia = stoi(sDia);
        i++;
        while ((i < p_data.size()) && (p_data[i] != separador)) {
            sMes.push_back(p_data[i]);
            i++;
        }
        mes = stoi(sMes);
        i++;
        while ((i < p_data.size()) && (p_data[i] != separador)) {
            sAno.push_back(p_data[i]);
            i++;
        }
        ano = stoi(sAno);
    }
    ~DataInterface(){};
    virtual string getData() = 0;
};