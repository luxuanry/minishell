# minishell

A minimal Unix shell implementation in C, a core project from École 42.

## Project Overview

minishell is a functional shell implementation designed to deepen understanding of Unix process management, inter-process communication via pipes, and command-line parsing. The project implements core shell functionality from scratch, including command parsing, execution, redirection, and pipeline handling.

## Core Features

### Basic Functionality
- **Command Execution** - Parse and execute user input commands
- **Built-in Commands** - Implement `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`, and more
- **Environment Variables** - Support variable expansion (`$VAR`) and special variables (`$?`, `$0`, etc.)

### Advanced Functionality
- **Pipelines** - Support multiple commands connected via `|` for inter-process communication
- **Input/Output Redirection** - Support `>`, `>>`, `<`, and `<<` (here-document)
- **Signal Handling** - Handle Ctrl+C and Ctrl+D with bash-compatible interactive behavior
- **Quoting** - Correctly parse single quotes, double quotes, and escape characters

## Technical Highlights

### Core Concepts
- **Process Management** - Create and execute child processes using `fork()` and `execve()`
- **Pipe Communication** - Implement inter-process data transmission with `pipe()`
- **File Redirection** - Redirect standard input/output using `dup2()`
- **Lexical Analysis** - Build a lexer to handle complex command syntax

### Architecture Design
The project consists of the following modules:

1. **Lexer** - Tokenize input strings into manageable units
2. **Parser** - Build an Abstract Syntax Tree (AST) from tokens
3. **Executor** - Interpret and execute the AST
4. **Environment Manager** - Manage environment variables and shell state

## Learning Outcomes

Through this project, I gained deep knowledge and skills in:

- Unix process model and system calls
- C memory management and pointer operations
- Compiler theory fundamentals (lexical and syntax analysis)
- Systems programming best practices
- Complex architecture design and debugging

## Build & Run

```bash
# Compile
make

# Run
./minishell

# Clean
make clean
make fclean
```

## Usage Examples

```bash
$ ./minishell
minishell$ echo "Hello, World!"
Hello, World!

minishell$ pwd
/path/to/minishell

minishell$ ls -la | grep minishell
drwxr-xr-x  user  group  minishell

minishell$ cat < input.txt > output.txt

minishell$ export VAR=value
minishell$ echo $VAR
value
```

## Technical Challenges & Solutions

| Challenge | Solution |
|-----------|----------|
| Synchronizing multiple processes in a pipeline | Use `waitpid()` to wait for all child processes and properly handle return statuses |
| Dynamic environment variable updates | Maintain a separate environment table and copy to child processes before `fork()` |
| Complex quoting and escaping | Character-by-character scanning with a state machine to track parsing context |
| Reliable signal handling | Use `sigaction()` instead of `signal()` to avoid race conditions |

## Possible Extensions

- Background process execution (`&`)
- Command history and line editing (readline integration)
- Advanced redirection (`>&`, `<>`)
- More complex variable substitution scenarios
- Custom functions and script execution

## Code Standards

- Follows École 42 coding standards (Norminette)
- Memory leak detection using valgrind
- Modular design for maintainability and extensibility

---

**Contact**  
GitHub: [luxuanry/minishell](https://github.com/luxuanry/minishell)  