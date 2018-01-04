NAME = figureRecognition
INCLUDE = ./include
CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++11 -I $(INCLUDE)
CVLIBS = `pkg-config --cflags --libs opencv`
FANNLIBS = -lfann -lm
DEBUG =
OBJECTS = Idx1Reader.o Idx3Reader.o
SRC = ./src


GenerateTrainingData: GenerateTrainingData.o $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG) $(CVLIBS) $^ -o $@

GenerateTrainingData.o: $(SRC)/GenerateTrainingData.cpp $(INCLUDE)/GenerateTrainingData.h
	$(CC) $(CFLAGS) $(DEBUG) $(CVLIBS) -c $<

Idx1Reader.o: $(SRC)/Idx1Reader.cpp $(INCLUDE)/Idx1Reader.h
	$(CC) $(CFLAGS) $(DEBUG) $(CVLIBS) -c $<

Idx3Reader.o: $(SRC)/Idx3Reader.cpp $(INCLUDE)/Idx3Reader.h
	$(CC) $(CFLAGS) $(DEBUG) $(CVLIBS) -c $<

TrainFann: $(SRC)/TrainFann.cpp
	$(CC) $(CFLAGS) $(DEBUG) $(FANNLIBS) $< -o $@

TestFann: $(SRC)/TestFann.cpp $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG) $(FANNLIBS) $(CVLIBS) $^ -o $@

clean:
	rm -rf *.o
