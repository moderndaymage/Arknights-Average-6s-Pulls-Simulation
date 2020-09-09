  
SRC = $(wildcard src/*.c)
HDR = $(wildcard src/*.h)
comp = gcc
flags = -Wall -o main.o arknights_pulls_simulation.c

.PHONY: create
.PHONY: clean
.PHONY: Memory_Check

JangFileToCheck = null

create: ${SRC} ${HDR}
	${comp} ${flags}  ${SRC} ${HDR}

clean: ${SRC} ${HDR}
	rm *.o