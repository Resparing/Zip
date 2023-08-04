#App Name and App Directory
APP_NAME = main
APP_DIR = bin/

#Log Path
LOG_PATH = bin/log.txt

#C++ Files
CPP_FILES = $(wildcard src/cpp/*.cpp)

#C++ Standard
CPP_VERSION = -std=c++20

#Includes
INC_DIR = "-Ilib/hpp" "-Isrc/hpp"
INC_LIB = "-Llib/inc"
INC_DYLIB = 
INC_FLAGS = -lssl.3 -lcrypto.3

#Combine All "INC" Variables into one
INC = $(INC_DIR) $(INC_LIB) $(INC_DYLIB) $(INC_FLAGS)

#Compiler Warning Arguments
COMPILER_WARNING_ARGS =  -Wall -Wextra -Wpedantic -Wstrict-aliasing -Wconversion -Wshadow -Wdeprecated -Wstrict-warnings #-Werror

.PHONY: build compile clear clearLog publish

#Build Command
build:
	make compile

	clear

	./$(APP_DIR)$(APP_NAME)

	make clear

#Compile C++ Project
compile:
	clang++ $(CPP_VERSION) -v -o $(APP_DIR)$(APP_NAME) $(CPP_FILES) $(INC) $(COMPILER_WARNING_ARGS)

#Clear Bin Folder
clear:
	rm $(APP_DIR)$(APP_NAME)

#Will Clear the Log
clearLog:
	rm $(LOG_PATH)

#Publish - Unfinished
publish:
	echo Publish Command has not Been Filled Yet!