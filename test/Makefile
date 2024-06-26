#set environment variable VKM_INCLUDE_DIR to the location of redismodule.h
ifndef VKM_INCLUDE_DIR
	VKM_INCLUDE_DIR=$(shell pwd)/../src
endif

DEPS_DIR=$(shell pwd)/../deps

# Setting the DEBUG env variable to 1 will cause us to build with -O0
ifndef DEBUG
	DEBUG = 0
endif
DEBUGFLAGS = -g -ggdb -O2
ifeq ($(DEBUG), 1)
	DEBUGFLAGS = -g -ggdb -O0
endif

# find the OS
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
INCLUDE_DIRS = -I"$(VKM_INCLUDE_DIR)" -I"$(DEPS_DIR)/jsonsl" -I"$(DEPS_DIR)/ValkeyModuleSDK/vkmutil"
CFLAGS =  $(INCLUDE_DIRS) -Wall $(DEBUGFLAGS)  -std=gnu99 -D_GNU_SOURCE
CC:=$(shell sh -c 'type $(CC) >/dev/null 2>/dev/null && echo $(CC) || echo gcc')

# Compile flags for linux / osx
ifneq ($(uname_S),Linux)
	CFLAGS += -mmacosx-version-min=10.6
endif

export CFLAGS
export DEBUGFLAGS

all: build test
test: test_object test_json_object test_json_validator unittest
build: object json_object json_validator

# Dependency libraries
LIBS = $(VKM_INCLUDE_DIR)/libvalkeyjson.a $(DEPS_DIR)/ValkeyModuleSDK/kvmutil/libvkmutil.a $(DEPS_DIR)/jsonsl/libjsonsl.a -lm
# Compile flags for linux / osx
ifeq ($(uname_S),Linux)
	LIBS += -lrt
endif

# TODO: add a test that uses json_printer on a JSON file and then validates the output
# Building of json validator test
json_validator: 
	$(CC) $(CFLAGS) -o $@.out json_printer.c $(LIBS)

# Execute json validator test
test_json_validator: json_validator
	./$@.sh
.PHONY: test_json_validator

# Build test_object
object: 
	$(CC) $(CFLAGS) -o test_$@.out test_$@.c $(LIBS) 

# Run test_object
test_object: object
	./$@.out
.PHONY: test_object

# Buid json_object
json_object:
	$(CC) $(CFLAGS) -o test_$@.out test_$@.c $(LIBS)

# Run test_json_object
test_json_object: json_object
	./$@.out
.PHONY: test_json_object

# Unit testing
unittest:
	$(MAKE) -C pytest

clean:
	rm -rvf *.xo *.so *.o *.a *.out
	rm -rvf json_printer test_json_object test_object
