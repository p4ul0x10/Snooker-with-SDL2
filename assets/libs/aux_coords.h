void rend_coords_dst(SDL_Renderer *aux_renderer, float deg_mode, float pos_x, float pos_y, float dest_x[], float dest_y[], float dst){

	int count_px = 0;
	int tang_coords = 125; //max aux degs -> px
	
	float center_px1, center_py1;
	float center_px2, center_py2;
	 
	center_px1 = pos_x + 10; //target x
	center_py1 = pos_y + 10; //target y

	center_px2 = dest_x[0]; //collision center dest x 
	center_py2 = dest_y[0]; //collision center dest y

	SDL_SetRenderDrawColor(aux_renderer, 0, 0, 0, 0);
	//start find tang dest (x y coords)
	float width, height, deg_w, deg_h;
	float init_tangx, init_tangy;

	width = (center_px2 - center_px1) / dst; //px size w
	height = (center_py2 - center_py1) / dst; //px size h

	float init_target_x, init_target_y;	
	//end find tang dest (x y coords)

	
	//start route coords
	while(count_px < tang_coords){

		//start find tang 
		init_target_x = center_px1 + (-width * count_px);
		init_target_y = center_py1 + (-height * count_px);
		//end find tang

		SDL_Rect coords_rect;

        coords_rect.w = 2;
        coords_rect.h = 2;

        coords_rect.x = init_target_x;
        coords_rect.y = init_target_y;

        SDL_RenderFillRect(aux_renderer, &coords_rect);

		count_px++;
	}
	//end route coords

}


void rend_dest(SDL_Renderer *aux_renderer, float deg_mode, int num[], float x[], float y[], float dest_x[], float dest_y[], char rtn_resp[]){

	int count = 0;

	float p_x, p_y, dst, dst_x, dst_y;
	float get_x, get_y;
    float cX, cY;
    
    cX = dest_x[0];
    cY = dest_y[0];
    
	while(count <= 15){

		if(num[count] != 0){ // != white ball

			p_x = x[count]; //target x 
			p_y = y[count]; //target y

			dst_x = p_x - (dest_x[0] - 10); //dest mira x 
			dst_y = p_y - (dest_y[0] - 10); // dest mira y

			dst = sqrtf(dst_x*dst_x + dst_y*dst_y);

			if(dst <= 20){ //true

				get_x = p_x;
				get_y = p_y;
				
                float dstlap = 0.5 * (dst - 20);
                
				dest_x[0] -= dstlap * (dest_x[0] - p_x) / dst;
				dest_y[0] -= dstlap * (dest_y[0] - p_y) / dst;
			
			    get_x += dstlap * (dest_x[0] - p_x) / dst;
				get_y += dstlap * (dest_y[0] - p_y) / dst;
				
				rend_coords_dst(aux_renderer, deg_mode, get_x, get_y, dest_x, dest_y, dst);
				
				rendMiraDest(aux_renderer, cX, cY);
				rtn_resp[0] = 't';	
				
			}			

		}
		
		count++;
		
	}

}