all: randmst

randmst: randmst.o
	g++ randmst.o -o randmst

randmst.o: randmst.cpp
	g++ -c randmst.cpp

disjointset.o: disjointset.cpp
	g++ -c disjointset.cpp

clean:
	rm -rf *o randmst
