class Exception : public exception {
private:
	string msg;
public:
    Exception(string _msg) : msg(_msg) {};
	~Exception() throw() {};
    static const Exception undefinedDateFormat() {
      return Exception("O formato de data não foi definido na documentação");
	}
	static const Exception undefinedDay() {
		return Exception("Esse dia não existe.");
	}
	static const Exception undefinedMonth() {
		return Exception("Esse mês não existe");
	}
	static const Exception undefinedYear() {
		return Exception("Esse ano não existe");
	}
	static const Exception leapYear() {
		return Exception("29 de fevereiro ocorre apenas nos anos bissextos");
	}
	static const Exception invalidDate() {
		return Exception("Todos campos devem ser inteiros maiores que 0");
	}
	static const Exception invalidYear() {
		return Exception("O ano está inválido");
	}
	static const Exception invalidMonth() {
		return Exception("O mês está inválido");
	}
	static const Exception invalidDay() {
		return Exception("O dia está inválido");
	}
    const char *what() const throw() { 
      return msg.c_str(); 
    };
};