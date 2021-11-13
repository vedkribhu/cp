import math
class segment_tree:
    def __init__(self, l, n):
        self.arr = l
        self.n = n
        self.lazy = [0 for i in range(2*n)]
        self.segTree = []
        self.ans = math.inf
    def inintialize_tree(self):
        n = self.n
        ct = 0
        m = int(math.log(n,2))
        # print(m,n)
        if 2**m == n:
            self.segTree = [0 for i in range(2*n - 1)]
        else:
            self.segTree = [0 for i in range(2**(m+2) - 1)]
        # print(len(self.segTree))
    def constructTree(self, low, high, pos):
        if low == high:
            self.segTree[pos] = self.arr[low]
            return
        mid = (low + high)//2
        self.constructTree(low, mid, 2*pos + 1)
        self.constructTree(mid+1, high, 2*pos + 2)
        self.segTree[pos] = min(self.segTree[2*pos + 1], self.segTree[2*pos + 2])
    def query(self, left, right, curr_left, curr_right, pos):
        if left <= curr_left and right >= curr_right:
            return self.segTree[pos]
        elif left > curr_right or right < curr_left:
            return math.inf
        mid = (curr_left+curr_right)//2
        return min(self.query(left, right,curr_left, mid, 2*pos + 1), self.query(left, right,mid + 1, curr_right, 2*pos + 2))
        
x = segment_tree([-1,2,4,0], 4)
x.inintialize_tree()
x.constructTree(0, 3, 0)
q = x.query(1, 2, 0, 3, 0)
print(x.segTree, q)
