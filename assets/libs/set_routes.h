void mode_op_change(int i_key, int mode_op[], char mode_e[]){

	if(mode_op[i_key] == 0){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 1;
		}

	}else if(mode_op[i_key] == 1){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 0;
		}

	}else if(mode_op[i_key] == 2){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 3;
		}

	}else if(mode_op[i_key] == 3){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 2;
		}
	}
}

void add_effect(int i_key, char mode_e[], float dec_percent, float f[], float v[]){

	float dec_p, dec_v, mb;

	if(mode_e[0] == 't' || mode_e[0] == 'b' || mode_e[0] == 'n'){

		dec_p = (dec_percent / 100) * v[i_key];
		dec_v = v[i_key] - dec_p;

		v[i_key] = dec_v;
		f[i_key] = dec_v;

	}else if(mode_e[0] == 'l' || mode_e[0] == 'r' || mode_e[0] == 'n'){


	}
}

void check_effect_xy(int m1, char mode_ex[], float percent_efx, char mode_ey[], float percent_efy, float v[], float f[], int m[]){

	/*
	m1 = key for vetor(s) - > speed, force, mode op
	mode_ex = effect x (l = center x from left or r = center y for right);
	percent_efx = percent 0 ~ 100 % effect x (side l or side r)
	mode_ey = effect y (t = center y for top y or b = center y for bottom);
	percent_efy = percent 0 ~ 100 % effect y (top or right)
	v = vetor force + speed
	m = vetor mode op (moviments, x y);
	*/

	float calc_efy, dec_percent_y, final_percent_y;
	float calc_efx, dec_percent_x, final_percent_x;

	//start check effect y x

	//if(percent_efy >= percent_efx){ //percent ef y > perfecnt ef x

		if(mode_ey[0] == 't'){ //y center for top y

			dec_percent_y = (v[m1] / 100) * percent_efy;

			mode_op_change(m1, m, mode_ey); //check change mode op
			add_effect(m1, mode_ey, dec_percent_y, f, v);

			if(mode_ex[0] != 'n'){ //init check dec inc effect x side

				if(mode_ex[0] == 'l'){ //ef x -> left

				}else if(mode_ex[0] == 'r'){ // ef x -> right

				}
			}

		}else if(mode_ey[0] == 'b'){

			dec_percent_y = (v[m1] / 100) * percent_efy;

			mode_op_change(m1, m, mode_ey); //check change mode op
			add_effect(m1, mode_ey, dec_percent_y, f, v);

			if(mode_ex[0] != 'n'){ //init check dec inc effect x side

	 			if(mode_ex[0] == 'l'){ //ef x -> left

	 			}else if(mode_ex[0] == 'r'){ // ef x -> right

	 			}
			}

		}else{


		}

	/*}else{

	}*/

	//end check effect y x

}

void rendEffects(SDL_Renderer *rendE, int e_x[], int e_y[]){

	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture_play = SDL_CreateTextureFromSurface(rendE, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;

	image_branca_rect.w = 40;
	image_branca_rect.h = 40;
	image_branca_rect.x = 750;
	image_branca_rect.y = 465;

	SDL_RenderCopy(rendE, texture_play, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_play);

	SDL_SetRenderDrawColor(rendE, 0, 0, 0, 1);

	int pos_ex, pos_ey;

	SDL_Rect e_rect;

	e_rect.w = 3;
	e_rect.h = 3;
	e_rect.x = e_x[0];
	e_rect.y = e_y[0];

	SDL_RenderDrawRect(rendE, &e_rect);
	SDL_RenderFillRect(rendE, &e_rect);

}

void coord_xy(int m1, int m2, float wh, float hw, float ax[], float ay[]){

	/*
	m1 -> ball
	m2 -> ball target
	wh -> width /height  && height / width
	ax[] -> aux ang vetor x
	ay[] -> aux ang vetor y
	*/
	//start add x y - > angle in px
	if(wh >= 1){

		ax[m1] = 1;
		ay[m1] = hw;

		ax[m2] = 1;
		ay[m2] = hw;

	}else{

		ax[m1] = wh;
		ay[m1] = 1;

		ax[m2] = wh;
		ay[m2] = 1;
	}
	//end add x y -> angle in px
}

void set_dest_xy(int m1, int m2, float x[], float y[], float vx[], float vy[], float ax[], float ay[], float vFX[], float vFY[]){
	
	float fDistance = sqrtf((x[m1] - x[m2])*(x[m1] - x[m2]) + (y[m1] - y[m2])*(y[m1] - y[m2])); //20

	// Normal
	float dstx = (x[m2] - x[m1]) / fDistance;
	float dsty = (y[m2] - y[m1]) / fDistance;

	float dfvx = (vFX[m1] - vFX[m2]);
	float dfvy = (vFY[m1] - vFY[m2]);
	float mass= 20;
	float f = 2.0 * (dstx * dfvx + dsty * dfvy) / (mass  + mass);
	
	vFX[m1] = vFX[m1] - f * mass * dstx;
	vFY[m1] = vFY[m1] - f * mass * dsty;
	vFX[m2] = vFX[m2] + f * mass * dstx;
	vFY[m2] = vFY[m2] + f * mass * dsty;
}

