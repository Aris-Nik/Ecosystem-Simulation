#include <iostream>
#include "class.h"

using namespace std;

Carnivore::Carnivore(string name,int x, int y, int size, int speed, int neededFood, int attack, int defence) : Animal(x, y, size, speed, neededFood){
	this->token = 'C';
	this->attack = attack;
	this->defence = defence;
	this->name = name;
	this->eatCount = neededFood;
	if(name == "Bear")
		this->hibernates = true;
	else
		this->hibernates = false;
}
Carnivore::~Carnivore(){
	cout << "A Carnivore animal died " <<endl;
}


int Carnivore::get_attack()const{return this->attack;}
void Carnivore::set_attack(int i, char d){
	if(d == '+')
		this->attack += i;
	else if( d == '-')
		this->attack -= i;
	else if( d == '=')
		this->attack = i;

}
int Carnivore::get_defence()const{return this->defence;}
void Carnivore::set_defence(int i, char d){
	if(d == '+')
		this->defence += i;
	else if( d == '-')
		this->defence -= i;
	else if( d == '=')
		this->defence = i;
}

void Carnivore::Meal(Tile *tile,int k){

	if( (this->name == "Fox" || this->name == "Wolf")){
		if(this->HungerCount  < 8){
			Animal* temp = tile->FindHerbivore(this->size,this->speed,"Salmon");
			if(temp){
				temp->set_size(0,'=');
				this->isHungry = 0; 
				this->HungerCount = 0;
				this->eatenFood = this->neededFood; // 1 meal == not hungry
			}
		}
		else if(this->HungerCount  >= 8){ // fight each other if animal hasnt eat for 8 days
			Animal* temp = tile->FindCarnivore(this->attack,this->size,k); // fight between carnivores
			if(temp){
				temp->set_size(0,'=');
				this->isHungry = 0; 
				this->HungerCount = 0;
				this->eatenFood = this->neededFood; // 1 meal == not hungry
			}

		}
	}
	else if(this->name == "Bear"){
		if(this->HungerCount  < 8){
			Animal* temp = tile->FindHerbivore(this->size,100,"1312"); // acab fuck the police
			if(temp){
				temp->set_size(0,'=');
				this->isHungry = 0; 
				this->HungerCount = 0;
				this->eatenFood = this->neededFood; // 1 meal == not hungry	
			}
		}
		else{
			Animal* temp = tile->FindCarnivore(this->attack,this->size,k); // fight between carnivores
			if(temp){
				temp->set_size(0,'=');
				this->isHungry = 0; 
				this->HungerCount = 0;
				this->eatenFood = this->neededFood; // 1 meal == not hungry
			}
		}
	}

}