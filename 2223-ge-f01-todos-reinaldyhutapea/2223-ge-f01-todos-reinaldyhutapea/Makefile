compile :
	gcc f01_01.c ./libs/todo.c ./libs/repository.c -o f01_01 -Wall
	gcc f01_02.c ./libs/todo.c ./libs/repository.c -o f01_02 -Wall
	gcc f01_03.c ./libs/todo.c ./libs/repository.c -o f01_03 -Wall

test_01 :
	git restore ./storage/todo-repository.txt
	./f01_01

test_02 :
	git restore ./storage/todo-repository.txt
	./f01_02

test_03 :
	git restore ./storage/todo-repository.txt
	./f01_03
