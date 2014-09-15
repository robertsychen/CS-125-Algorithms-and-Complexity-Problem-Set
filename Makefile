all: randmst test001

randmst: randmst.o disjointset.o graph.o
	g++ -g randmst.o disjointset.o graph.o -lm -o randmst

test002: test002.o disjointset.o graph.o
	g++ -g test002.o graph.o disjointset.o -lm -o test001

test002.o: test002.cpp disjointset.h graph.h
	g++ -Wall -g -c test002.cpp

test001: test001.o graph.o
	g++ -g test001.o graph.o -lm -o test001

test001.o: test001.cpp graph.h
	g++ -Wall -g -c test001.cpp

randmst.o: randmst.cpp graph.h disjointset.h
	g++ -Wall -g -c randmst.cpp

disjointset.o: disjointset.cpp disjointset.h graph.h
	g++ -Wall -g -c disjointset.cpp

graph.o: graph.cpp graph.h disjointset.h
	g++ -Wall -g -c graph.cpp

clean:
	rm -rf *o randmst test*
