a=0
b=1
echo "Enter limit:"
read limit
echo "$a"
echo "$b"
for ((i=0 ;i<limit-2 ;i++))
   do
    c=$(($a+$b))
    a=$b
    b=$c
    echo "$c"
   done
