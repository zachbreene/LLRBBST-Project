<h1 align=center> LLRBBST: Left Leaning Red-Black Binary Search Tree </h1>
<h2 align=center> A CSC212 Project by Zach Breene </h2>

## Introduction
My task for this project was to create an implementation of the Left Leaning Red-Black Binary Search Tree, or LLRBBST. The LLRBBST is a more efficient alternative to the 2-3 and Red Black Binary Search Trees. The LLRBBST is more efficient due to certain rules set in place. In this tree, all red links are to be left leaning, which means pointing towards the left child, and there cannot be a node that has two red links connected. The LLRBBST also has perfect black balance, where each path from the root to the leaves crosses the same number of black links. With everything correctly applied and implemented, the LLRBBST runs insertion, search, and deletion methods in log(n) time.

---

## Implementation + Functions
### LLRBBST.cpp

This is the main file for all methods of the LLRBBST. </n>

&emsp; &emsp; **Insertion Method**

&emsp; &emsp; &emsp; &emsp; Placeholder

&emsp; &emsp; **Search Method**

&emsp; &emsp; &emsp; &emsp; Placeholder

&emsp; &emsp; **DOT File Print**

&emsp; &emsp; &emsp; &emsp; Placeholder


### LLRBBST.h

This file is the header file that contains the calls for the node class and the tree class of this implementation, as well as calling the methods made in LLRBBST.cpp. The node class calls two overloading constructors, and a destructor, while the tree class calls the methods provided in LLRBBST.cpp. The nodes are pairs of data, the first being a string and the second being a char. Alongside that a variable "count" detects the amount of duplicate words in the given data.


### main.cpp


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
