#include<iostream>
#include"class.h"
#define HILLS 7
	
	using namespace std;
	Terrain:: Terrain(){}
	Terrain:: Terrain( int terrainSize ){this->terrainSize = terrainSize;}
	int Terrain::get_terrainSize()const{return this->terrainSize;}

	Terrain::~Terrain(){
		for(int i = 0; i < terrainSize ; i++){
			for (int j = 0; j < terrainSize; j++){
				for (int k = 0; k < Map[i][j]->animals.size() ; k++){
					delete Map[i][j]->animals[k];
				}
				delete Map[i][j];
			}
		}
	}

	void Terrain:: PrintPlantStatistics(){
		int count = 0;
		for(int i = 0; i < terrainSize; i++){
			for( int j = 0; j < terrainSize; j++)
				if(this->Map[i][j]->get_Plant()->get_token() != '-')
					count++;
		}
		cout << "The number of plants in this terrain is " << count << endl;
	}
	
	point Terrain::FindFreeTile(int x, int y,char t){
		point temp;
		temp.x = x;
		temp.y = y;
		if ( x-1 >= 0)
			if (this->Map[x-1][y]->get_Plant()->get_token() == '-' && this->Map[x-1][y]->get_type() == t){
				temp.x--;
				return temp;
			}
		if ( x+1 <= this->terrainSize - 1)
			if(this->Map[x+1][y]->get_Plant()->get_token() == '-' && this->Map[x+1][y]->get_type() == t ){
				temp.x++;
				return temp;
			}
		if ( y-1 >= 0)
			if (this->Map[x][y-1]->get_Plant()->get_token() == '-' && this->Map[x][y-1]->get_type() == t ){
				temp.y--;
				return temp;
			}
		if ( y+1 <= this->terrainSize -1)
			if (this->Map[x][y+1]->get_Plant()->get_token() == '-' && this->Map[x][y+1]->get_type() == t ){
				temp.y++;
				return temp;
			}
		return temp;
	}

	point Terrain::FindFreeTile(int x, int y,char t1,char t2){
		point temp;
		temp.x = x;
		temp.y = y;
		if ( x-1 >= 0)
			if (this->Map[x-1][y]->get_Plant()->get_token() == '-' && (this->Map[x-1][y]->get_type() == t1 || this->Map[x-1][y]->get_type() == t2) ){
				temp.x--;
				return temp;
			}
		if ( x+1 <= this->terrainSize - 1)
			if(this->Map[x+1][y]->get_Plant()->get_token() == '-' && (this->Map[x+1][y]->get_type() == t1 || this->Map[x+1][y]->get_type() == t2) ){
				temp.x++;
				return temp;
			}
		if ( y-1 >= 0)
			if (this->Map[x][y-1]->get_Plant()->get_token() == '-' && (this->Map[x][y-1]->get_type() == t1 || this->Map[x][y-1]->get_type() == t2) ){
				temp.y--;
				return temp;
			}
		if ( y+1 <= this->terrainSize -1)
			if (this->Map[x][y+1]->get_Plant()->get_token() == '-' && (this->Map[x][y+1]->get_type() == t1 || this->Map[x][y+1]->get_type() == t2) ){
				temp.y++;
				return temp;
			}
		return temp;
	}

	void Terrain::PrintAnimalStatistics(){
		int counth = 0;
		int countc = 0;
		int count = 0;
		Animal* temp;
		for(int i = 0; i < terrainSize; i++){
			for( int j = 0; j < terrainSize; j++){
				for(int k = 0; k < this->Map[i][j]->animals.size(); k++){
					temp = this->Map[i][j]->animals[k];
					count++;
					if(temp->get_token() == 'C')
						countc++;
					else if( temp->get_token() == 'H')
						counth++;
				}
			}
		}
		cout << "Animals in this terrain are " << count << endl;
		cout << "Carnivores in this terrain are " <<  countc << endl;
		cout << "Herbivores in this terrain are " << counth << endl;
	}

	void Terrain:: print(){
		for(int i = 0; i < terrainSize; i++){
			for( int j = 0; j < terrainSize; j++){
				if(this->Map[i][j]->get_Plant()->get_token() == '-')
					cout << this->Map[i][j]->get_type()  << " ";

				else
					cout << this->Map[i][j]->get_Plant()->get_token() << " "; 	
			}
			cout << endl;
		}
	}


	void Terrain:: GenerateMap(){
		this->Map = new Tile**[terrainSize];
		for(int i = 0; i < terrainSize ; i++){
			this->Map[i] = new Tile*[terrainSize];
			for (int j = 0; j < terrainSize; j++)
				this->Map[i][j] = new Tile();				
		}
	}

	void Terrain::GenerateRiver(){
		srand(time(NULL));
		int random =  5 + rand() %  (((terrainSize -5) + 1) - 5); // generate numbers at [5, terrainSize -5]
		cout << random << endl;
		Map[0][random -1 ]->set_type('#'); // creator of array's maybe is an  idiot so we must decrease the index by one
		int j = random - 1; // column

		for( int N = 0; N < terrainSize - 1; N++){
			random = rand() % 10 + 1;
			if( random <= 3  ){
				int left = rand() %  2; // propabillity 50%
				int step = rand() % 2 + 1;				
				if( left == 1 && j > 0 ){
					Map[N][j -1 ]->set_type('#');
					j--;		
					if( step == 2 && j > 0 ){
						Map[N][j-1]->set_type('#');
						j--; //  decreasing index for columns
					}
						
				} // river left
				else if( left == 0 && j < terrainSize - 1 ){ // river goes right if left = 0
					Map[N][j + 1]->set_type('#');
					j++;
					if(step == 2 &&  j < terrainSize - 1 ){
						Map[N][j + 1]->set_type('#');
						j++;
					} //increasing index for columns
				}

			} 
			Map[N+1][j]->set_type('#'); // river goes down with propabillity 70%

		}
	}

	void Terrain::GenerateLake(){
		int x,y;
		int lakesize;
		cout << "Give lake size" << endl;
		cin >> lakesize;
		x = rand() % terrainSize;
		y = rand() % terrainSize;

		for( int i  =  x; i <  terrainSize && i < lakesize + x; i++){
			for( int j = y; j < terrainSize && j < lakesize + y; j++)
				Map[i][j]->set_type('#');
		}
	}

	void Terrain::GenerateHills(){

		int x,y;
		for( int k = 0 ; k < HILLS; k++){	
			int hillsize = rand() % 3 + 2;
			x = rand() % terrainSize;
			y = rand() % terrainSize;
			for( int i  =  x; i <  terrainSize && i < hillsize + x; i++){
				for( int j = y; j < terrainSize && j < hillsize + y; j++){
					if( Map[i][j]->get_type() == '-')
						Map[i][j]->set_type('^');
				}
			}
		}
		
	}

	void Terrain:: GenerateMeadow(){

		for( int i = 0; i < terrainSize; i++){
			for( int j = 0; j < terrainSize; j++){
				if( Map[i][j]->get_type() != '#' && Map[i][j]->get_type() != '^')
					Map[i][j]->set_type('"');
			}
		}
	}
	
