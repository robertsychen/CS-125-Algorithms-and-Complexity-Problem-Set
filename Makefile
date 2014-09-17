CXXFLAGS := -Wall -g 


all: randmst test001 test002 test003

randmst: randmst.o kruskal.o disjointset.o graph.o
	g++ $(CXXFLAGS) randmst.o graph.o disjointset.o kruskal.o \
	    -lm -o randmst

test003: test003.o graph.o kruskal.o disjointset.o
	g++ $(CXXFLAGS) test003.o graph.o disjointset.o kruskal.o \
	    -lm -o test003

test003.o: test003.cpp kruskal.h graph.h disjointset.h
	g++ $(CXXFLAGS) -c test003.cpp

test002: test002.o disjointset.o graph.o
	g++ $(CXXFLAGS) test002.o graph.o disjointset.o -lm -o test002

test002.o: test002.cpp disjointset.h graph.h
	g++ $(CXXFLAGS) -c test002.cpp

test001: test001.o graph.o
	g++ $(CXXFLAGS) test001.o graph.o disjointset.o -lm -o test001

test001.o: test001.cpp graph.h
	g++ $(CXXFLAGS) -c test001.cpp

kruskal.o: kruskal.cpp kruskal.h graph.h disjointset.h
	g++ $(CXXFLAGS) -c kruskal.cpp

randmst.o: randmst.cpp graph.h disjointset.h
	g++ $(CXXFLAGS) -c randmst.cpp

disjointset.o: disjointset.cpp disjointset.h graph.h
	g++ $(CXXFLAGS) -c disjointset.cpp

graph.o: graph.cpp graph.h disjointset.h
	g++ $(CXXFLAGS) -c graph.cpp

clean:
	rm -rf *o randmst test001 test002 test003
