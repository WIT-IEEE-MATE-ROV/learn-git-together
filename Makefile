# Using µnit is very simple; just include the header and add the C
# file to your sources.  That said, here is a simple Makefile to build
# the example.

CSTD:=99
OPENMP:=n
ASAN:=n
UBSAN:=n
EXTENSION:=
TEST_ENV:=
CFLAGS:=
AGGRESSIVE_WARNINGS=n

ifeq ($(CC),pgcc)
	CFLAGS+=-c$(CSTD)
else
	CFLAGS+=-std=c$(CSTD)
endif

ifeq ($(OPENMP),y)
	ifeq ($(CC),pgcc)
		CFLAGS+=-mp
	else
		CFLAGS+=-fopenmp
	endif
endif

ifneq ($(SANITIZER),)
	CFLAGS+=-fsanitize=$(SANITIZER)
endif

ifneq ($(CC),pgcc)
	ifeq ($(EXTRA_WARNINGS),y)
		CFLAGS+=-Wall -Wextra -Werror
	endif

	ifeq ($(ASAN),y)
		CFLAGS+=-fsanitize=address
	endif

	ifeq ($(UBSAN),y)
		CFLAGS+=-fsanitize=undefined
	endif
endif

example$(EXTENSION): munit.h munit.c testcase.c
	$(CC) $(CFLAGS) -o testcase munit.c testcase.c ourlib.c

test:
	make
	$(TEST_ENV) ./testcase$(EXTENSION)

clean:
	rm -f testcase$(EXTENSION)

all: example$(EXTENSION)
