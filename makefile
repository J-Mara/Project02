default:
	gcc -c Encoder.c
	gcc -c central.c
	gcc -o testprogram Encoder.o central.o

run:
	./testprogram $(ARGS)

inputs:
	./make_inputs.sh testDirIn 300 10

clear:
	rm -rf testDirIn/* testDirOut/*
