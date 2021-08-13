# set.h

A simple implementation of fixed sized sets in **C**.

It has the usual set operations: member, insert, delete, union,
intersection, and difference. It does not have set negation since that
implies a universal set.

Since the sets are fixed-sized and fit in a machine word, they are *by
value* sets. A set is a parameter to the function, and the function
returns a set as a result.

Originally written for the students of CSE 13S at the University of California, Santa Cruz.
