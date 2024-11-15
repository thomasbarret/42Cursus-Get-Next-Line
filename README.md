# 42Cursus - Get Next Line

This repository contains the **Get Next Line** project for **42Cursus**, where you will implement a function that reads a line from a file descriptor, handling multiple lines and various edge cases.

---

## Repository Structure

```plaintext
.
├── get_next_line.c             # Main implementation of the Get Next Line function
├── get_next_line.h             # Header file containing function prototypes and necessary definitions
├── get_next_line_bonus.c       # Bonus version with support for multiple file descriptors
├── get_next_line_bonus.h       # Header file for the bonus part
├── get_next_line_utils.c       # Utility functions used in the main implementation
└── get_next_line_utils_bonus.c # Utility functions used in the bonus part
```

---

## Overview

The project focuses on implementing the `get_next_line` function, which reads a line from a file descriptor, handling different situations like reading from a file, stdin, or even a socket. 

Key features:
- The function should handle multiple file descriptors.
- Each call to `get_next_line` returns the next line from the input.
- If there is no more content, the function should return `NULL`.
- The bonus part includes handling multiple file descriptors.

---

## Functions Implemented

| **Function**              | **Description**                                      |
|---------------------------|------------------------------------------------------|
| `get_next_line`           | Reads a line from a file descriptor and returns it.  |
| `get_next_line_bonus`     | Bonus version of the function supporting multiple file descriptors. |
| `get_next_line_utils`     | Utility functions for reading and managing the input buffer in the main implementation. |
| `get_next_line_utils_bonus` | Bonus utility functions supporting multiple file descriptors. |

---

## How to Use

1. **Include the Header**  
   To use `get_next_line`, include the header file in your code:
   ```c
   #include "get_next_line.h"

   int main() {
       int fd = open("somefile.txt", O_RDONLY);
       char *line;
       while ((line = get_next_line(fd)) != NULL) {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return 0;
   }
   ```

2. **Bonus Functionality**  
   The bonus part handles multiple file descriptors. It works exactly like the main function but can handle several files simultaneously.

   Example of using `get_next_line_bonus`:
   ```c
   #include "get_next_line_bonus.h"

   int main() {
       int fd1 = open("file1.txt", O_RDONLY);
       int fd2 = open("file2.txt", O_RDONLY);
       char *line1, *line2;
       while ((line1 = get_next_line(fd1)) != NULL && (line2 = get_next_line(fd2)) != NULL) {
           printf("File 1: %s", line1);
           printf("File 2: %s", line2);
           free(line1);
           free(line2);
       }
       close(fd1);
       close(fd2);
       return 0;
   }
   ```

---

## Example

```c
#include "get_next_line.h"

int main() {
    int fd = open("sample.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

**Output:**
```
Hello, this is the first line.
This is the second line.
The third line is here.
```
