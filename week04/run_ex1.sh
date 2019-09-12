x=1
while [ $x -le 10 ]
do
  gcc -std=c11 ex1.c -o ex1 && ./ex1;
  x=$(($x + 1))
done
