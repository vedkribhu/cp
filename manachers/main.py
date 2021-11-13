a = "abaxabaxabb"
s = []
n = len(a)
for i in range(n):
	s.append("#")
	s.append(a[i])
s.append("#")
print(s[22], 2*n)
p = [0]*len(s)
c = 0
r = 0
print(len(s))
max_len = 0
for i in range(1,len(s)):
	# print(p, r)
	if i<r:
		mirror = 2*c - i
		p[i] = min(p[mirror], r-i)
	a = i+p[i]+1
	b = i-p[i]-1
	while(a<len(s) and b>=0 and s[a]==s[b]):
		# print(a,b)
		a+=1
		b-=1
		p[i]+=1
		# if a==2*n+1 or b==0:
		# 	break

		
	if p[i]>=max_len:
		if i+p[i]==len(s)-1 or i-p[i]==0:
			max_len = p[i]
			c = i
			r = i+p[i]
	# if r>=2*n+1:
		# break
m = "".join(s[c-max_len:c+max_len+1])
m = "".join(m.split("#"))
print(m)




