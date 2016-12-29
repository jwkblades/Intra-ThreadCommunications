FLAGS:=-Wall -pedantic -std=c++11 -pthread
CC:=g++

EXE=ThreadComms

.cpp.o:
	${CC} ${FLAGS} -o $@ -c $^

${EXE}: main.o RAIIMutex.o PostOffice.o Address.o Message.o
	${CC} ${FLAGS} -o $@ $^

.Phony: clean

clean:
	@rm -f *.o ${EXE}
