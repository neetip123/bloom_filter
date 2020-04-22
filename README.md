# bloom_filter
Bloom Filter is a data structure for storing an unordered set using hash functions.
For this task you will implement a Bloom filter on the universe U = {0, 1, 2, ..., n − 1}. Your array should have size n.
You will choose any m hash functions of the from h(x) = ((ax + b) mod c) mod n where a, b and c are large positive
integers.
Now, you should do the followings:
1. Initialization of Bloom Filter: Initialize your Bloom Filter by inserting any k elements at random from U . Let
us denote this randomly generated k elements as S. Display the Bloom filter created using S.
2. Membership Queries & Finding Causes for False Positives: Once the state of the Bloom filter has been
displayed, then the program should ask to move forward with a keypress. After that the program should launch
queries on each of the remaining n − k items. If any one of these returns a yes answer, the program should pause
and find out why this false positive has been returned i.e. it should locate the hash function collisions that have
caused this false positive to occur. More formally, if we get a yes answer for x although x is not in S, this means
that A[h 1 (x)], A[h 2 (x)] and A[h 3 (x)] are all 1. Your program should return (at most) m elements u 1 , u 2 , · · · , u m
from S which hash to the positions h 1 (x), h 2 (x), · · · , h m (x) through one of the m hash functions. Your program
should display which location has been set to 1 by which element of S through which hash function.
3. Summarizing False Positive Cases: Finally the program should count the total number of false positives
occurring in all n − k membership queries and display the false positive probability p i.e. the fraction of false
)
positives out of n − k. Formally p can be defined as p = ∀x ∈ {U − S}( count((x∈S)=yes
