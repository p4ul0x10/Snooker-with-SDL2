
void gencoord_xy(float wd, float ht, float tx[], float ty[]){

	/*
	wh -> width /height  && height / width
	ax[] -> aux ang vetor x
	ay[] -> aux ang vetor y
	*/
	//start add x y - > angle in px
	
	float la = wd / ht;
	float al = ht / wd;

	if(la >= 1){

		tx[0] = 1;
		ty[0] = al;

	}else{

		tx[0] = la;
		ty[0]= 1;

	}
	//end add x y -> angle in px
}

void rt_tgtb_in_tgtt(float tgtx, float tgty, float dx, float dy, float x[], float y[], int vetN[], int ndst, float tx, float ty, char rpre[], float vx[], float vy[]){
	
	/* */
	float vpx[14], vpy[14];
	int cf = 0;
	float tgtnx, tgtny;
	//start rest all coords
    for(int f = 0; f < 14; f++){
    
    		if(x[f] > 10 && y[f] > 10 && vetN[f] != ndst){
    		vpx[cf] = x[f] + 10;
    		vpy[cf] = y[f] + 10;
             cf++;
      	}
      	if(x[f] < 10 && y[f] < 10){
      		vpx[cf] = 0;
      		vpy[cf] = 0;
      		cf++;
      	}
	}	
    //end rest all coords	
	
	bool run_rt = true, run_loc = false;
	float dstlap, dst_target;
	float dxloc, dyloc, dst_loc, posx, posy;
	float rdx, rdy;
	float aux_x = tgtx + dx;
	float aux_y = tgty + dy;
	
	//rencoord_xy(dstx, dsty, ax, ay);

	  rdx = aux_x - tgtx;
      rdy = aux_y - tgty;
			
     dst_target = sqrtf(rdx*rdx + rdy*rdy);			
     dstlap = 0.5 * (dst_target - 20);
     
     if(dst_target < 20){	
		  				
		while(run_loc == false){
					
				aux_x -= 2*dstlap * (aux_x - tgtx) / dst_target;
				aux_y -= 2*dstlap * (aux_y - tgty) / dst_target;
				//aux_x[b] += fOverlap * (aux_x[b_num_route] - aux_x[b]) / dst_target;
				//aux_y[b] += fOverlap * (aux_y[b_num_route] - aux_y[b]) / dst_target;
												
				 dxloc = aux_x - tgtx;
				 dyloc = aux_y - tgty;
					
				 dst_loc = sqrtf(dxloc*dxloc + dyloc*dyloc);
											
				if(dst_loc >= 20){ 
					
					run_loc = true;
					
				}	
	  	}  
 	} 	
	
	//start check route tgt on tx ty ->table
	float rtangx, rtangy;
	float rpx, rpy, cx, cy;
	int incp =0, vc = 0;
	float dsttx, dstty, dstcx, dstcy;
	
	dstty = fabs(tgty - ty);
	dsttx = fabs(tgtx - tx);
	
    //rtangx = (tgtx - aux_x) * 0.01; //tangent ajust coord
	//rtangy = (tgty - aux_y) * 0.01; //tanget ajust coord
	
	float bx, by, wbx, hxy;
    float vtx[1], vty[1];
    float v = 80;
    
     if(aux_x <= tgtx){
		wbx = tgtx - aux_x;
	}else{
		wbx = aux_x - tgtx;
	}
		
	if(aux_y <= tgty){
		hxy  = tgty - aux_y;
	}else{
		hxy = aux_y - tgty;
	}	
	
	gencoord_xy(wbx, hxy, vtx, vty);

    wbx = vtx[0];
    hxy = vty[0];
    bx = 1;
    by = 1;
    if(aux_x >= tgtx){
      // wbx = -vtx[0];
      //bx = -1;
    }
    
    if(aux_y >= tgty){
    	//hxy = -vty[0];
    	//by = -1;
    }
    
    rtangx = wbx;
    rtangy = hxy;
    
	cx = tgtx;
	cy = tgty;
	
	while(run_rt == true){		
		
		//cx = tgtx + rtangx * bx;
		//cy = tgty + rtangy * by;
	
		 
      if(aux_x <= tgtx){
	 	cx  = tgtx + rtangx * bx;
   	}else{
	 	cx  = tgtx + (-rtangx * bx);
 	 }
		
	  if(aux_y <= tgty){
 		cy  = tgty + rtangy * by;
	  }else{
	 	cy = tgty + (-rtangy * by);
  	}	
		
		dstcx = fabs(cx - tx);
		dstcy = fabs(cy - ty);
		
		if(dstcx > dsttx || dstcy > dstty){
		  // run_rt = false;
		}
		
		if(run_rt == true){
	   
	   	for(int nxt = 0; nxt < 14; nxt++){
	   	    
		       if(run_rt == true && vpx[nxt] > 10 && vpy[nxt] > 10){
		    	   rpx = vpx[nxt];
		       	rpy = vpy[nxt];
	               
	               rdx = cx - rpx;
	               rdy = cy - rpy;
				
	                dst_target = sqrtf(rdx*rdx + rdy*rdy);			
	          
	               if(dst_target < 20){	
			  				
			            run_rt = false;
			           // rpre[0] = '0';
	 	           } 
 	           }	
	   	}	   	
		}
		
		if(tx <= 837 && rpre[0] != '0'){ // cu cd lu ld 
	
	        //start route range false
	         if(cx < 45 && cy > 50 && cy < 400 || cx > 50 && cx < 420 && cy < 40 || cx > 50 && cx < 420 && cy > 408){ // x < 50 && > 50 && < 400
	         	//run_rt = false;
	         	//rpre[0] = '0';
	         }
	         if(cy < 30){
	         	run_rt = false;
	         //	rpre[0] = '0';
	         }
	         if(cy > 410){
	         	run_rt = false;
	         //	rpre[0] = '0';
	         }
	         if(cx < 35){
	         	run_rt = false;
	       //  	rpre[0] = '0';
	         }
	         if(cx > 855){
	         	run_rt = false;
	         }
	        //end route range false 
			if(tx < 440){
			     
			     //start shot checked
	             if(tx == 50 && ty == 50 && cx <= 50 && cx > 40 && cy <= 50 && cy > 40){
	             	run_rt = false; // u l
	             	vc = 1;
	             	rpre[0] = '0';
	             }

				if(tx == 50 && ty == 400 && cx <= 50 && cx > 40 && cy >= 398 && cy < 408){
			       run_rt = false; // d l
			      vc = 1;
			      rpre[0] = '0';
				}
				//end shot checked
				
			}else if(tx > 440){
				
				//start shot checked
	             if(tx == 837 && ty == 50 && cx >= 837 && cy <= 50){
	             	run_rt = false; // u r
	             	vc = 1;
	             	rpre[0] = '0';
	             }

				if(tx == 837 && ty == 400 && cx <= 847 && cx > 837 && cy >= 398 && cy < 408){
			       run_rt = false; // d r
			      vc = 1;
			      rpre[0] = '0';
				}
				//end shot checked
				
			}else{
				
				if(tx == 440 && ty <= 50){
					//start shot checked
					if(cx >= 420 && cx <= 460 && cy < 38){
					run_rt = false; // c u
					vc = 1;
					rpre[0] = '0';
					}
					//end shot checked
				}else if(tx == 440 && ty >= 400){
				      //stsrt shot checked
			       if(cx >= 420 && cx <= 460 && cy > 400){
		   		run_rt = false; // c d
		   		vc = 1;
		   		rpre[0] = '0';
			       }
			       //end shot checked
				}
			}
		} //cu cd lu ld
		
		incp++;
		bx += 1;
		by += 1;
	}
	//end check route tgt on tx ty
	
	//start 
	
    if(vc == 1 && rpre[0] == '0'){
    	
		bx = x[15] + 10;
		by = y[15] + 10;
		
		//wbx = fabs(aux_x - bx);
		//hxy = fabs(aux_y - by);
	    
		if(aux_x <= bx){
			wbx = bx - aux_x;
		}else{
			wbx = aux_x - bx;
		}
		
		if(aux_y <= by){
			hxy  = by - aux_y;
		}else{
			hxy = aux_y - by;
		}	
		gencoord_xy(wbx, hxy, vtx, vty);
		
		if(aux_x <= bx){
			vx[15] = -vtx[0] * v;
		}else{
			vx[15] = vtx[0] * v;
		}
		
		if(aux_y <= by){
			vy[15] = -vty[0] * v;
		}else{
			vy[15] = vty[0] * v;
		}
		rpre[0] = '2';
	}
	//end
}

