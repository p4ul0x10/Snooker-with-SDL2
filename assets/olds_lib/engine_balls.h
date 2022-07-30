void show_init_pos(int n[], float vetX[], float vetY[])
{
	/*
		init pos x y
		count -> counter limit max ball
		step_x -> counter columns
		step_y -> recover and counter coluns y
		inc_x -> increment total x && inc_y -> increment total y
	*/

	int count = 0, step_x = 0, step_y = 0;

	float x, y, x_inc, y_inc, y_limit = 0;

	x = 670;
	y = 217;

	float cl1 = 0.25, cl2 = 0.5, cl3 = 0.75, cl4 = 1;
	while (count < 15)
	{
		//start increment step x -> limit left or right
		if (count == 1 || count == 3 || count == 6 || count == 10)
		{
			step_x++;
		}
		//end increment step x -> limit left or right

		x_inc = x + (1 * step_x) + (17.35 * step_x);

		if (count == 0)
		{
			vetX[count] = x;
			vetY[count] = y;
		}
		else if (count > 0 && count < 3)
		{
			//1 2
			step_y = count - 1;
			y_inc = y - 10 + (20 * step_y);

			vetX[count] = x_inc;
			vetY[count] = y_inc;
		}
		else if (count > 2 && count <= 5)
		{
			//3 4 5
			step_y = count - 2;
			y_inc = y - 40 + (20 * step_y);

			vetX[count] = x_inc;
			vetY[count] = y_inc;
		}
		else if (count > 5 && count < 10)
		{
			//6 7 8 9
			step_y = count - 4;
			y_inc = y - 70 + (20 * step_y);

			vetX[count] = x_inc;
			vetY[count] = y_inc;
		}
		else
		{
			step_y = count - 10;
			y_inc = y - 40 + (20 * step_y);

			vetX[count] = x_inc;
			vetY[count] = y_inc;
		}

		//
		if (count >= 1 && count < 3)
		{
			if (count == 1)
			{
				vetY[count] = vetY[count] - cl1;
			}
			else
			{
				vetY[count] = vetY[count] + cl1;
			}
		}

		if (count >= 3 && count < 6)
		{
			if (count == 3)
			{
				vetY[count] = vetY[count] - 3 * cl1;
			}
			else if (count == 5)
			{
				vetY[count] = vetY[count] + 3 * cl1;
			}
		}

		if (count >= 6 && count < 10)
		{
			if (count == 6)
			{
				vetY[count] = vetY[count] - 1 * cl4;
			}
			else if (count == 9)
			{
				vetY[count] = vetY[count] + 1 * cl4;
			}

			if (count == 7)
			{
				vetY[count] = vetY[count] - 1 * cl1;
			}
			else if (count == 8)
			{
				vetY[count] = vetY[count] + 1 * cl1;
			}
		}

		if (count >= 10 && count <= 14)
		{
			if (count == 10)
			{
				vetY[count] = vetY[count] - 6 * cl1;
			}
			else if (count == 14)
			{
				vetY[count] = vetY[count] + 6 * cl1;
			}

			if (count == 11)
			{
				vetY[count] = vetY[count] - 2 * cl1;
			}
			else if (count == 13)
			{
				vetY[count] = vetY[count] + 2 * cl1;
			}
		}
		//

		count++;
	}
}

void init_random(char random_units[], int n[], int vetM[], float vx[], float vy[], float vetX[], float vetY[], int ini_x[], float ini_y[])
{
	/*
	vetor x -> init pos x
	vetor y -> init pos y
	vetor m = 100 -> null ball < 100 movements true
	vetor n = random num ball -> 1 <= 15
	*/

	int count_ax = 0, count_units = 0, num_n;
	bool add_num = true;

	srand(time(NULL));
	// init random (triangle pos)
	while (random_units[0] == 'f')
	{
		num_n = rand() % 15 + 1;

		if (num_n == 0)
		{
			num_n = 1;
		}

		if (num_n > 15)
		{
			num_n = 15;
		}

		while (count_ax <= count_units)
		{
			if (num_n == n[count_ax])
			{
				add_num = false;
			}
			count_ax++;
		}

		count_ax = 0;

		if (add_num == true)
		{
			n[count_units] = num_n;
			vx[count_units] = 0;
			vy[count_units] = 0;
			vetM[count_units] = 0;
			ini_x[count_units] = num_n;
			ini_y[count_units] = 0;
			count_units++;
		}

		add_num = true;

		if (count_units > 14)
		{
			vetX[15] = 250;
			vetY[15] = 217;
			vetM[15] = 0;
			vx[15] = 0;
			vy[15] = 0;
			n[15] = 0;
			ini_x[15] = 0;
			ini_y[15] = 0;

			show_init_pos(n, vetX, vetY);
			random_units[0] = 't';
		}
	}
	//end init random triangle
}

