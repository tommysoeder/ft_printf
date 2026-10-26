# ft_printf

`ft_printf` is a compact reimplementation of the core `printf` conversion workflow, developed in C for the 42 curriculum. It parses a format string, retrieves variadic arguments with `stdarg.h`, writes their textual representation to standard output, and returns the number of characters produced.

The project demonstrates variadic functions, format-string parsing, numeric base conversion, recursion, file-descriptor output, and static-library integration.

## Supported conversions

| Specifier | Expected argument | Output |
| --- | --- | --- |
| `%c` | `int` | One character. |
| `%s` | `char *` | A null-terminated string. |
| `%p` | `void *` | A lowercase hexadecimal address prefixed with `0x`. |
| `%d` | `int` | A signed decimal integer. |
| `%i` | `int` | A signed decimal integer. |
| `%u` | `unsigned int` | An unsigned decimal integer. |
| `%x` | `unsigned int` | Lowercase hexadecimal. |
| `%X` | `unsigned int` | Uppercase hexadecimal. |
| `%%` | none | A literal percent sign. |

A null string is rendered as `(null)`. A null pointer passed to `%p` is rendered as `(nil)`.

These conversions form the implemented mandatory scope. The optional formatting bonus—flags, field width, precision, and combinations of those features—is not implemented.

## How it works

`ft_printf` scans the format string from left to right:

1. Ordinary characters are written directly to file descriptor `1`.
2. When `%` is found, the next character is sent to the format dispatcher.
3. The dispatcher selects a dedicated handler and retrieves the expected value with `va_arg`.
4. Numeric handlers recursively emit one digit at a time in decimal or hexadecimal.
5. Every handler returns its character count, which is added to the function's final result.

The variadic lifecycle is started with `va_start` and completed with `va_end`. Passing a null format pointer returns `-1`.

## Project structure

```text
.
├── Makefile
├── ft_printf.h
├── ft_printf.c                 # Main parser and variadic entry point
├── ft_handle_format.c          # Conversion dispatcher
├── ft_handle_char.c
├── ft_handle_string.c
├── ft_handle_integer.c
├── ft_handle_unsigned.c
├── ft_handle_hex_lower.c
├── ft_handle_hex_upper.c
├── ft_handle_pointer.c
├── ft_handle_percent.c
├── ft_hex_utils.c              # Recursive hexadecimal output
└── libft/                      # Bundled Libft sources and build
```

The Makefile builds the bundled Libft archive as a prerequisite and creates a separate `libftprintf.a` containing the formatter objects. The current formatter performs its output directly with `write`.

## Build

Requirements:

- a C compiler available as `cc`;
- GNU Make;
- `ar`, used to create the static archive.

```bash
git clone https://github.com/tommysoeder/ft_printf.git
cd ft_printf
make
```

The build uses `-Wall -Wextra -Werror` and creates:

```text
libftprintf.a
libft/libft.a
```

Available targets:

```bash
make          # Build both static libraries
make clean    # Remove object files
make fclean   # Remove object files and both archives
make re       # Rebuild from scratch
```

## Usage

Include the public header and call `ft_printf` with a valid format string:

```c
#include "ft_printf.h"

int main(void)
{
    int value;
    int written;

    value = 42;
    written = ft_printf(
        "text=%s number=%d hex=%x pointer=%p %%\n",
        "example", -42, 42u, &value);
    ft_printf("written=%d\n", written);
    return (0);
}
```

Compile and link the example:

```bash
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o example
./example
```

Example output begins with:

```text
text=example number=-42 hex=2a pointer=0x...
```

The exact pointer value changes between executions.

## Technical takeaways

- Variadic argument handling with `va_list`, `va_start`, `va_arg`, and `va_end`.
- Sequential parsing and dispatch based on conversion specifiers.
- Signed, unsigned, and base-16 integer representation.
- Recursive digit emission without standard conversion helpers.
- Character-count propagation across specialized handlers.
- Static libraries, public headers, and linker options.

## Current limitations

- Flags such as `-`, `0`, `#`, space, and `+` are not supported.
- Field width, precision, and length modifiers are not supported.
- Floating-point, scientific, wide-character, and `%n` conversions are not implemented.
- Unsupported conversion characters are consumed without output; callers should use only the documented specifiers and avoid a trailing `%`.
- Output is written one character at a time rather than buffered.
- Most handlers count intended characters without propagating `write` failures, so the return value does not reproduce every error behavior of the standard `printf`.
- The repository does not include an automated test suite or a Makefile bonus target.

## Author

Created by [tommysoeder](https://github.com/tommysoeder) as part of the 42 curriculum.

AI tools were used to review the repository and improve this documentation. The supported behavior and limitations described here were checked against the source code, header, Makefile, and a compiled usage example; this statement does not attribute AI use to code where the repository provides no such record.
