#include "LLRBBST.h"
#include <iostream>
#include <fstream>
using namespace std;

/*Node*/

//Overloading Constructor
node::node(string data){
  dataPair.first = data;
  dataPair.second = 'r';
  left = nullptr;
  right = nullptr;
  count = 1;
}

//Destructor
node::~node(){
}


/*Tree*/


//*PRIVATE*//

//Constructor
tree::tree(){
  root = nullptr;
}

//Destructor
tree::~tree(){
  destroyTree(root);
}

//Raises the right child of a parent node that is rotated to the left, and reassigns the former child’s left pointer to the new child node.
node * tree::leftRotation(node * parent){
  node * child = parent -> right;
  node * gchild = child -> left;
  parent -> right = gchild;
  child -> left = parent;

  child -> dataPair.second = parent -> dataPair.second;
  parent -> dataPair.second = 'r';
  return child;
}

//Raises the left child of a parent node that is rotated to the right, and reassigns the former child’s right pointer to the new child node.
node * tree::rightRotation(node * parent){
  node * child = parent -> left;
  node * gchild = child -> right;
  parent -> left = gchild;
  child -> right = parent;

  child -> dataPair.second = parent -> dataPair.second;
  parent -> dataPair.second = 'r';
  return child;
}

//Swaps the parent node’s color to red, and its child nodes are changed to black.
void tree::colorSwap(node * parent){
  parent ->right -> dataPair.second = 'b';
  parent -> left -> dataPair.second = 'b';
  parent -> dataPair.second = 'r';
  return;
}

//Balances the tree after insertion is called using rotation calls and color swapping, due to insertion making the tree unbalanced.
node * tree::autoBalance(node * start){
  bool startR = start -> right, startL = start -> left;

  if((startR) and (((start -> left == nullptr) or (start -> left -> dataPair.second == 'b')) and (start -> right -> dataPair.second == 'r'))){
    start = leftRotation(start);
  }

  startR = start -> right;
  startL = start -> left;
  bool startLL = false;

  if(startL){
    startLL = start -> left -> left;
  }

  if((startL and startLL) and (start -> left -> left -> dataPair.second == 'r') and (start -> left -> dataPair.second == 'r')){
    start = rightRotation(start);
  }

  startR = start -> right;
  startL = start -> left;

  if((startR and startL) and (start -> right -> dataPair.second == 'r') and (start -> left -> dataPair.second == 'r')){
    colorSwap(start);
  }
  return start;
}

//Creates a node to insert and stores the given string, and inserts the node where it should be. If the string inserted is not a duplicate, the tree will perform an autobalance up to the root. If any duplicate words are detected, the "count" variable is increased by 1 per duplicate.
node * tree::insertNode(string data, node * parent){
	if(parent == nullptr){
    parent = new node(data);
		return parent;
  }

  //Insert Left
  if(data < parent -> dataPair.first){
    parent -> left = insertNode(data, parent -> left);
	}
	//Insert Right
	else if(data > parent -> dataPair.first){
    parent -> right = insertNode(data, parent -> right);
	}
	//Duplicate detection, count increases by 1
	else{
    parent -> count += 1;
  }

  //Autobalance the new node.
  parent = autoBalance(parent);

  return parent;
}

//Goes through the tree and finds the node of the provided string that it is stored in, and it returns a pointer to that node. If it doesn't exist, a null pointer is returned.
node * tree::searchNode(string data, node * traversal){
  //Node Doesn't Exist
  if(traversal == nullptr){
    return nullptr;
  }

  //Node Found
  if(traversal -> dataPair.first == data){
    return traversal;
  }

  //Searching
  else if(data > traversal -> dataPair.first){
      if(traversal -> right != nullptr){
        return searchNode(data, traversal -> right);
      }
  }
  else if(data < traversal -> dataPair.first){
    if(traversal -> left != nullptr){
      return searchNode(data, traversal -> left);
    }
  }
  return nullptr;
}

//Goes through the entire tree and deletes all nodes, deleting the root node last, overall deleting the tree to prevent data leaking.
void tree::destroyTree(node * destroy){
	if (destroy -> right != nullptr){
		destroyTree(destroy -> right);
	}
	if (destroy -> left != nullptr){
		destroyTree(destroy -> left);
	}
	(*destroy).~node();
	return;
}

//Function to convert the generated LLRBBST into DOT file format.
void tree::DOTFile(node * start, int& i){
	if (start == nullptr){
		return;
	}

  outFile << "\t\"" << start -> dataPair.first << "\" [label = \"" << start -> dataPair.first << ": " << start -> count << "\" shape = box ]\n";

  if(start -> left == nullptr){
		outFile << "\tNULL" << i << " [shape = \"point\"]\n\t\"" << start -> dataPair.first << "\" -- NULL" << i << " [style = bold]\n";
    i++;
	}
	else{
		if(start -> left -> dataPair.second == 'r'){
			outFile << "\t\"" << start -> dataPair.first << "\" -- \"" << start -> left -> dataPair.first << "\" [color = red style = bold]\n";
		}
		else{
			outFile << "\t\"" << start -> dataPair.first << "\" -- \"" << start -> left -> dataPair.first << "\" [style = bold]\n";
		}
	}

	if(start -> right == nullptr){
		outFile << "\tNULL" << i << " [shape = \"point\"]\n\t\"" << start -> dataPair.first << "\" -- NULL" << i << " [style = bold]\n";
    i++;
	}
	else{
		outFile << "\t\"" << start -> dataPair.first << "\" -- \"" << start -> right -> dataPair.first << "\" [style = bold]\n";
	}

	DOTFile(start -> left, i);
	DOTFile(start -> right, i);
}


//*PUBLIC*//

//Calls the insertNode() function and inserts a node into the tree using the provided dataPair.
void tree::insertFunc(string data){
  root = insertNode(data, root);
  root -> dataPair.second = 'b';
  return;
}

//Calls the searchNode() function and returns a pointer to that node using the provided dataPair. Returns a null pointer given nothing found.
node * tree::searchFunc(string data){
  return searchNode(data, root);
}

//Calls the DOTFile() function to print a DOT file format of the tree using the dataPair.
void tree::printDOT(){
  outFile.open("visual.dot");
  outFile << "graph {\n";
  DOTFile(root, treeCount);
  outFile << '}';
  outFile.close();
	return;
}