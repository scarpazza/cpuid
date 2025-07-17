CXX=/usr/local/bin/clang++

CXXFLAGS=--gcc-toolchain='~/repos/clang-p2996/build-llvm/lib/clang/21'  -isystem /usr/local/include/c++/v1 -isystem '/usr/local/include/x86_64-unknown-linux-gnu/c++/v1'  -freflection-latest --std=c++26

LDFLAGS=-Wl,-rpath,/home/scarpaz/repos/clang-p2996/build-llvm/lib/x86_64-unknown-linux-gnu


HEADERS := $(wildcard *.hpp)

all: cpuid.exe

%.exe: %.o
	$(CXX) $(LDFLAGS) -lc++ $< -o $@
	./$@

cpuid: cpuid.o $(HEADERS)
	$(CXX) $(LDFLAGS) -lc++ $< -o $@

%.o: %.cpp leaf_EAX1.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f cpuid *.o *~