void pre_check_route(int vetN[], float x[], float y[], int ndst, char rdst[], float tx, float ty, float vx[], float vy[]){

	/* */
	
	float tgtx, tgty, bx, by;
	
	bx = x[15] + 10; //default x
	by = y[15] + 10; //default y
    
    //start tgt coords
    for(int f = 0; f < 15; f++){
    
    		if(vetN[f] == ndst && x[f] > 10 && y[f] > 10){
    		tgtx = x[f] + 10;
    		tgty = y[f] + 10;
  
      	}
	}	
    //end tgt coords 	
    
    float dtgtx, dtgty;
    dtgtx = tx - 1;
    dtgty = ty - 1;
    
    bool loop1 = true, loop2 = true;
    int st = 0;
    float inc = 0, incx = 0, incy = 0, fx = 0, fy = 0;
    float pinc = 0.1, dx, dy;
    float dinix, diniy, dinixd, diniyd, tdxy, tdinixy;
    char rpre[1];
    
    fx = tgtx - 15;
    fy = tgty - 15;
    rpre[0] = '1'; // 1 returned == loop true || 0 returned == loop1 false || 2 returned good route 
    while(loop1 == true){
    
    	//start df point added (max size 2 x 2) stage range max 3 
    	if(incx <= 2 && st <= 150){
    	   
        	fx += 0.1;
    	   // incx += pinc;
    	   	
    	}else if(incy <= 2 && st > 150 && st <= 300){
    
            fy += 0.1;
            //incy += pinc;
    
    	}else if(incx <= 2 && st > 300 && st <= 450){
    
    		fx -= 0.1;
    	    //incx += pinc;
    
		}else if(incy <= 2 && st > 450){
	 
	 	   fy -= 0.1;
           // incy += pinc;
     
		}
	//end df point added (max size 2 x 2) stage range max 3
		
        dx = tgtx - fx; //df initial point x inc added
        dy = tgty - fy; //df initial point y inc added
        
        dinix = fabs(tgtx - tx); //df default init x relative tx x
        diniy = fabs(tgty - ty); //df default init y relative ty y
        
       dinixd = fabs((tgtx + dx) - tx); //df added relative tx tgt
       diniyd = fabs((tgty + dy) - ty); //df added relative ty tgt
       
       tdxy = dinixd + diniyd; //sum eixs coords df added
       tdinixy = dinix + diniy; //sum eixs coords default
       
     //  if(tdxy < tdinixy){ // pre rota > ponto inicial do alvo
          // inc = 2;
      // }else{ //possivel rota livre tgt ~ dst tx ty
       	 rt_tgtb_in_tgtt(tgtx, tgty, dx, dy, x, y, vetN, ndst, tx, ty, rpre, vx, vy);
      // }
    
       if(rpre[0] == '2'){
       	loop1 = false; // break search tang
       	rdst[0] = '1'; // route collision + route tx ty == true
       }
      if(rpre[0] == '0'){
      	//loop1 = false;
      }
       //start check limit mods for stage range max 3
       
       if(st >= 600){
       	loop1 = false; //stop loop 1
       }
       //end check limi mods for stage range max 3
    	
    	//start inc mods relative center -2 + 2 x y
    	st++;
   	//end inc mods
    }
    
    		
}

