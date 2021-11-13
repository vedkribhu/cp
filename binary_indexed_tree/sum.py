def update(bit, index, val):
	n = len(bit)
	while(index<n):
		bit[index]+=val
		index += index&(-1*index)
		# print(index)
		# break

	
	
def getsum(bit, index):
	n = len(bit)
	ans = 0
	while(index>0):
		ans+=bit[index]
		index -= index&(-1*index)
	return ans
arr = [3, 6, 2, 4, 1, 7]
n = len(arr)
bit = [0]*(len(arr)+1)
# inv_ct = 0
# print(bit)
# update(bit, 1, -1)
for i in range(n):
	# index = arr[i]
	# inv_ct += getsum(bit, index-1)
	update(bit, i+1, arr[i])
# print(getsum(bit, 4+1))
print(getsum(bit, 2))
update(bit, 2, -3)
print(getsum(bit, 2))

	# print(inv_ct, bit)