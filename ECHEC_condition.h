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



bool Si_N_P_P_E(void){
	//renvoi true si le deplacement sur la case donné ne provoque pas d'echec 
	
	return true;

	}



bool Si_P_N_P(int x,int y,int posit,int * actu){
	//renvoi true si il y a une piece noire presente sur la case donné
	
	if (( actu[deplacement(x,y,posit)]>=1 )&&( actu[deplacement(x,y,posit)]<=6 )){
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



bool Si_P_Nr_Pass(int x,int y,int posit,int * actu){
	
	//renvoi true si il y a un pion blanc passant present sur la case donné
	
	if ( actu[deplacement(x,y,posit)]==13 ){
		return true;		
		}
	
	return false;

	}


// conditions fou