void check_point(int i_key, int ini_mod[], float vetX[], float vetY[], float vx[], float vy[])
{
	float y_d, x_d;

	y_d = vetY[i_key] + 20;
	x_d = vetX[i_key] + 20;

	if (vetX[i_key] <= 50 && vetY[i_key] <= 62 || vetX[i_key] >= 810 && vetY[i_key] <= 62)
	{
		if (vetY[i_key] < 50 && vetX[i_key] <= 50 || vetY[i_key] < 50 && vetX[i_key] >= 830)
		{
			vetX[i_key] = 0;
			vetY[i_key] = 0;
			//vetM[i_key] = 100;
			vx[i_key] = 0;
			vy[i_key] = 0;
		}
	}

	if (vetX[i_key] <= 50 && vetY[i_key] < 50 || vetX[i_key] >= 830 && vetY[i_key] <= 50)
	{
		vetX[i_key] = 0;
		vetY[i_key] = 0;
		//vetM[i_key] = 100;
		vx[i_key] = 0;
		vy[i_key] = 0;
	}

	if (vetX[i_key] >= 420 && vetX[i_key] <= 460 && vetY[i_key] < 30 ||
		vetX[i_key] >= 420 && vetX[i_key] <= 460 && vetY[i_key] > 407)
	{
		vetX[i_key] = 0;
		vetY[i_key] = 0;
		//vetM[i_key] = 100;
		vx[i_key] = 0;
		vy[i_key] = 0;
	}

	if (vetX[i_key] < 50 && vetY[i_key] > 380 || vetX[i_key] > 830 && vetY[i_key] > 380)
	{
		if (vetY[i_key] > 390 && vetX[i_key] < 50 || vetY[i_key] >= 390 && vetX[i_key] > 830)
		{
			vetX[i_key] = 0;
			vetY[i_key] = 0;
			//vetM[i_key] = 100;
			vx[i_key] = 0;
			vy[i_key] = 0;
		}
	}

	if (vetX[i_key] <= 50 && vetY[i_key] >= 390 || vetX[i_key] >= 830 && vetY[i_key] >= 390)
	{
		vetX[i_key] = 0;
		vetY[i_key] = 0;
		//vetM[i_key] = 100;
		vx[i_key] = 0;
		vy[i_key] = 0;
	}
}

