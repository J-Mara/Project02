default:
	gcc -c Encoder.c
	gcc -c central.c
	gcc -o testprogram Encoder.o central.o

run:
	./testprogram
