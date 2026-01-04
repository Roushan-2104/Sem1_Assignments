# C Programming Assignments Collection

This repository contains three distinct C programs covering syntax tricks, ASCII art animation, and algorithmic recursion.

## Table of Contents

1. [Assignment 1: Semicolon-less Printing](https://www.google.com/search?q=%23assignment-1-semicolon-less-printing)
2. [Assignment 2: ASCII House Animation](https://www.google.com/search?q=%23assignment-2-ascii-house-animation)
3. [Assignment 3: Matrix Chain Multiplication (Recursion)](https://www.google.com/search?q=%23assignment-3-matrix-chain-multiplication-recursion)

---

## Assignment 1: Print name without using semicolon in entire program

### Description

**Goal:** Print a specific string to the console without using a semicolon (`;`) anywhere in the source code logic.

**Logic:**
This program utilises the return value of the `printf` function inside an `if` statement.

* `printf` returns the number of characters successfully written.
* Since "ROUSHAN SHARMA" is non-empty, `printf` returns a non-zero integer.
* The `if` condition treats this non-zero value as `true`, executing the (empty) block, effectively running the print statement as a side effect of the condition check.

### Source Code

```c
#include <stdio.h>

void main(){
    if(printf("ROUSHAN SHARMA")){
    }
}

```

### Output

```text
ROUSHAN SHARMA

```

---

## Assignment 2: ASCII House Animation

### Description

**Goal:** Construct a visual representation of a house using ASCII characters, drawn sequentially with a delay effect.

**Logic:**

* **Header:** Uses `<windows.h>` for the `Sleep()` function to create animation delays.
* **The Roof:** Uses nested loops to print a pyramid shape using slashes (`/` and `\`), calculating dynamic spacing for alignment.
* **The Walls:** Uses a string array (`char *walls[]`) to store the architectural pattern (windows and door). It iterates through this array to build the house body.
* **The Floor:** Prints a distinct bottom border.

> **Note:** This code is designed for Windows environments due to the dependency on `windows.h`.

### Source Code

```c
#include <stdio.h>
#include <windows.h> // Required for Sleep()

int main() {
    int i, j;

    // --- PART 1: THE ROOF ---
    printf("\n");
    Sleep(300);

    for (i = 0; i < 12; i++) {
        printf("\t");

        // Print leading spaces (decreases by 1 each row)
        for (j = 0; j < 11 - i; j++) {
            printf(" ");
        }

        printf("/");

        // Print inner spaces (increases by 2 each row)
        for (j = 0; j < 2 * i; j++) {
            printf(" ");
        }

        printf("\\\n");
        Sleep(300);
    }

    // The roof baseline
    printf("\t");
    for (i = 0; i < 24; i++) {
        printf("-");
    }
    printf("\n");
    Sleep(300);

    // --- PART 2: THE WALLS (BODY) ---
    const char *walls[] = {
        "  _____        _____  ", // Top of windows
        " |__|__|      |__|__| ", // Window grids
        " |__|__|      |__|__| ", // Window grids
        "                      ", // Empty wall
        "                      ", // Empty wall
        "        ____          ", // Top of door
        "       |    |         ", // Door sides
        "       |    |         "  // Door sides
    };

    int wall_rows = sizeof(walls) / sizeof(walls[0]);

    for (i = 0; i < wall_rows; i++) {
        printf("\b\t|%s|", walls[i]); 
        printf("\n");
        Sleep(300);
    }

    // --- PART 3: THE FLOOR ---
    printf("\b\t|");
    printf("________|____|________");
    printf("|\n");
    Sleep(300);

    printf("\n");
    return 0;
}

```

### Output (Visual Representation)

*The output appears line-by-line with a 300ms delay.*

```text
               /\
              /  \
             /    \
            /      \
           /        \
          /          \
         /            \
        /              \
       /                \
      /                  \
     /                    \
    /                      \
    ------------------------
    |  _____        _____  |
    | |__|__|      |__|__| |
    | |__|__|      |__|__| |
    |                      |
    |                      |
    |         ____         |
    |        |    |        |
    |        |    |        |
    |________|____|________|

```

---

## Assignment 3: Matrix Chain Multiplication (Recursion)

### Description

**Goal:** Calculate the number of ways to parenthesise the multiplication of  matrices.

**Logic:**
This problem determines the optimal order of operations for matrix multiplication (often used to minimise calculation cost). The number of ways to parenthesize a sequence of  matrices corresponds to the **Catalan Numbers**.

The recurrence relation used in the code is:

      $$Ways(n) = \sum_{k=1}^{n-1} Ways(k) \times Ways(n-k)$$

Where:

* n is the number of matrices.
* k is the split point in the chain.

### Source Code

```c
#include <stdio.h>

// Recursive function to find the number of ways to parenthesise n matrices.
long long countMatrixMultiplicationWays(int n) {
    // Base Case: If there is 1 matrix, there is only 1 way (no multiplication needed).
    // If n is 2, there is 1 way: (AB).
    if (n <= 2) {
        return 1;
    }

    long long totalWays = 0;

    // Iterate through every possible split point k
    for (int k = 1; k < n; k++) {
        totalWays += countMatrixMultiplicationWays(k) * countMatrixMultiplicationWays(n - k);
    }

    return totalWays;
}

int main() {
    int n;

    printf("Enter the number of matrices: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    long long ways = countMatrixMultiplicationWays(n);

    printf("Number of ways to multiply %d matrices: %lld\n", n, ways);

    return 0;
}

```

### Output Example

**Input:**

```text
Enter the number of matrices: 4

```

**Explanation for n=4:**
If we have matrices A, B, C, and D, the possible parenthesizations are:

1. ((AB)C)D
2. (A(BC))D
3. (AB)(CD)
4. A((BC)D)
5. A(B(CD))

**Result:**

```text
Number of ways to multiply 4 matrices: 5

```

---





