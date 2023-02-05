#!/usr/bin/env python3
n1="111101"
n2="101"
r = "0"*1000
if(len(n1) < len(n2)): n1, n2 = n2, n1
for i in range(len(n1)-len(n2)): n2 = "0"+ n2
for i in range(len(n1)):
	t = int(n1[i])+int(n2[i])
	if t > 1: r[i+1] = "1"
	r += str((t + int(r[i]))%2)
print(r)