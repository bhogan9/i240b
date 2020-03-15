seqFiles =\
	command.hh\
	command.cc\
	arrayseq.hh\
	seq.hh\
	seq-test.cc

numsFiles =\
	nums.cc\
	arrayseq.hh\
	seq.hh

seq-test:
	g++ -g -Wall -std=c++17 $(seqFiles) -o seq-test
nums:
	g++ -g -Wall -std=c++17 $(numsFiles) -o nums
clean:
	rm -f *~ *.o seq-test nums
