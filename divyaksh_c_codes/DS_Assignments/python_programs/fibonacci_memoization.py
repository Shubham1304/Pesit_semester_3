#!/usr/bin/python3

def fibonacci(num):
  if(num == 1):
    return 1
  if(num == 0):
    return 0;
  return fibonacci(num-1)+fibonacci(num-2)

#for i in range(0,100000000):
#  fibonacci(20)

def fibonacci_memoization(num):
  if(num == 1):
    return 1;
  if(num == 0):
    return 0;

  num1 = 1
  num2 = 0
  ans = 0

  for i in range(2,num):
          ans = num1+num2;
          num2 = num1
          num1 = ans

  return ans

# print(fibonacci(1000000))
print(fibonacci_memoization(1000000))
