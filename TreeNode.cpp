/* Filename: TreeNode.cpp
 * Created by: Japneet Kaur
 * Created on: 28 September 2020
 */

#include <cstdlib>
#include <cstddef> // for NULL
#include "TreeNode.h"

TreeNode::TreeNode() {
    TreeNode::data = 0;
    TreeNode::leftChild = NULL;
    TreeNode::rightChild = NULL;
    TreeNode::parent = NULL;
} // end constructor

TreeNode::TreeNode(int data) {
    TreeNode::data = data;
    TreeNode::parent = NULL;
    TreeNode::leftChild = NULL;
    TreeNode::rightChild = NULL;
} // end parameterized constructor


// Getters and Setters

void TreeNode::setData(int data) {
    TreeNode::data = data;
} // end setData

int TreeNode::getData() {
    return TreeNode::data;
} // end getData

void TreeNode::setLeft(TreeNode* left) {
    TreeNode::leftChild = left;
} // end setLeft

TreeNode * TreeNode::getLeft() {
    return TreeNode::leftChild;
} // end getLeft

void TreeNode::setRight(TreeNode* right) {
    TreeNode::rightChild = right;
} // end setRight

TreeNode * TreeNode::getRight() {
    return TreeNode::rightChild;
} // end getRight

void TreeNode::setParent(TreeNode* parent) {
    TreeNode::parent = parent;
} // end setParent

TreeNode * TreeNode::getParent() {
    return TreeNode::parent;
} // end getParent

