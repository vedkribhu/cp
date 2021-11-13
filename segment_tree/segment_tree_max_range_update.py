from math import log2, inf
import sys
from copy import deepcopy
class segTree():
    def __init__(self, ls):
        n = len(ls)
        arr = []
        if int(log2(n)) == log2(n):
            arr = [0]*(2*n-1)
        else:
            arr = [0]*(2**(int(log2(n))+2)-1)
        self.arr = ls
        self.tree = arr
        self.update = deepcopy(arr)
    def create(self,lf,rt,pos):
        # print(pos)
        if lf==rt:
            self.tree[pos] = self.arr[lf]
            return 
        mid = (rt+lf)//2
        self.create(lf, mid, 2*pos+1)
        self.create(mid+1, rt, 2*pos+2)
        self.tree[pos] = max(self.tree[2*pos+2], self.tree[2*pos+1])
    def query(self, left, right, curr_left, curr_right, pos):
        if self.update[pos]!=0:
            self.tree[pos]+=self.update[pos]
            # self.update[pos] = 0
            if curr_left!=curr_right:
                self.update[2*pos+1]+=self.update[pos]
                self.update[2*pos+2]+=self.update[pos]
            self.update[pos] = 0
        if left <= curr_left and right >= curr_right:
            return self.tree[pos]
        elif left > curr_right or right < curr_left:
            return -1*inf
        mid = (curr_left+curr_right)//2
        return max(self.query(left, right,curr_left, mid, 2*pos + 1), self.query(left, right,mid + 1, curr_right, 2*pos + 2))
    def range_update(self, left, right, curr_left, curr_right, pos, update):
        if self.update[pos]!=0:
            self.tree[pos]+=self.update[pos]
            # self.update[pos] = 0
            if curr_right!=curr_left:
                self.update[2*pos+1]+=self.update[pos]
                self.update[2*pos+2]+=self.update[pos]
            self.update[pos] = 0
        if left <= curr_left and right >= curr_right:
            if curr_left!=curr_right:
                self.update[2*pos+1]+=update
                self.update[2*pos+2]+=update
            self.update[pos] = 0
            self.tree[pos] += update
            return self.tree[pos]
        elif left > curr_right or right < curr_left:
            return 
        mid = (curr_left+curr_right)//2
        self.range_update(left, right,curr_left, mid, 2*pos + 1, update)
        self.range_update(left, right,mid + 1, curr_right, 2*pos + 2, update)
        self.tree[pos] = max(self.tree[2*pos+1], self.tree[2*pos+2])
pre_sum = [1,2,3,4,5,6,7,8]
n = len(pre_sum)
seg_tree1 = segTree(pre_sum)
seg_tree1.create(0, len(pre_sum)-1, 0)
print(seg_tree1.tree, seg_tree1.update)
print(seg_tree1.query(1,3, 0, n-1,0))
seg_tree1.range_update(4,7, 0, n-1,0,2)
print(seg_tree1.query(4, 5,0, n-1,0))
print(seg_tree1.tree, seg_tree1.update)