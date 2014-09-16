all: randmst test001 test002 

randmst: randmst.o kruskal.o disjointset.o graph.o
	g++ -g randmst.o disjointset.o graph.o kruskal.o -lm -o randmst

test003: test003.o graph.o kruskal.o disjointset.o
	g++ -g test003.o graph.o disjointset.o kruskal.o -lm -o test003

test003.o: test003.cpp kruskal.h graph.h disjointset.h
	g++ -Wall -g -c test003.cpp

test002: test002.o disjointset.o graph.o
	g++ -g test002.o graph.o disjointset.o -lm -o test002

test002.o: test002.cpp disjointset.h graph.h
	g++ -Wall -g -c test002.cpp

test001: test001.o graph.o
	g++ -g test001.o graph.o -lm -o test001

test001.o: test001.cpp graph.h
	g++ -Wall -g -c test001.cpp

kruskal.o: kruskal.cpp kruskal.h graph.h disjointset.h
	g++ -Wall -g -c kruskal.cpp

randmst.o: randmst.cpp graph.h disjointset.h
	g++ -Wall -g -c randmst.cpp

disjointset.o: disjointset.cpp disjointset.h graph.h
	g++ -Wall -g -c disjointset.cpp

graph.o: graph.cpp graph.h disjointset.h
	g++ -Wall -g -c graph.cpp

clean:
	rm -rf *o randmst test001 test002 test003
