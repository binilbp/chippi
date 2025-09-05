# chippi 

🐚 chippi(ചിപ്പി) is Malayalam for shell.

As the name suggests, this project is a hobby attempt to build a lightweight, minimal, and fun command-line shell in C. (primarily to study C, do give feedback if you feel like i could have made a better code somewhere)


## Current Status 
- dev focus on user input reading
- no parsing or execution
- fun simple chippi features (eg:`hello` command)
- support exit on pressing `Ctrl+D` or typing `exit` in user input

## Testing Out

### Prerequisites
- C compiler, GCC is prefered as i have not tested this out with any other compiler
- and ofcourse terminal

### Compile 
```bash
git clone https://github.com/binilbp/chippi.git
cd chippi
gcc main.c chippi.c commands.c input.c -o chippi
```
### Run
```
./chippi
```
