prb:prb.c main.c
	gcc $^ -o $@

.PHONY:clean
clean:
	rm -f prb
