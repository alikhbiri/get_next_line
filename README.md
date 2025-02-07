# get_next_line

## Overview
The **get_next_line** project is a fundamental exercise in C programming that focuses on handling file input efficiently. The goal is to create a function that reads a file, line by line, without loading the entire file into memory at once. This function must be optimized to work with various file descriptors and different buffer sizes.

## Understanding Key Concepts
Before diving into the implementation, it's essential to understand the following principles:

### 1. **File Descriptors**
   - A file descriptor (fd) is an integer that uniquely identifies an open file.
   - Standard file descriptors: `0` (stdin), `1` (stdout), `2` (stderr).
   - When opening a file using `open()`, a new file descriptor is assigned.

### 2. **Dynamic Memory Allocation**
   - Since we don’t know the size of the lines beforehand, we must dynamically allocate memory using `malloc()`.
   - Memory management is crucial to avoid leaks and optimize performance.

### 3. **Buffers and Static Variables**
   - A buffer is used to store temporary data read from the file.
   - Using a static variable allows persisting data between function calls, making it possible to retrieve the remaining part of the line in subsequent calls.

### 4. **String Manipulation**
   - Functions like `strchr()`, `strlen()`, `strdup()`, `strjoin()`, and `memcpy()` are useful for handling substrings and concatenations.

### 5. **Reading a File Efficiently**
   - The function reads a file using `read()` and processes data chunk by chunk.
   - `read()` returns the number of bytes read or `0` if the end of the file (EOF) is reached.

---

## Implementation Details
### Function Prototype
```c
char *get_next_line(int fd);
```

### Steps of Execution
1. **Check Input Validity**
   - If the file descriptor is invalid or `BUFFER_SIZE` is not properly defined, return `NULL`.

2. **Read and Store Data**
   - Use `read()` to fetch data from the file and append it to a static buffer.

3. **Extract a Line**
   - Identify a newline character (`'\n'`) and extract the complete line.
   - Store the remaining content in a static variable for the next call.

4. **Return the Line**
   - Allocate memory dynamically to store the extracted line and return it.

5. **Handle End of File (EOF) and Errors**
   - If `read()` returns `0`, free all allocated memory and return `NULL`.
   - Properly close file descriptors when they are no longer needed.

### Edge Cases Considered
- Reading from an empty file.
- Handling multiple file descriptors simultaneously.
- Managing different buffer sizes (`BUFFER_SIZE` can be modified for testing).
- Ensuring proper memory allocation and avoiding leaks.

---

## Example Usage
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## Testing and Debugging
To test the function, use different file inputs with varying line lengths and content:
```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
./a.out
```
Use **Valgrind** to check for memory leaks:
```sh
valgrind --leak-check=full ./a.out
```

---

## Summary
This project enhances knowledge of file handling, memory management, and efficient data processing. Mastering **get_next_line** is crucial for more advanced system programming projects in C.

