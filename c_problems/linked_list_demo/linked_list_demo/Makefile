
linked_list_demo: main.c linked_list.so valid_selection.so
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra main.c linked_list.so valid_selection.so -o linked_list_demo

linked_list.so: linked_list.c linked_list.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c linked_list.c -o linked_list.so

valid_selection.so: valid_selection.c valid_selection.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c valid_selection.c -o valid_selection.so

launch: linked_list_demo
	./linked_list_demo
