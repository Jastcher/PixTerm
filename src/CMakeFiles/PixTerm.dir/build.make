# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kali/Documents/programming/PixTerm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/Documents/programming/PixTerm/src

# Include any dependencies generated for this target.
include CMakeFiles/PixTerm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PixTerm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PixTerm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PixTerm.dir/flags.make

CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch: CMakeFiles/PixTerm.dir/flags.make
CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch: CMakeFiles/PixTerm.dir/cmake_pch.hxx.cxx
CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch: CMakeFiles/PixTerm.dir/cmake_pch.hxx
CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch: CMakeFiles/PixTerm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/programming/PixTerm/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -x c++-header -MD -MT CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -MF CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch.d -o CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -c /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.cxx

CMakeFiles/PixTerm.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PixTerm.dir/cmake_pch.hxx.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -x c++-header -E /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.cxx > CMakeFiles/PixTerm.dir/cmake_pch.hxx.i

CMakeFiles/PixTerm.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PixTerm.dir/cmake_pch.hxx.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -fpch-instantiate-templates -Xclang -emit-pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -x c++-header -S /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.cxx -o CMakeFiles/PixTerm.dir/cmake_pch.hxx.s

CMakeFiles/PixTerm.dir/Buffer.cpp.o: CMakeFiles/PixTerm.dir/flags.make
CMakeFiles/PixTerm.dir/Buffer.cpp.o: Buffer.cpp
CMakeFiles/PixTerm.dir/Buffer.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx
CMakeFiles/PixTerm.dir/Buffer.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch
CMakeFiles/PixTerm.dir/Buffer.cpp.o: CMakeFiles/PixTerm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/programming/PixTerm/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PixTerm.dir/Buffer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -MD -MT CMakeFiles/PixTerm.dir/Buffer.cpp.o -MF CMakeFiles/PixTerm.dir/Buffer.cpp.o.d -o CMakeFiles/PixTerm.dir/Buffer.cpp.o -c /home/kali/Documents/programming/PixTerm/src/Buffer.cpp

CMakeFiles/PixTerm.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PixTerm.dir/Buffer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -E /home/kali/Documents/programming/PixTerm/src/Buffer.cpp > CMakeFiles/PixTerm.dir/Buffer.cpp.i

CMakeFiles/PixTerm.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PixTerm.dir/Buffer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -S /home/kali/Documents/programming/PixTerm/src/Buffer.cpp -o CMakeFiles/PixTerm.dir/Buffer.cpp.s

CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/PixTerm.dir/flags.make
CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp
CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx
CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch
CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o: CMakeFiles/PixTerm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/programming/PixTerm/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -MD -MT CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o -MF CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o.d -o CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o -c /home/kali/Documents/programming/PixTerm/src/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp

CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -E /home/kali/Documents/programming/PixTerm/src/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp > CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.i

CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -S /home/kali/Documents/programming/PixTerm/src/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp -o CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.s

CMakeFiles/PixTerm.dir/Terminal.cpp.o: CMakeFiles/PixTerm.dir/flags.make
CMakeFiles/PixTerm.dir/Terminal.cpp.o: Terminal.cpp
CMakeFiles/PixTerm.dir/Terminal.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx
CMakeFiles/PixTerm.dir/Terminal.cpp.o: CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch
CMakeFiles/PixTerm.dir/Terminal.cpp.o: CMakeFiles/PixTerm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Documents/programming/PixTerm/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PixTerm.dir/Terminal.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -MD -MT CMakeFiles/PixTerm.dir/Terminal.cpp.o -MF CMakeFiles/PixTerm.dir/Terminal.cpp.o.d -o CMakeFiles/PixTerm.dir/Terminal.cpp.o -c /home/kali/Documents/programming/PixTerm/src/Terminal.cpp

CMakeFiles/PixTerm.dir/Terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PixTerm.dir/Terminal.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -E /home/kali/Documents/programming/PixTerm/src/Terminal.cpp > CMakeFiles/PixTerm.dir/Terminal.cpp.i

CMakeFiles/PixTerm.dir/Terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PixTerm.dir/Terminal.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -Xclang -include-pch -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch -Xclang -include -Xclang /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/cmake_pch.hxx -S /home/kali/Documents/programming/PixTerm/src/Terminal.cpp -o CMakeFiles/PixTerm.dir/Terminal.cpp.s

# Object files for target PixTerm
PixTerm_OBJECTS = \
"CMakeFiles/PixTerm.dir/Buffer.cpp.o" \
"CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o" \
"CMakeFiles/PixTerm.dir/Terminal.cpp.o"

# External object files for target PixTerm
PixTerm_EXTERNAL_OBJECTS =

libPixTerm.a: CMakeFiles/PixTerm.dir/cmake_pch.hxx.pch
libPixTerm.a: CMakeFiles/PixTerm.dir/Buffer.cpp.o
libPixTerm.a: CMakeFiles/PixTerm.dir/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp.o
libPixTerm.a: CMakeFiles/PixTerm.dir/Terminal.cpp.o
libPixTerm.a: CMakeFiles/PixTerm.dir/build.make
libPixTerm.a: CMakeFiles/PixTerm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kali/Documents/programming/PixTerm/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libPixTerm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/PixTerm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PixTerm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PixTerm.dir/build: libPixTerm.a
.PHONY : CMakeFiles/PixTerm.dir/build

CMakeFiles/PixTerm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PixTerm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PixTerm.dir/clean

CMakeFiles/PixTerm.dir/depend:
	cd /home/kali/Documents/programming/PixTerm/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/Documents/programming/PixTerm /home/kali/Documents/programming/PixTerm /home/kali/Documents/programming/PixTerm/src /home/kali/Documents/programming/PixTerm/src /home/kali/Documents/programming/PixTerm/src/CMakeFiles/PixTerm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PixTerm.dir/depend