void check_table(int i_key, int vetM[], float aux_x[], float aux_y[], float vetX[], float vetY[], float vx[], float vy[], int ini_xy[], int vetN[], int ini_mod[], int last_b[])
{
	//42 px l esquerda && 837 px r direita && 34 px cima 402 baixo

	float r_x, l_x, u_y, d_y, center_x;

	center_x = aux_x[i_key] + 10;

	//start match point
	float xx[16], yy[16];
	xx[i_key] = aux_x[i_key];
	yy[i_key] = aux_y[i_key];

	check_point(i_key, ini_mod, xx, yy, vx, vy);

	vetX[i_key] = xx[i_key];
	vetY[i_key] = yy[i_key];

	if (vetX[i_key] < 10 && vetY[i_key] < 10)
	{
		if(vetN[i_key] > 0){
   		last_b[0] = vetN[i_key]; // last true shot
   		vetM[i_key] = 10;
		}
	}
	//end match point

	if (vetX[i_key] != 0 && vetY[i_key] != 0)
	{
		if (vy[i_key] <= 0 && vx[i_key] >= 0)
		{
			r_x = aux_x[i_key];
			u_y = aux_y[i_key];

			if (vetM[i_key] != 100)
			{
				if (aux_x[i_key] >= 837 && u_y >= 50)
				{
					ini_mod[0] = 2;
					ini_xy[i_key] = vetN[i_key];
					vx[i_key] = -vx[i_key];
					vetM[i_key] = 100;
				}

				if (u_y <= 35 && r_x <= 420 || u_y <= 35 && aux_x[i_key] >= 460)
				{
					ini_mod[0] = 3;
					ini_xy[i_key] = vetN[i_key];

					vy[i_key] = fabs(vy[i_key]);
					/*yvx = vetY[i_key] + vy[i_key];
					if(yvx <= 35){
						
					}*/

					vetM[i_key] = 100;
				}
			}
		}
		else if (vy[i_key] >= 0 && vx[i_key] <= 0)
		{
			d_y = aux_y[i_key];
			l_x = aux_x[i_key];

			if (vetM[i_key] != 100)
			{
				if (aux_x[i_key] <= 42 && aux_y[i_key] <= 402)
				{
					ini_mod[0] = 3;
					ini_xy[i_key] = vetN[i_key];
					aux_x[i_key] = 42;
					vx[i_key] += 2 * fabs(vx[i_key]);
					vetM[i_key] = 100;
				}

				if (d_y >= 402 && l_x < 420 || d_y >= 402 && aux_x[i_key] > 460)
				{
					ini_mod[0] = 2;
					ini_xy[i_key] = vetN[i_key];

					vy[i_key] = -vy[i_key];
					vetM[i_key] = 100;
				}
			}
		}
		else if (vy[i_key] <= 0 && vx[i_key] <= 0)
		{
			l_x = aux_x[i_key];

			if (vetM[i_key] != 100)
			{
				if (aux_x[i_key] < 42 && aux_y[i_key] >= 50)
				{
					ini_mod[0] = 0;
					ini_xy[i_key] = vetN[i_key];
					aux_x[i_key] = 42;
					vx[i_key] = fabs(vx[i_key]);
					vetM[i_key] = 100;
				}

				if (aux_y[i_key] <= 35 && l_x < 420 || aux_y[i_key] <= 35 && aux_x[i_key] > 460)
				{
					ini_mod[0] = 1;
					ini_xy[i_key] = vetN[i_key];

					vy[i_key] = fabs(vy[i_key]);
					vetM[i_key] = 100;
				}
			}
		}
		else if (vy[i_key] >= 0 && vx[i_key] >= 0)
		{
			r_x = aux_x[i_key];
			d_y = aux_y[i_key];

			if (vetM[i_key] != 100)
			{
				if (aux_x[i_key] >= 837 && d_y <= 402)
				{
					ini_mod[0] = 1;
					ini_xy[i_key] = vetN[i_key];

					vx[i_key] = -vx[i_key];
					vetM[i_key] = 100;
				}

				if (d_y >= 402 && r_x <= 420 || d_y >= 402 && aux_x[i_key] >= 460)
				{
					ini_mod[0] = 0;
					ini_xy[i_key] = vetN[i_key];
					vy[i_key] = -vy[i_key];
					vetM[i_key] = 100;
				}
			}
		}
	}
}

void route_detect_mode(int b_check, float x[], float y[], int m[], float aux_x[], float aux_y[], float fX[], float fY[], float vx[], float vy[], int ini_x[], int ini_y[], int min_fx[], int min_fy[], float final_route_x[], float final_route_y[])
{
	x[b_check] = aux_x[b_check];
	y[b_check] = aux_y[b_check];

	final_route_x[b_check] = x[b_check] + fX[b_check];
	final_route_y[b_check] = y[b_check] + fY[b_check];

	if (x[b_check] <= final_route_x[b_check])
	{
		min_fx[b_check] = 1;
		ini_x[b_check] = 1;
	}
	else
	{
		min_fx[b_check] = -1;
		ini_x[b_check] = -1;
	}

	if (y[b_check] <= final_route_y[b_check])
	{
		min_fy[b_check] = 1;
		ini_y[b_check] = 1;
	}
	else
	{
		min_fy[b_check] = -1;
		ini_y[b_check] = -1;
	}

	vx[b_check] = fabs(fX[b_check]) * 0.01;
	vy[b_check] = fabs(fY[b_check]) * 0.01;
	//vx[b_check] = fabs(fX[b_check]) * 0.01;
	//vy[b_check] = fabs(fY[b_check]) * 0.01;
	m[b_check] = 0;
}

