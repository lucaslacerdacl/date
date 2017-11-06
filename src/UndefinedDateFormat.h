class UndefinedDateFormat : public exception {
public:
    UndefinedDateFormat() {};
    ~UndefinedDateFormat() throw() {};
    const char *what() const throw() { 
      return "O formato de data não foi definido na documentação"; 
    };
};