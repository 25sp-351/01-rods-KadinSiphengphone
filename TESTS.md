#Tests

1.arg count

- length not present
- no extra parameters allowed

  2.invalid length

- '<1'
- '> MAX_INT'
- not int

  3.len/cost input tests

- at least one
- no duplicates
- both integers >=1
- nothing but "num,"num" on line
- space after comma optional
- can input lots

  4.unusual situations

- length < any piece : len 10 20,20 -> 0 remainder 10

  5.no remainder

- no dupes: len 50, 2/4 6/4 -> 25@2 remainder: 0
- single len: len 50, 5/5 = 10@5 remainder:0
- multi pieces: len 30, 2/3 4/7 1/1 18/30 -> 7@4 1@2 remainder: 0

  6.remainder

- one piece: len 20 6/3 -> 3@6 remainder: 2
- mult piece: len 50 17/20 20/30 19/21 -> 2@20 remainder: 10
