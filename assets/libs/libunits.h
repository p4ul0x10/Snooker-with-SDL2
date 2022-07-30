void rpvsmm(SDL_Renderer *pvsm, int pm[]){
	
    int n0, n1, wpx = 0;
   
	SDL_Surface *Surface;
    SDL_Texture *Texture;
	SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
	SDL_Rect Texture_rect;

    Texture_rect.w = 30;
    Texture_rect.h = 30;
    
     n0 = pm[1];
     n1 = pm[0];
    
	     if(n0 == 0){
	         Surface = IMG_Load("assets/images/nums/num0.jpeg");
		
	     }else if(n0 == 1){
	         Surface = IMG_Load("assets/images/nums/num1.jpeg");
		
	     }else if(n0 == 2){
	         Surface = IMG_Load("assets/images/nums/num2.jpeg");
		
	     }else if(n0 == 3){
	         Surface = IMG_Load("assets/images/nums/num3.jpeg");
	         
	     }else if(n0 == 4){
	         Surface = IMG_Load("assets/images/nums/num4.jpeg");
		
	     }else if(n0 == 5){
	         Surface = IMG_Load("assets/images/nums/num5.jpeg");
		
	     }else if(n0 == 6){
	         Surface = IMG_Load("assets/images/nums/num6.jpeg");
		
	     }else if(n0 == 7){
	         Surface = IMG_Load("assets/images/nums/num7.jpeg");
	         
	     }else if(n0 == 8){
	         Surface = IMG_Load("assets/images/nums/num8.jpeg");
		
	     }else if(n0 == 9){
	         Surface = IMG_Load("assets/images/nums/num9.jpeg");
		
	     }
	   	
	    //start player img
	    SDL_Rect Texture_p;
	    Texture_p.w = 20;
	    Texture_p.h = 20;
		Texture_p.x = 255;
		Texture_p.y = 478;
	
		Texture = SDL_CreateTextureFromSurface(pvsm, Surface);
		SDL_FreeSurface(Surface);
	
		SDL_RenderCopy(pvsm, Texture, NULL, &Texture_p);
		SDL_DestroyTexture(Texture);
		//end player img
        
        if(n1 > 0){
        	
	     if(n1== 1){
	         Surface = IMG_Load("assets/images/nums/num1.jpeg");
		
	     }else if(n1 == 2){
	         Surface = IMG_Load("assets/images/nums/num2.jpeg");
		
	     }else if(n1 == 3){
	         Surface = IMG_Load("assets/images/nums/num3.jpeg");
	         
	     }else if(n1 == 4){
	         Surface = IMG_Load("assets/images/nums/num4.jpeg");
		
	     }else if(n1 == 5){
	         Surface = IMG_Load("assets/images/nums/num5.jpeg");
		
	     }else if(n1 == 6){
	         Surface = IMG_Load("assets/images/nums/num6.jpeg");
		
	     }else if(n1 == 7){
	         Surface = IMG_Load("assets/images/nums/num7.jpeg");
	         
	     }else if(n1 == 8){
	         Surface = IMG_Load("assets/images/nums/num8.jpeg");
		
	     }else if(n1 == 9){
	         Surface = IMG_Load("assets/images/nums/num9.jpeg");
		
	     }
	   	
	    //start player img
	    SDL_Rect Texture_p;
	    Texture_p.w = 20;
	    Texture_p.h = 20;
		Texture_p.x = 255-21;
		Texture_p.y = 478;
	
		Texture = SDL_CreateTextureFromSurface(pvsm, Surface);
		SDL_FreeSurface(Surface);
	
		SDL_RenderCopy(pvsm, Texture, NULL, &Texture_p);
		SDL_DestroyTexture(Texture);
		//end player img

        }
	
}

