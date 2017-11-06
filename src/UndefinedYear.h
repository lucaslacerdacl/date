class UndefinedYear : public exception {
public:
    UndefinedYear() {};
    ~UndefinedYear() throw() {};
    const char *what() const throw() { 
      return "Esse ano não existe"; 
    };
};