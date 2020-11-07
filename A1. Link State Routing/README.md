### How this program works?
```
Initialization

N = {A}     // A is a root node.
for all nodes v
  if v adjacent to A
    then D(v) = c(A,v)
  else D(v) = infinity
  
loop
  find w not in N such that D(w) is a minimum.
  Add w to N
  Update D(v) for all v adjacent to w and not in N:
    D(v) = min(D(v) , D(w) + c(w,v))
Until all nodes in N
```