void check_valid_moviments(float vx[], float vy[], float ax[], float ay[], float fX[], float fY[], int vM[], int bn, float xyF[])
{
	float cfxy;
	int last_op_index, count_ac = 0, valid_ac = 0, alloc_count = 0;
	int vmAC[16], vmAI[16];
	bool check_ac = true;

	//start valid not included
	for (int vmc = 0; vmc < 16; ++vmc)
	{
		cfxy = fabs(fX[vmc]) + fabs(fY[vmc]);

		if (cfxy < 1.35f)
		{
			ax[vmc] = 0;
			ay[vmc] = 0;
			vx[vmc] = 0;
			vy[vmc] = 0;
			fX[vmc] = 0;
			fY[vmc] = 0;
			xyF[vmc] = 0;
			vM[vmc] = 100;
		}
	}
	//end valid not included

	//start get realloc valid index
	/* for (int reloc_i = 0; reloc_i < 16; ++reloc_i){
		
		if(vM[reloc_i] != 100){

			vmAI[reloc_i] = vM[reloc_i];
			alloc_count++;

		}else{

			vmAI[reloc_i] = 100;
		}	
	}
	
   for(int reloc_vm = 0; reloc_vm < 16; ++reloc_vm){
		
		vM[reloc_vm] = 100;

	}*/
	//end reset vetor main

	/*
	int valid_index_realloc = 0;
	bool true_b = false;
	
	for(int count_realloc = 0; count_realloc < 16; count_realloc++){

		if(vmAI[count_realloc] != 100 && vmAI[count_realloc] != bn){

			vM[valid_index_realloc] = vmAI[count_realloc];
			valid_index_realloc++; 

		
		}

		if(bn != 100 && vmAI[count_realloc] == bn){
			true_b = true;
		}
	}

	if(bn != 100){

		vM[valid_index_realloc] = bn;
	}*/
}

/*void in_loop_runs(float xyF[], float fX[], fY[], float final_route_x[], float final_route_y[], int end_loop[], int loop_st[]){
	
}*/

void in_loop_st(int loop_st[])
{
	for (int rtn = 0; rtn < 16; rtn++)
	{
		loop_st[rtn] = 0;
	}
}
void check_distance(int v_key, float x[], float y[], float vx[], float vy[], float ax[], float ay[], int n[], float vFX[], float vFY[])
{
	int vetN[16];
	float dfx1, dfy1, dfx2, dfy2, rx1, ry1, rx2, ry2;
	float distance, dx, dy, rx, ry;
	bool check = false;
	float rec_x, rec_y;

	for (int nx1 = 0; nx1 < 16; nx1++)
	{
		for (int nx2 = 15; nx2 >= 0; nx2--)
		{
			if (x[nx2] != 0 && y[nx2] != 0 && nx1 != nx2)
			{
				if (n[nx1] != n[nx2])
				{
					dfx1 = x[nx1];
					dfy1 = y[nx1];

					dfx2 = x[nx2];
					dfy2 = y[nx2];

					dx = dfx1 - dfx2; //200-190
					dy = dfy1 - dfy2;

					distance = sqrtf(dx * dx + dy * dy);

					float limit_xy = fabs((dfx1 - dfx2) * (dfx1 - dfx2) + (dfy1 - dfy2) * (dfy1 - dfy2));

					if (distance < 20)
					{ //collision detected

						//Df distance
						float fOverlap = 0.5 * (distance - 20);
						//realloc pos for collision

						bool run_reloc = true;

						while (run_reloc == true)
						{
							x[nx1] -= fOverlap * (dfx1 - dfx2) / distance;
							y[nx1] -= fOverlap * (dfy1 - dfy2) / distance;
							x[nx2] += fOverlap * (dfx1 - dfx2) / distance;
							y[nx2] += fOverlap * (dfy1 - dfy2) / distance;

							float dst_reloc;
							float dxr, dyr;

							dxr = x[nx1] - x[nx2];
							dyr = y[nx1] - y[nx2];

							dst_reloc = sqrtf(dxr * dxr + dyr * dyr);

							if (dst_reloc >= 21)
							{
								run_reloc = false;
							}
						}
					}
				}
			}
		}
	}
}

