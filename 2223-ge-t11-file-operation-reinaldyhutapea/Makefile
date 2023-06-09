compile :
	gcc t11_01.c ./libs/gender.c ./libs/dorm.c ./libs/student.c ./libs/repository.c -o t11_01 -Wall
	gcc t11_02.c ./libs/gender.c ./libs/dorm.c ./libs/student.c ./libs/repository.c -o t11_02 -Wall

test_01 :
	./t11_01

test_02 :

	./t11_02
	sha1sum ./storage/student-repository.txt
	sha1sum ./storage/dorm-repository.txt
	git restore ./storage/student-repository.txt
	git restore ./storage/dorm-repository.txt
