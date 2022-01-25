default:
	gcc -o enc Encoder.c
	gcc -o cent central.c
run:
	./cent
encode:
	./enc
