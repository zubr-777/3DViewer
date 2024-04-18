CFLAG = -Wall -Wextra -Werror -std=c11
CHECKFLAGS = -lcheck -lsubunit -coverage -pthread -lrt -lm

all: install test gcov_report

clean:
	rm -rf report *.gcno *.gcda *.gcov gcovreport* s21_viewer_test ./3DViewer/.qmake.stash


install: 
#	export QT_QPA_PLATFORM=xcb
#	unset GTK_PATH
	mkdir build; cd build; qmake ../3DViewer/viwer.pro; make; ./viwer
	make clean

uninstall:
	@rm -rf build

dist:
	tar -cf 3DViewer_v1.0.tar Makefile 3DViewer 

dvi: gcov_report
	open report/index.html

test: 
	gcc $(FLAGS) 3DViewer/parser.c 3DViewer/transformation.c 3DViewer/validate.c Tests/3d_viewer_test.c -g -o s21_viewer_test  \
	$(CHECKFLAGS)
	./s21_viewer_test

gcov_report:
	gcc $(FLAGS) --coverage 3DViewer/parser.c 3DViewer/transformation.c 3DViewer/validate.c Tests/3d_viewer_test.c -o gcovreport \
	$(CHECKFLAGS)
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info	

clang:
	clang-format -n *.c *.h

#valgrind: 
#	valgrind  --track-origins=yes --leak-check=full --show-leak-kinds=all -v ./3d_viewer_test.o
