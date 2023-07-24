

int numer_case(char* code){
	//prend le code de la case sous forme ex:"a7" et renvoie son 
	//emplacement dans la liste echequier[] sous forme ex:"8"
	if((code[0]<'a')||(code[0]>'h')){
		return -1 ;
		}
	if((code[1]<'1')||(code[1]>'8')){
		return -1 ;
		}
	return (code[0]-'a'+('8'-code[1])*8);
	
}



void affiche_echeq(int* actuel){
	//prends le tableau echequier[] en entrée et affiche l'échequier avec
	// la case a8 dans le coin haut gauche  et la case h1 dans le coin bas droite
	
	for (int j = 0 ; j <= 7 ; ++j){
		for (int k = 0 ; k <= 7 ; ++k){
			printf(" %2d ",actuel[k+j*8]);
		}
		printf("\n");
	}
	printf("\n");
}



void affiche_echeq_piece(int* actuel){
	//prends le tableau echequier[] en entrée et affiche l'échequier avec
	// la case a8 dans le coin haut gauche  et la case h1 dans le coin bas droite
	
	
	for (int j = 0 ; j <= 7 ; ++j){
		printf( "%d | ", 8-j );
		for (int k = 0 ; k <= 7 ; ++k){
			switch( actuel[k+j*8] ) {
	        case 1:
	            printf( " ♜ " );
	            break;
	        case 2:
	            printf( " ♞ " );
	            break;
	        case 3:
	            printf( " ♝ " );
	            break;
	        case 4:
	            printf( " ♛ " );
	            break;
	        case 5:
	            printf( " ♚ " );
	            break;
	        case 6:
	            printf( " ♟ " );
	            break;
	        case 7:
	            printf( " ♙ " );
	            break;
	        case 8:
	            printf( " ♖ " );
	            break;
	        case 9:
	            printf( " ♘ " );
	            break;
	        case 10:
	            printf( " ♗ " );
	            break;
	        case 11:
	            printf( " ♕ " );
	            break;
	        case 12:
	            printf( " ♔ " );
	            break;
	        default:
	            printf( " - " );
	    }
	}
		printf(" \n");
	}
	printf("   ――――――――――――――――――――――――\n");
	printf("    ");
	for (int k = 0 ; k <= 7 ; ++k){
		printf(" %c ",'a'+k);
	}
	printf("\n");
}



void affiche_coup(int* actuel){
	//prends le tableau table_coup[] en entrée et l'affiche
	
	for (int j = 0 ; j <= 7 ; ++j){
		for (int k = 0 ; k <= 7 ; ++k){
			printf(" %2d ",actuel[k+j*8]);
		}
		printf("\n");
	}
	printf("\n");
}



