#---------------------------------
# PPM to PGM Pixel Conversion
#
# Creator: Ryan Oberfelder
# Assembly-type: MIPS assembly Code
#
.data 0x0
p2:		.asciiz	"P2\n"
newline:	.asciiz	"\n"
buffer:		.space 20
	
.text 0x3000

main:   #main(){
#this section is basically to read the p3 and remove it
addi $v0, $zero, 8 #char temp[2]; 
la $a0 buffer
addi $a1, $zero, 3
syscall
la $a0, p2
addi $v0, $zero 4
syscall
la $a0, newline # this is to print a new line
addi $v0, $zero 4
syscall

#this section is the section determining size 
#  scanf("%i %i",&collumn, &row);
addi $v0, $zero, 5 #scanf 
syscall
add $t1, $0, $v0 # input = collumn
add $a0, $0, $v0 # collumn ---> to be printed
addi $v0, $zero, 1 # print(int)
syscall
la $a0, newline # this is to print a new line
addi $v0, $zero 4
syscall
addi $v0, $zero, 5 #scanf 
syscall
add $t0, $0, $v0# &row)
add $a0, $0, $v0 # row ---> to be printed
addi $v0, $zero, 1
syscall
la $a0, newline # this is to print a new line
addi $v0, $zero 4
syscall

# this will print out the max size
addi $v0, $zero, 5 #scanf 
syscall
add $a0, $zero, $v0 # print max ppm_max
addi $v0, $zero, 1 #scanf 
syscall
la $a0, newline # this is to print a new line
addi $v0, $zero 4
syscall

#prep for looping, this includes adding 1
add $a3, $zero, $zero
addi $a2, $t1, 0
addi $a1, $t1, 0
addi $a0, $t0, 1
jal grayScale
#------------ END CODE ---------------
exit:
ori $v0, $0, 10				#System call code 10 for exit
syscall					#exit the program

grayScale:
loopThroughRows: #you have started to work on the iterations.
add $a2, $zero, $a1
addi $a0, $a0, -1
bne $a0, $zero, loopThroughCollumns
jr $ra

loopThroughCollumns:
addi $a2, $a2, -1
addi $sp, $sp, -4
sw $a0, 0($sp)
addi $sp, $sp, -4
sw $a1, 0($sp)
addi $sp, $sp, -4
sw $a2, 0($sp)
addiu $a2, $zero, 255
addi $v0, $zero, 5 #scanf for red
syscall
addu $a3,$zero ,$v0
addi $v0, $zero, 5 #scanf for green
syscall
addu $a3,$a3 ,$v0
addi $v0, $zero, 5 #scanf for blue
syscall
addu $a3,$a3 ,$v0
multu $a3, $a2
mflo $a3
addiu $a0, $zero, 3
multu $a0, $a2
mflo $a0
divu $a3, $a0
mflo $a0
addu $a3 $zero, $zero 
addi $v0, $zero, 1
syscall
la $a0, newline # this is to print a new line
addi $v0, $zero 4
syscall
lw $a2, 0($sp)
addi $sp, $sp, 4
lw $a1, 0($sp)
addi $sp, $sp, 4
lw $a0, 0($sp)
addi $sp, $sp, 4
bne $a2, $zero, loopThroughCollumns
j loopThroughRows