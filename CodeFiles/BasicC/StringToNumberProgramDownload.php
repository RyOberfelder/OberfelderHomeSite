<?php
header("Content-disposition: attachment; 
filename=StringToNumberProgram.txt");
header("Content-type: text/plain");
readfile("StringToNumberProgram.txt");
?>