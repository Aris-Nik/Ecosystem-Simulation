#include <iostream>
#include "class.h"

using namespace std;


	Plant::Plant(int x, int y, string name, int life, char token, int breedingProb, int illnessProb, int lifeFactor){
		this->x = x;
		this->y = y;
		this->name = name;
		this->life = life;
		this->token = token;
		this->breedingProb = breedingProb;
		this->illnessProb = illnessProb;
		this->lifeFactor = lifeFactor;

	}

	Plant::Plant(){
		this->token = '-';
	}
	Plant::~Plant(){
	
		cout << "A Plant died" << endl;
	}

	char Plant::get_token()const{return this->token;}
	void Plant::set_token(char s){ this->token = s;}
	string Plant::get_name()const{ return this->name;}
	void Plant::set_life(int s,char d){
		if( d == '-')
			this->life -= s;
		else if( d == '+')
			this->life += s;
		else if( d == '=')
			this->life = s;
		
	}
	int Plant::get_life()const{ return this->life;}
	int Plant::get_size()const{ return this->size;}
	void Plant::set_size(int s){ this->size = s;}
	int Plant::get_breedingProb()const{return this->breedingProb;}
	int Plant::get_lifeFactor()const{return this->lifeFactor;}
	int Plant::get_illnessProb()const{ return this->illnessProb;}

	Seeded::Seeded(int x, int y, string name,int foliage, int seeds, char token,int size, int breedingProb, int illnessProb, int lifeFactor) 
	: Plant(x,y,name,foliage,token,breedingProb,illnessProb,lifeFactor){
		this->foliage = foliage;
		this->seeds = seeds;
		this->size = size;
	}
	Seeded::~Seeded(){
		cout << "A seeded plant died" <<endl;
		this->~Plant();
	}


	int Seeded::LoseLife(int eatCount){
		int eatenFood = 0;
		if (this->seeds > 0){
			if (this->seeds < eatCount){		//there is no eatcount > 2 (so when the seeds are > 0 and seeds are < eatCount then there is only one seed)
				this->seeds--;
				eatenFood++;
				if (eatCount > 1){				// then eatCount is 2 because eatCount can be either 1 or 2
					this->foliage--;
					this->life--;
					eatenFood++;
				}
			}
			else{
				this->seeds -= eatCount;
				eatenFood = eatCount;
			}
		}
		else{
			if (this->life < eatCount){		//then life and foliage is 1 (because eatCount can be either 1 or 2)
				eatenFood = this->life;
				this->foliage--;
				this->life--;
			}
			else{
				this->foliage -= eatCount;
				this->life -= eatCount;
				eatenFood = eatCount;
			}
		}
		return eatenFood;
	}

	Seedless::Seedless(int x, int y, string name,int life, char token,int breedingProb, int illnessProb, int lifeFactor)
	 : Plant(x,y,name,life,token,breedingProb,illnessProb,lifeFactor){
		this->size = 0;
	}

	Seedless::~Seedless(){
		cout << "A seedless plant died " <<endl;
		this->~Plant();
	}
	int Seedless::LoseLife(int eatCount){
		int eatenFood = 0;
		if (this->life < eatCount){					//	ama den mporei to futo na dwsei osh posothta xreiazetai sto animal
			eatenFood = this->life;
			this->life = 0;
		}
		else{
			this->life -= eatCount;
			eatenFood = eatCount;
		}
		return eatenFood;
	}