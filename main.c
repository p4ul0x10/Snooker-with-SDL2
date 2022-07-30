#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include "assets/libs/libunits.h"
#include "assets/libs/functions.h"
#include "assets/libs/aux_coords.h"
#include "assets/libs/rend_taco.h"
#include "assets/libs/set_routes.h"
#include "assets/libs/engine_balls.h"
#include "assets/libs/check_mods.h"
#include "assets/libs/machine_trace.h"
#include "assets/libs/machine_make_route.h"


int main(int argc, char *argv[]){

	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;

	int posX = 200, posY = 40, width = 935, height = 540;
	float Bx, By, deg = -90, mouseX = 0, mouseY = 0, div_larg, div_alt; 
	int activePlay = 0;
	int loadSinuca = 0;

	/*SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2096);*/

	win = SDL_CreateWindow("Snooker Game by S3r3n0s group", posX, posY, width , height, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_ENABLE);

	float bx_central, mirax_central, by_central, miray_central, deg_mode, df_x, df_y, add_deg;
	bool stop_move = false, bmp = false, inc_loopm = false, sttm = false;
   
    float f_cue, calc_cue, divAL, divLA, add_v=0;
    float f = 0, fmax = 0, al;
    int cont_play = 0, cont_prox = 0, init_mode[1], vetN[16], init_x[16], vetM[16], all_k[1], e_x[1], e_y[1];    
    int endb = 0, cp = 0, cm = 0, ca = 0;
    int cont_units[1], cont_ball[15], cont_p[1], cont_m[1], cont_all[1];
   
    float eq_y, div_eq_y, percent_y_1, percent_y_2, percent_y;
    
    float vetAX[16], vetAY[16], vetV[16], deg_b[16], vetFX[16], vetFY[16], vang[16], init_y[16], return_x[1], return_y[1];
    float vetX[16], vx[16], dfx[16], get_mx[1];
    float vetY[16], vy[16], dfy[16], get_my[1];
    float p_x[1], p_y[1];
    float m_ang_t, degmx[1], degmy[1], rrdeg[1], rdeg[1], finit_mode[1];
    int pp[2], pm[2], cpx=0, cpy=0, endlm = 0, endlp = 0, count_null = 0, dftb[1], addv[1];
     
    char check_over[1], random_units[1], mode_play_new[1], rand_on[1], status_check[1], mode_player[2], change_mode[1], pmod[1];

    //move branca lisa vars
	Uint32 windowID = SDL_GetWindowID(win);
    int SDL_CaptureMouse(SDL_bool enabled);

    SDL_Event event;

    const char* SDL_GetKeyName(SDL_Keycode key);

    for(int ixy = 0; ixy < 16; ixy++){
        init_x[ixy] = vetN[ixy];
    }

    //init set init defaults
    int ctm = 0, ctp = 0, b = 0, c = 0;
    int xM[16], lastProxTarget[1]; //pos x y in moviments (for check with all possibles)
    float xyF[16];
    float mxp[1], myp[1];
    
    while(b < 15){

        vx[b] = 0;
        vy[b] = 0;
        vetFY[b] = 0;
        vetFX[b] = 0;
        xM[b] = 100;
        xyF[b] = 0;
        deg_b[b] = 0;
        cont_ball[b] = 0;
        dfx[b] = 0;
        dfy[b] = 0;
        b++;
    }
        
    p_x[0] = 0;
    p_y[0] = 0;
    all_k[0] = 0;

    deg_b[15] = 0;

    dfx[15] = 0;
    dfy[15] = 0;
    xM[15] = 100;
    xyF[15] = 0;
    vetFX[15] = 0;
    vetFY[15] = 0;
    addv[0] = 0;
    //end set init defaults 

    //start init coord x y effect img (bottom side right)
    e_y[0] = (40 / 2) + 465;
    e_x[0] = (40 / 2) + 750;
    //end init coord x y effect img (bottom side right)
    
    //srand (time(NULL));
    //activePlay = rand() % 2+1;

    //start init set mods (player || ia)
    random_units[0] = 'f';
    check_over[0] = 't';
    cont_units[0] = 0;
    lastProxTarget[0] = 0;
    init_mode[0] = 4;
    cont_ball[0] = 100;
    cont_p[0] = 7;
    cont_m[0] = 7;
    rand_on[0] = 'n';
    status_check[0] = 'n';
    change_mode[0] = 't';
    mode_play_new[0] = 't';
    mode_player[0] = '0';
    mode_player[1] = '0';
    check_over[0] = 'f';
    pmod[0] = 'f';
    rdeg[0] = 0;
    rrdeg[0] = 0;
    m_ang_t = 0;
    
    pp[0] = 0;
    pp[1] = 0;             
    pm[0] = 0;
    pm[1] = 0;
    dftb[0] = 10;
    addv[0]= 0;

    float  mouseYF, max_fv = 0.01818181818;// 8" / 440;

    //end init set mods (player || ia)

    init_random(random_units, vetN, vetM, vx, vy, vetX, vetY, init_x, init_y);

    while(true){
    	
        //SDL_StartTextInput();					                                					        			
        SDL_RenderClear(renderer);
		loadMesa(renderer, bmp);
                  
         if(bmp == true && cpx < 2){
         	cpx++;
         }
         		
        while(SDL_PollEvent(&event) != 0){

			switch (event.type){
			         
            case SDL_MOUSEBUTTONDOWN:
            
              if (event.button.clicks == 1 && event.button.x >= 900 && event.button.x < 960 && event.button.y > 485 && mode_play_new[0] != 'f'){
                    
                    //start player if force != 0

					if (f > 0 && activePlay == 2){
						
                        //SDL_StopTextInput();
                        all_k[0] = 0;
                        init_x[15] = vetX[15];
                        init_y[15] = vetY[15];
                        mode_play_new[0] = 't';
                        change_mode[0] = 'n';
                        pmod[0] = 't';
                        cont_play++;
                      //  check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                        float bxx, byy, add_fvx, add_fvy;
                        bxx = vetX[15] + 10;
                        byy = vetY[15] + 10;
                        init_x[15] = 0;

                        //add_v *= 5;
                      if(get_mx[0] >= bxx && get_my[0] <= byy){
                           
                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 0;
                            add_fvx = -add_v;
                            add_fvy = add_v;

                        }else if(get_mx[0] >= bxx && get_my[0] > byy){

                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 3;
                            add_fvx = -add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] >= byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 1;
                            add_fvx = add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] < byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 2;
                            add_fvx = add_v;
                            add_fvy = add_v;

                        }                      
                        
                        //start calc force && degs -> x y (x y coords)
                        float px1, py1;
                        divLA = div_larg / div_alt; //largura / altura
                        divAL = div_alt / div_larg; //altura / largura   
                       if(divLA >= 1){
				         	px1 = 1 / 100;
				         	py1 = divAL / 100;
				         }else{
				         	px1 = divLA / 100;
				         	py1 = 1 / 100;
				         }
                        if(divLA >= 1){

                            vetFX[15] = 0.01*add_fvx;
                            vetFY[15] = py1*add_fvy;

                        }else{

                            vetFX[15] = px1*add_fvx;
                            vetFY[15] = 0.01*add_fvy;
                        }
                       
                       vetFX[15] = vetFX[15]; //bxx -  get_mx[0];
                       vetFY[15] = vetFY[15]; //byy -  get_my[0];
                        xM[0] = 15; 
                        xyF[15] = fabs(vetFX[15]) + fabs(vetFY[15]); //total mass force (x + y)
    
                        //end calc force && degs -> px (x y coords)
                        
                        //start 
                        lastProxTarget[0] = 100;
                        add_v = 0;
                        f = 0; 
                        mouseX = 0;
                        mouseY = 0;
                        //end
				    }
                   
                   if(mode_player[1] != '0'){
                     check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                   }
                    //end player if force != 0

                }else if(event.button.clicks == 1 && fmax >= 40 && fmax <= 440){ //run play if click == true 

                     //start player if force != 0

                    if (f > 0 && activePlay == 2){
                        
                        //SDL_StopTextInput();
                        all_k[0] = 0;
                        init_x[15] = vetX[15];
                        init_y[15] = vetY[15];
                        mode_play_new[0] = 't';
                        change_mode[0] = 'n';
                        pmod[0] = 't';
                        cont_play++;
                      //  check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                        float bxx, byy, add_fvx, add_fvy;
                        bxx = vetX[15] + 10;
                        byy = vetY[15] + 10;
                        init_x[15] = 0;

                        //add_v *= 5;
                      if(get_mx[0] >= bxx && get_my[0] <= byy){
                           
                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 0;
                            add_fvx = -add_v;
                            add_fvy = add_v;

                        }else if(get_mx[0] >= bxx && get_my[0] > byy){

                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 3;
                            add_fvx = -add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] >= byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 1;
                            add_fvx = add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] < byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 2;
                            add_fvx = add_v;
                            add_fvy = add_v;

                        }                      
                        
                        //start calc force && degs -> x y (x y coords)
                        float px1, py1;
                        divLA = div_larg / div_alt; //largura / altura
                        divAL = div_alt / div_larg; //altura / largura   

                       if(divLA >= 1){
                        
                            px1 = 1 / 100;
                            py1 = divAL / 100;
                        
                        }else{
                        
                            px1 = divLA / 100;
                            py1 = 1 / 100;
                        
                        }

                        if(divLA >= 1){

                            vetFX[15] = 0.01*add_fvx;
                            vetFY[15] = py1*add_fvy;

                        }else{

                            vetFX[15] = px1*add_fvx;
                            vetFY[15] = 0.01*add_fvy;
                        }
                       
                        vetFX[15] = vetFX[15]; //bxx -  get_mx[0];
                        vetFY[15] = vetFY[15]; //byy -  get_my[0];
                        xM[0] = 15; 
                        xyF[15] = fabs(vetFX[15]) + fabs(vetFY[15]); //total mass force (x + y)
    
                        //end calc force && degs -> px (x y coords)
                        
                        //start 
                        lastProxTarget[0] = 100;
                        add_v = 0;
                        f = 0; 
                        mouseX = 0;
                        mouseY = 0;
                        //end
                    }
                   
                   if(mode_player[1] != '0'){
                     check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                   }
                  //end player if force != 0

                }else if(event.button.clicks == 1 && mode_play_new[0] == 'f' || event.button.clicks == 1 && mode_play_new[0] == 'f' && cont_prox > 0){

                    if(event.button.x < 900 && event.button.y < 402){
                     
	                    vetX[15] = return_x[0];
	                    vetY[15] = return_y[0];
	                 
	                      mode_play_new[0] = 't';
	                                    
                    }
                    
                }else if(event.button.clicks == 1 && bmp == false){
                	
                	if(event.button.x < 450){
                		activePlay = 2;
                	}else{
                		activePlay = 1;
                	    check_over[0] = 't';
                	    sttm = false;
                	    inc_loopm = false;	
                	}        
                   // bolaBranca(renderer, 250, 217);
                  
                	bmp = true;
                	
              
                  }else if(m_ang_t == 0 && event.button.clicks == 1 && event.button.y > 440/*event.button.state == SDL_PRESSED*/){
                  	
                  	if(addv[0] > 5 && event.button.x < 900 && event.button.y > 440){
                  	                	 		
                  	     m_ang_t = 1;
                  	                   	 
                  	}
                  	
                   }else if(event.button.clicks == 1 && event.button.y > 440/*event.button.state == SDL_PRESSED*/){
                  	
                  	if(m_ang_t == 1){
                  		addv[0] = 0;
                  	     m_ang_t = 0;
                  	     
                  	}
                  	
                  }else if(event.button.clicks == 2 && cont_prox >= 0 && event.button.y < 490){
                  	
                  	if(pmod[0] == 'f' && cont_prox >= 0){
                            
                        if(cont_play == cont_prox){
                          	
                   	      mode_play_new[0] = 'f';
                        }
                  	}
                  	
                }else if(event.button.clicks == 2 /*&& bmp == true/*/){
                	
                	if(event.button.x > 500 && event.button.x < 550 && event.button.y > 490 && event.button.y < 530){
                	
                        //start reset / init new game
                        for(int r = 0; r < 16; r++){

                            vx[r] = 0;
                            vy[r] = 0;
                            vetN[r] = 100;
                            vetM[r] = 0;
                            vetFX[r] = 0;
                            vetFY[r] = 0;

                            xM[r] = 100;
                            xyF[r] = 0;
                            vetV[r] = 0;
                            vetX[r] = 0;
                            vetY[r] = 0;
                            vetAX[r] = 0;
                            vetAY[r] = 0;
                            dfx[r] = 0;
                            dfy[r] = 0;
                            cont_ball[r] = 0;
                            deg_b[r] = 0;
                        }

                        check_over[0] = 'f';
                        all_k[0] = 0;
                        random_units[0] = 'f';
                        init_mode[0] = 4;
                        mode_play_new[0] = 't';
                        lastProxTarget[0] = 0;

                        init_random(random_units, vetN, vetM, vx, vy, vetX, vetY, init_x, init_y);
                 
                        for(int mxy = 0; mxy < 16; mxy++){
                            init_x[mxy] = vetN[mxy];
                        }
                 
                        vetY[15] = 217;
                        vetX[15] = 250;
                        vetM[15] = 0;
                        f = 0;
                        fmax = 0;
                        add_v = 0;
                        cont_play = 0;
                        cont_prox = 0;
                        ctm = 0;
                        ctp = 0;
                        cont_units[0] = 0;
                        cont_ball[0] = 100;
                        rand_on[0] = 'n';
                        status_check[0] = 'n';
                        mode_player[0] = '0';
                        mode_player[1] = '0';
                        cont_p[0] = 7;
                        cont_m[0] = 7;
                        addv[0] = 0;
                        change_mode[0] = 't'; 
                        pmod[0] = 'f';            
                        count_null = 0;
                        mouseX = 0;
                        mouseY = 0;
                        mouseYF = 0;
                       /* pp[0] = 0;
                        pp[1] = 0; 
                        pp[2] = 0;
                        pp[3] = 0;
                        
                        pm[0] = 0;
                        pm[1] = 0;
                        pm[2] = 0;
                        pm[3] = 0; */
                        
                         //srand (time(NULL));
                        //activePlay = rand() % 2+1;
                        activePlay = 0;
                        //start init coord x y effect img
                        e_y[0] = (40 / 2) + 465;
                        e_x[0] = (40 / 2) + 750;
                        //end init coord x y effect img
                        
                        //end reset / init new game
                    
                    	bmp = false;
                    	sttm = false;
                    	inc_loopm = false;
                    	m_ang_t = 0;
                    	cpx = 0;
                    	cpy = 0;
                    	endlm= 0;
                    	endlp = 0;
                    	degmx[0] = 0;
                    	degmy[0] = 0;
                    	rrdeg[0] = 0;
                    	dftb[0] = 10;
                	}
                }
				
            break;
            
			case SDL_KEYDOWN:

                if(event.key.keysym.sym == SDLK_r){ // return init game

                    //start reset / init new game
                    for(int r = 0; r < 16; r++){

                        vx[r] = 0;
                        vy[r] = 0;
                        vetN[r] = 100;
                        vetM[r] = 0;
                        vetFX[r] = 0;
                        vetFY[r] = 0;

                        xM[r] = 100;
                        xyF[r] = 0;
                        vetV[r] = 0;
                        vetX[r] = 0;
                        vetY[r] = 0;
                        vetAX[r] = 0;
                        vetAY[r] = 0;
                        dfx[r] = 0;
                        dfy[r] = 0;
                        cont_ball[r] = 0;
                        deg_b[r] = 0;
                    }

                    check_over[0] = 'f';
                    all_k[0] = 0;
                    random_units[0] = 'f';
                    init_mode[0] = 4;
                    mode_play_new[0] = 't';
                    lastProxTarget[0] = 0;

                    init_random(random_units, vetN, vetM, vx, vy, vetX, vetY, init_x, init_y);
             
                    for(int mxy = 0; mxy < 16; mxy++){
                        init_x[mxy] = vetN[mxy];
                    }
             
                    vetY[15] = 217;
                    vetX[15] = 250;
                    vetM[15] = 0;
                    f = 0;
                    fmax = 0;
                    add_v = 0;
                    cont_play = 0;
                    cont_prox = 0;
                    ctm = 0;
                    ctp = 0;
                    cont_units[0] = 0;
                    cont_ball[0] = 100;
                    rand_on[0] = 'n';
                    status_check[0] = 'n';
                    mode_player[0] = '0';
                    mode_player[1] = '0';
                    cont_p[0] = 7;
                    cont_m[0] = 7;
                    addv[0] = 0;
                    change_mode[0] = 't'; 
                    pmod[0] = 'f';            
                    count_null = 0;
                    mouseX = 0;
                    mouseY = 0;
                    mouseYF = 0;
                   /* pp[0] = 0;
                    pp[1] = 0; 
                    pp[2] = 0;
                    pp[3] = 0;
                    
                    pm[0] = 0;
                    pm[1] = 0;
                    pm[2] = 0;
                    pm[3] = 0; */
                    
                     //srand (time(NULL));
                    //activePlay = rand() % 2+1;
                    activePlay = 0;
                    //start init coord x y effect img
                    e_y[0] = (40 / 2) + 465;
                    e_x[0] = (40 / 2) + 750;
                    //end init coord x y effect img
                    
                    //end reset / init new game
                
                    bmp = false;
                    sttm = false;
                    inc_loopm = false;
                    m_ang_t = 0;
                    cpx = 0;
                    cpy = 0;
                    endlm= 0;
                    endlp = 0;
                    degmx[0] = 0;
                    degmy[0] = 0;
                    rrdeg[0] = 0;
                    dftb[0] = 10;

                }else if(event.key.keysym.sym == SDLK_SPACE && mode_play_new[0] != 'f'){

                    if(fmax > 40){

                       float val_fv;
                       float my = fmax-40;//event.motion.y;
                       fmax = my;

                       if(my > 440){
                            my = 440;
                       }
                       if(my < 40){
                            my = 40;
                       }
                       mouseYF = my;                                    
                       val_fv = max_fv * my;
                       f = val_fv;
                                                        
                        if(f > 8){
                            f = 8; //max limit
                        }
                     
                        f_cue = 1;
                        calc_cue = f_cue * (f / val_fv); //(cue force + mass)

                        add_v = f * 10 + (calc_cue); //f forca -> cue * speed f          
                        add_v *= 100; //refino base

                        if(f > 6.5){
                          add_v *= 1.35; //1.67;
                        }else if(add_v >= 380){
                          //add_v *= 1.30;  
                        }
                                                        

                        if(event.motion.y < 10){
                           f = 0;
                           add_v = 0;
                           mouseYF = 0; 
                        }

                       /* f = f - 0.5; //dec 0.5 value force speed

                        f_cue = 10 / 10;
                        calc_cue = f_cue * (f / 10); // ^ (cue force mass)
                        
                        add_v = f * 10 + (calc_cue); //f forca -> cue * speed */
                    }

				}else if (event.key.keysym.sym == SDLK_f && mode_play_new[0] != 'f'){
				                
                    //SDL_Quit();
				    if(fmax < 440){

                        float val_fv;
                       float my = fmax+40;//event.motion.y;
                       fmax = my;

                       if(my > 440){
                            my = 440;
                       }
                       
                       mouseYF = my;                                    
                       val_fv = max_fv * my;
                       f = val_fv;
                                                        
                        if(f > 8){
                            f = 8; //max limit
                        }
                     
                        f_cue = 1;
                        calc_cue = f_cue * (f / val_fv); //(cue force + mass)

                        add_v = f * 10 + (calc_cue); //f forca -> cue * speed f          
                        add_v *= 100; //refino base

                        if(f > 6.5){
                          add_v *= 1.35; //1.67;
                        }else if(add_v >= 380){
                          //add_v *= 1.30;  
                        }
                                                        

                        if(event.motion.y < 10){
                           f = 0;
                           add_v = 0;
                           mouseYF = 0; 
                        }
                        /*
                        f = f + 0.5; //inc 0.5 value force speed

    					if(f > 10){
    						f = 10; //max limit
    					}

                        f_cue = 10 / 10;
                        calc_cue = f_cue * (f / 10); // ^ (cue force + mass)

                        add_v = f * 10 + (calc_cue); //f forca -> cue * speed
                        */
                    }
                    
				}else if (event.key.keysym.sym == SDLK_j && mode_play_new[0] != 'f'){
                    
                    //start player if force != 0

                    if (f > 0 && activePlay == 2){
                        
                        //SDL_StopTextInput();
                        all_k[0] = 0;
                        init_x[15] = vetX[15];
                        init_y[15] = vetY[15];
                        mode_play_new[0] = 't';
                        change_mode[0] = 'n';
                        pmod[0] = 't';
                        cont_play++;
                      //  check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                        float bxx, byy, add_fvx, add_fvy;
                        bxx = vetX[15] + 10;
                        byy = vetY[15] + 10;
                        init_x[15] = 0;

                        //add_v *= 5;
                      if(get_mx[0] >= bxx && get_my[0] <= byy){
                           
                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 0;
                            add_fvx = -add_v;
                            add_fvy = add_v;

                        }else if(get_mx[0] >= bxx && get_my[0] > byy){

                            div_larg = get_mx[0] - bxx; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 3;
                            add_fvx = -add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] >= byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = get_my[0] - byy; //calc diferencia altura
                            init_mode[0] = 1;
                            add_fvx = add_v;
                            add_fvy = -add_v;

                        }else if(get_mx[0] <= bxx && get_my[0] < byy){

                            div_larg = bxx - get_mx[0]; //calc diferencia largura
                            div_alt = byy - get_my[0]; //calc diferencia altura
                            init_mode[0] = 2;
                            add_fvx = add_v;
                            add_fvy = add_v;

                        }                      
                        
                        //start calc force && degs -> x y (x y coords)
                        float px1, py1;
                        divLA = div_larg / div_alt; //largura / altura
                        divAL = div_alt / div_larg; //altura / largura   

                       if(divLA >= 1){
                        
                            px1 = 1 / 100;
                            py1 = divAL / 100;
                        
                        }else{
                        
                            px1 = divLA / 100;
                            py1 = 1 / 100;
                        
                        }

                        if(divLA >= 1){

                            vetFX[15] = 0.01*add_fvx;
                            vetFY[15] = py1*add_fvy;

                        }else{

                            vetFX[15] = px1*add_fvx;
                            vetFY[15] = 0.01*add_fvy;
                        }
                       
                        vetFX[15] = vetFX[15]; //bxx -  get_mx[0];
                        vetFY[15] = vetFY[15]; //byy -  get_my[0];
                        xM[0] = 15; 
                        xyF[15] = fabs(vetFX[15]) + fabs(vetFY[15]); //total mass force (x + y)
    
                        //end calc force && degs -> px (x y coords)
                        
                        //start 
                        lastProxTarget[0] = 100;
                        add_v = 0;
                        f = 0; 
                        mouseX = 0;
                        mouseY = 0;
                        //end
                    }
                   
                   if(mode_player[1] != '0'){
                     check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                   }
                  //end player if force != 0

                }else if(event.key.keysym.sym == SDLK_b && mode_play_new[0] == 'f'){

                    vetX[15] = return_x[0];
                    vetY[15] = return_y[0];
                    mode_play_new[0] = 't';

                }else if(event.key.keysym.sym == SDLK_UP){

                    if(e_y[0] >= 466){ //end top

                        e_y[0] = e_y[0] - 1; // dec 1 y force effect
                    }

                    //start percentual for affects y u & y d,  x l & x r
                    if(e_y[0] <= 485){ //init center up (continue effect)

                        eq_y = (40 / 2) + 465 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_1 = 100 - percent_y;

                        printf("\nEFFECT Y UP -> %.2f up\n", percent_y_1);

                    }else{ //init center up down (continue effect)

                        eq_y = (40 / 2) + 485 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_2 = percent_y;

                        printf("\nEFFECT Y DOWN -> %.2f up\n", percent_y_2);

                    }
                    //end percentual for effects y u & y d, x l & x r

                }else if(event.key.keysym.sym == SDLK_DOWN){

                    if(e_y[0] <= 504){ //end final down

                        e_y[0] = e_y[0] + 1; //inc 1 force effect
                    }

                    //start percentual for effects y u & y d, l x &  x r
                    if(e_y[0] <= 485){ //init top for center

                        eq_y = (40 / 2) + 465 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_1 = 100 - percent_y;

                        printf("\nEFFECT Y UP -> %.2f down\n", percent_y_1);

                    }else{ //init center + for center

                        eq_y = (40 / 2) + 485 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_2 = percent_y;

                        printf("\nEFFECT Y DOWN -> %.2f down\n", percent_y_2);
                    }
                    //end percentual for effects y u & y d, l x & x r

                }else if(event.key.keysym.sym == SDLK_q){

                    printf("Key %s = quit", SDL_GetKeyName(event.key.keysym.sym));

                    printf("\nSNOOKER GAME END\n");
                    
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    
                    return 0;

                }
    		    break;
    		       		        		     
    		    case SDL_WINDOWEVENT:

    	           if(event.window.windowID == windowID){

                        switch (event.window.event)  {

    	                   case SDL_WINDOWEVENT_CLOSE:

                            //event.type = SDL_QUIT;
    	                    SDL_PushEvent(&event);
    	              	    SDL_DestroyWindow(win);
    					    SDL_Quit();

    	                   break;
    	                }

    	            }

                    case SDL_MOUSEMOTION:{

                        if(mode_play_new[0] == 'f'){

                            mouseX = event.motion.x;
                            mouseY = event.motion.y;

                            mirax_central = mouseX + 0;
                            miray_central = mouseY + 0;

                            return_x[0] = mirax_central;
                            return_y[0] = miray_central;
                        }
                        
                        if(event.motion.x > 910 && event.motion.y > 0 && event.motion.y < 445){
                                   
	                       float val_fv;
	                       float my = event.motion.y;
	                       fmax = my;
	                       if(my > 440){
	                       	my = 440;
	                       }
	                       
	                       mouseYF = my;                                    
                           val_fv = max_fv * my;
	                       f = val_fv;
	                                                        
	    					if(f > 8){
	    						f = 8; //max limit
	    					}
	                     
	                        f_cue = 1;
	                        calc_cue = f_cue * (f / val_fv); //(cue force + mass)
	
	                        add_v = f * 10 + (calc_cue); //f forca -> cue * speed f          
	                        add_v *= 100; //refino base

	                        if(f > 6.5){
	                          add_v *= 1.35; //1.67;
	                        }else if(add_v >= 380){
	                          //add_v *= 1.30;	
	                     	}
	                     			                        

	                        if(event.motion.y < 10){
	                           f = 0;
	                           add_v = 0;
	                           mouseYF = 0;	
	                        }	
                        }
                        
                        if(event.motion.x < 920 && event.motion.y < 465 && activePlay == 2 && cont_play >= cont_prox && mode_play_new[0] != 'f' && m_ang_t != 1){ // player && machine mode of
                            
                            mouseX = event.motion.x;
                            mouseY = event.motion.y;
                            mode_play_new[0] = 'c';
                            bx_central = vetX[15] + 10; //center x bola branca
                            mirax_central = mouseX + 10; //center x mira (mouse cursor)

                            by_central = vetY[15] + 10; //center y bola branca
                            miray_central = mouseY + 10; //center y mira(mouse cursor)

                            get_mx[0] = mirax_central;
                            get_my[0] = miray_central;
                            
                            Bx = vetX[15];
                            By = vetY[15];

                            //mxp[0] = bx_central - mirax_central;
                            //myp[0] =  by_central - miray_central;

                            //start calcs divisao e diferencia largura x altura
                            if(mirax_central <= bx_central && miray_central <= by_central){

                                div_larg = mouseX - Bx; //calc diferencia largura
                                div_alt = mouseY - By; //calc diferencia altura
                                df_x = bx_central - mirax_central; //calculo diferencia largura
                                df_y = by_central - miray_central; //calculo diferencia de altura
                                deg_mode = 0;
                                deg = 0;
                                init_mode[0] = 3;

                            }else if(mirax_central >= bx_central && miray_central >= by_central){

                                div_larg = Bx - mouseX; //calc diferencia de largura
                                div_alt = By - mouseY; //cal diferencia de altura
                                df_x = mirax_central - bx_central; //calculo diferencia largura
                                df_y = miray_central - by_central; //calculo diferencia de altura
                                deg_mode = 180;
                                deg = 180;
                                init_mode[0] = 2;                                             
                            }else if(mirax_central <= bx_central && miray_central >= by_central){
      
                                div_larg = mouseX - Bx; //calc diferencia largura
                                div_alt = By - mouseY; //calc diferencia altura
                                df_x = bx_central - mirax_central; //calculo diferencia largura
                                df_y = miray_central - by_central; //calculo diferencia de altura
                                deg_mode = -90;
                                deg = -90;
                                init_mode[0] = 0;
                            
                            //end calcs divisao e diferencia largura x altura


                            }else if(mirax_central >= bx_central && miray_central <= by_central){
 
                                div_larg = Bx - mouseX; //calc diferencia largura
                                div_alt = mouseY - By; //calc direferencia altura
                                df_x = mirax_central - bx_central; //calculo diferencia largura
                                df_y = by_central - miray_central; //calculo diferencia de altura
                                deg_mode = 90;
                                deg = 90;
                                init_mode[0] = 1;

                            } 
                            //end calcs divisao e diferencia largura x altura
                        }
                    }

    	          break;

    			}
    			//end window close event
		}
        
        if(vetX[15] == 0 && vetY[15] == 0){           
                        
            mode_play_new[0] = 'f';
            pmod[0] = 'f'; 
            //activePlay = 2;
        }
        
        
        if(bmp == true /*&& cpx == 2*/){   	  
        	                	 
           engine_show_all(renderer, vetN, vetM, vx, vy, vetX, vetY, vetAX, vetAY, deg_b, all_k, init_x, mode_play_new, e_x, e_y, init_mode, vetFX, vetFY, xM, xyF, lastProxTarget, cont_ball);          
           
            lastProxTarget[0] = 100;
            
            rpvsmp(renderer, pp);	 
            rpvsmm(renderer, pm);
            	
            if(addv[0] < 10 && mode_play_new[0] != 'c'){
                
                addv[0] = addv[0] + 1;
                
            }
            
          if(m_ang_t == 1){
             		
             	get_mx[0] = mirax_central;
                 get_my[0] = get_my[0] + 0.1;
                              
                  df_x = bx_central - get_mx[0]; //calculo diferencia largura
                 df_y = get_my[0] - by_central;//calculo diferencia de altura
            }
            
            if(mode_play_new[0] == 'c'){
             mode_play_new[0] = 't';
            }
        }
        
        //start
        if(activePlay == 1 && change_mode[0] == 't' && cpx == 2){
          
           if(check_over[0] == 't'  && count_null < 2 /*&& inc_loopm == false*/){
              
              if(sttm == false){
                 machine_route(vetN, vetM, vetFX, vetFY,  vetX, vetY, vetAX, vetAY, rand_on, mode_player, xyF, xM, lastProxTarget);
              }
              
              if(mode_player[1] != '0' && sttm == false){
               check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                              
               
            }         
            //start rotate x y machine
                  
            //start get cmp pos / define mods
            if(sttm == false && fabs(vetFX[15]) > 70 || fabs(vetFY[15]) > 70){  
           
                //getcmp_defmods(lastProxTarget, vetX, vetY, vetFX, vetFY, finit_mode, degmx, degmy, rdeg); 
                sttm = true;

              }
                 
             if(sttm == true && inc_loopm == false){
                 
                 inc_loopm = true;
                 lastProxTarget[0] = 100;
                 rrdeg[0] = 0;
            }  
         
          if(inc_loopm == true /*&& activePlay == 3*/){
                 
                 cont_play++;
                 change_mode[0] = 'n';
                 check_over[0] = 'f';
                 all_k[0] = 0;
                 sttm = false;
                 inc_loopm = false;
                 
                 sleep(2);              
                 
              }
                 
           }                 
            
        }
        //end
        
         
        //start reset mode off
        //
        int count_zero = 0, cont_s = 0;
        all_k[0] = 0;
        
        for (int ak = 0; ak < 15; ak++){
                	
         	if(vetX[ak] > 10 && vetY[ak] > 10){
                  all_k[0] = all_k[0] + 1;
                	count_zero++;
              }else{
              	//count_null++;
              }
              
              if(count_null < 2 && vetN[ak] == 8 && vetX[ak] == 0 && vetY[ak] == 0){
                 count_null = 1;	
              }
         }
        
        float fabxydft = fabs(vetFX[15]) + fabs(vetFY[15]);   
        
        for(int s = 0; s < 15; s++){ 
        
              float fabxy = fabs(vetFX[s]) + fabs(vetFY[s]);
               
              if(vetX[s] > 10 && vetY[s] > 10 && fabxy < 0.5f){
                   cont_s++; //count ball zero mfs
               }     
          }  
          
          if(cont_play > cont_prox && fabxydft < 0.5f && count_zero == cont_s && cpy < 3){
          	
          	cpy++;
          	dftb[0] = 10;
          	
          }   
          
         if(cont_play > cont_prox && count_zero == cont_s && fabxydft < 0.5f && cpy > 0){
	           
	       //start check end eound    
	       /* int cp = 0, cm = 0, ca = 0;
	       */
	       cp = 0;
           cm = 0;
             
            if(count_null == 1){
             
                if(mode_player[1] == '7'){

                    for(int p1 = 0; p1 < 15; p1++){
    
                        if(vetN[p1] < 8 && vetY[p1] != 0 && vetX[p1] != 0){
                            cp++;
                        }                              
                          
                        if(vetN[p1] > 8 && vetY[p1] != 0 && vetX[p1] != 0){
                            cm++;
                        }
                    }

                }else if(mode_player[1] == '9'){

                    for(int p2 = 0; p2 < 15; p2++){
    
                        if(vetN[p2] > 8 && vetY[p2] != 0 && vetX[p2] != 0){
                            cp++;
                        }                                 
                        
                        if(vetN[p2] < 8 && vetY[p2] != 0 && vetX[p2] != 0){
                            cm++;
                        }
                    }
                }
  
                for(int edl = 0; edl < 15; edl++){                          
                                   
                      if(vetN[edl] == 8 && vetX[edl] == 0 && vetY[edl] == 0){
                         	
                       	pmod[0] = 'f';
                       	
                      }                                                   	                                        	             
                }
                
                if(vetN[15] == 0 && vetX[15] < 10 && vetY[15] < 10){
                      	dftb[0] = 1;
                      	
                }else if(vetN[15] == 0 && vetX[15] > 10 && vetY[15] > 10){
                    	 
                    	 dftb[0] = 0;
                    	             	                            	               	                            }
                pvsm(mode_player, pmod, activePlay, dftb, cp, cm, pm, pp); 
                
                if(pmod[0] == 'f'){
                	pmod[0] = 'm';
                }  
                count_null = 2;
              //end check end round
            }
         }  

         // 
                  
        if(change_mode[0] == 'n' && count_zero == cont_s && cont_play > cont_prox && sttm == false && fabxydft < 0.5f && cpx == 2 && cpy > 1){    
               
            int cont_b = 0;
            cont_units[0] = 0; // cont_units[0];
            cpy = 0;
            
            if(change_mode[0] == 'n'){

                int get_y, get_x;
                get_y = e_y[0];
                get_x = e_x[0];
                 
                if(fabxydft < 0.15f && rand_on[0] == 'n' && all_k[0] >= cont_s){

                    bool num_checked = false;                                                                        
	                   //
	                  if(all_k[0] >= cont_s){
	
	                    //activePlay = 0;
	                    f = 0;
	                    add_v = 0;
	
	                    //reset effect adds
	                    e_x[0] = (40 / 2) + 750;
	                    e_y[0] = (40 / 2) + 465;
	                    //reset effect adds  
	                   }
	                   //
                   
                    if(cont_s == count_zero && rand_on[0] == 'n'){

                        for(int ss = 0; ss < 15; ss++){

                            if(vetN[ss] != 0 && vetX[ss] < 10 && vetY[ss] < 10){
                    
                                cont_units[0] = cont_units[0] + 1;
                                if(vetM[ss] == 10){
                                	cont_b += 10;
                                }
                            }
                        }
                    }

                    if(rand_on[0] == 'n' && cont_ball[0] != 0 && cont_b >= 20){

                        int check_range;
                        check_range = cont_ball[0];
                        
                        if(rand_on[0] == 'n'){

                            //start normal 
                            if(activePlay == 2 && check_range > 8){

                                rand_on[0] = 'j';
                                mode_player[0] = 'p';
                                mode_player[1] = '9';

                            }else if(activePlay == 2 && check_range < 8){
                            
                                rand_on[0] = 'j';
                                mode_player[0] = 'p';
                                mode_player[1] = '7';
                            }
                        
                            if(activePlay == 1 && check_range > 8){
                             
                                rand_on[0] = 'm';
                                mode_player[0] = 'p';
                                mode_player[1] = '7';

                            }else if(activePlay == 1 && check_range < 8){
                            
                                rand_on[0] = 'm';
                                mode_player[0] = 'p';
                                mode_player[1] = '9';
                            }
                            //end normal 
                            
                            //start reverse mode
                            if(vetX[15] == 0 && vetY[15] == 0){
                            	
                            	if(mode_player[1] == '7'){
                            		
                            		mode_player[1] = '9';
                            		
                            	}else if(mode_player[1] == '9'){
                            		
                            		mode_player[1] = '7';
                            		
                            	}
                            	
                            }
                            //end reverse mode 
                        }   

                        if(rand_on[0] == 'j' || rand_on[0] == 'm'){

                            status_check[0] = 't';
                        }

                    }
                    
                    //check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                    
                }
               
                if(change_mode[0] == 'n'){                    

                    if(fabxydft < 0.5f){   
                                           
                         cp = 0;
                         cm = 0;
                         ca = 0;
                         
                        if(mode_player[1] == '7'){

                            for(int p1 = 0; p1 < 15; p1++){
            
                                if(vetN[p1] < 8 && vetY[p1] != 0 && vetX[p1] != 0){
                                    cp++;
                                }
                                
                                if(vetN[p1] == 8 && vetX[p1] != 0 && vetY[p1] != 0){
                                	endb = 8;
                                }
                                
                                if(vetN[p1] > 8 && vetY[p1] != 0 && vetX[p1] != 0){
                                    cm++;
                                }
                            }

                        }else if(mode_player[1] == '9'){

                            for(int p2 = 0; p2 < 15; p2++){
            
                                if(vetN[p2] > 8 && vetY[p2] != 0 && vetX[p2] != 0){
                                    cp++;
                                }

                                 if(vetN[p2] == 8 && vetX[p2] != 0 && vetY[p2] != 0){
                                 	endb = 8;
                                }
                                
                                if(vetN[p2] < 8 && vetY[p2] != 0 && vetX[p2] != 0){
                                    cm++;
                                }
                            }
                        }
                        
                       int tb = 0;
                       
                        for(int all = 0; all < 15; all++){

                            if(vetN[all] != 8 && vetX[all] == 0 && vetY[all] == 0){
                                ca++;
                                tb++;
                            }                            
                           
                        }
                        //end check units
                        
                        //start reset mode player x machine 
                        if(activePlay == 1 && change_mode[0] == 'n'){

                            if(activePlay == 1 && vetX[15] <= 10 && vetY[15] <= 10){

                          	     activePlay = 2;
                       	
                           	  if(ca == 1){
    								                                                  
    	                             ctm = 1;
    	                         }
    	                         
    	                          endlp = 0;
                                  endlm = 0;                 
    	                            
                               }else{
                                     
                                 if(mode_player[1] == '0' && ca == 1 && ctm == 0 && ctp == 0){
                                     
                                    activePlay = 1;
                                    check_over[0] = 't';
                                    ctm = 1;
                                    
                                }else if(mode_player[1] == '0' && ca == 1 && ctm == 0 && ctp == 1 || ctm == 1 && ctp == 0){
                               
                               	activePlay = 2;
                                	ctm = 1;
                                	
                                }else if(mode_player[1] == '0' && ca == 1 && ctm == 1 && ctp == 1){
                                	
                                	activePlay = 2;
                                }                                                 
                                
    					     	if(mode_player[1] == '0' && ca == 0){
    								                         
    	                             activePlay = 2;
    	        
    	                          }	                          	                     
    	                        
    	                          	
                                 if(cm == cont_m[0] && mode_player[1] != '0' && ca > 1){
                                      activePlay = 2;
                                        
                                    }else if(cm != cont_m[0] && mode_player[1] != '0'){
                                    	
                                   	check_over[0] = 't';
                                       activePlay = 1;                         
                                    	
                                  }else if(mode_player[1] != '0' && cm == 0){
                                   activePlay = 2;
                                   
                                  }
                                   		                        
                                 //end
                                 
                                  change_mode[0] = 't';
                          }
                          
                        }else if(activePlay == 2 && change_mode[0] == 'n'){

                           if(activePlay == 2 && vetX[15] <= 10 && vetY[15] <= 10){
                            activePlay = 1;
                        	check_over[0] = 't';
                            cpx = 0;
                       	  
                       	 if(ca == 1){
								                                                  
	                             ctp = 1;
	                         }
	                         
	                         endlm = 0;
                             endlp = 0;
	 
	                         change_mode[0] = 't';
	                         
                            }else{
                                
                            if(mode_player[1] == '0' && ca == 1 && ctp == 0 && ctm == 0){
                                
                                activePlay = 2;
                                ctp = 1;
                                
                            }else if(mode_player[1] == '0' && ca == 1 && ctp == 0 && ctm == 1 || ctp == 1 && ctm == 0){
                        
                             activePlay = 1;
                             check_over[0] = 't';                 
                             ctp = 1;
                             
                            }else if(mode_player[1] == '0' && ca == 1 && ctp == 1 && ctm == 1){
                             
                             activePlay = 1;
                             check_over[0] = 't';    
                                              
                            }
                                                                  
	                        if(mode_player[1] == '0' && ca == 0){
	                                
	                             activePlay = 1;
	                             check_over[0] = 't';
	                               
	                        }
	                                            
	                        	                         
	                        if(cp == cont_p[0] && mode_player[1] != '0' && ca > 1){
	                              activePlay = 1; 
	                              check_over[0] = 't';
	                                                         
	                        }else if(cp != cont_p[0] && mode_player[1] != '0'){
	                             activePlay = 2;	
	                      
	                          }else if(mode_player[1] != '0' && cp == 0){
	                       
	                             activePlay = 1;	                           
	                        }
	                            	                          	          
                         //end
                                                     
                             change_mode[0] = 't';
                            
                            }
                        }
                                        
                        //end reset mode playrer x machine
                        
                        //addv[0] = addv[0] + 1;
                        cont_prox = cont_play;
                        m_ang_t = 0;
                        sttm = false;
                        inc_loopm = false; 
                        fmax = 0;
                        if(activePlay == 1){
                    
                    	    if(vetX[15] == 0 && vetY[15] == 0){
				            vetX[15] = 250;
				            vetY[15] = 217;		           
				            mode_play_new[0] = 't';
			
				           }
                          lastProxTarget[0] = 0;                   
                        }
                        mouseYF = 0;
                    }
                }
            }
        }
        //end reset mode off 
        
        //start show in mode off
  
         reset_engine(renderer, cm, cp);       
   
        if(activePlay == 2 && vetFX[15] == 0 && vetFY[15] == 0 && count_zero == cont_s && cont_prox == cont_play){
                           
            rendFor(renderer, f);

            if(vetX[15] != 0 && vetY[15] != 0){
               // rendMiraDest(renderer, mouseX, mouseY);
            }else{
                rendHand(renderer, mouseX, mouseY);
            }

            rendEffects(renderer, e_x, e_y);
            
           rendTaco(renderer, vetN, vetX, vetY, deg, deg_mode, df_x, df_y, p_x, p_y, rrdeg);
         
         //   rend_dest(renderer, deg_mode, vetN, vetX, vetY, get_mx, get_my);

           count_units(renderer, vetX, vetY, cont_units, vetN, mode_player); 
           
           
           status_fs(renderer);
           status_fsd(renderer, mouseYF);  
           
           if(f > 0.1){
           status_jp(renderer);
           }
        }
        //end show in mode off

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderPresent(renderer);
    

	}

    printf("SNOOKER GAME");

    return 0;
	SDL_DestroyWindow(win);
	SDL_Quit();

}