void coup_possible(int nume, int posit, int * table_coup, int* echequier){
	        int x ;
            int y ;
	        int l ;
            int m ;
	//prends le nombre associé à une piece ( int nume ) ,
	// son emplacement dans la liste echequier[] ( int posit ) ,
	//  l'adresse du tableau table_coup[] ( int * table_coup ) ,
	//  l'adresse du tableau echequier[] ( int * echequier ) ,
	//
	// et modifie ce tableau pour afficher la case de la piece selectionné avec 
	// son nombre, afficher les cases inaccessible avec '0' et afficher
	// les cases accessibles avec '1' 
	table_coup[posit] = 99 ;
    switch( nume ) {
        case 1:
	            //tour noire ♜
            
				for ( int i = 0; i <= 3 ; i++ ){
						x = (1-2*(i%2))*i/2 ;
						y = (1-2*(i%2))*(3-i)/2 ;
						l  = x ;
						m  = y ;
			            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 1 ;
							x = x + l;
							y = y + m ;
						}
			            if ( Si_C_E(x,y,posit) && Si_P_B_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 2 ;
				}	}
            break;
        case 2:
	            //cavalier noir ♞ 
            
				for ( int i = 0; i <= 7 ; i++ ){
						x = (1+(i/4)) * (1-2*((i/2)%2)) ;
						y =  (2-(i/4)) * (-1+2*(i%2)) ;
						
				        if (  (Si_C_E(x,y,posit))   &&  Si_N_P_P_E()  ){
							if (   Si_A_P_P(x,y,posit,echequier) ){
								table_coup[deplacement(x,y,posit)] = 1 ;
								}
							if ( Si_P_B_P(x,y,posit,echequier) ){
								table_coup[deplacement(x,y,posit)] = 2 ;
								}
				}	}
            break;
        case 3:
	            //fou noir ♝ 
				for ( int i = 0; i <= 3 ; i++ ){
					x =  (1-2*(i%2)) ;
					y =  (1-2*(i/2)) ;
					l  = x ;
					m  = y ;
						
		            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 1 ;
						x = x + l;
						y = y + m ;
						}
		            if ( Si_C_E(x,y,posit) && Si_P_B_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 2 ;}
					}
            break;
        case 4:
            //dame noire ♛ 
				for ( int i = 0; i <= 3 ; i++ ){
					x =  (1-2*(i%2)) ;
					y =  (1-2*(i/2)) ;
					l  = x ;
					m  = y ;
						
		            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 1 ;
						x = x + l;
						y = y + m ;
						}
		            if ( Si_C_E(x,y,posit) && Si_P_B_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 2 ;}
					}
				for ( int i = 0; i <= 3 ; i++ ){
						x = (1-2*(i%2))*i/2 ;
						y = (1-2*(i%2))*(3-i)/2 ;
						l  = x ;
						m  = y ;
			            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 1 ;
							x = x + l;
							y = y + m ;
						}
			            if ( Si_C_E(x,y,posit) && Si_P_B_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 2 ;
				}	}
            
            break;
        case 5:
            //roi noir ♚ 
			for ( int i = 0; i <= 7 ; i++ ){
					x = 1 - ((13-i)/3)%3 ;
					y =  1- ((i+2)%3) ;
					
			        if (  (Si_C_E(x,y,posit))   &&  Si_N_P_P_E()  ){
						if (   Si_A_P_P(x,y,posit,echequier) ){
							table_coup[deplacement(x,y,posit)] = 1 ;
							}
						if ( Si_P_B_P(x,y,posit,echequier) ){
							table_coup[deplacement(x,y,posit)] = 2 ;
							}
					}
			}
            break;
        case 6:
	            //pion noir ♟
		        if (  (Si_C_E(0,-1,posit))  &&  Si_A_P_P(0,-1,posit,echequier)  &&  Si_N_P_P_E()  ){
					table_coup[deplacement(0,-1,posit)] = 1 ;
				}
		        if (  Si_C_E(0,-2,posit) && Si_A_P_P(0,-2,posit,echequier) && Si_A_P_P(0,1,posit,echequier)  && Si_R_I_N(posit) &&  Si_N_P_P_E() ){
					table_coup[deplacement(0,-2,posit)] = 1 ;
				}
		        if (  Si_C_E(1,-1,posit)  &&   (   Si_P_B_P(1,-1,posit,echequier)  ||  Si_P_Nr_Pass(1,0,posit,echequier) )  &&  Si_N_P_P_E()  ){
					table_coup[deplacement(1,-1,posit)] = 2 ;
				} 
		        if (  Si_C_E(-1,-1,posit)  &&   (   Si_P_B_P(-1,-1,posit,echequier)  ||  Si_P_Nr_Pass(-1,0,posit,echequier) )  &&  Si_N_P_P_E()   ){
					table_coup[deplacement(-1,-1,posit)] = 2 ;
				}
				
            break;
        case 7:
				//pion blanc ♙
		        if (  (Si_C_E(0,1,posit))  &&  Si_A_P_P(0,1,posit,echequier)  &&  Si_N_P_P_E()  ){
					table_coup[deplacement(0,1,posit)] = 1 ;
				}
		        if (  Si_C_E(0,2,posit) && Si_A_P_P(0,2,posit,echequier) && Si_A_P_P(0,1,posit,echequier)  && Si_R_I_B(posit) &&  Si_N_P_P_E() ){
					table_coup[deplacement(0,2,posit)] = 1 ;
				}
		        if (  Si_C_E(1,1,posit)  &&   (   Si_P_N_P(1,1,posit,echequier)  ||  Si_P_Nr_Pass(1,0,posit,echequier) )  &&  Si_N_P_P_E()  ){
					table_coup[deplacement(1,1,posit)] = 2 ;
				} 
		        if (  Si_C_E(-1,1,posit)  &&   (   Si_P_N_P(-1,1,posit,echequier)  ||  Si_P_Nr_Pass(-1,0,posit,echequier) )  &&  Si_N_P_P_E()   ){
					table_coup[deplacement(-1,1,posit)] = 2 ;
				}
	        
            break;
        case 8:
				// tour blanche ♖ 
				for ( int i = 0; i <= 3 ; i++ ){
						x = (1-2*(i%2))*i/2 ;
						y = (1-2*(i%2))*(3-i)/2 ;
						l  = x ;
						m  = y ;
			            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 1 ;
							x = x + l;
							y = y + m ;
						}
			            if ( Si_C_E(x,y,posit) && Si_P_N_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 2 ;
				}	}
				
            break;
        case 9:
				//cavalier blanc ♘ 
				for ( int i = 0; i <= 7 ; i++ ){
						x = (1+(i/4)) * (1-2*((i/2)%2)) ;
						y =  (2-(i/4)) * (-1+2*(i%2)) ;
						
				        if (  (Si_C_E(x,y,posit))   &&  Si_N_P_P_E()  ){
							if (   Si_A_P_P(x,y,posit,echequier) ){
								table_coup[deplacement(x,y,posit)] = 1 ;
								}
							if ( Si_P_N_P(x,y,posit,echequier) ){
								table_coup[deplacement(x,y,posit)] = 2 ;
								}
				}	}
            break;
        case 10:
				//  fou blanc ♗
				for ( int i = 0; i <= 3 ; i++ ){
					x =  (1-2*(i%2)) ;
					y =  (1-2*(i/2)) ;
					l  = x ;
					m  = y ;
						
		            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 1 ;
						x = x + l;
						y = y + m ;
						}
		            if ( Si_C_E(x,y,posit) && Si_P_N_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 2 ;}
					}
            break;
        case 11:
	            //	dame blanche ♕ 
				for ( int i = 0; i <= 3 ; i++ ){
					x =  (1-2*(i%2)) ;
					y =  (1-2*(i/2)) ;
					l  = x ;
					m  = y ;
						
		            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 1 ;
						x = x + l;
						y = y + m ;
						}
		            if ( Si_C_E(x,y,posit) && Si_P_N_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
						table_coup[deplacement(x,y,posit)] = 2 ;}
					}
				for ( int i = 0; i <= 3 ; i++ ){
						x = (1-2*(i%2))*i/2 ;
						y = (1-2*(i%2))*(3-i)/2 ;
						l  = x ;
						m  = y ;
			            while ( Si_C_E(x,y,posit) && Si_A_P_P(x, y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 1 ;
							x = x + l;
							y = y + m ;
						}
			            if ( Si_C_E(x,y,posit) && Si_P_N_P(x,y,posit,echequier)  &&  Si_N_P_P_E()){
							table_coup[deplacement(x,y,posit)] = 2 ;
				}	}
            
            
            break;
        case 12:
            //	roi blanc ♔ 
            
			for ( int i = 0; i <= 7 ; i++ ){
					x = 1 - ((13-i)/3)%3 ;
					y =  1- ((i+2)%3) ;
					
			        if (  (Si_C_E(x,y,posit))   &&  Si_N_P_P_E()  ){
						if (   Si_A_P_P(x,y,posit,echequier) ){
							table_coup[deplacement(x,y,posit)] = 1 ;
							}
						if ( Si_P_N_P(x,y,posit,echequier) ){
							table_coup[deplacement(x,y,posit)] = 2 ;
							}
					}
			}
            
            break;
        default:
            printf( "Aucune piece\n" );
    }
	
}



void nom_piece(int nume){
	//prends le nombre associé à une piece ( pris à l'emplacement dans la liste echequier[] de la case
	// selectionné) et affiche le nom de la piece
	
	//~ printf( "%d : ",nume);
    switch( nume ) {
        case 1:
            printf( "tour noire ♜ \n" );
            break;
        case 2:
            printf( "cavalier noir ♞ \n" );
            break;
        case 3:
            printf( "fou noir ♝ \n" );
            break;
        case 4:
            printf( "dame noire ♛ \n" );
            break;
        case 5:
            printf( "roi noir ♚ \n" );
            break;
        case 6:
            printf( "pion noir ♟ \n" );
            break;
        case 7:
            printf( "pion blanc ♙ \n" );
            break;
        case 8:
            printf( "tour blanche ♖ \n" );
            break;
        case 9:
            printf( "cavalier blanc ♘ \n" );
            break;
        case 10:
            printf( "fou blanc ♗ \n" );
            break;
        case 11:
            printf( "dame blanche ♕ \n" );
            break;
        case 12:
            printf( "roi blanc ♔ \n" );
            break;
        default:
            printf( "Aucune piece\n" );
    }
    //~ printf("\n");
}



