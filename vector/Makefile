all : a.out

a.out : obj ./obj/main.o
	@c++ -std=c++98 --pedantic-errors -Werror -Wall -Wextra -MMD -MP ./obj/main.o

std : obj ./obj/std_main.o
	c++ -std=c++17 --pedantic-errors -Werror -Wall -Wextra -MMD -MP ./obj/std_main.o


.PHONY : run
run : a.out
	@./a.out > ft
	@make fclean
	@make std
	@./a.out > std
	diff ft std
	@make fclean



./obj/main.o : main.cpp
	@c++ -c $< -std=c++17 --pedantic-errors -Werror -Wall -Wextra -MMD -MP -o $@

./obj/std_main.o : main.cpp
	c++ -c $< -std=c++17 -D STD --pedantic-errors -Werror -Wall -Wextra -MMD -MP -o $@

obj :
	@mkdir -p obj

.PHONY : clean fclean
clean :
	@rm -rf obj

fclean : clean
	@rm a.out
