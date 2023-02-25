a.out : main.cpp
	g++ -std=c++17 main.cpp -o $@
	./$@

.PHONY : clean
clean :
	rm -rf main.o

.PHONY : fclean
fclean : clean
	rm -rf a.out

.PHONY : re
re : fclean a.out
