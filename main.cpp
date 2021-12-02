#include<iostream>
#include"class.h"

using namespace std;
int main(void){
	int terrainSize,dayofyear,days;
	string season;
	cout << "Give terrain size" <<endl;
	cin >> terrainSize;
	cout << " Give  season" << endl;
	cin >> season; 

	if( season == "winter")
		dayofyear = 331;
	else if( season == "spring")
		dayofyear = 61;
	else if( season == "summer")
		dayofyear = 151;
	else if(season ==   "autumn")
		dayofyear = 241;
	
	cout << "Give days " <<endl;
	cin >> days;


	Ecosystem* ecosystem = new Ecosystem(terrainSize,dayofyear);
	ecosystem->get_Terrain()->GenerateMap();
	ecosystem->get_Terrain()->GenerateRiver();
	ecosystem->get_Terrain()->GenerateLake();
	ecosystem->get_Terrain()->GenerateHills();
	ecosystem->get_Terrain()->GenerateMeadow();

	int G,A,O,P,M;
	int D,R,GH,S,F,B,W;
	cout << "Give number of Grass,Algae,Oak,Pine,Maple " << endl;
	cin >> G >> A >> O >> M >> P ;
	ecosystem->PlacePlants(G,A,O,M,P);
	ecosystem->get_Terrain()->print();
	cout << " Give number of Deers,Rabbits,GroundHogs,Salmons,Fox,Bear,Wolves " <<endl;
		
	cin >> D >> R  >> GH >> S >> F >> B >> W;
	ecosystem->PlaceAnimals(D,R,GH,S,F,B,W);


	ecosystem->PrintSystem();
	ecosystem->RunEcosystem(days);
	ecosystem->PrintSystem();

	delete ecosystem;



}
