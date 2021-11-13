class union_find:
    def __init__(self, n):
        self.n = n
        self.rank = [0]*n
        self.parent = [int(j) for j in range(n)]
    
    def union(self,i,j):
        i = self.find(i)
        j = self.find(j)
        if self.rank[i] == self.rank[j]:
            self.parent[i] = j
            self.rank[j] += 1

        elif self.rank[i] > self.rank[j]:
            self.parent[j] = i
        else:
            self.parent[i] = j

    def find(self, i):
        temp = i
        if self.parent[temp] != temp:
            self.parent[temp] = self.find(self.parent[temp])
        return self.parent[temp]

#union find data structure makes union like 0,1,2,3 now if union(0,2) it will assign 0 to both 0 and 2 as 0 beinf minimum of both. 
# self.parent contains parent[i] = parent[i]. Whereas maximum rank can be 1.
x = union_find(5)
x.union(4,1)
x.union(4,2)
print(x.find(4))
print(x.parent)