void rpvsmp(SDL_Renderer *pvsm, int pp[]){	
 
    int n0, n1, wpx = 0;
    
	SDL_Surface *Surface;
    SDL_Texture *Texture;
	SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
	SDL_Rect Texture_rect;

    Texture_rect.w = 30;
    Texture_rect.h = 30;
    
     n0 = pp[1];
     n1 = pp[0];
    
	     if(n0 == 0){
	         Surface = IMG_Load("assets/images/nums/num0.jpeg");
		
	     }else if(n0 == 1){
	         Surface = IMG_Load("assets/images/nums/num1.jpeg");
		
	     }else if(n0 == 2){
	         Surface = IMG_Load("assets/images/nums/num2.jpeg");
		
	     }else if(n0 == 3){
	         Surface = IMG_Load("assets/images/nums/num3.jpeg");
	         
	     }else if(n0 == 4){
	         Surface = IMG_Load("assets/images/nums/num4.jpeg");
		
	     }else if(n0 == 5){
	         Surface = IMG_Load("assets/images/nums/num5.jpeg");
		
	     }else if(n0 == 6){
	         Surface = IMG_Load("assets/images/nums/num6.jpeg");
		
	     }else if(n0 == 7){
	         Surface = IMG_Load("assets/images/nums/num7.jpeg");
	         
	     }else if(n0 == 8){
	         Surface = IMG_Load("assets/images/nums/num8.jpeg");
		
	     }else if(n0 == 9){
	         Surface = IMG_Load("assets/images/nums/num9.jpeg");
		
	     }
	   	
	    //start player img
	    SDL_Rect Texture_p;
	    Texture_p.w = 20;
	    Texture_p.h = 20;
		Texture_p.x = 255;
		Texture_p.y = 460;
	
		Texture = SDL_CreateTextureFromSurface(pvsm, Surface);
		SDL_FreeSurface(Surface);
	
		SDL_RenderCopy(pvsm, Texture, NULL, &Texture_p);
		SDL_DestroyTexture(Texture);
		//end player img
        
        if(n1 > 0){
        	
	     if(n1== 1){
	         Surface = IMG_Load("assets/images/nums/num1.jpeg");
		
	     }else if(n1 == 2){
	         Surface = IMG_Load("assets/images/nums/num2.jpeg");
		
	     }else if(n1 == 3){
	         Surface = IMG_Load("assets/images/nums/num3.jpeg");
	         
	     }else if(n1 == 4){
	         Surface = IMG_Load("assets/images/nums/num4.jpeg");
		
	     }else if(n1 == 5){
	         Surface = IMG_Load("assets/images/nums/num5.jpeg");
		
	     }else if(n1 == 6){
	         Surface = IMG_Load("assets/images/nums/num6.jpeg");
		
	     }else if(n1 == 7){
	         Surface = IMG_Load("assets/images/nums/num7.jpeg");
	         
	     }else if(n1 == 8){
	         Surface = IMG_Load("assets/images/nums/num8.jpeg");
		
	     }else if(n1 == 9){
	         Surface = IMG_Load("assets/images/nums/num9.jpeg");
		
	     }
	   	
	    //start player img
	    SDL_Rect Texture_p;
	    Texture_p.w = 20;
	    Texture_p.h = 20;
		Texture_p.x = 255-21;
		Texture_p.y = 460;
	
		Texture = SDL_CreateTextureFromSurface(pvsm, Surface);
		SDL_FreeSurface(Surface);
	
		SDL_RenderCopy(pvsm, Texture, NULL, &Texture_p);
		SDL_DestroyTexture(Texture);
		//end player img

        }
	
}


void pvsm(char mode_player[], char pmod[], int activePlayer, int dft[],  int cp, int cm, int pm[], int pp[]){
      
    int inc = 0;
                  
    if(pmod[0] == 'f'){
           
          //start 
         if(activePlayer == 1){
         
         	if(dft[0] == 0){
         	   
         	    if(mode_player[1] != '0'){	
         	    	
		         	if(cm == 0){
		         		inc = 1;
		         	}else{
		         		inc = 2;
		         	}
		         	
	             }else{
	             	
	             	inc = 2;
	             }
	             	
             }else if(dft[0] == 1){
             	          	
                	inc = 2;         	
             	
             }
             	
         }else if(activePlayer == 2){
              
               if(dft[0] == 0){ 
                
                   if(mode_player[1] != '0'){	
                   
		           	if(cp == 0){
		           		inc = 2;
		           	}else {
		           		inc = 1;
		          	}
		          	
                  }else{
                      
                      inc = 1;
                  }
                   
          	}else if(dft[0] == 1){      		
          		
          			inc = 1;         		
          		
          	}	
           
         } 
         //end
          
          //start
          int cont1 = 0, cont2 = 0;
          int st = 0, tab;
               
          if(inc == 2){
            	
          	 cont1 = pp[0] + pp[1];            
                
          	 if(pp[1] <= 9 && st == 0){
          	       
                  pp[1] = pp[1] + 1;
                  
                  if(pp[1] % 10 == 0 && st == 0){
                  	
                  	pp[0] = pp[0] + 1;
                  	pp[1] = 0;          
                  	
                  }
                  
               }
               	 
            }else if(inc == 1){
            	
            	cont1 = pm[0] + pm[1];               	              
                
          	if(pm[1] <= 9 && st == 0){
          	       
                  pm[1] = pm[1] + 1;
                  
                  if(pm[1] % 10 == 0 && st == 0){
                  	          	
                  	pm[0] = pm[0] + 1;
                  	pm[1] = 0;           
                 	
                  }
                  
               }
          	
            } 
                                
          //end
    }                                               
                    
}
                    
