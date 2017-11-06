class UndefinedDay : public exception {
public:
    UndefinedDay() {};
    ~UndefinedDay() throw() {};
    const char *what() const throw() { 
      return "Esse dia não existe."; 
    };
};