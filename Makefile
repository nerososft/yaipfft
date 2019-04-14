# dir
BASE_DIR=/Users/neroyang/project/sbwIP

# include
INCLUDE_DIR=$(BASE_DIR)/framework/include/
INCLUDE_DIR+=$(BASE_DIR)/app/include/

# app
SRC=$(wildcard $(BASE_DIR)/app/src/*.cpp)
# framework
SRC+=$(wildcard $(BASE_DIR)/framework/src/*.cpp)

# build dir
BUILD_DIR=$(BASE_DIR)/app/build
# objs dir
OBJS_DIR=$(BASE_DIR)/app/obj
# asm dir
ASM_DIR=$(BASE_DIR)/app/asm

# compiler
CXX=g++

# build flags
CPP_FLAGS=-I$(INCLUDE_DIR) -std=c++11 -Wall
LINK_FLAGS=

# extera lib
LIB=-lstdc++ -ljpeg -lSDL2 -lSDL2main `sdl2-config --cflags --libs` -lpthread

run:	clean	all
	$(BUILD_DIR)/app
 
all:	main.o Window.o WindowManager.o Thread.o	Runnable.o	JPGImageLoader.o 	ImageLoader.o GrayFliter.o BinaryValFliter.o 	Fliter.o	IOManager.o PixelMatrix.o Pixel.o
	$(CXX) -o $(BUILD_DIR)/app \
	$(OBJS_DIR)/main.o \
	$(OBJS_DIR)/Window.o \
	$(OBJS_DIR)/WindowManager.o \
	$(OBJS_DIR)/Thread.o \
	$(OBJS_DIR)/Runnable.o \
	$(OBJS_DIR)/JPGImageLoader.o \
	$(OBJS_DIR)/ImageLoader.o \
	$(OBJS_DIR)/GrayFliter.o \
	$(OBJS_DIR)/BinaryValFliter.o \
	$(OBJS_DIR)/Fliter.o \
	$(OBJS_DIR)/IOManager.o \
	$(OBJS_DIR)/PixelMatrix.o \
	$(OBJS_DIR)/Pixel.o \
	$(LIB)

main.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/main.o -c $(BASE_DIR)/app/src/main.cpp $(LIB)
Window.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/Window.o -c $(BASE_DIR)/framework/src/window/Window.cpp $(LIB)
WindowManager.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/WindowManager.o -c $(BASE_DIR)/framework/src/window/WindowManager.cpp $(LIB)
Runnable.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/Runnable.o -c $(BASE_DIR)/framework/src/thread/Runnable.cpp $(LIB)
Thread.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/Thread.o -c $(BASE_DIR)/framework/src/thread/Thread.cpp $(LIB)
JPGImageLoader.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/JPGImageLoader.o -c $(BASE_DIR)/framework/src/io/JPGImageLoader.cpp $(LIB)
ImageLoader.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/ImageLoader.o -c $(BASE_DIR)/framework/src/io/ImageLoader.cpp $(LIB)
GrayFliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/GrayFliter.o -c $(BASE_DIR)/framework/src/fliter/GrayFliter.cpp $(LIB)
BinaryValFliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/BinaryValFliter.o -c $(BASE_DIR)/framework/src/fliter/BinaryValFliter.cpp $(LIB)
Fliter.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/Fliter.o -c $(BASE_DIR)/framework/src/fliter/Fliter.cpp $(LIB)
IOManager.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/IOManager.o -c $(BASE_DIR)/framework/src/io/IOManager.cpp $(LIB)
PixelMatrix.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/PixelMatrix.o -c $(BASE_DIR)/framework/src/image/PixelMatrix.cpp $(LIB)
Pixel.o:
	$(CXX) $(CPP_FLAGS) -o $(OBJS_DIR)/Pixel.o -c $(BASE_DIR)/framework/src/image/Pixel.cpp $(LIB)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(BUILD_DIR)
	mkdir $(OBJS_DIR)
	mkdir $(BUILD_DIR)

