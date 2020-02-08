TARGET=breaker
all:
	(unshadow training-passwd.txt training-shadow.txt) > shadow.txt
	gcc breaker.c -o $(TARGET) -lcrypt

runall:

	./breaker -i shadow.txt -d top250.txt -o all
