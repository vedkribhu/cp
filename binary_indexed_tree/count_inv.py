def update(bit, index, val):
	n = len(bit)
	while(index<n):
		bit[index]+=val
		index += index&(-1*index)

	
	
def getsum(bit, index):
	n = len(bit)
	ans = 0
	while(index>0):
		ans+=bit[index]
		index -= index&(-1*index)
	return ans
arr = [3, 2, 0]
n = len(arr)
bit = [0]*(max(arr)+1)
inv_ct = 0
for i in range(n-1, -1, -1):
	index = arr[i]
	inv_ct += getsum(bit, index)
	update(bit, index+1, 1)
	print(inv_ct, bit)