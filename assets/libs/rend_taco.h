
void rendTaco(SDL_Renderer *rendT, int num[],  float vetX[], float vetY[], float deg, float deg_mode, float df_x, float df_y, float c_px[], float c_py[], float rdeg[]){

    float x, y;

    x = vetX[15];
    y = vetY[15];
    
    SDL_Surface *image_taco = IMG_Load("assets/images/taco1.png");

    SDL_Texture *texture_taco = SDL_CreateTextureFromSurface(rendT, image_taco);
    SDL_FreeSurface(image_taco);

    int cont_px = 0, px = 0;
    float px1, py1, incPx, divAL, divLA, bx, by;
    bool stop_px = false, run = true;

    divLA = fabs(df_x) / fabs(df_y); //largura / altura
    divAL = fabs(df_y) / fabs(df_x); //altura / largura
  
     rdeg[0] = divAL;
 
    bx = x + 10;
    by = y + 10;

    SDL_SetRenderDrawColor(rendT, 0, 0, 0, 0);
    
    float r_pi, r_ang_t, df_px;
    float rdg;
    r_pi = 3.141592; 
    r_ang_t = atan (divAL) * 180 / r_pi; //total de graus
    df_px=0;

    //start recover aux middle x y(each 45 deg)
    //start 
    if(deg_mode == -90 && r_ang_t <= 45){
       
       df_px = df_x;

    }else if(deg_mode == -90 && r_ang_t > 45){
       
        df_px = df_y;
    
    }
    //end
    //start
    if(deg_mode == 180 && r_ang_t <= 45){

        df_px = df_x;

    }else if(deg_mode == 180 && r_ang_t > 45){

        df_px = df_y;

    }
    //end
    //start
    if(deg_mode == 90 && r_ang_t <= 45){

        df_px = df_x;

    }else if(deg_mode == 90 && r_ang_t > 45){

        df_px = df_y;
    }
    //end
    //start
    if(deg_mode == 0 && r_ang_t <= 45){

        df_px = df_x;

    }else if(deg_mode == 0 && r_ang_t > 45){

        df_px = df_y;
    }
    //end
    
    //rdeg[0] = rdg;
    
    if(df_px < 0 || df_px > 1000){
        df_px = 0;
    }
    //end recover aux middle x y(each 45 deg)
    
    //start line init calc limit renderer deg
  
     bool loop_target = true;
    char rtn[1];
    rtn[0] = 'n';
    
    while (px < 100000 && loop_target == true){
         
         //
         if(divLA >= 1){
         	px1 = 1 / 2;
         	py1 = divAL / 2;
         }else{
         	px1 = divLA / 2;
         	py1 = 1 / 2;
         }
        //
       
        if(by > 45 && by < 412 && bx >= 52 && bx <= 847){ 
        
	         if(divLA >= 1){ 
	           
	            if(deg_mode == -90 || deg_mode == 180){
	                      
	                by  -= py1;//divAL;            
	      
	           }else if(deg_mode == 90 || deg_mode == 0){
	             
	                by += py1;//divAL;
	                
	            }
	
	
	            if(deg_mode == 90 || deg_mode == 180){
	            
	                bx -= 0.5;//1;
	                
	            }else if(deg_mode == -90 || deg_mode == 0){
	            
	                bx += 0.5;//1;
	                
	            }         
	
	        }else{ 
	
	            if(deg_mode == -90 || deg_mode == 180){
	             
	                by -= 0.5;//1;               
	               
	            }else if(deg_mode == 90 || deg_mode == 0){
	             
	                by += 0.5;//1;
	               
	            }
	
	            if(deg_mode == 90 || deg_mode == 180){
	                
	                bx -= px1;//divLA;
	                
	            }else if(deg_mode == -90 || deg_mode == 0){
	                         
	                bx += px1;//divLA;            
	            
	            }
	        
	        }
	        
        }else{
        	
        	rendMiraDest(rendT, bx, by);
        	px = 100000;
        }
        
        SDL_Rect pxxx_rect;
        pxxx_rect.w = 2;
        pxxx_rect.h = 2;
        pxxx_rect.x = bx;
        pxxx_rect.y = by;

        SDL_RenderFillRect(rendT, &pxxx_rect);
                  
        c_px[0] = bx;
        c_py[0] = by;
        
        rend_dest(rendT, 0, num, vetX, vetY, c_px, c_py, rtn);
        
        if(rtn[0] == 't'){
        	loop_target = false;
        }
        
        px += 1;

    }
    //end line calc limit renderer deg <= 90 graus por mode deg
 
    float rec_ang, rsen, rcos, ang_t, ang, pi, cue_size;
    float r = 10;
    cue_size = 400; //size width px
   
    //start set & pos (sen, cos, deg) + x y
    if(deg_mode == -90){
        
        //start init sets
        x = x - cue_size / 2; //taco / 2
        x = x + 7; // width left align
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2  
        //end init set
        
        //start get degs 
        pi = 3.141592; 
        ang_t = atan (divAL) * 180 / pi; 
        //end get degs
        
        //start pos x y + cos sen ajusts align
        rcos = cos (ang_t * pi / 180);
        rsen = sin (ang_t * pi / 180);
        ang = 90 + ang_t;
        
         x = x + 200 - rcos * 200; 
         y = y + rsen * 200;
        //end pos x y cos sen ajust align

         //start rotation seno y coseno x - > over + 2r
         y = y + rsen * r * 2;
         x = x - rcos * r * 2; 
         //end rotation seno y coseno x       
      
        deg = -ang; //add degs 

    }else if(deg_mode == 180){

        //start init sets
        x = x + 7;
        y = y + 10;
        //end init sets

        float rcos, rsen, ang_t, ang, ang_y, pi, ang_recover, rec_ang;

        //start get degs
        pi = 3.141592;
        ang_recover = atan (divAL) * 180 / pi;
        //end get degs
        
        //start pos x y + cos sen ajusts
        ang = 90 + ang_recover; 
        ang_t = 180 - ang_recover;
        ang_y = 180 + ang_recover;
        
        rcos = cos (ang_t * pi / 180);
        rsen = sin (ang_y * pi / 180);
       
        x = x + fabs(rcos) * cue_size / 2;
        y = y  - (cue_size / 2) - rsen * cue_size / 2;    
        //end pos x y ajust aling 
        
        //start pos x y rotation seno y coseno x -> over 2r
        y = y - rsen * r * 2;
        x = x - rcos * r * 2;        
        //end pos x y rotation seno y coseno x
        
        deg = ang; //add degs      

    }else if(deg_mode == 90){ 
 
        //start init set pos
        x = x + cue_size / 2; //taco / 2
        x = x + (20 - 3) / 2; //bola / 2 
   
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2       
        //end init set pos

        float ang_t, ang, ang_x, pi;
         
        //start set get degs 
        pi = 3.141592;
        ang_t = atan (divAL) * 180 / pi;
        ang_x = 180 - ang_t;
        ang = 90 - ang_t;
        //end set get degs

        //start pos x y + cos sen (init ajusts)
        rcos = cos (ang_x * pi / 180);
        rsen = sin (ang_t * pi / 180);
      
        x = x - (400 / 2) - rcos * (cue_size / 2);
        y = y - rsen * 200;
        //end pos x y ajust align
        
        //start x y rotation seno y coseno x -> over 2r
        y = y - rsen * r * 2;
        x = x - rcos * r * 2;
        //end x y rotation seno y coseno x
        
        deg = 90 - ang_t; //deg added         

    }else if(deg_mode == 0){

        //start init sets
        x = x + 20 / 2; //bola / 2
        x = x - 3; //width align
        y = y - cue_size / 2; //taco / 2
        y = y - (200 - 10);//taco / 2
        //end init sets        

        float rsen, rcos, ang_t, ang_x, ang_y, rec_ang, ang, pi;
       
        //start set get degs
        pi = 3.141592; //pi
        ang_t = atan (divAL) * 180 / pi; //quantidade de graus atual sem conversao
        ang = 90 - ang_t; //rec ang >= 0
        //end set get degs

        //start pos x y + cos sen (init ajusts)
        rcos = cos (ang_t * pi / 180);
        rsen = sin (-ang_t * pi / 180);

        x = x - rcos * (cue_size / 2); // cos * size  cue / 2
        y = y + (cue_size / 2) + rsen * (cue_size / 2); //sen * size cue / 2   
        //end pos x y ajust align
        
        //start rotation x y seno y coseno x -> 2r
         y = y + rsen * r * 2;
         x = x - rcos * r * 2;     
         //end rotation x y seno y coseno x
              
        deg = -ang; //degs added        
    }
    
    //start sdl renderer cue pos rotate
    SDL_Rect image_taco_rect;
    image_taco_rect.w = 6;
    image_taco_rect.h = 400;
    image_taco_rect.x = x; //round(x);
    image_taco_rect.y = y; //round(y);
    
    SDL_RendererFlip flip = SDL_FLIP_VERTICAL;

    SDL_RenderCopyEx(rendT, texture_taco, NULL, &image_taco_rect, deg, NULL, flip);
    SDL_DestroyTexture(texture_taco);
    //end sdl renderer cue pos rotate
    
}


