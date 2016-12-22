// Swapping values of two variables without using temperory variables.

//Method 1 : 

void swap_plus_minus(int &a,int &b)
{
  a = a + b;
  b = a - b;
  a = a - b;
  
  // Single statement
  //a -= b = (a += b) - b;
}

void swap_exor(int &a,int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  // Single statement
  //a ^= b ^= a ^= b;
}

void swap_multiply_divide(int &a,int &b)
{
  a = a * b;
  b = a / b;
  a = a / b;
}
