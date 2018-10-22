# cmdline_facility
some useful tools when you use cmdline in *nix

#### mergecol
This is a tool to merge all the columns in a ascii file which share the same first columns.the content of the file must be sorted and this program will print the modified one to the stdout.
I did not apply too much options,one of the reasons is that I just want a simple tool,another is that other unix tools can provide some advance functions,such as sort,unique,paste and awk.Using simple tools to build complex functions,this is the philosophy of unix.
And maybe you can optimize it,just do it.

#### youdao
This is a python script using YouDao's api(a translation-service company in China) to translate the scentence you input.With no arguments from the cmdline,it will start a loop,while with arguments,it just translate the arguments.You should register your own api keys.
Make sure that you have installed python request library.(I think it is a good library to use)

#### storeidea
Sometimes I just come up with some arguments about...and maybe I should write it down.However,it is quite annoying that there are so many txt files.So I use sqlite3 to setup a database to store my ideas.Similar to the mergecol above,it just provide simple tools,storing time and content.However,with power tools like grep,you can do a lot of things such as search with keywords and check what you write several days ago.
It is lite,and so is the sqlite3

-s : show all the content you insert in
-i : insert the words
-q : quiet,without newline after the date

#### genMakefile.sh
This is a script to generate makefile for C and C++.Because it is hard to deal with the dependance between source files when the project is large.So I wrote this shell script to help with it.You should have install echo,awk,gcc to use it.What you should do is just put this in your project-root directory and run the command.It can deal with all the dependance itself with gcc.Or you can put it in your ~/bin and add it to your path,which is recommended.If you have any good advice,just tell me and
help improve it

(maybe I am just too lazy.But that's not a problem.)You can modify it as you like.I think you can do better than me.
