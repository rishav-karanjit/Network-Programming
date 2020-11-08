#### Shuffle Algorithm

To shuffle an array a of n elements (indices 0..n-1):
```
for i from n-1 downto 1 do
  j = random integer with 0 <= j <= i
  exchange a[j] and a[i]
```
#### Sorting Algorithm

```
procedure insertionSort( A : array of items )
  for i = 1 to length(A) inclusive do:
    valueToInsert = A[i]
    holePosition = i

    while holePosition > 0 and A[holePosition-1] > valueToInsert do:
      A[holePosition] = A[holePosition-1]
      holePosition = holePosition -1
    end while

    A[holePosition] = valueToInsert
  end for
end procedure
```
