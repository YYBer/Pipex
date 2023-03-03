# Pipex
##It must take 4 arguments:
• file1 and file2 are le names.
• cmd1 and cmd2 are shell commands with their parameters.

## How does it work?
### in Linux:
#### To play, first compile the project with make:
    $make
    $./pipex infile "ls -l" "wc -l" outfile
##### or
    $> ./pipex infile "grep a1" "wc -w" outfile
#####< file1 cmd1 | cmd2 > file2 , you can use anyother shell commands you like.
