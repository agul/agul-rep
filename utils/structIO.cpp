friend ostream& operator << (ostream &o, item& x) {
	return o << "# A = \"" << x.a << "\"; B = " << x.b << endl;
}

friend istream& operator >> (istream &i, item& x) {
	return i >> x.a >> x.b;
}