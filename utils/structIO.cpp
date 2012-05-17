	friend ostream& operator << (ostream &o, user& u) {
		return o << "# name = \"" << u.name << "\"; n = " << u.n << endl;
	}
	
	friend istream& operator >> (istream &i, item& u) {
			return i >> u.a >> u.b;
	}