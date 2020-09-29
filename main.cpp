/* 
 * File:   main.cpp
 * Author: Japneet Kaur
 *
 * Created on September 28, 2020, 12:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstddef>
#include "TreeNode.h"

// function prototypes
TreeNode * buildTreeRecursive(int array[], int lower, int upper); // function that uses the median logic to recursively build the tree
int kthMin(TreeNode * root, int k); // the function to find the k (th) minimum element 
void inOrderPrint(TreeNode * head); // function to print the tree in order once it is created
void preOrderPrint(TreeNode * head); 
void postOrderPrint(TreeNode * head); 


int main() {
    int array[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    int arraySize = sizeof(array)/sizeof(array[0]);
    TreeNode root = TreeNode();
    root = *buildTreeRecursive(array, 1, arraySize); // recursive function that builds the tree recursively and returns the root
    
    // print the tree in all three ways: pre-order, in-order, and post-order traversal to illustrate the created BST
    std::cout << "Pre-Order Traversal:" << std::endl;
    preOrderPrint(&root);
    std::cout << std::endl; // empty line
    std::cout << "In Order Traversal" << std::endl;
    inOrderPrint(&root);
    std::cout << std::endl; // empty line
    std::cout << "Post-Order Traversal" << std::endl;
    postOrderPrint(&root);
    std::cout << std::endl; // empty line
    return 0;
} // end main


/* Function name: buildTreeRecursively()
 * Purpose: To use recursion and the median of sub arrays of the original array to place the elements into a BST
 * Parameters: the array of integers, the lower and upper boundaries of each turn of finding a median
 * Return value: the currentNode built on every call of the function, gets returned one by one once the base case is reached
 *          at the leaves of the tree when there is nothing more to take the median of for the corresponding sub-array
 */
TreeNode * buildTreeRecursive(int array[], int lower, int upper) {
    if (lower > upper) {
        // base case for each recursive function call to end
        // when the lower index is crossed upon by the upper index, return null
        return NULL;
    }
    else {
        // find the median of the current array
        int median = (lower + upper)/2;
        // create a new node that stores the current median value as its data
        TreeNode currentNode = TreeNode(array[median]);
        // the following actions are performed recursively in the whole function
        currentNode.setLeft(buildTreeRecursive(array, lower, median-1));
        currentNode.setRight(buildTreeRecursive(array, median+1, upper));
        return &currentNode; // this will the root of the tree in the end once the whole tree is constructed and the function call stack unravels one by one
    } // end if
} // end function buildTree



/* Function name: inOrderPrint()
 * Purpose: Once the BST is created from the array, this method is used to print the array following the in order traversal
 *          This function is also recursive
 * Parameters: a pointer to the root node to begin with, then every time it is the node that is being traversed through in the current function call
 * Return value: none, just prints the tree values
 */
void inOrderPrint(TreeNode * nodePointer) {
    if (nodePointer != NULL) {
        // create a new node that stores the value of the head node from the passed in pointer
        TreeNode currentNode = *nodePointer;
        // go to the left first, then root (meaning currentNode), then right
        inOrderPrint(currentNode.getLeft()); // getLeft returns a pointer
        std::cout << currentNode.getData() << " ";
        inOrderPrint(currentNode.getRight());
    } // end if
} // end inOrderPrint



/* Function name: preOrderPrint()
 * Purpose: to print the BST using pre-order traversal
 * Parameters: a pointer to the current node being traversed through
 * Return value: none
 */
void preOrderPrint(TreeNode * nodePointer) {
    if (nodePointer != NULL) {
        TreeNode currentNode = *nodePointer;
        // print the root (currentNode which is the root of the current subtree) first
        std::cout << currentNode.getData() << " ";
        // go to the left node
        preOrderPrint(currentNode.getLeft());
        // go to the right node
        preOrderPrint(currentNode.getRight());
    } // end if
} // end preOrderPrint



/* Function name: postOrderPrint()
 * Purpose: to print the BST using post-order traversal
 * Parameters: a pointer to the current node being traversed through
 * Return value: none
 */
void postOrderPrint(TreeNode * nodePointer) {
    if (nodePointer != NULL) {
        TreeNode currentNode = *nodePointer;
        // go to the left node first
        preOrderPrint(currentNode.getLeft());
        // go to the right node
        preOrderPrint(currentNode.getRight());
        // print the root in the end
        std::cout << currentNode.getData() << " ";
    } // end if
} // end postOrderPrint
