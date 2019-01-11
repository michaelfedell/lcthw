# Debuggers

Mac OSX comes with `lldb` as a debugger for C code. This allows you to set breakpoints and step through scripts line by line after hitting the break

To use debugging tools, you will first need to compile your program with the `-g` flag e.g.

```shell
CFLAGS=-Wall -g make ex3
```

This will produce some sort of `.dSYM/` directory

Now, the compiled program is ready for the debugger!

Run the program with lldb by calling:

```shell
lldb ex3
```

This opens up a new shell ready to accept `lldb` commands

Quick reference to lldb commands can be found [here - LCTHW](https://www.safaribooksonline.com/library/view/learn-c-the/9780133124385/ch04.html) or [here - basic commands](https://www.cs.williams.edu/~morgan/cs136-f15/lldb.html)


## Common Debugging Principles:

1. You can't debug code by just looking at it.
2. Repeat the bug with an automated test. (adding debug logs etc)
3. Run the program under a debugger, valgrind, and lint.
4. Find the backtrace and print out all variables in path.
5. Once you fix it, add `check()` macro to prevent future bugs.

Once you start investigating, focusing on the call stack and path variables will help you identify bugs

Get comfortable with lldb, but try out graphical debuggers as well (like ddd debugger or IDE debuggers like in CLion etc)

Try enabling core dumps on your OS which will generate a core file after your program runs

Approach debugging with a "scientific method" attitude. Come up with a possible cause and then rule it out or prove that it does cause a defect. This can be facilitated with ample debug logging

For serious debugging, follow this strategy:

- Start a text file (notes.txt etc) to write out ideas, bugs, problems, etc.
- Before opening debugger, write out the bug that you are hunting and what could be causing it.
- For each cause, write out the files/functions where you think the causeis coming from
- Fire up the debugger and pick the first possible cause with good file and function variables and set breakpoints there
- Use the debugger to run the program and confirm the cause. This can be easily done by using the `set` command to instantly fix or trigger the problem.
- If this cause is not the source, mark it as such in `notes.txt`. Move on and repeat.
