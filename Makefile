COMPILE_CPP = 1
CCFLAGS = -std=c++14 -stdlib=libc++

ifeq ($(COMPILE_CPP),1)
	CC = /usr/bin/clang++
else
	CC = /usr/bin/clang
endif

array_ptr.o: array_ptr.cpp
	@echo "printing"
	@echo $@
	@echo $<
	$(CC) $(CCFLAGS) -o $@ $<

.PHONY: clean
clean:
	@echo "Clean output and log"
	@rm -f hello array_ptr crc32 rgb16 heap_stack *.o
	@rm -rf *.dSYM