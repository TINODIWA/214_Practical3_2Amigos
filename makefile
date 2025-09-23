files = Main

# List all source files that need to be compiled
SOURCES = Main.cpp ChatRoom.cpp Users.cpp CtrlCat.cpp Dogorithm.cpp Nathan.cpp Dominiqu.cpp Luyanda.cpp

Main:
	g++ -g -std=c++11 $(SOURCES) -o Main

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${files}

run: Main
	./Main

mem: Main
	valgrind --leak-check=full --track-origins=yes ./Main

coverage:
# 	# 1. Clean previous coverage data
	rm -rf cov *.gcda *.gcno *.gcov *.html *.css

# 	# 2. Compile with coverage flags
	g++ -fprofile-arcs -ftest-coverage -o Main *.cpp

# 	# 3. Run the program to collect coverage data
	./Main

# 	# 4. Create output directory
	mkdir -p cov

# 	# 5. Generate HTML coverage report
	lcov --capture --directory . --output-file cov/coverage.info
	genhtml cov/coverage.info --output-directory cov/report

	@echo "Coverage report generated in cov/report/index.html"