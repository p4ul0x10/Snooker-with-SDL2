void loadMesa(SDL_Renderer *renderer, bool bmp){

if(bmp == true){
	SDL_Surface *image_mesa = IMG_Load("assets/images/mesa-edt.png");
	SDL_Texture *texture_mesa = SDL_CreateTextureFromSurface(renderer, image_mesa);
	SDL_FreeSurface(image_mesa);
	SDL_Rect image_mesa_rect;
	image_mesa_rect.w = 900;
	image_mesa_rect.h = 540;
	image_mesa_rect.x = 0;
	image_mesa_rect.y = 0;
	SDL_RenderCopy(renderer, texture_mesa, NULL, &image_mesa_rect);
    SDL_DestroyTexture(texture_mesa);
}else{
	SDL_Surface *image_mesa = IMG_Load("assets/images/mesa-edt-wt.png");
	SDL_Texture *texture_mesa = SDL_CreateTextureFromSurface(renderer, image_mesa);
	SDL_FreeSurface(image_mesa);
	SDL_Rect image_mesa_rect;
	image_mesa_rect.w = 900;
	image_mesa_rect.h = 540;
	image_mesa_rect.x = 0;
	image_mesa_rect.y = 0;
	SDL_RenderCopy(renderer, texture_mesa, NULL, &image_mesa_rect);
    SDL_DestroyTexture(texture_mesa);
}
	

	
}

void bolaBranca(SDL_Renderer *renderer, float x, float y){

	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);


	SDL_Rect image_branca_rect;
	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;

	SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_branca);
}

void status_fs(SDL_Renderer *renderer){

	SDL_Surface *image_branca = IMG_Load("assets/images/status_fs.jpg");

	SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);


	SDL_Rect image_branca_rect;
	image_branca_rect.w = 20;
	image_branca_rect.h = 440;
	image_branca_rect.x = 910;
	image_branca_rect.y = 10;

	SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_branca);
}

void status_fsd(SDL_Renderer *renderer, float px_status){

	SDL_Surface *image_branca = IMG_Load("assets/images/status_fsd.jpg");

	SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);


	SDL_Rect image_branca_rect;
	image_branca_rect.w = 20;
	image_branca_rect.h = px_status;
	image_branca_rect.x = 910;
	image_branca_rect.y = 10;

	SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_branca);
}

void status_jp(SDL_Renderer *renderer){

	SDL_Surface *image_branca = IMG_Load("assets/images/b8.png");

	SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);


	SDL_Rect image_branca_rect;
	image_branca_rect.w = 40;
	image_branca_rect.h = 40;
	image_branca_rect.x = 900;
	image_branca_rect.y = 485;

	SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_branca);
}

void reset_engine(SDL_Renderer *renderer, int cm, int cp){

    if(cm > 0 && cp > 0){
    	
		SDL_Surface *image_branca = IMG_Load("assets/images/reset1.jpg");
	
		SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
		SDL_FreeSurface(image_branca);
	
	
		SDL_Rect image_branca_rect;
		image_branca_rect.w = 50;
		image_branca_rect.h = 40;
		image_branca_rect.x = 500;
		image_branca_rect.y = 490;
	
		SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
		SDL_DestroyTexture(texture_branca);
    
    }else{
    	
    	SDL_Surface *image_branca = IMG_Load("assets/images/reset2.jpg");
	
		SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
		SDL_FreeSurface(image_branca);
		
		SDL_Rect image_branca_rect;
		image_branca_rect.w = 50;
		image_branca_rect.h = 40;
		image_branca_rect.x = 500;
		image_branca_rect.y = 490;
	
		SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
		SDL_DestroyTexture(texture_branca);

    }
}


void rendFor(SDL_Renderer *rendFor, float f){
    
	//start get rend force color
	if(f < 2.66){

		SDL_SetRenderDrawColor(rendFor, 0, 200, 0, 1);
	
	}else if(f >= 2.66 && f < 5.32){

		SDL_SetRenderDrawColor(rendFor, 255, 255, 51, 1);

	}else if(f >= 5.32 && f <= 6.5){

		SDL_SetRenderDrawColor(rendFor, 255, 0, 0, 1);
		
	}else{
		
		SDL_SetRenderDrawColor(rendFor, 25, 25, 25, 0.5);
		
	}	
	//end get rend force color

	//start rend px (represent range force limit)
	
    float fs = 0, add_b = 0.5, y = 460;
    float ff = 1.25*f;
      
	if(f > 0){

		while(fs < ff){

			y += add_b;
			SDL_Rect f_rect;

			f_rect.w = 30;
			f_rect.h = 7;
			f_rect.x = 810;
			f_rect.y = y;

			SDL_RenderFillRect(rendFor, &f_rect);
			
            fs += 0.1;
            
		}
	}
	//end rend px (represent range force limit)
}

void playJogada(SDL_Renderer *rendPlay, int x, int y, int deg_cont){

	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture_play = SDL_CreateTextureFromSurface(rendPlay, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;

	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;
	SDL_RenderCopy(rendPlay, texture_play, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_play);
}

void rendMiraDest(SDL_Renderer *rendDest, float mouseX, float mouseY){

    SDL_Surface *image_Dest = IMG_Load("assets/images/bm_dest.png");

	SDL_Texture *texture_mira = SDL_CreateTextureFromSurface(rendDest, image_Dest);
	SDL_FreeSurface(image_Dest);

	SDL_Rect image_Dest_rect;

	image_Dest_rect.w = 20;
	image_Dest_rect.h = 20;
	image_Dest_rect.x = mouseX-10;
	image_Dest_rect.y = mouseY-10;
	SDL_RenderCopy(rendDest, texture_mira, NULL, &image_Dest_rect);
    SDL_DestroyTexture(texture_mira);
}

void rendHand(SDL_Renderer *rendHand, float x, float y){

	SDL_Surface *image_Dest = IMG_Load("assets/images/hand.png");

	SDL_Texture *texture_hand = SDL_CreateTextureFromSurface(rendHand, image_Dest);
	SDL_FreeSurface(image_Dest);

	SDL_Rect hand_Dest_rect;

	hand_Dest_rect.w = 25;
	hand_Dest_rect.h = 25;
	hand_Dest_rect.x = x;
	hand_Dest_rect.y = y;

	SDL_RenderCopy(rendHand, texture_hand, NULL, &hand_Dest_rect);
    SDL_DestroyTexture(texture_hand);	
}