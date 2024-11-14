.PHONY: build run clean

BUILD 	:= ./build
SRC 	:= ./src

CC		:= zig c++
RM		:= rm -rf
EXEC_N	:= breakout


run: build
	@$(BUILD)/$(EXEC_N)

build: main
	@mkdir -p $(BUILD)
	@mv breakout $(BUILD)

main: $(SRC)/main.cxx
	@$(CC) $< -o $(EXEC_N)

clean: build
	@test -d $(BUILD) && $(RM) $(BUILD)

