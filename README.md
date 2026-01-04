# C Programming Assignments_Semester 1

This repository contains three distinct C programs covering syntax tricks, ASCII art animation, and algorithmic recursion.

## Table of Contents

1. [Assignment 1: Print name without using semicolon in entire program](https://www.google.com/search?q=%23assignment-1-semicolon-less-printing)
2. [Assignment 2: ASCII House Animation](https://www.google.com/search?q=%23assignment-2-ascii-house-animation)
3. [Assignment 3: Matrix Chain Multiplication (Recursion)](https://www.google.com/search?q=%23assignment-3-matrix-chain-multiplication-recursion)
4. [Assignment 4: donut.c Explanation]()

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

<img width="512" height="116" alt="image" src="https://github.com/user-attachments/assets/93ed1244-ce34-4103-a83c-e558971155de" />


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

## Assignment 4: donut.c Explanation

### Description

This repository contains an explanation and analysis of the famous **donut.c** code, originally written by [Andy Sloane](https://www.a1k0n.net/2011/07/20/donut-math.html) in 2006. It is a masterpiece of obfuscated C programming that renders a spinning 3D torus (donut) using ASCII characters.

## 🍩 The Source Code

Here is the original obfuscated code.

```c
          #include <stdio.h>
          #include <string.h>
          int k;double sin()
       ,cos();int main(){float A=
       0,B=0,i,j,z[1760];char b[
     1760];printf("\x1b[2J");for(;;
  ){memset(b,32,1760);memset(z,0,7040)
  ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
 >i;i+=0.02){float c=sin(i),d=cos(j),e=
 sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
 h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
in(B),t=c*h*g-f*        e;int x=40+30*D*
(l*h*m-t*n),y=            12+15*D*(l*h*n
+t*m),o=x+80*y,          N=8*((f*e-c*d*g
 )*m-c*d*e-f*g-l        *d*n);if(22>y&&
 y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
 ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
  printf("\x1b[H");for(k=0;1761>k;k++)
   putchar(k%80?b[k]:10);A+=0.08;B+=
     0.04;}}/*****####*******!!=;:~
       ~::==!!!**********!!!==::-
         .,~~;;;========;;;:~-.
             ..,--------,*/

```



## 🧠 How It Works

At a high level, the program performs 3D rendering logic usually reserved for Graphics Processing Units (GPUs), but it does so entirely in the CPU using text characters.

The process can be broken down into five distinct steps within the main infinite loop:

### 1. The Geometry (The Torus)

A torus is essentially a circle rotated around an axis. The code uses two loop variables, `i` and `j`, to sweep across the surface of the torus.

* **`i` ($\phi$):** Goes from 0 to 2PI . This draws the cross-sectional circle of the donut.
* **`j` ($\theta$):** Goes from 0 to 2PI. This rotates that circle around the central axis of the donut.

### 2. The Rotation (Spinning)

To make the donut spin, the code applies a 3D rotation matrix to every point (x, y, z) on the torus surface.

* **`A`**: The angle of rotation around the X-axis.
* **`B`**: The angle of rotation around the Z-axis.
* These variables are incremented at the end of every frame (`A+=0.08; B+=0.04`), causing the animation.

### 3. 3D to 2D Projection

The computer screen is 2D, but the math is 3D. To render this, the code performs **perspective projection**.

* It calculates the distance of the point from the viewer.
* It moves points that are further away closer to the centre of the screen, creating the illusion of depth.
* The variable `D` represents `1/z` (inverse depth), which is used to scale the coordinates.

### 4. The Z-Buffer (Depth Handling)

The screen is represented by a buffer array `b[]` (characters) and a Z-buffer array `z[]` (depth data).

* The code calculates thousands of points. Many points will overlap (e.g., the front of the donut overlaps the back).
* **The Logic:** Before drawing a character, the code checks `z[]`. If the new point is closer to the camera than what is currently there, it overwrites it. If it is further away (behind), it skips it.

### 5. Luminance (ASCII Shading)

How does the donut look 3D? By lighting.

* The code calculates the **Surface Normal** for every point (a vector perpendicular to the surface).
* It calculates the dot product of the surface normal and a light direction vector (fixed lighting).
* The result, `N`, determines how bright that pixel is.
* `N` is mapped to a string of characters sorted by pixel density:
```c
".,-~:;=!*#$@"

```


( `.` is dim/shadow, `@` is bright/lit).

---

## 🔍 De-obfuscating the Variables

The code is "obfuscated," meaning it is intentionally written to be hard to read (and shaped like a donut). Here is a translation of the single-letter variables:

| Variable | Meaning |
| --- | --- |
| `A`, `B` | The global rotation angles (animation state). |
| `i`, `j` | Loop iterators for the torus angles ( and ). |
| `c`, `d`, `e`, `f`, `g` | Pre-calculated sines and cosines. e.g., `c=sin(i)`, `d=cos(j)`. This optimises performance. |
| `D` | (1 / distance) Used for perspective projection (things get smaller as they get farther). |
| `x`, `y` | The final 2D coordinates on your terminal screen. |
| `o` | The offset/index in the screen buffer (calculating `y * width + x`). |
| `N` | Luminance index (0 to 11). Determines which ASCII character to use. |
| `z[]` | The Z-buffer (stores the depth of every pixel). |
| `b[]` | The frame buffer (stores the characters to be printed). |

---

The code combines the rotation matrices and projection into one condensed block of algebra to save space:

```c
// The "Magic" Formula in the code
D = 1 / (c * h * e + f * g + 5); 
int x = 40 + 30 * D * (l * h * m - t * n);
int y = 12 + 15 * D * (l * h * n + t * m);

```

---

## 📝 Credits

* **Original Author:** Andy Sloane
* **Source:** [The IOCCC (International Obfuscated C Code Contest)](https://www.ioccc.org/) inspired structure.
* **Original Blog Post:** [Donut Math](https://www.a1k0n.net/2011/07/20/donut-math.html) - Highly recommended for a deep dive into the derivation of the surface normals.





