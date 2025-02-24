# Red-Black Tree

A **Red-Black Tree** is a type of **Self-Balancing Binary Search Tree (BST)** that ensures the tree remains balanced with specific properties on the color of the nodes. These properties allow the tree to maintain efficient operations (insertion, deletion, and search) while ensuring the tree height stays logarithmic.

## Properties of Red-Black Tree

1. **BST Properties**:
   - Left subtree contains only nodes with values smaller than the node’s value.
   - Right subtree contains only nodes with values greater than the node’s value.
   - No duplicate values (typically).

2. **Red-Black Tree Properties**:
   - Each node is either **red** or **black**.
   - The root is always **black**.
   - All leaves (NIL nodes) are **black**.
   - If a red node has children then, the children must be **black** (no two red nodes can be adjacent).
   - Every path from a node to its descendant NIL nodes must have the same number of **black** nodes (black-height).
   - The tree remains balanced through rotations and color changes after insertions and deletions.

## Rotations and Fixes

Red-Black Trees maintain balance through **rotations** and **color fixes** after insertion or deletion:
   - **Left Rotation**
   - **Right Rotation**
   - **Recoloring**
   - **Double Rotations (Left-Right, Right-Left)**

The tree may require rotations and color changes to restore the Red-Black properties after insertion or deletion.

## How to Compile and Run

1. In the project directory, compile the code with:
   ```sh
   gcc -o main *.c
   ```
2. Then, run:
   ```sh
   ./main
   ```

## How to Run Tests

1. With the project already compiled, run:
   ```sh
   ./main < in.test > out.test
   ```
2. To compare the expected output with the generated output, use:
   ```sh
   diff expected.test out.test
   ```
   - If no output is displayed, all tests have passed.
