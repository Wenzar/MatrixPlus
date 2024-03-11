CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17 -lstdc++
FULL_VAL_LEAK_CHECK=--leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck --show-reachable=yes

TEST=main.cc
TARGET=s21_matrix_oop.a

SRC_DIRS := ./
SRCS := $(shell find $(SRC_DIRS) -name '*.cc' )
SRCSH := $(shell find $(SRC_DIRS) -name '*.h' )

OBJS = $(addsuffix .o,$(basename $(SRCS)))

all:  $(TARGET) 

$(TARGET): $(OBJS)
	ar rc s21_matrix_oop.a $(OBJS)

%.o: %.cc
	$(CC) $(CFLAGS) -c -o $@ $<

test: clean $(TARGET)
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST) s21_matrix_oop.a -lgtest -o test
	./test

gcov_report: clean test 
	gcov --no-output $(SRCS)
	lcov --no-external --capture --directory . --output-file coverage.info
	genhtml coverage.info -o report

valgrind: test
	valgrind $(FULL_VAL_LEAK_CHECK) ./test
	
style: 
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -n $(SRCS)
	clang-format -n $(SRCSH)
	rm -rf .clang-format

clean:
	rm -rf *.o report *.info *.gcda *.gcno *.gcov *.gch *.out *.a *.txt test main
