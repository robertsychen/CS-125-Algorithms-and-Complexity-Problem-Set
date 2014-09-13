all: randmst

randmst: randmst.o disjointset.o graph.o
	g++ -g randmst.o disjointset.o graph.o -lm -o randmst

randmst.o: randmst.cpp
	g++ -Wall -g -c randmst.cpp

disjointset.o: disjointset.cpp disjointset.h graph.h
	g++ -Wall -g -c disjointset.cpp

graph.o: graph.cpp graph.h disjointset.h
	g++ -Wall -g -c graph.cpp

clean:
	rm -rf *o randmst
