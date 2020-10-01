Instructions for Running the program:

  TASKS                                                     	COMMANDS
  To compile, execute:                                      	  make
  To compile and run, execute:                              	  make run
  To clean the current compilation and object files, execute:   make clean 
  To debug, if needed, execute:                             	  make debug
  
  
  
ALGORITHM FOR MY IMPLEMENTATION:

1. In order to construct the binary Search tree, I made a TreeNode class that stores the value, the left, and the right pointer for each node in the tree.
2. In order to build the tree using the input array of integers, I created a function that runs based on the following algorithm:
    initialiaze the *lower* median index = 0
    initialize the *upper* median index = array size - 1
    
    recursiveFunction():
    
     median = (lower + upper)/2;
     contruct a tree node object with the value array[median]
     recursively, do the following:
     1. Calculate the median of the left subarray from lower to median - 1 and create a new node with that. This will now be the root of the left sub-tree of the current node.
     2. Calculate the median of the right subarray from median + 1 to upper and create a new node with that. This is now the root of the right subtree of the current node.
     3. Continue till the base case: lower > upper is not reached
3. This recursive function returns the root of the tree once constructed. 
4. To find the kth minimum:
      1. I used another recursive function called kthMin() that uses in-order traversal through the tree along with the passed integer k to find the kth smallest element. 
      2. It traverses through the tree in an in-order traversal, and when it stops to get each element, it checks whether that element is the kth element using a counter which is passed by reference to this function.
      3. Once, the counter is equal to k, it stores the data of node in a variable and returns that in the end.

Similarly, to print the tree, I have other needed functions to go along with the tree. The purpose of each function and a detailed explanation of the logic is also given as comments in the code file.
      
    
