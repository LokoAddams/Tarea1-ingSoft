import sys

class UFDS:
    def __init__(self, n):
        self.parents = list(range(n))
        self.ranks = [0] * n
        self.sizes = [1] * n
        self.numdisjoint = n

    def find(self, x):
        xp = x
        children = []
        while xp != self.parents[xp]:
            children.append(xp)
            xp = self.parents[xp]
        for c in children:
            self.parents[c] = xp
        return xp

    def union(self, a, b):
        ap = self.find(a)
        bp = self.find(b)
        if ap == bp:
            return

        if self.ranks[ap] < self.ranks[bp]:
            self.parents[ap] = bp
            self.sizes[bp] += self.sizes[ap]
        elif self.ranks[bp] < self.ranks[ap]:
            self.parents[bp] = ap
            self.sizes[ap] += self.sizes[bp]
        else:
            self.parents[bp] = ap
            self.ranks[ap] += 1
            self.sizes[ap] += self.sizes[bp]

        self.numdisjoint -= 1

    def size(self, x):
        return self.sizes[self.find(x)]

ent = sys.stdin.read().splitlines()

n = int(ent[0])
per = {}
aux = []
rel = []
cont = 0

for l in range(n):
  aux = ent[l+1].strip().split()
  if aux[0].endswith(","):
    aux[0] = aux[0][:-1]
  if not(aux[0] in per):
    per[aux[0]] = cont
    cont += 1
      
  if not(aux[-1] in per):
    per[aux[-1]] = cont
    cont += 1
  
  if(aux[0] != aux[-1]):
      rel.append((per[aux[0]], per[aux[-1]]))

n = len(per)
conj = UFDS(n)
for a, b in rel:
  conj.union(a, b)
  
if(conj.numdisjoint == 1):
    print("possible")
else:
    print("impossible")
    
