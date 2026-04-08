*This project has been created as part of the 42 curriculum by opektas.*

# ft_printf

## Description

`ft_printf` is a partial reimplementation of the C standard library function `printf`. The goal is to understand how variadic functions work in C and how formatted output is produced without relying on the original function.

The function parses a format string character by character. When it encounters a `%` followed by a conversion specifier, it pulls the next argument from the variadic list and dispatches it to the appropriate output function. For all other characters, it writes them directly to stdout. The total number of characters written is tracked and returned.

**Prototype:**
```c
int ft_printf(const char *format, ...);
```

**Supported conversion specifiers:**

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String of characters (`(null)` if NULL) |
| `%p` | Pointer address in hexadecimal (`0x...`, `(nil)` if NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal integer (lowercase) |
| `%X` | Unsigned hexadecimal integer (uppercase) |
| `%%` | Literal `%` character |

### Algorithm and Data Structure

The core logic is a simple linear scan of the format string using an index `i`. No intermediate buffer is used — each character or formatted argument is written to stdout immediately via `write(1, ...)`. This keeps memory usage minimal and avoids any need for dynamic allocation.

When a `%` is detected, `i` is incremented and the next character is passed to `ft_dispatch`, a static dispatcher function that selects the correct output function based on the conversion type. Each output function returns the number of characters it wrote, which is accumulated in a `count` variable.

For numeric output, a single recursive function `ft_putnbr_base` handles all bases (decimal, hexadecimal) by dividing the number recursively until it reaches a single digit, then writing digits on the way back up the call stack. This avoids duplicating logic across `%u`, `%x`, and `%X`. Signed integers are handled separately in `ft_putnbr`, which prepends a `-` sign and negates the value before passing it to `ft_putnbr_base`.

---

## Instructions

### Compilation

```bash
make
```

Produces `libftprintf.a` in the project root.

### Linking in your project

```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

Include the header in your source:
```c
#include "ft_printf.h"
```

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compile the static library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Full rebuild |

### Example

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("String: %s\n", "hello");
    ft_printf("Integer: %d\n", n);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &n);
    return (0);
}
```

---

## Resources

### References

- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h — cppreference](https://en.cppreference.com/w/c/variadic)
- [va_start, va_arg, va_end — cppreference](https://en.cppreference.com/w/c/variadic/va_start)
- [Variadic functions in C — GNU C Library](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### AI Usage

Claude was used in the following ways during this project:

- **Learning `va_*` functions:** I asked Claude to explain how `va_list`, `va_start`, `va_arg`, `va_copy`, and `va_end` work internally, and how variadic argument traversal works at the ABI level. This helped me understand why `char` and `short` arguments must be retrieved as `int` via `va_arg`.
- **Understanding `printf` behavior:** I asked Claude to clarify edge case behavior of the real `printf`, such as how `NULL` is handled for `%s` and `%p`, and the practical difference between `%d` and `%i`.
- **README writing assistance:** I used Claude to help structure and phrase this README in English.
