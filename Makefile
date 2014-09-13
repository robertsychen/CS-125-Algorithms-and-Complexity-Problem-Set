all: randmst

randmst: randmst.o disjointset.o graph.o
	g++ randmst.o disjointset.o graph.o -o randmst

randmst.o: randmst.cpp
	g++ -c randmst.cpp

disjointset.o: disjointset.cpp
	g++ -c disjointset.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

clean:
	rm -rf *o randmst
