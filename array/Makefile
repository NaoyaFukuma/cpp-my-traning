a.out : obj ./obj/main.o
	@c++ -std=c++11 --pedantic-errors -Werror -Wall -Wextra -MMD -MP ./obj/main.o


.PHONY : run
run : a.out
	@./a.out


./obj/main.o : main.cpp
	@c++ -c $< -std=c++11 --pedantic-errors -Werror -Wall -Wextra -MMD -MP -o $@

obj :
	@mkdir -p obj

.PHONY : clean fclean
clean :
	@rm -rf obj

fclean : clean
	@rm a.out