void trace_route(float x[], float y[], float fX[], float fY[], float vx[], float vy[], float ax[], float ay[], int num[], int nb_check, int vM[], int ini_xy[], int ini_mod[], int m[], float xyF[], int last_b[])
{
	//start variable run sys collision and dest route (coords)
	int min_fx[16], min_fy[16], ini_x[16], ini_y[16];
	int end_loop[16], loop_st[16], count_st = 0, count_dec = 16;
	float final_route_x[16], final_route_y[16], ffxy[16];
	float aux_x[16], aux_y[16], dst_target, dx, dy, dfdx, dfdy, calc_vy, calc_vx;

	bool next_route = true, find_collision = false;
	bool run_loc = false, loop_status = false;
	//end variables run sys collison and dest route (coords)

	//start mass mass force (max get set vals)
	float max_mass_force_on, mass_object_b;
	float total_percent_sum, total_percent_mf, percent_df_mf, percent_mf_xy, current_mf_xy;

	mass_object_b = 20;

	float fx_min, fy_min, start_loop, c_mf_xy;
	float mf = 0.99, dec_pmf, df_dec_pmf, percent_dec_pmf, total_dec_mf, dec_percent_mf;

	for (int fxy = 0; fxy < 16; fxy++)
	{
		float tfxy = fabs(fX[fxy]) + fabs(fY[fxy]);
		ffxy[fxy] = tfxy;
	}

	for (int b_check = 0; b_check < 16; b_check++)
	{
		if (ffxy[b_check] >= 1.35f)
		{
			current_mf_xy = fabs(fX[b_check]) + fabs(fY[b_check]);
			start_loop = current_mf_xy;
			dec_pmf = (current_mf_xy * xyF[b_check]) / xyF[b_check];

			df_dec_pmf = xyF[b_check] - dec_pmf;

			percent_dec_pmf = (df_dec_pmf / xyF[b_check]) * 100;

			dec_percent_mf = (0.99 / 100) * percent_dec_pmf;

			total_dec_mf = mf - dec_percent_mf;
			if (total_dec_mf < 0.91)
			{
				total_dec_mf = 0.91;
			}
			fx_min = fX[b_check] * total_dec_mf;
			fy_min = fY[b_check] * total_dec_mf;

			current_mf_xy = fabs(fx_min) + fabs(fy_min);
			//end

			max_mass_force_on = xyF[b_check];

			percent_mf_xy = (current_mf_xy * max_mass_force_on) / xyF[b_check]; //calc current mass force (percentual ) * max received / max

			percent_df_mf = xyF[b_check] - percent_mf_xy; //rest diferrential max receive - current force max with max receive

			total_percent_mf = xyF[b_check] - percent_df_mf; //decreased mass force on time

			total_percent_sum = total_percent_mf / 2; //current percent mass force (x y)

			float fxx, fxy;

			fxx = total_percent_sum;
			fxy = total_percent_sum;

			calc_vx = fx_min;
			calc_vy = fy_min;
			fX[b_check] = calc_vx;
			fY[b_check] = calc_vy;
			//	vM[b_check] = 100;

			//

			end_loop[b_check] = 1;
			count_st++;
			loop_status = true;
			//
		}
		else
		{
			end_loop[b_check] = 0;
		}
		loop_st[b_check] = 0;

		//end mass force calcs(max get set vals)
	}
	//start init trace point (destination x y coords)
	float center_x1[16];
	float center_y1[16];
	for (int b_check = 0; b_check < 16; b_check++)
	{
		min_fx[b_check] = 0;
		ini_x[b_check] = 0;
		min_fy[b_check] = 0;
		ini_y[b_check] = 0;

		vx[b_check] = 0;
		vy[b_check] = 0;

		if (ffxy[b_check] >= 1.40f)
		{
			final_route_x[b_check] = x[b_check] + fX[b_check];
			final_route_y[b_check] = y[b_check] + fY[b_check];

			if (x[b_check] <= final_route_x[b_check])
			{
				min_fx[b_check] = 1;
				ini_x[b_check] = 1;

				center_x1[b_check] = fabs((final_route_x[b_check]) - (x[b_check]));
			}
			else
			{
				min_fx[b_check] = -1;
				ini_x[b_check] = -1;

				center_x1[b_check] = fabs((x[b_check]) - (final_route_x[b_check]));
			}

			if (y[b_check] <= final_route_y[b_check])
			{
				min_fy[b_check] = 1;
				ini_y[b_check] = 1;

				center_y1[b_check] = fabs((final_route_y[b_check]) - (y[b_check]));
			}
			else
			{
				min_fy[b_check] = -1;
				ini_y[b_check] = -1;

				center_y1[b_check] = fabs((y[b_check]) - (final_route_y[b_check]));
			}

			/*float rx2, ry2, txy, tyx;
				float px_wh, px_hw;
				
				rx2 = center_x1[b_check] / center_y1[b_check];
				ry2 = center_y1[b_check] / center_x1[b_check];
				
				px_wh = rx2;
				px_hw = ry2;
				
				if(px_wh >= 1){
			
			        vx[b_check] = 1;
			        vy[b_check] = px_hw;
			
			    }else{
			
			        vx[b_check] = px_wh;
			        vy[b_check] = 1;
			
			    }*/

			vx[b_check] = fabs(fX[b_check]) * 0.01;
			vy[b_check] = fabs(fY[b_check]) * 0.01;
			//vx[b_check] = fX[b_check] * 0.01;
			//vy[b_check] = fY[b_check] * 0.01;
		}

		aux_x[b_check] = x[b_check];
		aux_y[b_check] = y[b_check];
	}
	//end init trace point (destination x y coords)

	//start pre check route
	bool run_all = true;
	int dec_all = count_st, ret_loop = 0, next_inc = 100;

	while (dec_all > 0)
	{
		find_collision = false;
		next_route = true;

		for (int b_num_route = 0; b_num_route < 16; b_num_route++)
		{
			loop_st[b_num_route] = loop_st[b_num_route] + 1;

			if (loop_st[b_num_route] > 99 && end_loop[b_num_route] > 0)
			{
				//end_loop[b_num_route] = 0;
				dec_all--;
			}

			if (ffxy[b_num_route] >= 1.35f && end_loop[b_num_route] > 0 && loop_st[b_num_route] <= next_inc && x[b_num_route] != 0 && y[b_num_route] != 0)
			{
				next_route = true;

				//while(next_route == true){

				//start check limit route x y (stop run times route)
				if (next_route == true)
				{
					//start next coord x y -> aux vet (for check collision)
					aux_x[b_num_route] = x[b_num_route] + vx[b_num_route] * min_fx[b_num_route];
					aux_y[b_num_route] = y[b_num_route] + vy[b_num_route] * min_fy[b_num_route];
					//end next coord x y -> aux vet (for check collision)

					//start recalc next trace point
					/*   if(min_fx[b_num_route] >= 1){
						min_fx[b_num_route] = min_fx[b_num_route] + 1;
					}else{
						min_fx[b_num_route] = min_fx[b_num_route] - 1;
					}
			
					if(min_fy[b_num_route] >= 1){
						min_fy[b_num_route] = min_fy[b_num_route] + 1;
					}else{
						min_fy[b_num_route] = min_fy[b_num_route] - 1;
					}*/
					//end recalc next trace point

					if (ini_x[b_num_route] == 1 && ini_y[b_num_route] == -1 && aux_x[b_num_route] >= final_route_x[b_num_route] && aux_y[b_num_route] <= final_route_y[b_num_route])
					{
						//		next_route = false;
						//		end_loop[b_num_route] = 0;
					}
					else if (ini_x[b_num_route] == 1 && ini_y[b_num_route] == 1 && aux_x[b_num_route] >= final_route_x[b_num_route] && aux_y[b_num_route] >= final_route_y[b_num_route])
					{
						//		next_route = false;
						//	end_loop[b_num_route] = 0;
					}
					else if (ini_x[b_num_route] == -1 && ini_y[b_num_route] == 1 && aux_x[b_num_route] <= final_route_x[b_num_route] && aux_y[b_num_route] >= final_route_y[b_num_route])
					{
						//		next_route = false;
						//		end_loop[b_num_route] = 0;
					}
					else if (ini_x[b_num_route] == -1 && ini_y[b_num_route] == -1 && aux_x[b_num_route] <= final_route_x[b_num_route] && aux_y[b_num_route] <= final_route_y[b_num_route])
					{
						//			next_route = false;
						//			end_loop[b_num_route] = 0;
					}
					//   vM[b_num_route] = vM[b_num_route] - 1;
				}
				//end check limit route x y ()

				//start stop engine (check coords for collision)
			    if(x[b_num_route] != 0 && y[b_num_route] != 0){
					check_table(b_num_route, m, aux_x, aux_y, x, y, fX, fY, ini_xy, num, ini_mod, last_b);
		     	}
				if (x[b_num_route] <= 10 && y[b_num_route] <= 10)
				{
					//next_route = false;
					if (m[b_num_route] != 10)
					{
						m[b_num_route] = 1;
					}
					end_loop[b_num_route] = 0;
					//check_valid_moviments(vx, vy, ax, ay, fX, fY, vM, b_num_route, xyF);
					loop_st[b_num_route] = 100;
					dec_all--;
				}

				if (m[b_num_route] == 100)
				{
					route_detect_mode(b_num_route, x, y, m, aux_x, aux_y, fX, fY, vx, vy, ini_x, ini_y, min_fx, min_fy, final_route_x, final_route_y);
					// next_route = false;
					//end_loop[b_num_route] = 0;
					//dec_all--;
					// loop_st[b_num_route] = 0;
				}

				if (m[b_num_route] != 1 && m[b_num_route] != 10)
				{
					if (find_collision == false && end_loop[b_num_route] == 0)
					{
						x[b_num_route] = aux_x[b_num_route];
						y[b_num_route] = aux_y[b_num_route];
					}
					else
					{
						//end_loop[b_num_route] = 0;
						x[b_num_route] = aux_x[b_num_route];
						y[b_num_route] = aux_y[b_num_route];
						//	next_route = false;
					}
					//end stop engine (check coords for collision)
				}
				find_collision = false;

				if (find_collision == false && ffxy[b_num_route] >= 1.35f && end_loop[b_num_route] > 0 && x[b_num_route] != 0 && y[b_num_route] != 0)
				{
					for (int b = 15; b >= 0; --b)
					{
						if (x[b] != 0 && y[b] != 0 && num[b] != num[b_num_route]/* && find_collision == false*/)
						{
							dx = aux_x[b_num_route] - aux_x[b];
							dy = aux_y[b_num_route] - aux_y[b];

							dst_target = sqrtf(dx * dx + dy * dy);

							if (find_collision == false && dst_target < 20)
							{
								//find_collision = true;

								float fdst = (dst_target - 21) / 2; //
								aux_x[b_num_route] -= fdst * (aux_x[b_num_route] - aux_x[b]) / dst_target;
								aux_y[b_num_route] -= fdst * (aux_y[b_num_route] - aux_y[b]) / dst_target;
								aux_x[b] += fdst * (aux_x[b_num_route] - aux_x[b]) / dst_target;
								aux_y[b] += fdst * (aux_y[b_num_route] - aux_y[b]) / dst_target;
								//

								x[b_num_route] = aux_x[b_num_route];
								y[b_num_route] = aux_y[b_num_route];
								x[b] = aux_x[b];
								y[b] = aux_y[b];

								set_dest_xy(b_num_route, b, x, y, vx, vy, ax, ay, fX, fY);

								xyF[b_num_route] = fabs(fX[b_num_route]) + fabs(fY[b_num_route]);
								xyF[b] = fabs(fX[b]) + fabs(fY[b]);
                                 
                                 					                 route_detect_mode(b_num_route, x, y, m, aux_x, aux_y, fX, fY, vx, vy, ini_x, ini_y, min_fx, min_fy, final_route_x, final_route_y);
                                					route_detect_mode(b, x, y, m, aux_x, aux_y, fX, fY, vx, vy, ini_x, ini_y, min_fx, min_fy, final_route_x, final_route_y);
                                					
								/*if (end_loop[b] > 0)
								{
									loop_st[b] = 100;
									end_loop[b] = 0;
									dec_all--;
								}

								if (end_loop[b_num_route] > 0)
								{
									loop_st[b_num_route] = 100;
									dec_all--;
								}
								end_loop[b_num_route] = 0;*/
							}
						}
					}
				}
				//end engine all possibles ball
				//next_route = false;

				//}
				if (loop_st[b_num_route] > 99 && end_loop[b_num_route] != 0)
				{
					dec_all--;
					end_loop[b_num_route] = 0;
				}
			}
		}

		//end

		//in_loop_st(loop_st);

		/*for(int b_num_route = 0; b_num_route < 16; b_num_route++){
	            	
	      
		          }*/
		//end collision detect
		//start auto route stop detect

		/*  for(int end_run = 0; end_run < 16; end_run++){		  
	
		    if(end_loop[end_run] > 0){
			  ret_loop = 1;
		 }	 */
		//end loop stop
		// check_distance(0, x, y, vx, vy, ax, ay, num, fX, fY);
		if (dec_all < 1)
		{
			/*for(int end_run = 0; end_run < 16; end_run++){		  
		
			        if(end_loop[end_run] > 0){
			    	  ret_loop = 1;
		       	 }	 
		     	}
		        if(ret_loop == 1){
		       	ret_loop = -1;
		       	break;
		        }*/
			dec_all = -1;
		}
	}

	//end pre check route
}

