#Project02

Parallel processing in and out basic encryption from files

Jordan Maragakis pd5

The programs read the contents of a directory given in the command line and encrypt the file with a caesar cipher created from any numbers in the file. The encrypted files are written into another directory without touching the original files. The program uses forked processes to make the code run faster by parallel processing.

You should have two (ideally empty) directories in the same directory as the project. Run make to construct the project. If the input directory you are using is empty, run make inputs to create 300 files in a directory called testDirIn starting with a number, the phrase “this is a test” and then some gibberish. If your input directory isn’t empty, you might still want to put a number near the beginning. Run make run ARGS=”input_directory output_directory N T” with your own input and output directories. N is the number of forked processes you want to use (at most the number of cores you have to maximize efficiency), and T is an int where if T is 0, the cipher will shift each character up, but if it isn’t, it will shift down. Files in the output directory will have the same name as their corresponding file in the input directory, and will overwrite themselves if necessary.

No external libraries
