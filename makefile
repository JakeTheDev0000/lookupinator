
output: lookupinator.o delay.o UsrInfoMgr.o
	gcc lookupinator.o delay.o UsrInfoMgr.o -o ./bin/lookupinator-dev

lookupinator.o: src/lookupinator.c
	gcc -c src/lookupinator.c

delay.o: src/delay.c src/delay.h
	gcc -c src/delay.c

UsrInfoMgr.o: src/UsrInfoMgr.c src/UsrInfoMgr.h
	gcc -c src/UsrInfoMgr.c

# listLPF.o: src/listLPF.c src/listLPF.h
# 	gcc -c src/listLPF.c

exec:
	./bin/lookupinator-dev

clean:
	rm *.o