void moviments_on(int vM[], float x[], float y[], float vx[], float vy[], float ax[], float ay[], int num[], float vFX[], float vFY[], int lastProxTarget[], int ini_xy[], int ini_mod[], int m[], float xyF[])
{
	int aux_target, id_prox, prox = 15, allProx = 15;

	bool next_target = false, run_prox = true, run_all = false;

	//moviments_on(v_key, x, y, vx, vy, ax, ay, n, vFXY, vFYX, vFX, vFY, addv);
	//array for store valid moviments (fix last in first out)

	//start get first (last count)
	/* for(int pl = 15; pl >= 0; pl--){

		if(vM[pl] != 100 && run_all == false){

			int untv = 15 - pl;
			int untf = 15 - untv;

			prox = untf;
			run_all = true;
			
		}
	}*/
	// trace_route(x, y, vFX, vFY, vx, vy, ax, ay, num, 0, vM, ini_xy, ini_mod, m, xyF);

	//end get first (last count)

	//start run times (last in first out)
	/*while(run_prox == true && run_all == true){
		
		
		aux_target = vM[prox];
		next_target = false;

		
		  if(prox == 0){
            	run_prox = false;
           }
           
		if(vM[prox] != 100 && x[aux_target] != 0 && y[aux_target] != 0){		
            
			trace_route(x, y, vFX, vFY, vx, vy, ax, ay, num, aux_target, vM, ini_xy, ini_mod, m, xyF); 
		}
		
		if(next_target == false){
			prox = prox - 1;
		}
		
		
	}*/
	//end run time main loop (last in first out)
}

