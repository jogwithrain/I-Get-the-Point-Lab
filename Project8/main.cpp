#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
	double x = 0;
	double y = 0;
public:
	Point() {
	x = 0;
	y = 0;
}
	Point(double _x) {
		x = _x;
	}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	double getXPoint() {
		return x;
	}
	double getYPoint() {
		return y;
	}
	void setXPoint(double _x) {
		x = _x;
	}
	void setYPoint(double _y) {
		y = _y;
	}
	bool operator==(Point other) { // overrides ==
		if (x == other.x && y == other.y) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(Point& other) { // overrides !=
		if (x == other.x && y == other.y) {
			return false;
		}
		else {
			return true;
		}
	}
	Point operator/(Point& other) {
		return Point((x + other.x) / 2, (y + other.y) / 2);
	}

	double operator-(Point other) { //overrides -
		double p = sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
		return p;
	}

	bool operator<(Point other) { //overrides <
		if (x < other.x) {
			return true;
		}
		else {
			return y < other.y;
		}
	}
	Point operator*(double other) {//overrides *
		return Point(x * other, y * other);
	}
	double operator[](char z) {
		if (z == 'x') {
			return getXPoint();
		}
		else {
			return getYPoint();
		}
	}
	//prefix
	Point& operator++() {
		++x;
		return *this;
	}

	//postfix
	Point operator++(int) {
		Point old = Point(y);
		y++;
		return old;
	}
	//prefix
	Point& operator--() {
		--x;
		return *this;
	}

	//postfix
	Point operator--(int) {
		Point old = Point(y);
		y--;
		return old;
	}
	double operator[](int z) {
		if (z == 0) {
			return getXPoint();
		}
		else if (z > 1) {
			cout << "Out of index. Input a different value." << endl;
			return -1;
		
		}
		else {
			return getYPoint();
		}
	}
};
ostream& operator<<(ostream& out, Point n) {
	out << "(" << n.getXPoint() << "," << n.getYPoint() << ")";
	return out;
}
istream& operator>>(istream& in, Point& n) {
	char c;
	in >> c;
	if (c != '(') {
		in.setstate(ios_base::failbit);
		return in;
	}

	int x;
	in >> x;
	//cout << "x: " << x << endl;
	in >> c;
	//cout << "c:" << c << endl;
	int y;
	in >> y;
	//cout << "y: " << y << endl;
	if (c != ',') {
		in.setstate(ios_base::failbit);
		return in;
	}

	n.setXPoint(x);
	n.setYPoint(y);
	return in;
}


int main() {
	Point p1 = Point(3.2, 9.8);
	Point p2 = Point(5.5, -1.2);
	bool z = (p1 == p2);
	cout << p1 - p2 << endl; // Prints out 11.238
	cout << (p1 == p2) << endl; // Prints out 0 (false)
	cout << z << endl;
	cout << (p1 != p2) << endl; // parenthesis added in due to it reading it like (cout << p1) (p2 <<endl;)
	cout << p1 / p2 << endl; // Prints out a nicely formatted point such as (4.35, 4.3)

	Point p = Point(3.2, 9.8);
	cout << p * 2 << endl;   // This should print out (6.4, 19.6)
	cout << p * 2.0 << endl;   // This should print out (6.4, 19.6)
	cout << p * -3 << endl;   // This should print out (-9.6, -29.4)

	double my_x = p2['x'];   // my_x should be 5.5
	double my_y = p2['y'];   // my_y should be -1.2
	cout << my_x << endl;
	cout << my_y << endl;
	p++;
	cout << p << endl;
	p--;
	cout << p << endl;
	++p;
	cout << p << endl;
	--p;
	cout << p << endl;
	//double my_x1 = p2[0];   // my_x should be 5.5
	//double my_y1 = p2[1];   // my_y should be -1.2
	cout << p2[0] << endl;
	cout << p2[1] << endl;
	cout << p2[2] << endl;

	Point n;

	cout << "Enter a number in the form (x,y) ";
	cin >> n;

	if (cin.fail()) {
		cout << "Your input failed" << endl;
	}
	else {
		(cout << n) << endl;
	}

}


