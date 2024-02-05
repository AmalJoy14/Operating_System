echo "Enter two numbers:"
read num1
read num2
echo -e "Enter choice:\n1.Addition\n2.Substraction\n3.Division\n4.Multiplication"
read choice
case $choice in
   1)echo "Sum is $(($num1+$num2))";;
   2)echo "Difference is $(($num1-$num2))";;
   3)echo "Quotient is $(($num1/$num2))";;
   4)echo "Product is $(($num1*$num2))";;
   *)echo "Invalid Choice"
esac
