#include<iostream>
#include"class.h"

using namespace std;

	Tile:: Tile(){
		this->plant = new Plant();
		this->type = '-';
	}
	Tile:: Tile(char t){
		this->plant = new Plant();
		this->type = t;
		this->plant->set_token('-');
	}
	Tile::~Tile(){
		delete this->plant;
	}
	Animal* Tile::FindHerbivore(int size, int speed, string name){ // checking a herbivore with speed,size less																			
		for( int i = 0; i < animals.size(); i++){ // than the arguments
			if(animals[i]->get_speed() < speed && animals[i]->get_size() <= size && animals[i]->get_name() != name && animals[i]->get_token() == 'H'){
				return animals[i];
			}
		}
		return NULL;
	}	
	Animal* Tile::FindCarnivore(int attack,int size,int k){

		for( int i = 0; i < animals.size(); i++){ // than the arguments
			if( animals[i]->get_token() == 'C' && i != k){
				Carnivore* temp = (Carnivore*)animals[i];
				if(temp->get_size() < size || (temp->get_size() == size && temp->get_defence() < attack)){
					return temp;
				}
			}
		}
		return NULL;
	}	
	char Tile::get_type()const{ return this->type;}
	void Tile::set_type(char type){  this->type = type;}
	Plant* Tile::get_Plant()const{ return this->plant;}
	void Tile:: set_Plant(Plant* p){  this->plant = p;}