void count_units(SDL_Renderer *rendImg, float x[], float y[], int cont_units[], int cont_ball[], char mode_player[]){

	int deg = 360, units = 0, p_width_x = 15, m_width_x = 15;
	int cont_p = 0, cont_m = 0;

	SDL_Surface *Surface;
    SDL_Texture *Texture;
	SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
	SDL_Rect Texture_rect;

    Texture_rect.w = 20;
    Texture_rect.h = 20;
    
    //start player img
    SDL_Rect Texture_p;
    Texture_p.w = 60;
    Texture_p.h = 10;
    Surface = IMG_Load("assets/images/player.png");
	Texture_p.x = 5;
	Texture_p.y = 470;

	Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
	SDL_FreeSurface(Surface);

	SDL_RenderCopy(rendImg, Texture, NULL, &Texture_p);
	SDL_DestroyTexture(Texture);
	//end player img
	
	//start machine img
	SDL_Rect Texture_m;
	Texture_m.w = 60;
	Texture_m.h = 10;
	Surface = IMG_Load("assets/images/machine.png");
	Texture_m.x = 5;
	Texture_m.y = 492;

	Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
	SDL_FreeSurface(Surface);

	SDL_RenderCopy(rendImg, Texture, NULL, &Texture_m);
	SDL_DestroyTexture(Texture);
	//end machine img

	while(units <= 15){

		if(mode_player[1] == '7'){

			if(cont_ball[units] <= 7 && x[units] != 0 && y[units] != 0){
				
				cont_p++;
				
				if(cont_ball[units] == 1){
					Surface = IMG_Load("assets/images/b1.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 2){
					Surface = IMG_Load("assets/images/b2.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 3){
					Surface = IMG_Load("assets/images/b3.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 4){
					Surface = IMG_Load("assets/images/b4.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 5){
					Surface = IMG_Load("assets/images/b5.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 6){
					Surface = IMG_Load("assets/images/b6.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 7){
					Surface = IMG_Load("assets/images/b7.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

			if(cont_ball[units] >= 9 && x[units] != 0 && y[units] != 0){

				cont_m++;
				
				if(cont_ball[units] == 9){
					Surface = IMG_Load("assets/images/b9.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 10){
					Surface = IMG_Load("assets/images/b10.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 11){
					Surface = IMG_Load("assets/images/b11.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 12){
					Surface = IMG_Load("assets/images/b12.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 13){
					Surface = IMG_Load("assets/images/b13.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 14){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 15){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

		}else if(mode_player[1] == '9'){

			if(cont_ball[units] >= 9 && x[units] != 0 && y[units] != 0){

				cont_p++;
				
				if(cont_ball[units] == 9){
					Surface = IMG_Load("assets/images/b9.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 10){
					Surface = IMG_Load("assets/images/b10.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 11){
					Surface = IMG_Load("assets/images/b11.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 12){
					Surface = IMG_Load("assets/images/b12.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 13){
					Surface = IMG_Load("assets/images/b13.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 14){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 15){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+20*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

			if(cont_ball[units] <= 7 && x[units] != 0 && y[units] != 0){

				cont_m++;

				if(cont_ball[units] == 1){
					Surface = IMG_Load("assets/images/b1.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 2){
					Surface = IMG_Load("assets/images/b2.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 3){
					Surface = IMG_Load("assets/images/b3.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 4){
					Surface = IMG_Load("assets/images/b4.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 5){
					Surface = IMG_Load("assets/images/b5.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 6){
					Surface = IMG_Load("assets/images/b6.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 7){
					Surface = IMG_Load("assets/images/b7.png");
					Texture_rect.x = 60+20*cont_m;
					Texture_rect.y = 492;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}
		}

		units++;
	}
}