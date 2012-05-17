struct Rational {

	typedef ll TBase;

	static const Rational ZERO;
	static const Rational ONE;
	static const Rational TWO;
	static const double EPS;

	TBase a, b;

	Rational() : a(0), b(1) { }

	Rational(TBase _a) : a(_a), b(1) { }

	Rational(TBase _a, TBase _b) : a(_a), b(_b) {
		norm();
	}

	operator bool() {
		return (a != 0);
	}

	operator long long() {
		return a / b;
	}

	operator long double() {
		return (a + 0.) / b;
	}

	operator string() {
		return toa(a) + "/" + toa(b);
	}

	bool operator !() {
		return !a;
	}

	bool operator && (bool x) {
		return (a > 0 && x);
	}

	Rational operator - () {
		return Rational(-a, b);
	}

	Rational operator + () {
		return Rational(a, b);
	}

	Rational operator ++ () {
		a += b;
		return Rational(a, b);
	}

	Rational operator ++ (int) {
		a += b;
		return Rational(a - b, b);
	}

	Rational operator -- () {
		a -= b;
		return Rational(a, b);
	}

	Rational operator -- (int) {
		a -= b;
		return Rational(a + b, b);
	}

	Rational operator + (Rational& x) {
		return Rational(a * x.b + x.a * b, b * x.b);
	}

	Rational operator - (Rational& x) {
		return Rational(a * x.b - x.a * b, b * x.b);
	}

	Rational operator * (Rational& x) {
        return Rational(a * x.a, b * x.b);
    }

	Rational operator / (Rational& x) {
        return Rational(a * x.b, b * x.a);
    }

	void operator += (Rational& x) {
		a = a * x.b + x.a * b;
		b *= x.b;
		norm();
	}

	void operator -= (Rational& x) {
		a = a * x.b - x.a * b;
		b *= x.b;
		norm();
	}

	void operator *= (Rational& x) {
		a *= x.a;
		b *= x.b;
		norm();
    }

	void operator /= (Rational& x) {
		a *= x.b;
		b *= x.a;
		norm();
    }

	Rational operator + (int x) {
		return Rational(a + (TBase)x * b, b);
	}

	Rational operator - (int x) {
		return Rational(a - (TBase)x * b, b);
	}

	Rational operator * (int x) {
		return Rational(a * (TBase)x, b);
	}

	Rational operator / (int x) {
		return Rational(a, b * (TBase)x);
	}

	void operator += (int x) {
		a += b * (TBase)x;
	}

	void operator -= (int x) {
		a -= b * (TBase)x;
	}

	void operator *= (int x) {
		a *= (TBase)x;
		norm();
	}

	void operator /= (int x) {
		b *= (TBase)x;
		norm();
	}

	Rational operator + (ll x) {
		return Rational(a + (TBase)x * b, b);
	}

	Rational operator - (ll x) {
		return Rational(a - (TBase)x * b, b);
	}

	Rational operator * (ll x) {
		return Rational(a * (TBase)x, b);
	}

	Rational operator / (ll x) {
		return Rational(a, b * (TBase)x);
	}

	void operator += (ll x) {
		a += b * (TBase)x;
	}

	void operator -= (ll x) {
		a -= b * (TBase)x;
	}

	void operator *= (ll x) {
		a *= (TBase)x;
		norm();
	}

	void operator /= (ll x) {
		b *= (TBase)x;
		norm();
	}

	bool operator == (Rational& x) {
		return (a == x.a && b == x.b);
	}

	bool operator != (Rational& x) {
		return (a != x.a || b != x.b);
	}

	bool operator < (Rational& x) {
		return (a * x.b < x.a * b);
	}

	bool operator > (Rational& x) {
		return (a * x.b > x.a * b);
	}

	bool operator <= (Rational& x) {
		return (a * x.b <= x.a * b);
	}

	bool operator >= (Rational& x) {
		return (a * x.b >= x.a * b);
	}
	
	bool operator == (int x) {
		return (a == (TBase)x * b);
	}
	
	bool operator != (int x) {
		return (a != (TBase)x * b);
	}
	
	bool operator < (int x) {
		return (a < (TBase)x * b);
	}
	
	bool operator > (int x) {
		return (a > (TBase)x * b);
	}
	
	bool operator <= (int x) {
		return (a <= (TBase)x * b);
	}
	
	bool operator >= (int x) {
		return (a >= (TBase)x * b);
	}
	
	bool operator == (ll x) {
		return (a == (TBase)x * b);
	}
	
	bool operator != (ll x) {
		return (a != (TBase)x * b);
	}
	
	bool operator < (ll x) {
		return (a < (TBase)x * b);
	}
	
	bool operator > (ll x) {
		return (a > (TBase)x * b);
	}
	
	bool operator <= (ll x) {
		return (a <= (TBase)x * b);
	}
	
	bool operator >= (ll x) {
		return (a >= (TBase)x * b);
	}
	
	bool operator == (double x) {
		return (fabs((a + 0.) / b - x) < EPS);
	}
	
	bool operator != (double x) {
		return (fabs((a + 0.) / b - x) > EPS);
	}
	
	bool operator < (double x) {
		return ((a + 0.) / b + EPS < x);
	}
	
	bool operator > (double x) {
		return ((a + 0.) / b + EPS > x);
	}
	
	bool operator <= (double x) {
		return ((a + 0.) / b + EPS <= x);
	}
	
	bool operator >= (double x) {
		return ((a + 0.) / b + EPS >= x);
	}

	friend ostream& operator << (ostream &o, Rational& x) {
		return o << x.a << " " << x.b;
	}
	
	friend istream& operator >> (istream &i, Rational& x) {
		return i >> x.a >> x.b;
	}

	inline void norm() {
		TBase g = gcd(a, b);
		a /= g;
		b /= g;
		if (b < 0) {
			a = -a;
			b = -b;
		}
	}

	inline void read() {
		scanf(LLD LLD, &a, &b);
		norm();
	}

	inline void print() {
		printf(LLD" "LLD, a, b);
	}

	inline void readSlash() {
		scanf(LLD"/"LLD, &a, &b);
		norm();
	}

	inline void printSlash() {
		printf(LLD"/"LLD, a, b);
	}

	inline Rational negate() {
		return Rational(-a, b);
	}

	inline Rational abs() {
		if (a < 0) return Rational(-a, b); else return Rational(a, b);
	}

	inline Rational inverse() {
		return Rational(b, a);
	}

	inline int sign() {
		if (a < 0) return -1; else return (a > 0);
	}

	inline double doubleValue() {
		return (a + 0.) / b;
	}

	inline TBase Floor() {
		return a / b;
	}

	inline TBase Ceil() {
		return (TBase)ceil((a + 0.) / b - EPS);
	}

	inline TBase Round() {
		double cur = (a + 0.) / b;
		return (TBase)(cur < 0 ? ceil(cur - .5 - EPS) : floor(cur + .5 + EPS));
	}

	inline double frac() {
		return (a + 0.) / b - a / b;
	}

	inline ll hashCode() {
		return a * 877117 + b;
	}

};

const Rational Rational::ZERO = Rational(0);
const Rational Rational::ONE = Rational(1);
const Rational Rational::TWO = Rational(2);
const double Rational::EPS = 1e-9;
