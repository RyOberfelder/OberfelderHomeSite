# ----------------------
# String Conversion and Factorial
#
# Creator: Ryan Oberfelder
# Assembly-type: MIPS
#
.data 0x0
newline:	.asciiz	"\n"
buffer:		.byte 20
	
.text 0x3000

#-----------------------MAIN--------------------------
main:		#main(){

jal a_to_i							# Jumps and links to our function
addi $a0, $v0, 0
jal factorial
addi $t0, $a0, 0
addi $a0, $v0, 0
addi $v0, $zero, 1 						# print(int)
syscall
beq $t0, $zero, exit
la $a0, newline 						# this is to print a new line
addi $v0, $zero 4						# print string
syscall						
j main
#------------

#------------ END CODE ---------------
exit:
ori $v0, $0, 10							#System call code 10 for exit
syscall								#exit the program
#-------------------------------------

#-----------------------------------------------------



#--------------a_to_i-------------------
# The Assumption of this section
# 	Integer will be continuelly printed in $v0

a_to_i:
#----ReadInteger------
readInteger:
#This is where the data collection would start
addi $v0, $zero, 8 						# tells system to read a string 
la $a0 buffer							# loads buffer
addi $a1, $zero, 21						# this is because the num Chars will be less then 20 + null
syscall
#---------------------

#----PreWhile---------
preWhile:
#---STORE----
addi $sp, $sp, -4
sw $ra, 0($sp)							# stores the arguments
addi $sp, $sp, -4
sw $a0, 0($sp)
addi $sp, $sp, -4
sw $a1, 0($sp)
addi $sp, $sp, -4
sw $a2, 0($sp)
addi $sp, $sp, -4
sw $a3, 0($sp)
#------------
addiu $a0, $zero, 0 						# zeros the value
addiu $a1, $zero, 0 						# zeros the value
addiu $a2, $zero, 0 						# zeros the value
addiu $a3, $zero, 10 						# tens the value
#---------------------

#----MainWhile--------
mainWhile:
lbu $a2, buffer($a1)						# loads a char into a2 at the index a1
beq  $a2, $a3, afterWhile					# branches if the char == 10, otherwise known as '\n' 
addiu $a3, $zero, 10						# sets a3 == to 10 again
multu $a0, $a3							# muliplies our old value by 10 to make space for the new digit
mflo $a0, 							# sets the a0/ old value to the 10 shifted value
addiu $a2, $a2, -48						# shifts ascii code into real digits
addu $a0, $a2, $a0						# adds the shifted ascii digit into the larger integer
addiu $a1, $a1, 1						# increases our affective a1 iteratior by 1
j mainWhile 							# repeats the loops unless the beq while statement is true
#---------------------

#----afterWhile-------
afterWhile:
addi $v0, $a0, 0 						# stores the value into $v0
#--UNSTORE---							# restores all arguments values as they were before 
lw $a3, 0($sp)
addi $sp, $sp, 4
lw $a2, 0($sp)
addi $sp, $sp, 4
lw $a1, 0($sp)
addi $sp, $sp, 4
lw $a0, 0($sp)
addi $sp, $sp, 4
lw $ra, 0($sp)
addi $sp, $sp, 4
#------------
jr $ra								# jump returns to where we left.
#----------------------

#---------------------------------------


#-----------------------Factorial--------------------------
# assumes this arguements
	#a0 will be the number to factorial
factorial:
#---STORE----
addi $sp, $sp, -4
sw $ra, 0($sp) 
addi $sp, $sp, -4
sw $a0, 0($sp)
addi $sp, $sp, -4
sw $a1, 0($sp)
addi $sp, $sp, -4
sw $a2, 0($sp)
addi $sp, $sp, -4
sw $a3, 0($sp)
#------------
beq $a0, $zero, extraCaseZero 
addiu $a3, $zero, 1
sltiu $a2, $a0, 2
addiu $a1, $0, 1
beq $a2, $a3 extraCase
addiu $a2, $zero, 0
addiu $a3, $zero, 0
addiu $a1, $a0, 0
addiu $v0, $a0, 0

#-------innerFactorial:------
innerFactorial:
addi $sp, $sp, -4							# stores address
sw $ra, 0($sp)	
addiu $a3, $0, 1							# sets to 1
beq $a1, $a3 innerFac							# branches if a1 is 1
addi $a1, $a1, -1							# sets a1--
addi $sp, $sp, -4							# stores a1
sw $a1, 0($sp)
jal innerFactorial							# sets ra = here
lw $a1, 0($sp)
addi $sp, $sp, 4
lw $ra, 0($sp)
addi $sp, $sp, 4
multu $a1, $v0
mflo $v0
addiu $a2 $a0, -1
beq $a2, $a1, afterInnerFactorial 
jr $ra
innerFac: 
lw $ra, 0($sp)
addi $sp, $sp, 4
jr $ra

#------------
extraCase:
addu $v0, $zero, $a0

afterInnerFactorial:


#--UNSTORE---							# restores all arguments values as they were before 
lw $a3, 0($sp)
addi $sp, $sp, 4
lw $a2, 0($sp)
addi $sp, $sp, 4
lw $a1, 0($sp)
addi $sp, $sp, 4
lw $a0, 0($sp)
addi $sp, $sp, 4
lw $ra, 0($sp)
addi $sp, $sp, 4
#------------

#-------JR------
jr $ra 
#------------
extraCaseZero:
addiu $v0, $zero, 1
j afterInnerFactorial

#-----------------------------------------------------

