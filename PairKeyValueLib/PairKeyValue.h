#pragma once
#include <ostream>

template<typename K, typename V>
class Pair
{
	K key;
	V val;
public:                            // Konstruktory:
	Pair();                        // ... domyœlny
	Pair(const K& k, const V& v);  // ... parametryczny
	Pair(const Pair<K, V>& p);     // ... kopiuj¹cy {}
	~Pair() = default;             // Destruktor
	Pair& operator=(const Pair& p);// Operator przypisania (kopiuj¹cy)    if(this != &p) {  // wyci¹æ

	K getK() const; // Pobranie sk³adowej key
	V getV() const; // Pobranie sk³adowej val
};

// Szablony implementacji

template<typename K, typename V>
Pair<K, V>::Pair() : key{}, val{} {} // Domyœlne wartoœci K i V

template<typename K, typename V>
Pair<K, V>::Pair(const K& k, const V& v) : key(k), val(v) {}

template<typename K, typename V>
Pair<K, V>::Pair(const Pair<K, V>& p) : key(p.key), val(p.val) {}

// TODO Zdefiniowaæ operator przypisania
template<typename K, typename V>
Pair<K, V>& Pair<K, V>::operator=(const Pair<K, V>& p)
{
	if (this == &p)
		return *this;

	key = p.key;
	val = p.val;
	return *this;
}

// TODO Zdefiniowaæ funkcje pobierania atrybutów (getters)
template<typename K, typename V>
K Pair<K, V>::getK() const
{
	return key;
}

template<typename K, typename V>
V Pair<K, V>::getV() const
{
	return val;
}

// TODO Uzupe³niæ definicjê operatora transmisji wyjœciowej
// wed³ug formatu pokazanego w testach jednostkowych i Readme.md.
template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p)
{
	return os << "<" <<p.getK() << ":" << p.getV() << ">";    // "zaœlepka"
	
}

template<typename K, typename V>
bool cmpK(const Pair<K, V>& p1, const Pair<K, V>& p2)
{
	return p1.getK() < p2.getK();
}

template<typename K, typename V>
bool cmpV(const Pair<K, V>& p1, const Pair<K, V>& p2)
{
	return p1.getV() < p2.getV();
}