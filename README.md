<h1 align=center> LLRBBST: Left Leaning Red-Black Binary Search Tree </h1>
<h2 align=center> A CSC212 Project by Zach Breene </h2>

## Introduction
My task for this project was to create an implementation of the Left Leaning Red-Black Binary Search Tree, or LLRBBST. The LLRBBST is a more efficient alternative to the 2-3 and Red Black Binary Search Trees. The LLRBBST is more efficient due to certain rules set in place. In this tree, all red links are to be left leaning, which means pointing towards the left child, and there cannot be a node that has two red links connected. The LLRBBST also has perfect black balance, where each path from the root to the leaves crosses the same number of black links. With everything correctly applied and implemented, the LLRBBST runs insertion, search, and deletion methods in log(n) time.

---

## Implementation + Functions
### LLRBBST.cpp

This is the main file for all methods of the LLRBBST. </n>

&emsp; ***Insertion Method***

* The insertion method is a function called insertNode(string). This function creates a node to insert and stores the given string. If the string inserted is not a duplicate, the tree will perform an autobalance. If any duplicate words are detected, the "count" variable is increased by 1 per duplicate, with "count" starting at 1 in the overloaded constructor.  

&emsp; ***Search Method***

* The search method is a function called searchNode(string). This function finds the node of the provided string that it is stored in, and it returns a pointer to that node.

&emsp; ***DOT File Print***

* The function DOTFile() converts the generated LLRBBST into a DOT file format. The function printDOT is the method that prints out the DOT file format. Using a website like [edotor.net](https://edotor.net/), you can copy and paste the DOT file format and see the visual of your LLRBBST.


### LLRBBST.h

This file is the header file that contains the calls for the node class and the tree class of this implementation, as well as calling the methods made in LLRBBST.cpp. The node class calls an overloading constructor and a destructor, while the tree class calls the methods provided in LLRBBST.cpp. The nodes are pairs of data, the first being a string and the second being a char. Alongside that a variable "count" detects the amount of duplicate words in the given data.


### main.cpp

This file is composed of the readFile() function and a main to give the implementation a text file to convert into a tree. You will see in the main a line that has readFile("somebody.txt"). Depending on what your txt file is called, you must change what is between the quotation marks. The readFile() function reads from a txt file of words that are separated by a space, and creates it into an LLRBBST. After creating it into a tree, readFile() writes the tree to a DOT file for visualization, and deletes the tree to prevent data leakage. Essentially, the readFile() function is the call of the LLRBBST implementation.

### somebody.txt

This file is a text file with the lyrics to the song "Somebody That I Used To Know" by GOTYE. This was a text file used to visualize my implementation.

---

## How To Run
If you want to compile this implementation, you must download the "LLRBBST.cpp", "LLRBBST.h", and "main.cpp" files. You must also provide a text file of your choosing, or simply download "somebody.txt", the text file for Somebody That I Used To Know. Once all downloaded files are compiled on your chosen IDE, make sure to update the txt file to what you have provided, inside readFile() in "main.cpp", or else it will not work. At this point, run it, and it should give you a DOT file. To view the LLRBBST you have just created, copy and paste the DOT file onto a visualization website, such as [edotor.net](https://edotor.net/), a Graphviz editor, and gaze in awe at your beautiful tree.

---

## Contribution
As I was the sole member of this project, I contributed to the whole of the project. This contribution is as follows:
* Implementation of LLRBBST
* Creation of Report and Presentation
* DOT File Research
* DOT File Visualization
