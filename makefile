build:
	gcc -Wall -ggdb3 -std=c99 ./*.c -lSDL2 -lSDL2_image -lm -o game
