all: bin obj make_u make_w test

test.exe: test
	bin/test.exe

2048.exe: make_u
	bin/w_2048.exe

test: bin obj test.o end mergeoff
	gcc -o bin/test.exe obj/test.o obj/end.o obj/merge_and_offset.o -lm

test.o: bin obj test/test.c
	gcc -c test/test.c -o obj/test.o

make_u: u_main u_clear u_exit save read printrec print mergeoff genplace gen end display copypl comeback answer
	# для линукса
	gcc -o bin/u_2048.exe obj/unix_main.o obj/unix_exit.o obj/unix_clear.o obj/save.o obj/read.o obj/print_record.o obj/print.o obj/merge_and_offset.o obj/generate_place.o obj/generate.o obj/end.o obj/display_menu.o obj/copy_place.o obj/comeback.o obj/answer.o -lm

u_main: src/unix_main.c obj
	gcc -c src/unix_main.c -o obj/unix_main.o

u_clear: src/unix_clear.c obj
	gcc -c src/unix_clear.c -o obj/unix_clear.o

u_exit: src/unix_exit.c obj
	gcc -c src/unix_exit.c -o obj/unix_exit.o

make_w: w_main w_clear w_exit w_adaptive save read printrec print mergeoff genplace gen end display copypl comeback answer
	# для windows
	gcc -o bin/w_2048.exe obj/windows_main.o obj/adaptive_win.o obj/answer.o obj/comeback.o obj/copy_place.o obj/display_menu.o obj/end.o obj/generate.o obj/generate_place.o obj/merge_and_offset.o obj/print.o obj/print_record.o obj/read.o obj/save.o obj/win_clear.o obj/win_exit.o -lm

w_main: src/windows_main.c obj
	gcc -c src/windows_main.c -o obj/windows_main.o

w_clear: src/win_clear.c obj
	gcc -c src/win_clear.c -o obj/win_clear.o

w_exit: src/win_exit.c obj
	gcc -c src/win_exit.c -o obj/win_exit.o

w_adaptive: src/adaptive_win.c obj
	gcc -c src/adaptive_win.c -o obj/adaptive_win.o

save: src/save.c obj
	gcc -c src/save.c -o obj/save.o

read: src/read.c obj
	gcc -c src/read.c -o obj/read.o

printrec: src/print_record.c obj
	gcc -c src/print_record.c -o obj/print_record.o

print: src/print.c obj
	gcc -c src/print.c -o obj/print.o

mergeoff: src/merge_and_offset.c obj
	gcc -c src/merge_and_offset.c -o obj/merge_and_offset.o

genplace: src/generate_place.c obj
	gcc -c src/generate_place.c -o obj/generate_place.o

gen: src/generate.c obj
	gcc -c src/generate.c -o obj/generate.o

end: src/end.c obj
	gcc -c src/end.c -o obj/end.o

display: src/display_menu.c obj
	gcc -c src/display_menu.c -o obj/display_menu.o

copypl: src/copy_place.c obj
	gcc -c src/copy_place.c -o obj/copy_place.o

comeback: src/comeback.c obj
	gcc -c src/comeback.c -o obj/comeback.o

answer: src/answer.c obj
	gcc -c src/answer.c -o obj/answer.o

obj:
	mkdir obj

clean:
	rm obj/*.o
	rm bin/*.exe

bin:
	mkdir bin
