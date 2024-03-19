#include <vector>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <'modele.h'>
#include <random>
using namespace std;

typedef vector<vector<int> > Plateau;

int main(){
    return 0;
}

/** Des fonctions peuvent être ajoutés à ce fichier si besoin est (fonctions pour mettre à jour le score par exemple)
 */

/** Puissance
 * @param x un nombre de type double
 * @param n un entier
 * @return le nombre x^n de type double
**/
double puissance(double x, int n) {
   if(n==0 or x==1){
       return 1;
   }
	else{
        return x*puissance(x, n-1);
    }
}

/** génère un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide(){
	Plateau plateauVide = Plateau(4);
	for(int i = 0; i<plateauVide.size(); i++){
    	plateauVide[i] = {0,0,0,0};
	}
	return plateauVide;
}

/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial(){
	srand ( time(NULL) );
	Plateau p = plateauVide();
	for(int i = 1; i<3; i++){  /* 2 cases */
    	int r = rand()%4;
    	int d = rand()%4;
    	while(p[r][d] > 0){  /*pour ne pas tomber 2 fois sur la meme case, sachant qu'une case deja remplie est non nul*/
        	r = rand()%4;
        	d = rand()%4;
    	}
    	p[r][d] = 2;
	}
	return p;
}  

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxouQuatre() {
	srand ( time(NULL) );
	int r;
	r = rand()%10;
	if (r == 0){   
    	return 4;
    }
	else{
        return 2;
	}
}

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau){
   for(int i = 0; i < plateau.size(); i++){
       for(int j = 1; j < plateau[i].size(); j++){
           if(plateau[i][j-1] == plateau[i][j]){
               plateau[i][j-1] = plateau[i][j-1]*2;
               plateau[i][j] = 0;
           }
           while(plateau[i][j-1] == 0){
               plateau[i][j-1] = plateau[i][j];
               plateau[i][j] = 0;
           }
       }
   }
    return plateau;
}

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau){
    for(int i = 0; i < plateau.size(); i++){
       for(int j = 0; j < plateau[i].size()-1; j++){
           if(plateau[i][j+1] == 0){
               plateau[i][j+1] = plateau[i][j];
               plateau[i][j] = 0;
           }
           if(plateau[i][j+1] == plateau[i][j]){
               plateau[i][j+1] = plateau[i][j+1]*2;
               plateau[i][j] = 0;
           }
       }
   }
    return plateau;  
}

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau){
    for(int i = 1; i < plateau.size(); i++){
        for(int j = 0; plateau[i].size(); j++){
            if(plateau[i-1][j] == 0){
                plateau[i-1][j] = plateau[i][j];
                plateau[i][j] = 0;
            }
            if(plateau[i-1][j] == plateau[i][j]){
                plateau[i-1][j] = plateau[i][j]*2;
                plateau[i][j] = 0;
            }
        }
    }
    return plateau;
}