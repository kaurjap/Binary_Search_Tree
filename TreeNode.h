/* 
 * File:   TreeNode.h
 * Author: Japneet Kaur
 *
 * Created on September 28, 2020, 1:00 PM
 */

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
    protected:
        TreeNode * leftChild;
        TreeNode * rightChild;
        TreeNode * parent;
        int data;
    public:
        TreeNode(); // constructor
        TreeNode(int data); // parameterized constructor
        ~TreeNode(); // destructor, because memory will be allocated on the heap
        void setData(int data);
        int getData();
        void setLeft(TreeNode * left);
        TreeNode * getLeft();
        void setRight(TreeNode * right);
        TreeNode * getRight();
        void setParent(TreeNode * parent);
        TreeNode * getParent();
}; // end class declaration

#endif // TREENODE_H included

