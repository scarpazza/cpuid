CXX=/usr/local/bin/clang++

CXXFLAGS=-I include -freflection-latest --std=c++26 \
	--gcc-toolchain='~/repos/clang-p2996/build-llvm/lib/clang/21' \
	-isystem /usr/local/include/c++/v1 \
	-isystem '/usr/local/include/x86_64-unknown-linux-gnu/c++/v1'

LDFLAGS=-Wl,-rpath,$(HOME)/repos/clang-p2996/build-llvm/lib/x86_64-unknown-linux-gnu


HEADERS := $(wildcard include/*.hpp)

all: cpuid.exe samples

%.exe: %.o
	$(CXX) $(LDFLAGS) -lc++ $< -o $@
	./$@

cpuid: cpuid.o
	$(CXX) $(LDFLAGS) -lc++ $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

samples: cpuid.exe samples/output.$(shell hostname)

samples/output.$(shell hostname): cpuid.exe
	./$<  >  samples/output.$(shell hostname)
	cat samples/output.$(shell hostname)

clean:
	rm -f cpuid.exe *.o *~
