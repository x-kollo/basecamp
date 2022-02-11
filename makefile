CC = g++ -std=c++17
TARGET = main
LIB = lib
SOURCE = search.cpp main.cpp
OBJS = $(SOURCE:.cpp=.o)

LIBS = -pthread

all: $(LIB) 
	$(CC) $(TARGET).cpp search.a $(LIBS) -o search

$(LIB): $(OBJS)
	ar rvs search.a search.o

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS) search search.a
