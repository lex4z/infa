#!/usr/bin/env python3

#n = int(input())
for n in range(100,1000):
	a = n//100
	b = (n//10)%10
	c = n%10
	if(a<c): 
		c = a
	if(b<c):
		c = b
	if(c!=0 and n%c!=0):
		print(n)