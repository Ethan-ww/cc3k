CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = cc3k
OBJECTS = main.o floor.o cell.o character.o item.o goblin.o halfling.o dragon.o drow.o dwarf.o elf.o enemy.o gameplay.o merchant.o orcs.o human.o player.o potion.o shade.o treasure.o troll.o vampire.o conio.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
