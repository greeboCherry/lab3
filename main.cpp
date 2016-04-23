// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>

#include "Slav.h"

//Moje include
#include<cstdlib>


#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
    srand(123);

	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;

	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	for (int i=0; i<n;i++)
    {
        vectorOfSlavs.insert(vectorOfSlavs.begin() + rand()% (vectorOfSlavs.size()+1),slavs+i);
    }

	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
    for(vector<Slav *>::iterator it=vectorOfSlavs.begin();it<vectorOfSlavs.end(); it++)
    {

        cout<<(*it) -> description()<<endl;
    }

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for(vector<Slav *>::iterator it=vectorOfSlavs.end();it>vectorOfSlavs.begin(); it--)
    {
    		setOfSlavs.insert(*it);
    		vectorOfSlavs.pop_back();
    }


	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	for (set<Slav *>::iterator it = setOfSlavs.end(); it != setOfSlavs.begin(); --it, --it)
	{
//						printf("%p\n", --it);
		mapOfSlavs.insert(pair<Slav *, Slav *> ((*it),(*it-1) ) );
		setOfSlavs.erase(*it);
		setOfSlavs.erase(*it-1);


	}

	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
/*
	for (map<Slav *,Slav *>::iterator it = mapOfSlavs.begin(); it != mapOfSlavs.end(); it++)
	{
		printf("%p\n", mapOfSlavs.begin());
		printf("%p\n", it);
		(it->second)->description();
	}
*/
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.

	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
