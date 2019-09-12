gcc -std=c11 -Wall ex2.c -o ex2 && ./ex2 &
for i in {1..5}; do
pstree | grep "ex2"
sleep 5;
done
