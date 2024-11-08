//-----------------------------------------------------------------------------------//
// Nom du projet 		: EMSY TP1 
// Nom du fichier 		: EMSY_TP1.c 
// Date de création 	: 08.11.2024
// Date de modification : xx.xx.20xx
//
// Auteur 				: Louis (LCX)
//
// Version				: 0.1
//
// Description         calcule de la surface d'un carré
//
//
// Remarques :           
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h> 
 int main() 
{ 
    float cote, surface; 
  
    // Demander à l'utilisateur de saisir la longueur du côté 
    printf("Entrez la longueur du côté du carré: "); 
    scanf("%f", &cote); 
  
    // Calculer la surface du carré
    surface = cote * cote; 
  
    // Afficher la surface 
    printf("La surface du carré est: %.2f\n", surface); 
  
    return 0; 
} 
