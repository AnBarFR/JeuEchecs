# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include "ECHEC_condition.h"
#include "ECHEC_main.h"

// case vide : 0
// T noir : 1
// C noir : 2
// F noir : 3
// D noir : 4
// R noir : 5
// P noir : 6

// T blanc : 8
// C blanc : 9
// F blanc : 10
// D blanc : 11
// R blanc : 12
// P blanc : 7


int main(void){
					   
	int echequier[] = { 1, 2, 3, 4, 5, 3, 2, 1,
						6, 6, 6, 6, 6, 6, 6, 6,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0,
					    7, 7, 7, 7, 7, 7, 7, 7,
					    8, 9,10,11,12,10, 9, 8};
					   
	//~ int echequier[] = { 1, 0, 3, 0, 5, 0, 0, 1,
						//~ 6, 6, 0, 0, 2, 6, 6, 6,
						//~ 0, 0, 2, 0, 6, 0, 0, 0,
						//~ 0, 0, 0, 6, 7, 0, 0, 0,
						//~ 4, 0, 0, 7, 0, 0, 0, 0,
						//~ 7, 0, 0, 0, 0, 9, 0, 0,
					    //~ 0, 0, 0,10, 0, 7, 7, 7,
					    //~ 0, 8, 0,11,12,10, 0, 8};
					    
					    //13 = pion passant noir
					    //14 = pion passant blanc
	
	int table_coup[64] = {0};
	char case_selec[2];
	char case_desti[2];
	int nbr_tour = 1 ;
	//~ int couleur_tour ; // 0 = noir   1 = blanc

while (true){
	printf("\n------------------------------- \n\n");
	if (nbr_tour%2==1) {
		printf("Tour n° %d , les blancs jouent\n",nbr_tour);
		//~ couleur_tour = 1 ;
	}else{
		printf("Tour n° %d , les noirs jouent\n",nbr_tour);
		//~ couleur_tour = 0 ;
	}
	for (int i = 0 ; i <= 63 ; i++){
		table_coup[i] = 0 ;
	}
	affiche_echeq_piece(echequier);
	
	  
	  printf("Entrez la case : ");
	  
	if ( scanf("%s", case_selec) != 1 ){
		printf("Erreur dans la saisi ");
		continue;
	}
	if (numer_case(case_selec)==-1){
		printf("Entrez une case existante ");
		continue;
	}

	if ( echequier[numer_case(case_selec)] == 0 ){
		printf("Case vide");
		continue;
	}
		
	if ((nbr_tour%2==0) && (Si_P_B_P(0,0,numer_case(case_selec),echequier)) ){
		printf("Choisisez une piece noir");
		continue;
	}
	if ((nbr_tour%2==1) && (Si_P_N_P(0,0,numer_case(case_selec),echequier)) ){
		printf("Choisisez une piece blanche");
		continue;
	}
	
	//~ printf("case selectionne %s\n\n",case_selec);
	//~ printf("case numero %d\n\n",numer_case(case_selec));
	
	nom_piece(echequier[numer_case(case_selec)]);
	
	coup_possible(  echequier[numer_case(case_selec)]  , numer_case(case_selec)  , table_coup , echequier);
	
	//~ affiche_coup(table_coup);
	
	printf("Entrez la destination : ");
	  
	if ( scanf("%s", case_desti) != 1 ){
		printf("Erreur dans la saisi ");
	}
	
	if ((table_coup[numer_case(case_desti)] == 1)||(table_coup[numer_case(case_desti)] == 2)){
		echequier[numer_case(case_desti)] = echequier[numer_case(case_selec)] ;
		echequier[numer_case(case_selec)] = 0 ;
		printf("Deplacement effectuer\n\n");
		nbr_tour++;
		
		}else{
			printf("Deplacement impossible\n\n");
		}
	

}

}





