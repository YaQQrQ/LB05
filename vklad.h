#pragma once
#include <string>
#include <ostream>
#include <unordered_set>

using namespace std;

class vklad
{
private:
	std::string name;
	int sum;
	std::string type;
	double stavka;
public:
	vklad();
	vklad(std::string n, int s, std::string t, double st);
	friend std::ostream& operator<<(std::ostream& os, vklad& other);
	const double get_stavka() const;
	const string get_name() const;
	const string get_type() const;
	const int get_sum() const;
	bool operator<(const vklad & a) const;
	bool operator==(const vklad & a) const;
};

struct vklad_hasher
{
	hash<std::string> shash;
	hash<int> ihash;
	hash<double> dhash;
	size_t operator()(const vklad& ob) const
	{
		const size_t coef = 2'946'901;
		return (
			coef * coef * coef * dhash(ob.get_stavka()) +
			coef * coef * shash(ob.get_name()) +
			coef * shash(ob.get_type()) +
			ihash(ob.get_sum())
			);
	}
};