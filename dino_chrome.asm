mov r0, 28
mov r1, 25

circle 4, 77, 5
line 74,9,70,13
line 77,9,77,15
line 73,5,68,5
next:
bmp r1, 32, cact
bmp 10, r0, dino
draw
ji q
a:
circle 10, 10, 10
scol 0
circle 10, 10, 10
scol 1
jmp a
q:
sub r0, 21
jmp next
dino:
dd 20,3
dd 192,0,0,0,0,0,0,128,192,254,255,253,255,255,127,95,95,95,31,30
dd 15,31,62,124,252,254,255,255,255,255,255,127,63,31,2,6,0,0,0,0
dd 0,0,0,0,0,15,11,1,0,1,15,8,0,0,0,0,0,0,0,0
cact:
dd 12,2
dd 224,240,224,0,254,255,255,254,112,124,62,28
dd 1,3,7,7,255,255,255,255,0,0,0,0
