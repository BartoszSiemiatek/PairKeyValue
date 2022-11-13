#include <iostream>
#include <vector>
#include <algorithm>
#include "..\PairKeyValueLib\PairKeyValue.h"

template<typename T>
void showVector(const std::vector<T>& v)
{
	std::cout << "[";
	if (v.size() > 0)
	{
		for (unsigned i = 0; i < v.size() - 1; ++i)
			std::cout << v[i] << ", ";
		std::cout << v[v.size() - 1];
	}
	std::cout << "]\n";
}

int main()
{
	setlocale(LC_ALL, "pl-PL");
	std::vector<Pair<int, std::string>> vec
	{
	  {1, "jeden"},  {5, "piêæ"}, {6, "szeœæ"},
	  {4, "cztery"}, {2, "dwa"},    {3, "trzy"}
	};

	std::vector<Pair<std::string, std::string>> dic
	{
	  {"one", "jeden"}, {"five", "piêæ"}, {"six", "szeœæ"},
	  {"four", "cztery"}, {"two", "dwa"}, {"three", "trzy"}
	};

	std::cout << "Test szablonu Para<K, V>\n";

	std::cout << "\nKolekcja vec oryginalna\n";
	showVector(vec);

	std::cout << "\nKolekcja vec rosn¹ca wg klucza\n";
	std::sort(vec.begin(), vec.end(), cmpK<int, std::string>);
	showVector(vec);

	std::cout << "\nKolekcja vec rosn¹ca wg wartoœci\n";
	std::sort(vec.begin(), vec.end(), cmpV<int, std::string>);
	showVector(vec);

	std::cout << "\nKolekcja dic oryginalna\n";
	showVector(dic);

	std::cout << "\nKolekcja dic rosn¹ca wg klucza\n";
	std::sort(dic.begin(), dic.end(), cmpK<std::string, std::string>);
	showVector(dic);

	std::cout << "\nKolekcja dic rosn¹ca wg wartoœci\n";
	std::sort(dic.begin(), dic.end(), cmpV<std::string, std::string>);
	showVector(dic);

	std::cin.get();
}