void route_dft(char rdst[], float degx[], float degy[], float tgtx, float tgty, float x[], float y[], int vetN[], int nb, char type_r[]){
  
	float xdft;
	float ydft;
	float tgx, tgy;
	
	if(type_r[0] == 'd'){
    
    	xdft = x[15];
		ydft = y[15];
		
	}else{
		
		int st = 0;
		for(int t = 0; t < 15; t++){
			
			if(vetN[t] == nb && st == 0){
	     
	     	xdft = x[t];
	     	ydft = y[t];
	     	st++;
    	
    		}
		}
	}
	
    float rx, ry;
    
    bool rt = true;	
    
    //start cmp get mods x y
    float dst_x = xdft - tgtx;
    float dst_y = ydft - tgty;
    float mx, my, cmx, cmy;
    
    if(dst_x > 0){
    	
    	mx = -1;
    	cmx = -1;
    }else{
    	mx = 1;
    	cmx = 1;
    }
    
    if(dst_y > 0){
    	my = -1;
    	cmy = -1;
    }else{
    	my = 1;
    	cmy = 1;
    }
    //end cmp get mods x y
    
    float rdx, rdy, rpx, rpy, dst_target;
    float cx, cy, dst_tx, dst_ty;
    
    cx = xdft;
    cy = ydft;
    
    while(rt == true){
    	
    	//sart chdck if collision == true x y coord
    	for(int c = 0; c < 15; c++){
    		
    		if(rdst[0] == '0'){
    			
	    		if(x[c] > 10 && y[c] > 10 && vetN[c] != nb){
	    			
	    		  rpx = x[c]+10;
			      rpy = y[c]+10;
		               
		           rdx = (cx+10) - rpx;
		           rdy = (cy+10) - rpy;
					
		           dst_target = sqrtf(rdx*rdx + rdy*rdy);			
		          
		            if(dst_target < 20){	
				  				
				            rt = false;
				           rdst[0] = '1';
		 	         } 
	    		}
    		}
    	}
    	//end check if collision == true x y coord
    	
    	//start cmp limits x y min for collision
    	dst_tx = fabs(cx - tgtx);
    	dst_ty = fabs(cy - tgty);
    	
    	if(cmx == -1 && cmy == -1 && cx <= tgtx && cy <= tgty){
    		
    		if(rdst[0] == '0'){
    			rt = false;
    			rdst[0] = '0'; 
    		}
    		
    	}else if(cmx == -1 && cmy == 1 && cx <= tgtx && cy >= tgty){
    		
    		if(rdst[0] == '0'){
    			rt = false;
    			rdst[0] = '0'; 
    		}
    		
    	}else if(cmx == 1 && cmy == 1 && cx >= tgtx && cy >= tgty){
    		
    		if(rdst[0] == '0'){
    			rt = false;
    			rdst[0] = '0'; 
    		}
    		
    	}else if(cmx == 1 && cmy == -1 && cx >= tgtx && cy <= tgty){
    		
    		if(rdst[0] == '0'){
    			rt = false;
    			rdst[0] = '0'; 
    		}
    		
    	}
 
    	//end cmp limits x yin for collision
    	
    	//start cmp set inc route x y
    	cx = xdft + degx[0] * mx;
    	cy = ydft + degy[0] * my;
    
    	if(mx >= 1){
    		mx = mx + 1;
    	}else{
    		mx = mx - 1;
    	}
    	
    	if(my >= 1){
    		my = my + 1;
    	}else{
    		my = my - 1;
    	}    	  
    	// end cmp set inc route x y
 
    	//start stop loop if route == TRUE valid   	
    	if(rdst[0] == '1'){
    		rt = false;
    	}
    	//end stop loop if route == TRUE valid
    }
    
}

