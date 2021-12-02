#include <iostream>
#include "class.h"
#include<cmath>

using namespace std;


Animal::Animal(int x, int y, int size, int speed, int neededFood){
	this->x = x;
	this->y = y;
	this->size = size;
	this->speed = speed;
	this->neededFood = neededFood;
	this->flag = 0; 
	this->isHungry = 1;
	this->inHibernation = false;

}
Animal::~Animal(){
	cout << "An animal died " << this->name << endl;
}

string Animal::get_name()const{ return this->name;}
char Animal::get_token()const{ return this->token;}
int Animal::get_eatenFood()const{ return this->eatenFood;}
int Animal::get_neededFood()const{ return this->neededFood;}
int Animal::get_eatCount()const{ return this->eatCount;}
bool Animal::get_isHungry()const{ return this->isHungry;}
void Animal::set_isHungry(bool i){ this->isHungry = i;}
void Animal::set_HungerCount(int i, char d){
	if( d == '+')
		this->HungerCount += i;
	else if(d == '=')
		this->HungerCount = i;
}
int Animal::get_HungerCount()const{return this->HungerCount;}

void Animal::set_neededFood(int s, char d){
	if(d == '+')
		this->neededFood += s;
	else if( d == '-')
		this->neededFood -= s;
	else if( d == '=')
		this->neededFood = s;
}
int Animal::get_size()const{return this->size;}
int Animal::get_speed()const{ return this->speed;}
void Animal::set_size(int s,char d){ 
	if(d == '+')
		this->size += s;
	else if( d == '-')
		this->size -= s;
	else if( d == '=')
		this->size = s;
}
void Animal::set_speed(int s,char d){
		if(d == '+')
		this->speed += s;
	else if( d == '-')
		this->speed -= s;
	else if( d == '=')
		this->speed = s;

}

bool Animal::isAdult(){
	if(this->name == "Deer")
		if(this->size == 5)
			return true;
	if(this->name == "Rabbit")
		if(this->size == 2)
			return true;
	if(this->name == "GroundHog")
		if( this->size == 3)
			return true;
	if(this->name == "Fox")
		if(this->size == 4)
			return true;
	if(this->name == "Wolf")
		if(this->size == 7)
			return true;
	if( this->name == "Bear")
		if(this->size == 10)
			return true;

	return false;
	
}
bool Animal::get_inHibernation()const{ return this->inHibernation;}
void Animal::set_inHibernation(bool i){ this->inHibernation = i;}
bool Animal::get_flag()const{return this->flag;}
void Animal::set_flag(bool i){ this->flag = i;}


int Animal:: CheckMoveUp(Terrain* terrain){

	int moved = rand() % (this->speed); // animal can moved 0 to his speed tiles
	int temp1 = x;

	if( this->name == "Rabbit"){ // rabbits cannot be moved at hills
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x > 0){ // checking up
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1-1][this->y]->get_type() != '^'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else if( this->name == "GroundHog"){ // salmons cannot be moved in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x > 0){ // checking up
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1-1][this->y]->get_type() != '#'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else if(this->name == "Salmon"){ // salmons can be moved only in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x > 0){ // checking up
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1-1][this->y]->get_type() == '#'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else{
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x > 0){ // checking up
				while(abs(temp1 - this->x) < moved){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}

	return temp1; // returns the current animal's x 
}


int Animal:: CheckMoveDown(Terrain* terrain){

	int moved = rand() % (this->speed); // animal can moved 0 to his speed tiles
	int temp1 = this->x;

	if(this->name == "Rabbit"){ // rabbits cannot be moved at hills
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x < terrain->get_terrainSize() - 1){ // checking DOWN
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1+1][this->y]->get_type() != '^'){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else if( this->name == "GroundHog"){ // salmons cannot be moved in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x < terrain->get_terrainSize() - 1){ // checking DOWN
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1 + 1][this->y]->get_type() != '#'){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else if(this->name == "Salmon"){ // salmons can be moved only in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x < terrain->get_terrainSize() - 1){ // checking DOWN
				while(abs(temp1 - this->x) < moved &&  terrain->Map[temp1+1][this->y]->get_type() == '#'){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else{
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->x < terrain->get_terrainSize() - 1){ // checking uDOWN
				while(abs(temp1 - this->x) < moved){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}

	return temp1;
	
}




int Animal:: CheckMoveLeft(Terrain* terrain){

	int moved = rand() % (this->speed); // animal can moved 0 to his speed tiles
	int temp1 = this->y;

	if( this->name == "Rabbit"){ // rabbits cannot be moved at hills
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y > 0){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 - 1]->get_type() != '^'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else if( this->name == "GroundHog"){ // salmons cannot be moved in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y > 0){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 - 1]->get_type() != '#'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else if(this->name == "Salmon"){ // salmons can be moved only in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y > 0){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 - 1]->get_type() == '#'){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}
	else{
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y > 0){ // checking up
				while(abs(temp1 - this->y) < moved){
					temp1 = temp1 - 1;
					if( temp1 == 0)
						break;
				}
			}
		}
	}

	return temp1;
	
}



int Animal:: CheckMoveRight(Terrain* terrain){

	int moved = rand() % (this->speed); // animal can moved 0 to his speed tiles
	int temp1 = this->y;

	if( this->name == "Rabbit"){ // rabbits cannot be moved at hills
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y < terrain->get_terrainSize() - 1){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 + 1]->get_type() != '^'){
					temp1 = temp1  + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else if( this->name == "GroundHog"){ // salmons cannot be moved in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y < terrain->get_terrainSize() - 1){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 + 1]->get_type() != '#'){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else if(this->name == "Salmon"){ // salmons can be moved only in water
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y < terrain->get_terrainSize() - 1){ // checking up
				while(abs(temp1 - this->y) < moved &&  terrain->Map[this->x][temp1 + 1]->get_type() == '#'){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}
	else{
		if(!this->flag){ // if animal hasnt moved yet
			this->flag = 1; //  cannot be moved again
			if(this->y < terrain->get_terrainSize() - 1){ // checking up
				while(abs(temp1 - this->y) < moved){
					temp1 = temp1 + 1;
					if( temp1 == terrain->get_terrainSize() - 1)
						break;
				}
			}
		}
	}

	return temp1;
	
}




















