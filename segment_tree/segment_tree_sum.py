from math import log2
class Segtree():
    def __init__(self, l):
        n = len(l)
        self.arr = l
        if log2(n)==int(log2(n)):
            self.tree = [0]*(2*n-1)
        else:
            self.tree = [0]*(2**(int(log2(n))+2)-1)
    def build(self, lf, rt, pos = 0):
        if lf==rt:
            self.tree[pos] = self.arr[lf]
        else:
            mid = lf + (rt-lf)//2
            self.tree[pos] = self.build(lf, mid, 2*pos+1)+self.build(mid+1, rt, 2*pos+2)
        return self.tree[pos]
    def querry(self, lf, rt, curr_left, curr_right, pos=0):
        # print(curr_right, curr_left)
        if curr_left == curr_right:
            if curr_left<=rt and curr_left>=lf:
                return self.tree[pos]
            else:
                return 0 
        if lf>curr_right and rt<curr_left:
            return 0
        elif lf<=curr_left and rt>=curr_right:
            return self.tree[pos]
        else:
            mid = mid = curr_left + (curr_right-curr_left)//2
            return self.querry(lf, rt, curr_left, mid, 2*pos+1)+self.querry(lf, rt, mid+1, curr_right, 2*pos+2)
l = [1,2,3,4,5,6]
x = Segtree(l)
x.build(0, len(l)-1)
print(x.querry(0,2, 0, len(l)-1))
            