void sep_deg(float cx, float cy, float mgx[], float mgy[]){

	 bool run_rt = true, run_loc = false;
					float dstlap, dst_target;
					float dxloc, dyloc, dst_loc, posx, posy;
					float rdx, rdy;
					float aux_x = mgx[0];
					float aux_y = mgy[0];
					
					//rencoord_xy(dstx, dsty, ax, ay);
				
					  rdx = aux_x - cx;
				      rdy = aux_y - cy;
							
				     dst_target = sqrtf(rdx*rdx + rdy*rdy);			
				     dstlap = dst_target - 20;
				     
				     if(dst_target < 20){	
						  				
						while(run_loc == false){
									
								aux_x -= dstlap * (aux_x - cx) / dst_target;
								aux_y -= dstlap * (aux_y - cy) / dst_target;
												
								 dxloc = aux_x - cx;
								 dyloc = aux_y - cy;
									
								 dst_loc = sqrtf(dxloc*dxloc + dyloc*dyloc);
															
								if(dst_loc > 19.8){ 
									
									run_loc = true;
									
								}	
					  	}  
				 	} 	
				 	mgx[0] = aux_x;
				 	mgy[0] = aux_y;	
}

void mode_route(int c_mod, int y_mod, int x_mod, float vet_stx[], float vet_sty[], float cx, float cy){

	float tulx, turx, tdlx, tdrx;
	float tuly, tury, tdly, tdry;
	float tumx, tumy, tdmx, tdmy;	

 
    //start set coord xy table
	tulx = 42;
	tuly = 34;
	
	turx = 835;
	tury = 34;

	tumx = 440;
	tumy = 38;
	
	tdmx = 440;
	tdmy = 400;

	tdlx = 42;
	tdly = 403;
	
	tdrx = 835;
	tdry = 403;	
	//end set coord xy table
	
	//start
	float tx, ty;
	float dx, dy, tdxy;
	if(x_mod == 1 && y_mod == 1){
	   
	   	if(c_mod == 0){
				tx = tulx;
				ty = tuly;
			}else if(c_mod == 1){
				
				dx = cx - 10;
				if(dx < tumx && dx >= 420){
				   tumx = dx+0.5;	
				}
				tx = tumx;
				ty = tumy;
			}else if(c_mod == 2){
			   tx = tdlx;
			   ty = tdly;	
			}	
		
	}else if(x_mod == 1 && y_mod == 0){
	    
	      if(c_mod == 0){
			tx = tdlx;
			ty = tdly;
		}else if(c_mod == 1){
		
			dx = cx - 10;
			if(dx < tdmx && dx >= 420){
				   tdmx = dx+0.5;	
			}
			tx = tdmx;
			ty = tdmy;
			
    	}else if(c_mod == 2){
		   tx = tulx;
		   ty = tuly;	
		}
	
	}else if(x_mod == 0 && y_mod == 1){
		
		if(c_mod == 0){
			tx = turx;
			ty = tury;
		}else if(c_mod == 1){
			
			dx = cx - 10;
			if(dx < tumx && dx >= 420){
				 tumx = dx+0.5;	
			}
			tx = tumx;
			ty = tumy;
			
		}else if(c_mod == 2){
		   tx = tdrx;
		   ty = tdry;	
		}
		
	}else if(x_mod == 0 && y_mod == 0){
	
		if(c_mod == 0){
			tx = tdrx;
			ty = tdry;
		}else if(c_mod == 1){
			
			dx = cx - 10;
			if(dx < tdmx && dx >= 420){
				  tdmx = dx+0.5;	
			}
			tx = tdmx;
			ty = tdmy;
		}else if(c_mod == 2){
		   tx = turx;
		   ty = tury;	
    	}	
	}
	//end
	
	vet_stx[0] = tx;
	vet_sty[0] = ty;
	
}

void get_last_checked(int num[], int b_checked[], float mx[], float my[], float x[], float y[]){
	
	for(int glc = 0; glc < 15; glc++){
		
		if(num[glc] == 8){
		   mx[0] = x[glc];
		   my[0] = y[glc];
		   b_checked[0] = num[glc];
		}
		
	}
	
}

void get_last_checked_null(int num[], int nrand[]){
	
	for(int nr = 0; nr < 15; nr++){
		
		if(num[nr] == 8){
			nrand[0] = nr;
		}
		
	}
}

