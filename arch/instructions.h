void (*const comms[256]) (void) PROGMEM = {
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
	set_cursor, 
	set_cursor_r, 
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
	line_r,
	line_c,
	clear_screen
};
