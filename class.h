#include<iostream>
#include<vector> // include vector here
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct point
{
	int x;
	int y;
	
};

class Terrain;
class Animal;

class Plant{
protected:
	char token;
	string name;
	int life;
	int size;
	int breedingProb;
	int x,y;
	int lifeFactor;
	int illnessProb;
public:
	
	Plant();
	Plant(int x, int y, string name, int life, char token, int breedingProb, int illnessProb, int lifeFactor);
	virtual ~Plant();
	string get_name()const;
	void set_token(char s);
	char get_token()const;
	void set_size(int s);
	int get_size()const;
	void set_life(int s,char d);
	int get_life()const;
	int get_breedingProb()const;
	int get_lifeFactor()const;
	int get_illnessProb()const;

};

class Seeded: public Plant{
private:
		int foliage;
		int seeds;

	public:
		Seeded(int x, int y, string name,int foliage, int seeds, char token, int size, int breedingProb, int illnessProb, int lifeFactor);
		int LoseLife(int eatCount);
		~Seeded();

};

class Seedless: public Plant{

	public:
		Seedless(int x, int y, string name, int life, char token, int breedingProb, int illnessProb, int lifeFactor);
		int LoseLife(int eatCount);
		~Seedless();
};

class Tile{
private:
	char type;
	Plant* plant;
public:
	vector<Animal*> animals;
	Tile();
	Tile(char t);
	~Tile();
	Animal* FindHerbivore(int size, int speed, string name);
	Animal* FindCarnivore(int defence,int size,int k);
	char get_type()const;
	void set_type(char type);
	Plant* get_Plant()const;
	void set_Plant(Plant* p);


};

class Animal{
protected:
	string name;
	char token;
	int eatenFood;       		    // ?
	int neededFood;
	int eatCount;
	int speed;
	int size;
	bool isAlive;
	bool isHungry;
	int HungerCount;				//days without eating
	bool inHibernation;
	bool hibernates;				//an mpainei se xeimeria narkh
	bool flag;
	bool inHeat;					// ?
	

public:
	int x,y;
	Animal();
	Animal(int x, int y, int size, int speed, int neededFood);
	virtual ~Animal();
	int CheckMoveUp(Terrain* terrain); // return the final destination in Map
	int CheckMoveDown(Terrain* terrain); // return the final destination in Map
	int CheckMoveLeft(Terrain* terrain); // return the final destination in Map
	int CheckMoveRight(Terrain* terrain); // return the final destination in Map
	bool isAdult();
	string get_name()const;
	char get_token()const;
	int get_eatenFood()const;
	int get_neededFood()const;
	int get_eatCount()const;
	void set_neededFood(int s, char d);
	int get_size()const;
	int get_speed()const;
	void set_size(int s, char d);
	void set_speed(int s, char d);
	bool  get_isHungry()const;
	void set_isHungry(bool i);
	void set_HungerCount(int i, char d);
	int get_HungerCount()const;
	bool get_inHibernation()const;
	void set_inHibernation(bool i);
	bool get_flag()const;
	void set_flag(bool i);

};

class Herbivore: public Animal{
private:
	bool canClimb;
	int count;
public:
	Herbivore();
	Herbivore(string name, int x, int y, int size, int speed, int neededFood, bool canClimb, int eatCount);
	void Meal(Plant* plant);
	~Herbivore();
	int get_count()const;
	void set_count(int i, char d);
};


class Carnivore: public Animal{
private:
	int attack;
	int defence;
	
public:
	Carnivore(string name, int x, int y, int size, int speed, int neededFood, int attack, int defence);
	~Carnivore();
	void Meal(Tile* tile,int k);
	int get_attack()const;
	void set_attack(int i, char d);
	int get_defence()const;
	void set_defence(int i, char d);

};
class Terrain{

private:
	int terrainSize;
 
public:
	Tile*** Map;
	Terrain();
	Terrain(int terrainSize);
	~Terrain();
	void GenerateRiver();
	void GenerateMap();
	void GenerateLake();
	void GenerateHills();
	void GenerateMeadow();
	void PrintAnimalStatistics();
	void PrintPlantStatistics();
	void print();
	point FindFreeTile(int x, int y,char t);
	point FindFreeTile(int x, int y,char t1,char t2);
	int get_terrainSize()const;
};




class Ecosystem{
private:
	Terrain* terrain;
public:
	int dayOfyear;
	Ecosystem();
	Ecosystem(int terrainSize, int dayOfyear);
	~Ecosystem();
	void PlacePlants(int G, int A, int O, int M, int P);
	void PlaceAnimals(int Deers, int Rabbits, int GroundHogs, int Salmons, int Foxes, int Bears, int Wolves);
	void  AnimalMovement();
	int AnimalEating();
	void CheckDeadEntities();
	void CheckHunger();
	void DailyReset();
	void RunEcosystem(int days);
	void PrintSystem();
	void breedingPlants();
	void growthPlants();
	void AnimalBreeding(char c);
	void increaseStats(Animal* animal);
	void GrowAnimals();
	void breedingRepPeriod(int day);
	void growthPeriod(int day);
	void Hibernation();
	void outHibernation();
	Terrain* get_Terrain()const ;

};