void getcmp_defmods(int lastProxTarget[], float vetX[], float vetY[], float vetFX[], float vetFY[], float init_mod[], float dfx[], float dfy[], float rdeg[]){

		float dftx = vetX[15] + 0;
		float dfty = vetY[15] + 0;
		
		int idx = lastProxTarget[0];
		
		float width = vetX[15] + vetFX[15];
		float height = vetY[15] + vetFY[15];
		
		int modx, mody;
		float dfxx, dfyy;
		
		dfxx = width - dftx;
		dfyy = height - dfty;
		
		//
		if(dfxx > 0){
			modx = 1;
		}else{
			modx = 0;
		}
		
		if(dfyy > 0){
			mody = 1;
		}else{
			mody = 0;
		}
		//
		
		//
		float cx, cy, mgx[1], mgy[1];
		if(modx == 1 && mody == 1){
	
			init_mod[0] = 0;
			dfx[0] = dftx - width;
			dfy[0] = dfty - height;
		
		 /*   cx = vetX[10] +10;
            cy = vetY[10] + 10;
            mgx[0] = cx-(fabs(vetFX[15])*0.01);
            mgy[0] = cy-(fabs(vetFY[15])*0.01);
            sep_deg(cx, cy, mgx, mgy);*/
    
             
    		rdeg[0] = 90;
			
		}else if(modx == 1 && mody == 0){
	
     	   init_mod[0] = -90;	
		   dfx[0] = dftx - width;
		   dfy[0] = height - dfty;
           rdeg[0] = 0;
         
		}else if(modx == 0 && mody == 1){

			init_mod[0] = 90;
			dfx[0] = width - dftx;
			dfy[0] = dfty - height;
            rdeg[0] = 0;
            
		}else if(modx == 0 && mody == 0){
			
			init_mod[0] = 180;
			dfx[0] = width - dftx;
			dfy[0] = height - dfty;
			rdeg[0] = 90;
		}
		//
}

