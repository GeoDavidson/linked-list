CC = gcc

final: src/main.c
	$(CC) src/main.c -o main.exe && main.exe

clean:
	rm main.exe
