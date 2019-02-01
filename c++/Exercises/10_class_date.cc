#include <iostream>

enum class Month
{
	gen = 1, feb, mar, apr, mag, giu, lug, ago, set, ott, nov, dic
};

Month& operator++(Month& m)
{
	switch (m)
	{
	case Month::gen:
		return m = Month::feb;
	case Month::feb:
		return m = Month::mar;
	case Month::mar:
		return m = Month::apr;
	case Month::apr:
		return m = Month::mag;
	case Month::mag:
		return m = Month::giu;
	case Month::giu:
		return m = Month::lug;
	case Month::lug:
		return m = Month::ago;
	case Month::ago:
		return m = Month::set;
	case Month::set:
		return m = Month::ott;
	case Month::ott:
		return m = Month::nov;
	case Month::nov:
		return m = Month::dic;
	case Month::dic:
		return m = Month::gen;
	}
}

Month& operator++(Month& m, int)
{
	Month result = m;
	++m;
	return result;
}

std::ostream& operator<<(std::ostream& os, Month m)
{
	switch (m)
	{
	case Month::gen:
		os << "gennaio";
		return os;
	case Month::feb:
		os << "febbraio";
		return os;
	case Month::mar:
		os << "marzo";
		return os;
	case Month::apr:
		os << "aprile";
		return os;
	case Month::mag:
		os << "maggio";
		return os;
	case Month::giu:
		os << "giugno";
		return os;
	case Month::lug:
		os << "luglio";
		return os;
	case Month::ago:
		os << "agosto";
		return os;
	case Month::set:
		os << "settembre";
		return os;
	case Month::ott:
		os << "ottobre";
		return os;
	case Month::nov:
		os << "novembre";
		return os;
	case Month::dic:
		os << "gennaio";
		return os;
	}
}

bool is_leap(const int y);

class Date
{
private:

	int D;
	Month M;
	int Y;

private:

	void add_day()
	{
		if (D < 28 || D == 29)
		{
			++D;
			return;
		}

		if (D == 28 && M == Month::feb && !is_leap(Y))
		{
			D = 1;
			++M;
			return;
		}

		if (D == 28 && M == Month::feb && is_leap(Y))
		{
			D = 29;
			return;
		}

		if (D == 29 && M == Month::feb)
		{
			D = 1;
			++M;
			return;
		}

		if (D == 30 && (M == Month::apr || M == Month::giu || M == Month::set || M == Month::nov))
		{
			D = 1;
			++M;
			return;
		}

		if (D == 31)
		{
			if (M == Month::dic)
			{
				++Y;
			}
			D = 1;
			++M;
		}

		++D;
		return;
	}

public:

	Date(int day, Month month, int year)
		: D(day), M(month), Y(year) {}

	int day() const { return D; }

	Month month() const { return M; }

	int year() const { return Y; }

	void add_days(const unsigned int n)
	{
		for (unsigned int i = 0; i < n; ++i)
		{
			add_day();
		}
	}

	friend std::ostream& operator<<(std::ostream& os, Date& d)
	{
		os << d.D << " " << d.M << " " << d.Y;
		return os;
	}

	friend bool operator==(const Date& lhs, const Date& rhs)
	{
		return (lhs.D == rhs.D) && (lhs.M == rhs.M) && (lhs.Y == rhs.Y);
	}

	friend bool operator!=(const Date& lhs, const Date& rhs)
	{
		return (lhs.D != rhs.D) || (lhs.M != rhs.M) || (lhs.Y != rhs.Y);
	}

	friend bool is_leap(const int y)
	{
		bool leap{ false };

		if (!(y % 4)) { leap = true; }

		if ((y > 399 || y < -399) && !(y % 400)) { leap = false; }

		return leap;
	}

};

int main()
{
	Date today{ 30,Month::nov,1993 };

	std::cout << today << std::endl;
	today.add_days(200);
	std::cout << today << std::endl;
	today.add_days(25);
	std::cout << today << std::endl;
	today.add_days(3000);
	std::cout << today << std::endl;

	return 0;
}