# LRU Cache (C++)

## Overview
This project implements a **Least Recently Used (LRU) Cache** from scratch in C++.
The cache supports `get` and `put` operations in **O(1) time complexity** and does not use STL containers.

The goal of this project was to understand how caching systems work internally,
including memory management, hashing, and pointer manipulation.

---

## Features
- Fixed-capacity cache
- O(1) `get` and `put` operations
- Least Recently Used eviction policy
- Implemented without STL containers
- Manual memory management

---

## Design Approach
The cache is implemented using two core data structures:

### 1. Doubly Linked List
- Maintains the order of usage
- Most recently used item is placed at the front
- Least recently used item is removed from the back

### 2. Hash Table (Separate Chaining)
- Provides O(1) average-time lookup
- Maps keys to nodes in the linked list
- Handles collisions using linked list chaining

---

## How It Works
- On every `get` operation, the accessed node is moved to the front of the list.
- On `put`, if the cache is full, the least recently used node is evicted.
- The hash table and linked list are kept in sync to maintain correctness.

---

## Time and Space Complexity
| Operation | Complexity |
get-> O(1) 
put  ->  O(1) 
Space  -> O(capacity) 

