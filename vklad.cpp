#pragma once
#include <fstream>
#include "vklad.h"

using namespace std;

vklad::vklad() {
	this->name = "";
	this->sum = 0;
	this->type = "";
	this->stavka = 0;
}

vklad::vklad(std::string n, int s, std::string t, double st)
{
	this->name = n;
	this->sum = s;
	this->type = t;
	this->stavka = st;
}

std::ostream& operator<<(std::ostream& os, vklad& other) {
	os << other.name << " " << other.sum << " " << other.type << " " << other.stavka << std::endl;
	return os;
}

const double vklad::get_stavka() const
{
	return this->stavka;
}
const string vklad::get_name() const
{
	return this->name;
}
const string vklad::get_type() const
{
	return this->type;
}
const int vklad::get_sum() const
{
	return this->sum;
}
bool vklad::operator<(const vklad & a) const 
{
	return this->stavka < a.stavka;
}

bool vklad::operator==(const vklad & a) const
{
	return (this->stavka == a.stavka && this->name == a.name && this->type == a.type && this->sum == a.sum);
}
