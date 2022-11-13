#pragma once
#include <ostream>

template<typename K, typename V>
class Pair
{
	K key;
	V val;
public:                            // Konstruktory:
	Pair();                        // ... domy�lny
	Pair(const K& k, const V& v);  // ... parametryczny
	Pair(const Pair<K, V>& p);     // ... kopiuj�cy {}
	~Pair() = default;             // Destruktor
	Pair& operator=(const Pair& p);// Operator przypisania (kopiuj�cy)    if(this != &p) {  // wyci��

	K getK() const; // Pobranie sk�adowej key
	V getV() const; // Pobranie sk�adowej val
};

// Szablony implementacji

template<typename K, typename V>
Pair<K, V>::Pair() : key{}, val{} {} // Domy�lne warto�ci K i V

template<typename K, typename V>
Pair<K, V>::Pair(const K& k, const V& v) : key(k), val(v) {}

template<typename K, typename V>
Pair<K, V>::Pair(const Pair<K, V>& p) : key(p.key), val(p.val) {}

// TODO Zdefiniowa� operator przypisania
template<typename K, typename V>
Pair<K, V>& Pair<K, V>::operator=(const Pair<K, V>& p)
{
	if (this == &p)
		return *this;

	key = p.key;
	val = p.val;
	return *this;
}

// TODO Zdefiniowa� funkcje pobierania atrybut�w (getters)
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

// TODO Uzupe�ni� definicj� operatora transmisji wyj�ciowej
// wed�ug formatu pokazanego w testach jednostkowych i Readme.md.
template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p)
{
	return os << "<" <<p.getK() << ":" << p.getV() << ">";    // "za�lepka"
	
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