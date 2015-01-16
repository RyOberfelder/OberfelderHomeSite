# ----------------------
# Lab 9: EX1: String Conversion and Fibonocci
#
# Name: Ryan Oberfelder
# Assembly-type: MIPS
#
.data 0x0
newline:	.asciiz	"\n"

	
.text 0x3000

#-----------------------MAIN--------------------------
main:		#main(){

addiu $v0, $zero, 5
syscall 			
addiu $a0, $v0, 0
addiu $v0, $zero, 0
jal fibonacci
addiu $a0, $v0, 0
addiu $t0, $v0, 0
addiu $v0, $zero, 1 						# print(int)
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

#-----------------------Fibonacci--------------------------
# assumes these arguements
	#a0 will be the number to factorial
fibonacci:
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

# the following zeros non used values
fibonacciZeroed:
addiu $a1, $zero, 0
addiu $a2, $zero, 0
addiu $a3, $zero, 0
fibonaccistarts:
beq $a0, $zero fibCase1				# if(n<=0){
addiu $a1, $zero, 1				# sets a test value =1
beq $a0, $a1 fibCase2				# if(n==1){
addiu $a1, $zero, 0				# unsets the test value
j fibCase3				
fibCase1: 					# if(n<=0){
addiu $v0, $v0, 0				# return 0;
j unstore
fibCase2:
addiu $v0, $v0, 1
j unstore				# return 1;
fibCase3:
addiu $a0, $a0, -1
jal fibonacci
addiu $a0, $a0, -1
jal fibonacci


unstore:
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

#-----------------------------------------------------

