CC=gcc
FLAGS=-WALL -g

all: shell

shell: shell.c
	$(CC) -o shell shell.c