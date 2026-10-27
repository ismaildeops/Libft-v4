*This project has been created as part of the 42 curriculum by ilaakoub.*

# Libft

## Description

**Libft** is a C library built from scratch that reimplements a selection of standard C library (`libc`) functions and extends them with custom string, memory, output, and linked‑list utilities. It is the first project of the 42 core curriculum and serves as the foundation that every later C project is built on top of.

The goal of the project is twofold:

- Understand **how** the standard functions you use every day actually work internally, by reimplementing them under the exact same prototypes and behavior described in their man pages.
- Build a small, reusable **toolbox** of general‑purpose functions (string manipulation, memory handling, file‑descriptor output, and singly linked lists) that can be dropped into any future C project.

All reimplemented functions are prefixed with `ft_` (e.g. `strlen` → `ft_strlen`) and compiled into a single static library, `libft.a`.

## Instructions

### Compilation

The project is built with a `Makefile` that follows the standard 42 rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`. Sources are compiled with `cc` using `-Wall -Wextra -Werror`, and the archive is built with `ar`.

| Command | Effect |
|---|---|
| `make` / `make all` | Compiles every `ft_*.c` source file into object files and archives them into `libft.a` at the repository root. |
| `make clean` | Removes all intermediate object files (`.o`). |
| `make fclean` | Removes object files **and** the compiled `libft.a`. |
| `make re` | Equivalent to `make fclean` followed by `make`; forces a full rebuild. |

```bash
git clone <repository-url> libft
cd libft
make
```

This produces `libft.a` at the root of the repository, ready to be linked against.

### Using Libft in another project

Include the header and link the archive when compiling your own project:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Library Details

The library is organized into three parts, mirroring the structure of the subject: reimplemented `libc` functions, additional custom utilities, and a singly linked list toolkit.

### Part 1 — Libc Functions

Reimplementations of standard `libc` functions with identical prototypes and behavior, written without relying on any external function.

| Function | Prototype | Description |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c);` | Checks whether `c` is an alphabetic character. Returns `1`/`0`. |
| `ft_isdigit` | `int ft_isdigit(int c);` | Checks whether `c` is a decimal digit. Returns `1`/`0`. |
| `ft_isalnum` | `int ft_isalnum(int c);` | Checks whether `c` is alphanumeric. Returns `1`/`0`. |
| `ft_isascii` | `int ft_isascii(int c);` | Checks whether `c` is a valid ASCII code (0–127). Returns `1`/`0`. |
| `ft_isprint` | `int ft_isprint(int c);` | Checks whether `c` is a printable character (including space). Returns `1`/`0`. |
| `ft_strlen` | `size_t ft_strlen(const char *s);` | Returns the length of the string `s`. |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len);` | Fills the first `len` bytes of `b` with byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n);` | Zeroes out the first `n` bytes of `s`. |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n);` | Copies `n` bytes from `src` to `dst` (non‑overlapping). |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len);` | Copies `len` bytes from `src` to `dst`, safe for overlapping regions. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);` | Size‑bounded string copy; returns the length of `src`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);` | Size‑bounded string concatenation; returns total length attempted. |
| `ft_toupper` | `int ft_toupper(int c);` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | `int ft_tolower(int c);` | Converts an uppercase letter to lowercase. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c);` | Locates the first occurrence of `c` in `s`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c);` | Locates the last occurrence of `c` in `s`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares up to `n` bytes of two strings. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n);` | Locates the first occurrence of `c` in the first `n` bytes of `s`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares the first `n` bytes of two memory areas. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len);` | Locates a substring in a string, searching at most `len` bytes. |
| `ft_atoi` | `int ft_atoi(const char *str);` | Converts a string to an `int`, skipping leading whitespace and handling an optional sign. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size);` | Allocates and zero‑initializes memory using `malloc`. Always returns a valid, freeable pointer, even if `nmemb` or `size` is `0`. |
| `ft_strdup` | `char *ft_strdup(const char *s1);` | Allocates and returns a copy of the string `s1` using `malloc`. |

### Part 2 — Additional Functions

Custom utilities that do not exist in the standard `libc`, or exist in a different form, aimed at everyday string manipulation and output.

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Returns a newly allocated substring of `s`, starting at index `start`, of at most `len` characters. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Returns a newly allocated string resulting from the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Returns a newly allocated copy of `s1` with the leading and trailing characters found in `set` removed. |
| `ft_split` | `char **ft_split(char const *s, char c);` | Splits `s` into a `NULL`-terminated array of newly allocated strings, using `c` as a delimiter. |
| `ft_itoa` | `char *ft_itoa(int n);` | Returns a newly allocated string representing the integer `n` (handles negative numbers). |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies `f` to each character of `s` (with its index), building a new allocated string from the results. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Applies `f` to each character of `s` in place, passing its index and address so it can be modified. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Outputs the character `c` to the file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Outputs the string `s` to the file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Outputs the string `s` to `fd`, followed by a newline. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Outputs the integer `n` to the file descriptor `fd`. |

### Part 3 — Linked List Functions

A minimal singly linked list toolkit built around the `t_list` structure, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- **`content`** — a `void *`, so any data type can be stored in a node.
- **`next`** — the address of the following node, or `NULL` if it is the last one.

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates and returns a new node, initialized with `content` and a `NULL` `next` pointer. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Inserts the node `new` at the beginning of the list `lst`. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst);` | Counts and returns the number of nodes in `lst`. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of `lst`. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Inserts the node `new` at the end of the list `lst`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees a single node's content via `del`, then frees the node itself (does **not** touch `next`). |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees every node of `lst`, from the start, using `del`, and sets `*lst` to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies `f` to the content of each node of `lst`, without modifying the list itself. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Builds and returns a new list by applying `f` to each node's content of `lst`; frees any partially built list with `del` if an allocation fails. |

---

## Project Structure

```
libft/
├── Makefile          # NAME, all, clean, fclean, re rules
├── libft.h            # Prototypes + t_list structure declaration
├── ft_isalpha.c
├── ft_strlen.c
├── ft_split.c
├── ft_lstnew.c
├── ...                 # one (or a few related) functions per ft_*.c file
└── README.md
```

All `.c` and `.h` files are kept at the root of the repository, as required by the subject — no unused files are submitted.

---

## Norm & Technical Constraints

This project strictly follows the 42 Norm and the subject's technical requirements:

- No global variables.
- Helper functions used to break down more complex logic are declared `static` to keep their scope local to the file.
- Every `.c` file compiles cleanly with `-Wall -Wextra -Werror`.
- The `restrict` keyword (C99) is never used in prototypes, and the code does not rely on `-std=c99`.
- The archive is built exclusively with `ar` (no `libtool`).
- No function is allowed to crash unexpectedly (segfault, bus error, double free) outside of genuine undefined behavior.
- All heap-allocated memory is freed when no longer needed — no memory leaks.
- `ft_calloc` follows the rule that `nmemb == 0` or `size == 0` still returns a unique, freeable pointer.

## Resources

- The official **Libft subject**, provided by the 42 curriculum.
- Relevant **C and POSIX manual pages** (`man 3`) for every reimplemented function.
- **AI usage**: AI was used to review the submitted code, identify errors, and help format and correct implementations. It was not used to generate the logic of the functions from scratch; every change produced with its help was reviewed and understood before submission, in line with 42's AI usage guidelines.
