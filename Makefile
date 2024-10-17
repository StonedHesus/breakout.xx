.PHONY: build run clean

BUILD 	:= ./build
SRC 	:= ./src

CC		:= zig c++
EXEC_N	:= breakout

run:
	@$(BUILD)/$(EXEC_N)

build: main
	@mkdir -p $(BUILD)
	@mv breakout $(BUILD)

main: $(SRC)/main.cxx
	@$(CC) $(SRC)/main.cxx -o $(EXEC_N)

clean:
	@test -d $(BUILD) && rm -rf $(BUILD)

