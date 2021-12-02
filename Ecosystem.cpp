#include<iostream>
#include"class.h"

using namespace std;

	Ecosystem::Ecosystem(int terrainSize, int dayOfyear){
		this->terrain = new Terrain(terrainSize);
		this->dayOfyear = dayOfyear;
	}
	Terrain* Ecosystem::get_Terrain()const{ return this->terrain;}
	Ecosystem::~Ecosystem(){
		cout << "Terrain deleted " <<endl;
		delete this->terrain;
	}
	void Ecosystem::PrintSystem(){
		this->terrain->print();
		this->terrain->PrintPlantStatistics();
		this->terrain->PrintAnimalStatistics();

	}

	void Ecosystem::PlacePlants(int G, int A, int O, int M, int P){
		bool flag;
		for (int i = 0; i < G; i++){
			flag = 1;
			while(flag){
				int x = rand() % terrain->get_terrainSize();
				int y = rand() % terrain->get_terrainSize();
				if (terrain->Map[x][y]->get_type() == '"' && terrain->Map[x][y]->get_Plant()->get_token() ==  '-'){
					delete terrain->Map[x][y]->get_Plant();
					Plant* Grass = new Seedless(x,y,"grass",5,'G',15,15,4);
					terrain->Map[x][y]->set_Plant(Grass);
					flag = 0;
				}
			}
		}

		for (int i = 0; i < A; i++){
			flag = 1;
			while(flag){
				int x = rand() % terrain->get_terrainSize() ;
				int y = rand() % terrain->get_terrainSize() ;
				if (terrain->Map[x][y]->get_type() == '#' && terrain->Map[x][y]->get_Plant()->get_token() ==  '-'){
					delete terrain->Map[x][y]->get_Plant();
					Plant* Algae = new Seedless(x,y,"Algae",5,'A',25,25,2);
					terrain->Map[x][y]->set_Plant(Algae);
					flag = 0;
				}
			}
		}

		for (int i = 0; i < O; i++){
			flag = 1;
			while(flag){
				int x = rand() % terrain->get_terrainSize() ;
				int y = rand() % terrain->get_terrainSize() ;
				if (terrain->Map[x][y]->get_type() == '"' && terrain->Map[x][y]->get_Plant()->get_token() ==  '-'){
					delete terrain->Map[x][y]->get_Plant();
					Plant* Oak = new Seeded(x,y,"Oak",30,15,'O',5,20,20,15);
					terrain->Map[x][y]->set_Plant(Oak);
					flag = 0;
				}
			}
		}

		for (int i = 0; i < P; i++){
			flag = 1;
			while(flag){
				int x = rand() % terrain->get_terrainSize() ;
				int y = rand() % terrain->get_terrainSize() ;
				if (terrain->Map[x][y]->get_type() == '^' && terrain->Map[x][y]->get_Plant()->get_token() ==  '-'){
					delete terrain->Map[x][y]->get_Plant();
					Plant* Pine = new Seeded(x,y,"Pine",40,20,'P',5,15,15,20);
					terrain->Map[x][y]->set_Plant(Pine);
					flag = 0;
				}
			}
		}

		for (int i = 0; i < M; i++){
			flag = 1;
			while(flag){
				int x = rand() % terrain->get_terrainSize() ;
				int y = rand() % terrain->get_terrainSize() ;
				if (terrain->Map[x][y]->get_type() == '"' && terrain->Map[x][y]->get_Plant()->get_token() ==  '-'){
					delete terrain->Map[x][y]->get_Plant();
					Plant* Maple = new Seeded(x,y,"Maple",20,10,'M',2,5,5,10);
					terrain->Map[x][y]->set_Plant(Maple);
					flag = 0;
				}
			}
		}
	}


	void Ecosystem:: PlaceAnimals(int Deers, int Rabbits, int GroundHogs, int Salmons, int Foxes, int Bears, int Wolves){
		int i,x,y;
		int flag;
		for( i = 0; i < Deers; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '"'){
					Animal* Deer = new Herbivore("Deer",x,y,5,8,8,0,2); // creation of Deers
					terrain->Map[x][y]->animals.push_back(Deer);
					flag = 0;
				}
			}
		}
		for( i = 0; i < Rabbits; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();	
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '"'){
					Animal* Rabbit = new Herbivore("Rabbit",x,y,2,6,4,0,1); // creation of Rabbits
					terrain->Map[x][y]->animals.push_back(Rabbit);
					flag = 0;
				}
			}
		}
		for( i = 0; i < GroundHogs; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '"'){
					Animal* GroundHog = new Herbivore("GroundHog",x,y,3,5,5,1,1); // creation of GroundHogs
					terrain->Map[x][y]->animals.push_back(GroundHog);
					flag = 0;
				}
			}
		}
		for( i = 0; i < Salmons; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '#'){
					Animal* Salmon = new Herbivore("Salmon",x,y,1,5,1,0,1); // creation of Salmon
					terrain->Map[x][y]->animals.push_back(Salmon);
					flag = 0;
				}
			}
		}
		for( i = 0; i < Foxes; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '"'){
					Animal* Fox = new Carnivore("Fox",x,y,4,6,6,5,5); // creation of Fox
					terrain->Map[x][y]->animals.push_back(Fox);
					flag = 0;
				}
			}
		}
		for( i = 0; i < Wolves; i++){
			flag = 1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() != '#'){
					Animal* Wolf = new Carnivore("Wolf",x,y,7,8,8,8,6); // creation of Wolf
					terrain->Map[x][y]->animals.push_back(Wolf);
					flag = 0;
				}
			}
		}

		for( i = 0; i < Bears; i++){
			flag =  1;
			while(flag){
				x = rand() % terrain->get_terrainSize();
				y = rand() % terrain->get_terrainSize();
				if(terrain->Map[x][y]->get_type() == '^'){
					Animal* Bear = new Carnivore("Bear",x,y,10,4,10,10,10); // creation of Bear
					terrain->Map[x][y]->animals.push_back(Bear);
					flag = 0;
				}
			}
		}
	}

	void  Ecosystem:: AnimalMovement(){
		int moved,direction,temp1;

		for( int i = 0; i < this->terrain->get_terrainSize(); i++){
			for( int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					direction = rand() % 4;
					Animal* temp = this->terrain->Map[i][j]->animals.back(); // store animal in temp
					if(temp->get_inHibernation() ==  false){
						this->terrain->Map[i][j]->animals.pop_back(); // delete it
						if( direction == 0)
							temp->x = temp->CheckMoveUp(this->terrain);
						 // animal goes down
						else if( direction == 1)
							temp->x = temp->CheckMoveDown(this->terrain);
						else if( direction == 2)
							temp->y = temp->CheckMoveLeft(this->terrain);
								
						else if( direction == 3)
							temp->y = temp->CheckMoveRight(this->terrain);					

						this->terrain->Map[temp->x][temp->y]->animals.push_back(temp);// animal has moved
					}
				}// for loop for each animal vector
			} // for loop for each column
		}// for loop for each row
		for( int i = 0; i < this->terrain->get_terrainSize(); i++)
			for( int j = 0; j < this->terrain->get_terrainSize(); j++)
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++)
					this->terrain->Map[i][j]->animals[k]->set_flag(false);
	}


	void Ecosystem::CheckDeadEntities(){

		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				Plant *plant = this->terrain->Map[i][j]->get_Plant();
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					if(this->terrain->Map[i][j]->animals[k]->get_size() == 0 || this->terrain->Map[i][j]->animals[k]->get_HungerCount() > 10){
						Animal* temp = this->terrain->Map[i][j]->animals[k];
						this->terrain->Map[i][j]->animals.erase(this->terrain->Map[i][j]->animals.begin() + k);
						delete temp;
						k--; // we delete an element from vector,so size is changing during the for loop
					}
				}

				if(plant->get_token() !=  '-' && !plant->get_life() && plant){
					plant->set_token('-'); //dead plant

				}
			}
		}
	}

	int Ecosystem::AnimalEating(){
		//Herbivore
		for( int i = 0 ; i < this->terrain->get_terrainSize(); i++){ //herbivore eating
			for( int j = 0; j < this->terrain->get_terrainSize(); j++){
				if (this->terrain->Map[i][j]->get_Plant()->get_token() !=  '-'){ // if there is a plant in i,j tile
					for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
						if (this->terrain->Map[i][j]->animals[k]->get_token() == 'H' && this->terrain->Map[i][j]->animals[k]->get_isHungry()){
							Plant* plant  = this->terrain->Map[i][j]->get_Plant();
							Herbivore* temp =  (Herbivore*)this->terrain->Map[i][j]->animals[k];
							if(temp->get_count() == 0 && temp->get_inHibernation() ==  false)
								temp->Meal(plant);
						}
					}
				}
			}
		}
		for( int i = 0 ; i < this->terrain->get_terrainSize(); i++){ // carnivore eating
			for( int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					if (this->terrain->Map[i][j]->animals[k]->get_token() == 'C' && this->terrain->Map[i][j]->animals[k]->get_isHungry() && this->terrain->Map[i][j]->animals[k]->get_size() > 0){
						Carnivore* temp = (Carnivore*)this->terrain->Map[i][j]->animals[k];
						if(temp->get_inHibernation() ==  false)
							temp->Meal(this->terrain->Map[i][j],k);

					}
				}
			}
		} 
	}


	void Ecosystem::CheckHunger(){ //checking hunger at the end of the day
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* temp = this->terrain->Map[i][j]->animals[k];
					if(temp->get_token() == 'H'){ // if herbivore
						Herbivore* temp1 = (Herbivore*)temp;
						if(temp1->get_isHungry()){
							temp1->set_HungerCount(1,'+');
							if(temp1->get_count() > 0)
								temp1->set_count(1,'-');
						}
						else{
							temp1->set_HungerCount(0,'=');
							temp1->set_isHungry(false);
							temp1->set_count(7,'=');
						}	
					}
					else if(temp->get_token() == 'C'){
						Carnivore* temp1 = (Carnivore*)temp;
						if(temp1->get_isHungry())
							temp1->set_HungerCount(1,'+');

						else{
							temp1->set_HungerCount(0,'=');
							temp1->set_isHungry(false);
						}
					}
				}
			}
		}
	}
	void Ecosystem::DailyReset(){
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* temp = this->terrain->Map[i][j]->animals[k];
					if(temp->get_token() == 'C')
						temp->set_isHungry(true);
					else{
						Herbivore* temp1 = (Herbivore*)temp;
						if(temp1->get_count() == 0 ) // If herbivore has not eaten  in the last 7 days,then is hungry
							temp1->set_isHungry(true); 
						else
							temp1->set_isHungry(false);
					}
				}
			}
		}
	}

	void Ecosystem::Hibernation(){
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* animal = this->terrain->Map[i][j]->animals[k];
					if(animal->get_name() == "Bear" || animal->get_name() == "GroundHog"){
						animal->set_inHibernation(true);
					}
				}
			}
		}
	}

	void Ecosystem::outHibernation(){
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for(int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* animal = this->terrain->Map[i][j]->animals[k];
						if(animal->get_name() == "Bear" || animal->get_name() == "GroundHog"){
							animal->set_inHibernation(false);
						}
				}
			}
		}
	}
	
	void Ecosystem::increaseStats(Animal* animal){
		if(animal->get_name() == "Deer"){
			animal->set_size(1,'+');
			animal->set_speed(2,'+');
			animal->set_neededFood(2,'+');
			if(animal->get_size() > 5)
				animal->set_size(5,'='); // an to kseperasei to max
			if(animal->get_speed() > 8)
				animal->set_speed(8,'=');
			if(animal->get_neededFood() > 8)
				animal->set_neededFood(8,'=');
		}
		else if(animal->get_name() == "Rabbit"){
			animal->set_size(1,'+');
			animal->set_speed(2,'+');
			animal->set_neededFood(1,'+');
			if(animal->get_size() > 2)
				animal->set_size(2,'='); // an to kseperasei to max
			if(animal->get_speed() > 6)
				animal->set_speed(6,'=');
			if(animal->get_neededFood() > 4)
				animal->set_neededFood(4,'=');
		}
		else if(animal->get_name() == "GroundHog"){
			animal->set_size(1,'+');
			animal->set_speed(1,'+');
			animal->set_neededFood(1,'+');
			if(animal->get_size() > 3)
				animal->set_size(3,'='); // an to kseperasei to max
			if(animal->get_speed() > 5)
				animal->set_speed(5,'=');
			if(animal->get_neededFood() > 5)
				animal->set_neededFood(5,'=');
		}
		else if(animal->get_name() == "Fox"){
			Carnivore* temp = (Carnivore*)animal;
			temp->set_size(1,'+');
			temp->set_speed(1,'+');
			temp->set_neededFood(1,'+');
			temp->set_attack(1,'+');
			temp->set_defence(1,'+');
			if(temp->get_size() > 4)
				temp->set_size(4,'='); // an to kseperasei to max
			if(temp->get_attack() > 5)
				temp->set_attack(5,'=');
			if(temp->get_defence() > 5)
				temp->set_defence(5,'=');
			if(temp->get_speed() > 6)
				temp->set_speed(6,'=');
			if(temp->get_neededFood() > 5)
				temp->set_neededFood(5,'=');
		}
		else if(animal->get_name() == "Wolf"){
			Carnivore* temp = (Carnivore*)animal;
			temp->set_size(1,'+');
			temp->set_speed(2,'+');
			temp->set_neededFood(2,'+');
			temp->set_attack(2,'+');
			temp->set_defence(2,'+');
			if(temp->get_size() > 7)
				temp->set_size(7,'='); // an to kseperasei to max
			if(temp->get_attack() > 8)
				temp->set_attack(8,'=');
			if(temp->get_defence() > 6)
				temp->set_defence(6,'=');
			if(temp->get_speed() > 8)
				temp->set_speed(8,'=');
			if(temp->get_neededFood() > 8)
				temp->set_neededFood(8,'=');
		}
		else if(animal->get_name() == "Bear"){
			Carnivore* temp = (Carnivore*)animal;
			temp->set_size(2,'+');
			temp->set_speed(2,'+');
			temp->set_neededFood(2,'+');
			temp->set_attack(2,'+');
			temp->set_defence(2,'+');
			if(temp->get_size() > 10)
				temp->set_size(10,'='); // an to kseperasei to max
			if(temp->get_attack() > 10)
				temp->set_attack(10,'=');
			if(temp->get_defence() > 10)
				temp->set_defence(10,'=');
			if(temp->get_speed() > 4)
				temp->set_speed(4,'=');
			if(temp->get_neededFood() > 10)
				temp->set_neededFood(10,'=');
		}

	}

	void Ecosystem::breedingPlants(){
		point temp;
		Plant* temp1;
		Plant* plant;
		Plant* temp2;
		Seedless* temp3;
		Seeded* temp4;
		temp.x = 0;
		temp.y = 0;
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				if (this->terrain->Map[i][j]->get_Plant()->get_token() !=  '-'){
					plant = this->terrain->Map[i][j]->get_Plant();
					if (plant->get_token() !=  'M')
						temp = this->terrain->FindFreeTile(i,j,this->terrain->Map[i][j]->get_type());
					else
						temp = this->terrain->FindFreeTile(i,j,'"','^');
					if ( temp.x != i || temp.y != j){
						int random = rand() % 100 + 1;
						if ( random <= plant->get_breedingProb() ){
							if (this->terrain->Map[temp.x][temp.y]->get_Plant()->get_token() ==  'G' || this->terrain->Map[temp.x][temp.y]->get_Plant()->get_token() ==  'A'){
								temp3 = (Seedless*) this->terrain->Map[temp.x][temp.y]->get_Plant();
								delete temp3;
							}
							else{
								temp4 = (Seeded*) this->terrain->Map[temp.x][temp.y]->get_Plant();
								delete temp4;
							}
							if (plant->get_token() ==  'G')
								temp2 = new Seedless(temp.x,temp.y,"grass",5,'G',15,15,4);
							else if (plant->get_token() ==  'A')
								temp2 = new Seedless(temp.x,temp.y,"Algae",5,'A',15,15,4);
							else if (plant->get_token() ==  'O')
								temp2 =  new Seeded(temp.x,temp.y,"Oak",30,15,'O',5,20,20,15);
							else if (plant->get_token() ==  'P')
								temp2 = new Seeded(temp.x,temp.y,"Pine",40,20,'P',5,15,15,20);
							else if (plant->get_token() ==  'M')
								temp2 = new Seeded(temp.x,temp.y,"Maple",20,10,'M',2,5,5,10);
							this->terrain->Map[temp.x][temp.y]->set_Plant(temp2);

						}
					}
				}
			}
		}
	}

	void Ecosystem::growthPlants(){
		int random;
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				if(this->terrain->Map[i][j]->get_Plant()->get_token() !=  '-'){
					Plant* temp = this->terrain->Map[i][j]->get_Plant();
					random = rand() % 100 + 1;
					if(random <= temp->get_illnessProb())
						temp->set_life(temp->get_lifeFactor(),'-'); // decrease life by lifeFactor
					else
						temp->set_life(temp->get_lifeFactor(),'+');		
				}

			}
		}
	}

	void Ecosystem::AnimalBreeding(char c){ // C == carnivore h herbivore
		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for( int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* parent = this->terrain->Map[i][j]->animals[k];
					if( parent->isAdult() && parent->get_token() == c && parent->get_inHibernation() ==  false){ // an  den einai se xeimeria narkh
						if(parent->get_name() == "Deer"){
							Animal* animal = new Herbivore("Deer",i,j,2,4,4,0,2); // underage deer
							this->terrain->Map[i][j]->animals.push_back(animal);
						}
						else if( parent->get_name() == "Rabbit"){
							Animal* animal = new Herbivore("Rabbit",i,j,1,2,2,0,1); 
							this->terrain->Map[i][j]->animals.push_back(animal);	
						}
						else if( parent->get_name() == "GroundHog"){
							Animal* animal = new Herbivore("GroundHog",i,j,2,3,3,1,1); // creation of GroundHogs
							this->terrain->Map[i][j]->animals.push_back(animal);
							
						}
						else if( parent->get_name() == "Fox"){
							Animal* animal = new Carnivore("Fox",i,j,1,1,2,1,1); // creation of Fox
							this->terrain->Map[i][j]->animals.push_back(animal);
						
						}
						else if(parent->get_name() == "Wolf"){
							Animal* animal = new Carnivore("Wolf",i,j,1,2,2,2,2); // creation of Wolf
							this->terrain->Map[i][j]->animals.push_back(animal);
							
						}
						else if( parent->get_name() == "Bear"){
							Animal* animal = new Carnivore("Bear",i,j,3,4,5,6,6); // creation of underage Bear
							this->terrain->Map[i][j]->animals.push_back(animal);
						}
					}
				}

			}
		}
	}

	void Ecosystem::GrowAnimals(){


		for(int i = 0; i < this->terrain->get_terrainSize(); i++){
			for(int j = 0; j < this->terrain->get_terrainSize(); j++){
				for( int k = 0; k < this->terrain->Map[i][j]->animals.size(); k++){
					Animal* animal = this->terrain->Map[i][j]->animals[k];
					increaseStats(animal);
				}
			}
		}

	}

	void Ecosystem::breedingRepPeriod(int day){
		if(day >= 331 && day <= 60){
				//xeimeria narkh
				if(day % 18  == 0)
					AnimalBreeding('H');
				else if(day % 10 == 0)
					AnimalBreeding('C');
			}	
			else if(day > 60 && day <= 150){
				if(day % 12  == 0)
					AnimalBreeding('H');
				else if(day % 11 == 0)
					AnimalBreeding('C');
					
			}
			else if(day > 150 && day <= 240 ){
				if(day % 8  == 0)
					AnimalBreeding('H');
				else if(day % 9 == 0)
					AnimalBreeding('C');
					
			}
			else if (day > 240 && day <= 330){
				if(day % 5  == 0)
					AnimalBreeding('H');
				else if(day % 9 == 0)
					AnimalBreeding('C');
			}

			//// end of ANIMAL BREED


			if(day >= 331 && day <= 60){
				// futa den exoun
			}	
			else if(day > 60 && day <= 150){
				if (day % 10 == 0)
					breedingPlants();
			}
			else if(day > 150 && day <= 240 ){
				if (day % 10 == 0)
					breedingPlants();
				
			}
			else if (day > 240 && day <= 330){
				if (day % 20 == 0) 
					breedingPlants();
			}	

	}

	void Ecosystem::growthPeriod(int day){
		// MEGALWNOUN TA ZWAKIA

			if(day >= 331 && day <= 60){  //growth PLANTS
				if(day % 10 == 0)
					growthPlants();
			}	
			else if(day > 60 && day <= 150){
				if(day % 5 == 0)
					growthPlants();
			}
			else if(day > 150 && day <= 240 ){
				if (day % 10 == 0)
					growthPlants();
				
			}
			else if (day > 240 && day <= 330){
				if (day % 15 == 0) 
					growthPlants();
			}

			if( day >= 331 && day <= 60){
				// futa den exoun
				if(day % 30 == 0)
					GrowAnimals();
			}	
			else if( day > 60 && day <= 150){
				if(day % 20 == 0)
					GrowAnimals();
			}
			else if( day > 150 && day <= 240 ){
				if(day % 30 == 0)
					GrowAnimals();
				
			}
			else if ( day > 240 && day <= 330){
				if(day % 15 == 0)
					GrowAnimals();
			}	
	}

	void Ecosystem::RunEcosystem(int days){

		for(int i = 0; i < days; i++){
				
			if( i % 90 == 0){
				this->PrintSystem();

				if(this->dayOfyear >= 331 && this->dayOfyear <= 60)
					 cout <<  "Season is winter " << endl;
				else if( this->dayOfyear > 60 && this->dayOfyear <= 150)
					cout << "Season is spring " << endl;
				else if(this->dayOfyear > 150 && this->dayOfyear <= 240 )
					cout << "Season is  summer " << endl;
				else if ( this->dayOfyear > 240 && this->dayOfyear <= 330)
					cout << "Season is autumn " << endl;
			}

			DailyReset();
			growthPeriod(this->dayOfyear);

			// end of growth plants

			if(this->dayOfyear == 331) // season is winter
				Hibernation();
			if(this->dayOfyear == 61)
				outHibernation();

			for( int j = 0; j < 24; j++){
				AnimalMovement();
				AnimalEating();
				CheckDeadEntities();
			}
			breedingRepPeriod(this->dayOfyear);
			CheckHunger();

			this->dayOfyear++;
			this->dayOfyear = this->dayOfyear % 361 ; // initialize day of year at 0 when year changes
		}		
	}
