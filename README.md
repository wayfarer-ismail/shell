#Implementing a Shell in C that behaves like bash

when executed it does:\
• Print a prompt (# character).\
• Read in a line from stdin.\
• This line will be a command followed by space separated arguments.\
• Execute the command with the given arguments.\
• Wait until command completes.\
• Print the prompt again and accept more commands.\
• Exit when EOF is received (Ctrl+D).

The implemented commands are:\
ls\
sleep\
pwd\
mkdir\
pwd\
cd\
rmdir\
echo\
whoami\
cat\
head