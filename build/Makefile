

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bat-ulziipurev-ochir/VS/crs/Pong++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bat-ulziipurev-ochir/VS/crs/Pong++/build

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/bat-ulziipurev-ochir/VS/crs/Pong++/build/CMakeFiles /Users/bat-ulziipurev-ochir/VS/crs/Pong++/build//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/bat-ulziipurev-ochir/VS/crs/Pong++/build/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named PongPlusPlus

# Build rule for target.
PongPlusPlus: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 PongPlusPlus
.PHONY : PongPlusPlus

# fast build rule for target.
PongPlusPlus/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/build
.PHONY : PongPlusPlus/fast

src/Ball.o: src/Ball.cpp.o
.PHONY : src/Ball.o

# target to build an object file
src/Ball.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Ball.cpp.o
.PHONY : src/Ball.cpp.o

src/Ball.i: src/Ball.cpp.i
.PHONY : src/Ball.i

# target to preprocess a source file
src/Ball.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Ball.cpp.i
.PHONY : src/Ball.cpp.i

src/Ball.s: src/Ball.cpp.s
.PHONY : src/Ball.s

# target to generate assembly for a file
src/Ball.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Ball.cpp.s
.PHONY : src/Ball.cpp.s

src/GameManager.o: src/GameManager.cpp.o
.PHONY : src/GameManager.o

# target to build an object file
src/GameManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/GameManager.cpp.o
.PHONY : src/GameManager.cpp.o

src/GameManager.i: src/GameManager.cpp.i
.PHONY : src/GameManager.i

# target to preprocess a source file
src/GameManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/GameManager.cpp.i
.PHONY : src/GameManager.cpp.i

src/GameManager.s: src/GameManager.cpp.s
.PHONY : src/GameManager.s

# target to generate assembly for a file
src/GameManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/GameManager.cpp.s
.PHONY : src/GameManager.cpp.s

src/Paddle.o: src/Paddle.cpp.o
.PHONY : src/Paddle.o

# target to build an object file
src/Paddle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Paddle.cpp.o
.PHONY : src/Paddle.cpp.o

src/Paddle.i: src/Paddle.cpp.i
.PHONY : src/Paddle.i

# target to preprocess a source file
src/Paddle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Paddle.cpp.i
.PHONY : src/Paddle.cpp.i

src/Paddle.s: src/Paddle.cpp.s
.PHONY : src/Paddle.s

# target to generate assembly for a file
src/Paddle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Paddle.cpp.s
.PHONY : src/Paddle.cpp.s

src/PowerUp.o: src/PowerUp.cpp.o
.PHONY : src/PowerUp.o

# target to build an object file
src/PowerUp.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/PowerUp.cpp.o
.PHONY : src/PowerUp.cpp.o

src/PowerUp.i: src/PowerUp.cpp.i
.PHONY : src/PowerUp.i

# target to preprocess a source file
src/PowerUp.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/PowerUp.cpp.i
.PHONY : src/PowerUp.cpp.i

src/PowerUp.s: src/PowerUp.cpp.s
.PHONY : src/PowerUp.s

# target to generate assembly for a file
src/PowerUp.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/PowerUp.cpp.s
.PHONY : src/PowerUp.cpp.s

src/UI.o: src/UI.cpp.o
.PHONY : src/UI.o

# target to build an object file
src/UI.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/UI.cpp.o
.PHONY : src/UI.cpp.o

src/UI.i: src/UI.cpp.i
.PHONY : src/UI.i

# target to preprocess a source file
src/UI.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/UI.cpp.i
.PHONY : src/UI.cpp.i

src/UI.s: src/UI.cpp.s
.PHONY : src/UI.s

# target to generate assembly for a file
src/UI.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/UI.cpp.s
.PHONY : src/UI.cpp.s

src/Utilities.o: src/Utilities.cpp.o
.PHONY : src/Utilities.o

# target to build an object file
src/Utilities.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Utilities.cpp.o
.PHONY : src/Utilities.cpp.o

src/Utilities.i: src/Utilities.cpp.i
.PHONY : src/Utilities.i

# target to preprocess a source file
src/Utilities.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Utilities.cpp.i
.PHONY : src/Utilities.cpp.i

src/Utilities.s: src/Utilities.cpp.s
.PHONY : src/Utilities.s

# target to generate assembly for a file
src/Utilities.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/Utilities.cpp.s
.PHONY : src/Utilities.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/PongPlusPlus.dir/build.make CMakeFiles/PongPlusPlus.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... PongPlusPlus"
	@echo "... src/Ball.o"
	@echo "... src/Ball.i"
	@echo "... src/Ball.s"
	@echo "... src/GameManager.o"
	@echo "... src/GameManager.i"
	@echo "... src/GameManager.s"
	@echo "... src/Paddle.o"
	@echo "... src/Paddle.i"
	@echo "... src/Paddle.s"
	@echo "... src/PowerUp.o"
	@echo "... src/PowerUp.i"
	@echo "... src/PowerUp.s"
	@echo "... src/UI.o"
	@echo "... src/UI.i"
	@echo "... src/UI.s"
	@echo "... src/Utilities.o"
	@echo "... src/Utilities.i"
	@echo "... src/Utilities.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

