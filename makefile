
files = fork_example1 fork_example2 fd_example1 fd_example2 signal_example1 signal_example2 
files += pipe_example1 pipe_example2 pipe_example3
files += FIFO_example1 FIFO_example2
files += shared_memory_example1 shared_memory_example2 shared_memory_example3

main:
	$(foreach files, $(files), gcc $(files).c -o $(files).out;)
	g++ -o line_number line_number.cpp

main2: 
	rm -rf ./deploy/*.c ./deploy/*.cpp ./deploy/makefile ./deploy/README.md ./deploy/os_hw3_sample.m4v
	$(foreach files, $(files), cp $(files).c ./deploy/$(files).c;)
	cp makefile ./deploy/makefile
	cp line_number.cpp ./deploy/line_number.cpp
	cp README.md ./deploy/README.md
	
showlist: 
	@echo $(files)

clean:
	rm -rf *.out
	rm line_number
