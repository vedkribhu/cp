from math import log2, inf
from bisect import bisect_left
# Find the smallest integer less than x in range l to r for l, r, x querry.  
class Segtree():
    def __init__(self, l):
        n = len(l)
        self.arr = l
        if log2(n)==int(log2(n)):
            self.tree = [0]*(2*n-1)
        else:
            self.tree = [0]*(2**(int(log2(n))+2)-1)
    def merge(self, ls1, ls2):
        i = 0
        j = 0
        ls = []
        while(i<len(ls1) and j<len(ls2)):
            if ls1[i]>ls2[j]:
                ls.append(ls2[j])
                j+=1
            elif ls1[i]<=ls2[j]:
                ls.append(ls1[i])
                i+=1
        while(len(ls1)>i):
            ls.append(ls1[i])
            i+=1
        while(len(ls2)>j):
            ls.append(ls2[j])
            j+=1
        return ls
        
    def build(self, lf, rt, pos = 0):
        if lf==rt:
            self.tree[pos] = [self.arr[lf]]
        else:
            mid = lf + (rt-lf)//2
            self.tree[pos] = self.merge(self.build(lf, mid, 2*pos+1), self.build(mid+1, rt, 2*pos+2))
        return self.tree[pos]
    # def querry_for_ans(self, lf, rt, x,curr_left, curr_right, pos=0):
    #     # print(curr_right, curr_left)
    #     if curr_left == curr_right:
    #         if curr_left<=rt and curr_left>=lf:
    #             ind = bisect_left(self.tree[pos], x)
    #             if self.tree[pos][ind]<
    #         else:
    #             return inf
    #     if lf>curr_right and rt<curr_left:
    #         return inf
    #     elif lf<=curr_left and rt>=curr_right:
    #         return self.tree[pos]
    #     else:
    #         mid = mid = curr_left + (curr_right-curr_left)//2
    #         return min(self.querry(lf, rt, x, curr_left, mid, 2*pos+1),self.querry(lf, rt, mid+1, curr_right, 2*pos+2))
    def querry(self, lf, rt, x,curr_left, curr_right, pos=0):
        print(curr_right, curr_left, x, self.tree[pos])
        if curr_left == curr_right:
            if curr_left<=rt and curr_left>=lf:
                if x==curr_right: 
                    print(self.tree[pos])
                    return self.tree[pos][x - curr_left]
                # ind = bisect_left(self.tree[pos], x)
                # if self.tree[pos][ind]<
            else:
                return inf
        if lf>curr_right and rt<curr_left:
            return inf
        elif lf<=curr_left and rt>=curr_right:
            return self.tree[pos][x - curr_left]
        else:
            mid = mid = curr_left + (curr_right-curr_left)//2
            if x<=curr_right and x>=mid+1: 
                return self.querry(lf, rt,x, mid+1, curr_right, 2*pos+2)
            else:
                return self.querry(lf, rt, x, curr_left, mid, 2*pos+1)
l = [1,3,2,1,5,4,3,4,5,6]

x = Segtree(l)
x.build(0, len(l)-1)
print(x.tree)
print(x.querry(1,5, 2,0, len(l)-1))
            


