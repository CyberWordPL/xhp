override MAKEFLAGS += -rR

BINNAME = xhp

CXX = g++
CFLAGS = \
	 -Wall \
	 -Wextra \
	 -Werror \
	 -Wpedantic \
	 -std=c++23 \
	 -O3 \
	 -fpic

CPPFLAGS = \
	   -I include \
	   -MMD \
	   -MP

CXXFILES = $(shell cd src && find . -name "*.cc")
OBJFILES = $(addprefix obj/,$(CXXFILES:.cc=.o))
DEPS = $(addprefix obj/,$(CXXFILES:.cc=.d))

$(BINNAME): $(OBJFILES)
	ar rcs $(BINNAME).a $^
	$(CXX) -shared -o $(BINNAME).so $^

clean: 
	rm -r obj $(BINNAME).a $(BINNAME).so

-include $(DEPS)

obj/%.o: src/%.cc
	mkdir -p obj
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
