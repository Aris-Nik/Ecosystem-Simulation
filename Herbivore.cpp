#include <iostream>
#include "class.h"

using namespace std;


Herbivore::Herbivore(string name,int x, int y, int size, int speed, int neededFood, bool canClimb, int eatCount) : Animal(x, y, size, speed, neededFood){
	this->canClimb = canClimb;
	this->token = 'H';
	this->name = name;
	this->eatCount = eatCount;
	this->count = 0;
	if(name == "GroundHog")
		hibernates = true;
	else
		hibernates = false;
}
Herbivore::~Herbivore(){
	cout << "A Herbivore animal died " <<endl;
}

int Herbivore::get_count()const{ return this->count;}
void Herbivore::set_count(int i, char d){
	if(d == '+')
		this->count += i;
	else if( d == '-')
		this->count -= i;
	else if( d == '=')
		this->count = i;

}


void Herbivore::Meal(Plant* plant){
	int tempEatCount;
	if (this->name == "Deer" && plant->get_size()  < this->size + 4){
		tempEatCount = this->eatCount;
		if(this->neededFood - this->eatenFood  == 1) //FAE OSO XREIAZETAI
			tempEatCount  = 1;
		if (plant->get_token() ==  'G' || plant->get_token() ==  'A'){					//if plant is seedless
			Seedless* seedless = (Seedless*) plant;
			this->eatenFood += seedless->LoseLife(tempEatCount);
			if(this->eatenFood == this->neededFood){
				this->count = 7; // herbivore must eat after 7days 
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
		else{
			Seeded* seeded = (Seeded*) plant;
			this->eatenFood += seeded->LoseLife(tempEatCount);
			if(this->eatenFood == this->neededFood){
				this->count = 7;
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
	}
	else if (this->name == "Rabbit" && plant->get_token() !=  'A'){
		if (plant->get_token() ==  'G'){
			Seedless* seedless = (Seedless*) plant;
			this->eatenFood += seedless->LoseLife(this->eatCount);
			if(this->eatenFood == this->neededFood){
				this->count = 7;
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
		else{
			Seeded* seeded = (Seeded*) plant;
			if (seeded->get_size() <= this->size)
				this->eatenFood += seeded->LoseLife(this->eatCount);
			if(this->eatenFood == this->neededFood) {
				this->count = 7;
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
	}
	else if (this->name == "GroundHog" && plant->get_token() !=  'A'){
		if (plant->get_token() ==  'G'){
			Seedless* seedless = (Seedless*) plant;
			this->eatenFood += seedless->LoseLife(this->eatCount);
			if(this->eatenFood == this->neededFood){
				this->count = 7;
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
		else{
			Seeded* seeded = (Seeded*) plant;
			if (this->size >= seeded->get_size() && (this->canClimb && this->size * 3 >= seeded->get_size()))
				this->eatenFood += seeded->LoseLife(this->eatCount);
			if(this->eatenFood == this->neededFood){
				this->count = 7;
				this->isHungry = 0;
				this->HungerCount = 0;
			}
		}
	}
	else if (this->name == "Salmon" && plant->get_token() ==  'A'){			//SALMON EATS ONLY ALGAES
		Seedless* seedless = (Seedless*) plant;
		this->eatenFood += seedless->LoseLife(this->eatCount);
		if(this->eatenFood == this->neededFood){
			this->count = 7;
			this->isHungry = 0;
			this->HungerCount = 0;
		}
	}


}