void machine_route(int vetN[], int m[], float vx[], float vy[], float x[], float y[], float auxx[], float auxy[], char rand_on[], char mode_player[], float xyF[], int xM[], int lastIdx[]){

	int mon = 0;
	float mx[7], my[7];
	int on_rands[7], valid_check[7], b_checked[7], type_v[7];
	float target_inix, target_iniy;
	float cmp_x, cmp_y, wh, hw;


	for(int mc = 0; mc < 7; mc++){

		on_rands[mc] = 0;
		b_checked[mc] = 0;
		valid_check[mc] = 0;
		mx[mc] = 0; 
		my[mc] = 0;
	}

if(mode_player[0] == 'p' && mode_player[1] == '7'){ //machine 9 >=

		for(int on = 0; on < 15; on++){

			if(vetN[on] > 8 && x[on] > 10 && y[on] > 10){

				on_rands[mon] = on;
				b_checked[mon] = vetN[on];
				mx[mon] = x[on];
				my[mon] = y[on];
				mon++;

			}
		}

		//SDL_Quit();

	}else if(mode_player[0] == 'p' && mode_player[1] == '9'){ //machine 7 <= 

		for(int on = 0; on < 15; on++){

			if(vetN[on] < 8 && x[on] > 10 && y[on] > 10){

				on_rands[mon] = on;
				b_checked[mon] = vetN[on];
				mx[mon] = x[on];
				my[mon] = y[on];
				mon++;

			}
		}

		//SDL_Quit();
	}else if(mode_player[0] == '0' && mode_player[1] == '0'){
		
		int nums, num_m = 0;
		
		//
		int nint =0;
		for(int xy = 0; xy < 14; xy++){
			
			if(vetN[xy] != 8 && x[xy] == 0 && y[xy] == 0 && nint == 0){
		
		     nint++;
		     num_m = 1;
		     nums= vetN[xy];
		     
			}
		}
		//
		
		//
		int vnum;
		
		if(num_m == 1){
			
			if(nums > 8){
			  vnum = 1;	
			}else{
			   vnum = 0;	
			}
			
				for(int on = 0; on < 15; on++){
	
					if(vnum == 1 && vetN[on] > 8 && x[on] > 10 && y[on] > 10){
		
						on_rands[mon] = on;
						b_checked[mon] = vetN[on];
						mx[mon] = x[on];
						my[mon] = y[on];
						mon++;
		
					}
					
					if(vnum == 0 && vetN[on] < 8 && x[on] > 10 && y[on] > 10){
		
						on_rands[mon] = on;
						b_checked[mon] = vetN[on];
						mx[mon] = x[on];
						my[mon] = y[on];
						mon++;
		
					}
			}
			
		}
		//
		
		//
		if(num_m == 0){
			
			num_m = rand() % 5+1;
			for(int on = 0; on < 15; on++){
	
				if(num_m % 2 == 0 && vetN[on] < 8 && x[on] > 10 && y[on] > 10){
	
					on_rands[mon] = on;
					b_checked[mon] = vetN[on];
					mx[mon] = x[on];
					my[mon] = y[on];
					mon++;
	
				}
				
				if(num_m % 2 != 0 && vetN[on] > 8 && x[on] > 10 && y[on] > 10){
	
					on_rands[mon] = on;
					b_checked[mon] = vetN[on];
					mx[mon] = x[on];
					my[mon] = y[on];
					mon++;
	
				}
			}
		}
		//
	}
	//end get set ball values

	//start pre check
	int true_r = 0, m_num;
	float stx, sty, center_tabx, center_taby, vet_stx[1], vet_sty[1];
	
	char type_route[1], route_v[1];
	bool true_b = false; 
	
	int c1 = 0, ndst, c2 = 0, cr1 = 0, cr2 = 0; //init counts
	int x_mod= 100, y_mod = 100, c_mod = 0;
	float cx, cy, tx, ty, cb, df_limit, df_limit_y, df_limit_x, bw, bh, cmp_xb, cmp_yb, cmp_xt, cmp_yt;
	float degy[1], degx[1], tpx, tpy, px, py, divAL, target_y, target_x, t = 1, tt = 0.01;
    
    char rdst[1];
    rdst[0] = '0';
    ndst = 15; 
    
	if(mode_player[1] == '7' || mode_player[1] == '9' || mode_player[1] == '0'){
		
		//start
		if(mon == 0 && mode_player[1] != '0'){
		    
		    get_last_checked(vetN, b_checked, mx, my, x, y);
		    
		}
		//end
		
		while(c1 < 7 && true_r == 0){

			cb = mx[c1] + 10;
			//c_mod = 1;
			
			if(mx[c1] > 10 && my[c1] > 10 && b_checked[c1] != 0){

				if(x[15] >= mx[c1] && y[15] >= my[c1]){

					//left up
					//center up
					y_mod = 1;
					x_mod = 1;

				}else if(x[15] >= mx[c1] && y[15] < my[c1]){

					//left down
					//center down
					y_mod = 0;
					x_mod = 1;

				}else if(x[15] < mx[c1] && y[15] >= my[c1]){

					//center up
					//right up
					y_mod = 1;
					x_mod = 0;

				}else if(x[15] < mx[c1] && y[15] < my[c1]){

					//center down
					//right down
					y_mod = 0;
					x_mod = 0;
				}

			} 
			//end get set mods

			cx = mx[c1] + 10;
			cy = my[c1] + 10;
            
            //get last index checked 
            ndst = b_checked[c1];                  
            //get last index checked 
        
         //while(c_mod < 2 && true_r == 0){
          	
	          if(mx[c1] > 10 && my[c1] > 10){
	           	
	           	mode_route(c_mod, y_mod, x_mod, vet_stx, vet_sty, cx, cy);               
			       tx = vet_stx[0];
			       ty = vet_sty[0];
			  	     
			  	if(y_mod == 1 && x_mod == 1){
			  	     	      	  	    			  	     			  	     
			  	     //starttgt in table   
			  	      rdst[0]  = '0';
			  	      type_route[0] = '0';
		                cx -= 10;
			            cy -= 10;
			            
				        cmp_xb = cx - tx;
		                cmp_yb = cy - ty;         
			            			            
		                gencoord_xy(cmp_xb, cmp_yb, degx, degy);
		                route_v[0] = 't';
		                if(c_mod < 2 && cx > tx && cy > ty || c_mod >= 2 && cx > tx && cy < ty){
		                  
		                  route_dft(rdst, degx, degy, tx, ty, x, y, vetN, ndst, route_v);
		                  type_route[0] = '1';
		                }
		              //end tgt in table
		               
		              if(rdst[0] == '0' && type_route[0] == '1'){ // white in tgt
		                if(c_mod < 2){
		                  tpx = cx + (degx[0] * 1);
		                  tpy = cy + (degy[0] * 1);
		                }else{
		                  tpx = cx + (degx[0] * 1);
		                  tpy = cy - (degy[0] * 1);
		                }
		                
		                 degx[0] = tpx;
		                 degy[0] = tpy;
		                
		                 sep_deg(cx, cy, degx, degy);
		                
		                  tpx = degx[0];
		                  tpy = degy[0];
		                	  
			  			cmp_xt = (x[15]) - tpx;
		                  cmp_yt = (y[15]) - tpy;
		                
		                  gencoord_xy(cmp_xt, cmp_yt, degx, degy);
		            
		                  route_v[0] = 'd';
		                  if(c_mod < 2 && tpx < x[15] && tpy < y[15] || c_mod >= 2 && tpx < x[15] && tpy < y[15]){
		                   
			                  route_dft(rdst, degx, degy, cx, cy, x, y, vetN, ndst, route_v);
			                   if(rdst[0] != '1'){			                      
			                 
			                      vx[15] = degx[0] * -80;
			                      vy[15] = degy[0] * -80;
			                     			                      
			                      true_r = 1;
			                      break;
			                  }
		                  }  
		                  
		                }
		                  						
			    }else if (y_mod == 0 && x_mod == 1){
			     
			           cx -= 10;
			           cy -= 10;
			           rdst[0] = '0';
			           type_route[0] = '0';
			           //start tgt in table
				        cmp_xb = cx - tx;
		                cmp_yb = ty - cy;          
		                
		                gencoord_xy(cmp_xb, cmp_yb, degx, degy);
		                route_v[0] = 't';
		                
		                if(c_mod < 2 && cx > tx && cy < ty || c_mod >= 2 && cx > tx && cy > ty){
		                  route_dft(rdst, degx, degy, tx, ty, x, y, vetN, ndst, route_v);
		                  type_route[0] = '1';
		                }
		                //end tgt in table
		                
		                if(rdst[0] == '0' && type_route[0] == '1'){ //white in tgt route check 1 or 0
		                 
		                  if(c_mod < 2){
			                tpx = cx + (degx[0] * 1);
			                tpy = cy - (degy[0] * 1);
			             }else{
			                tpx = cx + (degx[0] * 1);
			                tpy = cy + (degy[0] * 1);
			             }    
			                degx[0] = tpx;
			                degy[0] = tpy;
			                
			                sep_deg(cx, cy, degx, degy);
			                
			                tpx = degx[0];
			                tpy = degy[0];
			                	  
							cmp_xt = (x[15]) - tpx;
			                cmp_yt =  tpy - (y[15]);
			                
			                gencoord_xy(cmp_xt, cmp_yt, degx, degy);
			       
			               route_v[0] = 'd';
			               
			               if(c_mod < 2 && tpx < x[15] && tpy > y[15] || c_mod >= 2 && tpx < x[15] && tpy > y[15]){
			                   route_dft(rdst, degx, degy, cx, cy, x, y, vetN, ndst, route_v);
			                   
			                   if(rdst[0] != '1'){ 			                   
			                    	
				                  vx[15] = degx[0] * -80;
				                  vy[15] = degy[0] * 80;
			                   
			                       true_r = 1;
			                       break;     
			                    }
		                    }  	
		               }
		               		 	      
			     }else if(y_mod == 1 && x_mod == 0){
				      				     		     
				         cx -= 10;
				         cy -= 10; 
				         rdst[0] = '0';
				         type_route[0] = '0';
				         //start tgt in table check route
		                cmp_xb = tx - cx;
		                cmp_yb = cy - ty;             
		                
		                gencoord_xy(cmp_xb, cmp_yb, degx, degy);
		                route_v[0] = 't';
		                if(c_mod < 2 && cx < tx && cy > ty || c_mod >= 2 && cx < tx && cy < ty){
		                  route_dft(rdst, degx, degy, tx, ty, x, y, vetN, ndst, route_v);
		                  type_route[0] = '1';
		                }
		                 //end tgt in table check route
		                 
		                 if(rdst[0] == '0' && type_route[0] == '1'){ //true tgt in dst table
		                 
		                     if(c_mod < 2){
		   	                tpx = cx - (degx[0] * 1);
		 	                  tpy = cy + (degy[0] * 1);
		                    }else{
		                      tpx = cx - (degx[0] * 1);
		                      tpy = cy - (degy[0] * 1);
		                    }
		                    
			                degx[0] = tpx;
			                degy[0] = tpy;
			         
			                sep_deg(cx, cy, degx, degy);
			                tpx = degx[0];
			                tpy = degy[0];	  
						
							cmp_xt = tpx - (x[15] + 0);
			                cmp_yt = (y[15] + 0) - tpy;
			                
			                gencoord_xy(cmp_xt, cmp_yt, degx, degy);
			                route_v[0] = 'd';
			                
			                if(tpx > x[15] && tpy < y[15]){
			                   
			                   route_dft(rdst, degx, degy, cx, cy, x, y, vetN, ndst, route_v);
				                
				                if(rdst[0] != '1'){ //true white in tgt				                 			               
				                    vx[15] = degx[0] * 80;
				                    vy[15] = degy[0] * -80;				                
				                  
				                   true_r = 1;
 			 	                 break;
				 
				                }
			                
			                }
		                 }
		                  
		               }else if(y_mod == 0 && x_mod == 0){
				      
				        cx -= 10;
				        cy -= 10;
				        rdst[0] = '0';
				        type_route[0] = '0';
				        
				        //		    	
				        cmp_xb = tx - cx;
		                cmp_yb = ty - cy;               
		                
		                gencoord_xy(cmp_xb, cmp_yb, degx, degy);
		                route_v[0] = 't';
		                if(c_mod < 2 && cx < tx && cy < ty || c_mod >= 2 && cx < tx && cy > ty){
		                   route_dft(rdst, degx, degy, tx, ty, x, y, vetN, ndst, route_v);
		                   type_route[0] = '1';
		                } 
		                //
		                
		                if(rdst[0] == '0' && type_route[0] == '1'){
		                 
		                    if(c_mod < 2){
			                   tpx = cx - (degx[0] * 1);
			                   tpy = cy - (degy[0] * 1);
		                    }else{
		                       tpx = cx - (degx[0] * 1);
		                       tpy = cy + (degy[0] * 1);
		                    }
		                    
			                degx[0] = tpx;
			                degy[0] = tpy;
			                
			                sep_deg(cx, cy, degx, degy);
			                tpx = degx[0];
			                tpy = degy[0];			  
							cmp_xt = tpx - (x[15] + 0);
			                cmp_yt = tpy - (y[15] + 0);
			                
			                gencoord_xy(cmp_xt, cmp_yt, degx, degy);
			                route_v[0] = 'd';
			                if(c_mod < 2 && tpx > x[15] && tpy > y[15] || c_mod >= 2 && tpx > x[15] && tpy > y[15]){
			                   
			                   route_dft(rdst, degx, degy, cx, cy, x, y, vetN, ndst, route_v);
			                   
				               if(rdst[0] != '1'){				               			                 				              
				                    vx[15] = degx[0] * 80;
			    	                vy[15] = degy[0] * 80;
				                			                   
		   		                 true_r = 1;
			  	                 break;
				               }
			                }
		                }			      	
			      }
			     // c_mod++;
              }
              
              if(c1 >= 6 && c2 == 0){
                 
                 c_mod = 1;
                 c2 = 1;
                 
              }else if(c1 >= 6 && c2 == 1){
                 
                 c_mod = 2;
                 c2 = 2;
                 
              }
		 //  }  
		  	  
	       	c1++;
		   
		    if(c_mod == 1 && c2 == 1){
	
		  	c1 = 0;
	          c2 = 2;
	          
		   }else if(c_mod == 2 && c2 == 2){
	
		  	c1 = 0;
	          c2 = 3;
		   }
		   	          
		}

      
		//start rand shot
		int rt = 0, t1, t2;
		int rand_indx = 0;
		float rtt = fabs(vx[15]) + fabs(vy[15]);
		
		if(rtt  <= 50){
            
       	//start
	  	if(mon == 0 && mode_player[1] != '0'){
		    
		      get_last_checked_null(vetN, on_rands);
		    
	  	}
		  //end
		
           for(int rand = 0; rand < 7; rand++){
           	
           	//
           	if(mon > 0){
                  rand_indx = on_rands[rand];
           	}else{
           		rand_indx = on_rands[0];
           	}
           	//
           	
            	for(int randx = 0; randx < 15; randx++){
            	 
	           	 if(rand_indx == randx && rt == 0 && x[randx] != 0 && y[randx] != 0){
	           	 	
	           	 	rt = 1;
						target_x = x[randx];
						target_y = y[randx];
			
						if(x[15] >= target_x){
							t1 = 1;
						}else{
							t1 = 0;
						}
			
						if(y[15] >= target_y){
							t2 = 1;
						}else{
							t2 = 0;
						}
			
						if(t1 == 1){
							cmp_x = x[15] - target_x;
						}else{
							cmp_x = target_x - x[15];
						}
			
						if(t2 == 1){
							cmp_y = y[15] - target_y;
						}else{
							cmp_y = target_y - y[15];
						}
			
						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;
			
						if(wh >= 1){
							wh = 1;
						}else{
							hw = 1;
						}
			
						if(t1 == 1 && t2 == 1){
							m[15] = 0;
							vx[15] = wh*(-76);
							vy[15] = hw*(-76);
						}else if(t1 == 1 && t2 == 0){
							m[15] = 0;
							vx[15] = wh*(-76);
							vy[15] = hw*76;
						}else if(t1 == 0 && t2 == 1){
							m[15] = 0;
							vx[15] = wh*76;
							vy[15] = hw*(-76);
						}else if(t1 == 0 && t2 == 0){
							m[15] = 0;
							vx[15] = wh*76;
							vy[15] = hw*76;
						}
	           	 }
            	}
           }
	
		}
		
		//end rand shot
	}
	//end pre check final
      xM[0] = 15;
      xyF[15] = fabs(vx[15]) + fabs(vy[15]); 
}

void check_units(int cont_m[], int cont_p[], int vetN[], float vetX[], float vetY[], char mode_player[]){

	int count = 0, cp = 0, cm = 0;
      
     cont_p[0] = cp;
	 cont_m[0] = cm;
	 			
	if(mode_player[1] == '7'){		

		for(int p1 = 0; p1 < 15; p1++){
			
			if(vetN[p1] < 8 && vetY[p1] != 0 && vetX[p1] != 0){
				cp++;
				cont_p[0] = cp;
			}

			if(vetN[p1] > 8 && vetY[p1] != 0 && vetX[p1] != 0){
				cm++;
				cont_m[0] = cm;
			}
		}

	}else if(mode_player[1] == '9'){

		for(int p2 = 0; p2 < 15; p2++){
			
			if(vetN[p2] > 8 && vetY[p2] != 0 && vetX[p2] != 0){
				cp++;
				cont_p[0] = cp;
			}

			if(vetN[p2] < 8 && vetY[p2] != 0 && vetX[p2] != 0){
				cm++;
				cont_m[0] = cm;
			}
		}
	}

}