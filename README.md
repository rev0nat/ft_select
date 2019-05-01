# ft_select
A program that allows you to quickly choose a set of selection from a given list of arguments.

## DOWNLOAD
  $> git clone https://github.com/rev0nat/21sh.git dir_name
 
## PREREQUISITES
  To be able to compile and run this program, you'll need the folowing:
  - A terminal emulator such as xterm or iterm;
  - Clang at any recent version; (mine is clang-900.0.39.2 -- Apple modified)

## COMPILATION
  Makefile rules:
  - $> make
      Compiles the project using the 'all' rule
  - $> make clean
      Removes all .o && .d
  - $> make fclean
      Same as 'clean' but removes the executable also
  <! Bear in mind that this project was developped under MacOs Sierra 10.12.6.
  Some features might not work if you are using another environment.
  For example the -ltermcaps Library option doesn't work on Linux and has to be replaced by -lncurses in order to compile !>
  
## RUN
  $> ./ft_select [arg1] [arg2] ...
  
## USE
  ft_select is a small usefull tool that will help you browse through your files to do anything specific with a set of files.
  Navigate through the arguments you give ft_select with the arrow keys.
  Select|Deselect any given file with the `spacebar` key.
  Select|Deselect all with the `a` key.
  Return your choices with the `return` key.
  
  You can chain ft_select with any command, such as:
  ```diff
  $> more `ft_select *.c`
  $> rm `ft_select ~/*`
  + try it out!
  ```
  
