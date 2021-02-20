void (*comms[256]) (void) = {
	add_rr, 
	add_rc, 
	sub_rr, 
	sub_rc, 
	mul_rr, 
	mul_rc,
	div_rr, 
	div_rc, 
	mov_rm, 
	mov_mr, 
	mov_rr, 
	mov_rc,
	mov_rmor, 
	mov_morr, 
	and_rr, 
	and_rc, 
	or_rr, 
	or_rc,
	xor_rr, 
	xor_rc, 
	cmp_rr, 
	cmp_rc, 
	jmp,
	jmp_c,
	lp,
	push,
	pop,
	mod_rr, 
	mod_rc, 
	print_num,
	print_line, 
	del_r,
	del_c,
	snd_r,
	snd_c, 
	to_int,
	get_key, 
	set_cursor_r, 
	set_cursor, 
	draw_screen,
	call, 
	ret,
	rnd,
	print_int,
	movb_rm,
	movb_mr,
	movb_rmor,
	movb_morr,
	pow_rr,
	pow_rc, 
	point_rr,
	point_cc,
	circle_r,
	circle_c,
	circle_rc,
	line_r,
	line_c,
	line_rc,
	clear_screen,
	rect_r,
	rect_c,
	rect_rc,
	bmp_rc,
	bmp_cr,
	bmp_rr,
	bmp_cc,
	scol,
	f_add_rr, 
	f_add_rc, 
	f_sub_rr, 
	f_sub_rc, 
	f_mul_rr, 
	f_mul_rc,
	f_div_rr, 
	f_div_rc, 
	f_pow_rr,
	f_pow_rc,
	f_cmp_rr,
	f_cmp_rc,
	shr_rr,
	shr_rc,
	shl_rr,
	shl_rc,
	fmov_rm,
	fmov_mr,
	fmov_rr,
	fmov_rc,
	fmov_rmor,
	fmov_morr
};