void engine_show_all(SDL_Renderer *rendEngine, int n[], int m[], float vx[], float vy[], float x[], float y[], float ax[], float ay[], float deg[], int key_all[], int ini_xy[], char mode_p[], int ex[], int ey[], int ini_mod[], float vFX[], float vFY[], int vM[], float xyF[], int lastProxTarget[], int last_b[])
{
	int vet_kmain[16], limit_count = 10;
	float aux_x[16], aux_y[16];
	char mode_add[2];

	//start show renderer balls && check tables
	SDL_Rect Texture_rect;

	Texture_rect.w = 20;
	Texture_rect.h = 20;

	int v_key, count = 15;
	float t_x, t_y;
	bool run = true, run_r = false;

	//start pointers decrarement
	SDL_Surface *Surface;
	SDL_Texture *Texture;

	SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
	//end pointers declarement
	if (lastProxTarget[0] == 100)
	{
		check_valid_moviments(vx, vy, ax, ay, vFX, vFY, vM, 100, xyF);
		trace_route(x, y, vFX, vFY, vx, vy, ax, ay, n, 0, vM, ini_xy, ini_mod, m, xyF, last_b);
	}

	while (run == true)
	{
		v_key = count;

		aux_x[v_key] = x[v_key];
		aux_y[v_key] = y[v_key];
		if(aux_x[v_key] > 10 && aux_y[v_key] > 10){
		check_table(v_key, m, aux_x, aux_y, x, y, vFX, vFY, ini_xy, n, ini_mod, last_b);
		}
		if (x[v_key] > 0 && y[v_key] > 0)
		{
		//	check_table(v_key, m, x, y, vFX, vFY, ini_xy, n, ini_mod);

			//start
			float cfxy = fabs(vFX[v_key]) + fabs(vFY[v_key]);
			//printf("\nCALC F %.2f %i \n", cfxy, v_key);
			//end stop / reset engine 
			
			if (x[15] == 0 && y[15] == 0)
			{
				mode_p[0] = 'f';
			}

			//end stop / reset engines

			//start show effect side
			if (vx[v_key] > vy[v_key])
			{
				deg[v_key] = 2 * vFX[v_key] * (vFX[v_key] * 90 * vx[v_key]);
			}
			else
			{
				deg[v_key] = 2 * vFY[v_key] * (vFY[v_key] * 90 * vy[v_key]);
			}
			//end show effect side

			if (n[v_key] == 1)
			{
				Surface = IMG_Load("assets/images/b1.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 2)
			{
				Surface = IMG_Load("assets/images/b2.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 3)
			{
				Surface = IMG_Load("assets/images/b3.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 4)
			{
				Surface = IMG_Load("assets/images/b4.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 5)
			{
				Surface = IMG_Load("assets/images/b5.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 6)
			{
				Surface = IMG_Load("assets/images/b6.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 7)
			{
				Surface = IMG_Load("assets/images/b7.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 8)
			{
				Surface = IMG_Load("assets/images/b8.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 9)
			{
				Surface = IMG_Load("assets/images/b9.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 10)
			{
				Surface = IMG_Load("assets/images/b10.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 11)
			{
				Surface = IMG_Load("assets/images/b11.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 12)
			{
				Surface = IMG_Load("assets/images/b12.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 13)
			{
				Surface = IMG_Load("assets/images/b13.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 14)
			{
				Surface = IMG_Load("assets/images/b14.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 15)
			{
				Surface = IMG_Load("assets/images/b15.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
			else if (n[v_key] == 0)
			{
				Surface = IMG_Load("assets/images/bm.png");
				Texture_rect.x = x[v_key];
				Texture_rect.y = y[v_key];

				Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
				SDL_FreeSurface(Surface);

				SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg[v_key], NULL, flip_x);
				SDL_DestroyTexture(Texture);
			}
		}

		if (count < 1)
		{
			run = false; // end loop
		}

		if (count != 0)
		{
			count--; //increment ball count if limit true
		}
	}
	//sep_distance(0, x, y, vx, vy, ax, ay, n, vFX, vFY);
}
//move balls functions
