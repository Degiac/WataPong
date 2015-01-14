OBJS = include/WataPong.h src/WataPong.cpp include/Entity.h src/Entity.cpp include/Speed.h src/Speed.cpp include/GameWorld.h src/GameWorld.cpp

CC = g++

COMPILER_FLAGS = -Wall -std=c++11 -pedantic

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)

OBJ_NAME = WataPong.out

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(SDL_CFLAGS) $(SDL_LDFLAGS) -o $(OBJ_NAME)
	
run : $(OBJ_NAME)
	./$(OBJ_NAME)
