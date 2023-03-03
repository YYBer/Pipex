# Pipex

## It must take 4 arguments:
• file1 and file2 are file names.

• cmd1 and cmd2 are shell commands with their parameters.

## How does it work?
### in Linux:

    $make
    $./pipex infile "ls -l" "wc -l" outfile
##### or
    $> ./pipex infile "grep a1" "wc -w" outfile
prototype：< file1 cmd1 | cmd2 > file2
