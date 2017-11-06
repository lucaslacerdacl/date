class UndefinedMonth : public exception {
public:
    UndefinedMonth() {};
    ~UndefinedMonth() throw() {};
    const char *what() const throw() { 
      return "Esse mês não existe"; 
    };
};