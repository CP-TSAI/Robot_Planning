# 8-Puzzle Solver
In this project, we are solving the 8-Puzzle problem with `BFS algorithm` by C++11 and STL.

First, we have to define the INITIAL and FINAL state by a 2D vector, 
```
vector<vector<int>> initial = {{7, 5, 4}, 
			       {0, 3, 2}, 
			       {8, 1, 6}}; 

vector<vector<int>> final = {{1, 2, 3}, 
			     {4, 5, 6}, 
			     {7, 8, 0}};
```

then generate the child node through the `Left / Right / Up / Down` actions. 
In the same time, we have to use a map to record the child node and parent node.

Secondly, to implement `BFS algorithm`, we use a `Queue` to save each node, 
and to avoid generating repeated node, we also use a `hash map` to save the nodes that already appeared. 

Finally, when the final state appears, the process can be stoped and we can start tracing back.


# Result
In this case, the BFS generate 16468 nodes, 
the steps are shown in the followings:

step 1:  
7  5  4  
0  3  2  
8  1  6  

step 2:  
0  5  4  
7  3  2  
8  1  6  

step 3:  
5  0  4  
7  3  2  
8  1  6  

step 4:  
5  4  0  
7  3  2  
8  1  6  

step 5:  
5  4  2  
7  3  0  
8  1  6  

step 6:  
5  4  2  
7  0  3  
8  1  6  

step 7:  
5  4  2  
7  1  3  
8  0  6  

step 8:  
5  4  2  
7  1  3  
0  8  6  

step 9:  
5  4  2  
0  1  3  
7  8  6  

step 10:  
0  4  2  
5  1  3  
7  8  6  

step 11:  
4  0  2  
5  1  3  
7  8  6  

step 12:  
4  1  2  
5  0  3  
7  8  6  

step 13:  
4  1  2  
0  5  3  
7  8  6  

step 14:  
0  1  2  
4  5  3  
7  8  6  

step 15:  
1  0  2  
4  5  3  
7  8  6  

step 16:  
1  2  0  
4  5  3  
7  8  6  

step 17:  
1  2  3  
4  5  0  
7  8  6  

step 18:  
1  2  3  
4  5  6  
7  8  0  


