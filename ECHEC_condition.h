int deplacement(int x,int y,int posit){
	
	if (((posit+x)/8)!=(posit/8)){
		return -1;
	}
	if (((posit + x - y * 8)<0)||((posit + x - y * 8)>63)){
		return -1;
	}
	
	posit = posit + x - y * 8 ;
	return posit ;
	
}


// condition pions

bool Si_C_E(int x,int y,int posit){
	//renvoi true si la case donné existe sur le plateau
	
	if (((posit+x)/8)!=(posit/8)){
		return false;
	}
	if (((posit + x - y * 8)<0)||((posit + x - y * 8)>63)){
		return false;
	}

	return true;
	
	}



bool Si_A_P_P(int x,int y,int posit,int * actu){
	//renvoi true si aucune piece n'est presente sur la case donné
	
	if ( actu[deplacement(x,y,posit)]==0){
		return true;		
		}
	return false;
	
	}
	
	
	
bool Si_R_I_B(int posit){
	//renvoi true si la case est sur la rangé initial des pions blanc
	
	if ((posit<=55)&&(posit>=48)){
		return true;		
		}
	return false;
	
	}
	
	
bool Si_R_I_N(int posit){
	//renvoi true si la case est sur la rangé initial des pions noir
	
	if ((posit<=15)&&(posit>=8)){
		return true;		
		}
	return false;
	
	}

//~ void affiche_echeq(int* actuel);

bool Si_N_P_P_E(int posix,int posiy,int posit,int * actu, int couleur){
	//renvoi true si le deplacement sur la case donné ne provoque pas d'echec 
	int echequier[64] = {0};
	for (int i = 0 ; i <= 63 ; i++ ){
		echequier[i] = actu[i];
	}
	echequier[deplacement(posix,posiy,posit)] = echequier[posit] ;
	echequier[posit] = 0 ;
	//~ affiche_echeq(echequier);
	
	if (couleur == 0){ // si aux noir de jouer
		for (int i = 0 ; i <= 63 ; i++ ){
			if (echequier[i] == 5){
				posit = i ;
				//~ printf("posit roi noir : %d \n",posit);
			}
		}
	}else{
		for (int i = 0 ; i <= 63 ; i++ ){
			if (echequier[i] == 12){
				posit = i ;
				//~ printf("posit roi blanc : %d \n",posit);
			}
		}
	}
	
	
	int x ;
	int y ;
	int l ;
	int m ;
	
		//tour et reine
		for ( int i = 0; i <= 3 ; i++ ){
				x = (1-2*(i%2))*i/2 ;
				y = (1-2*(i%2))*(3-i)/2 ;
				l  = x ;
				m  = y ;
	            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)){
					x = x + l;
					y = y + m ;
				}
	            if ( Si_C_E(x,y,posit)){
					if (couleur == 0){ // si aux noir de jouer
						if (echequier[deplacement(x,y,posit)]==8 || echequier[deplacement(x,y,posit)]==11){
							return false;
							//~ printf("tour et reine \n");
						}
					}else{
						if (echequier[deplacement(x,y,posit)]==1 || echequier[deplacement(x,y,posit)]==4){
							return false;
						}
					}
				}
		}
		//fou et reine
		for ( int i = 0; i <= 3 ; i++ ){
			x =  (1-2*(i%2)) ;
			y =  (1-2*(i/2)) ;
			l  = x ;
			m  = y ;
				
            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier) ){
				x = x + l;
				y = y + m ;
				}
            if ( Si_C_E(x,y,posit)){
					if (couleur == 0){ // si aux noir de jouer
						if (echequier[deplacement(x,y,posit)]==10 || echequier[deplacement(x,y,posit)]==11){
							return false;
						}
					}else{
						if (echequier[deplacement(x,y,posit)]==3 || echequier[deplacement(x,y,posit)]==4){
							return false;
						}
					}
			}
		}
		//roi 
		for ( int i = 0; i <= 7 ; i++ ){
				x = 1 - ((13-i)/3)%3 ;
				y =  1- ((i+2)%3) ;
				
		        if (  (Si_C_E(x,y,posit))){
					if (couleur == 0){ // si aux noir de jouer
						if (echequier[deplacement(x,y,posit)]==12 ){
							return false;
						}
					}else{
						if (echequier[deplacement(x,y,posit)]==5 ){
							return false;
						}
					}
				}
		}
		//cavalier 
		for ( int i = 0; i <= 7 ; i++ ){
				x = (1+(i/4)) * (1-2*((i/2)%2)) ;
				y =  (2-(i/4)) * (-1+2*(i%2)) ;
				
		        if (  (Si_C_E(x,y,posit)) ){
					if (couleur == 0){ // si aux noir de jouer
						if (echequier[deplacement(x,y,posit)]==9 ){
							return false;
						}
					}else{
						if (echequier[deplacement(x,y,posit)]==2 ){
							return false;
						}
					}
				}
		}
		//pion
		if (couleur == 0){ // si aux noir de jouer
			if ( Si_C_E(1,-1,posit)){
				if (echequier[deplacement(1,-1,posit)]==7 ){
					return false;
				}
			}
			if ( Si_C_E(-1,-1,posit)){
				if (echequier[deplacement(-1,-1,posit)]==7 ){
					return false;
				}
			}

		}else{
			if ( Si_C_E(1,1,posit)){
				if (echequier[deplacement(1,1,posit)]==6 ){
					return false;
				}
			}
			if ( Si_C_E(-1,1,posit)){
				if (echequier[deplacement(-1,1,posit)]==6 ){
					return false;
				}
			}
		}
	
	return true;

	}



bool Si_P_N_P(int x,int y,int posit,int * actu){
	//renvoi true si il y a une piece noire presente sur la case donné
	
	if (( actu[deplacement(x,y,posit)]>=1 )&&( actu[deplacement(x,y,posit)]<=6 )){
		return true;		
		}
	
	return false;

	}
	
bool Si_R_N_P(int x,int y,int posit,int * actu){
	//renvoi true si il y a le roi noire present sur la case donné
	
	if ( actu[deplacement(x,y,posit)]==5 ){
		return true;		
		}
	
	return false;

	}


bool Si_P_B_P(int x,int y,int posit,int * actu){
	//renvoi true si il y a une piece blanche presente sur la case donné
	
	if (( actu[deplacement(x,y,posit)]>=7 )&&( actu[deplacement(x,y,posit)]<=12 )){
		return true;		
		}
	
	return false;

	}
	
bool Si_R_B_P(int x,int y,int posit,int * actu){
	//renvoi true si il y a le roi blanc present sur la case donné
	
	if (actu[deplacement(x,y,posit)]==12){
		return true;		
		}
	
	return false;

	}



bool Si_P_Nr_Pass(int x,int y,int posit,int * actu){
	
	//renvoi true si il y a un pion blanc passant present sur la case donné
	
	if ( actu[deplacement(x,y,posit)]==13 ){
		return true;		
		}
	
	return false;

	}


// conditions fou



