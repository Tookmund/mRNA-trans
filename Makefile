SOURCES = $(wildcard *.cpp) $(wildcard *.h)
CFlags = -Wall -Wno-unused-variable -Wno-sign-compare
Target = runtime

bake:
	g++ $(CFlags) $(SOURCES) -o $(Target) 
