BIN=./bin
BUILD=./build
SRC=./src

SRCS=$(SRC)/vcd2csv.cpp
BINS=$(BIN)/vcd2csv

all: $(BINS)

depend: $(BUILD)/.depend

$(BUILD)/.depend: $(SRCS)
	rm -f $(BUILD)/.depend
	$(CC) $(CFLAGS) -MM $^ > $(BUILD)/.depend;

include $(BUILD)/.depend

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(INC) $< $(CFLAGS) -c -o $@ $(LIBS)

$(BIN)/vcd2csv: $(BUILD)/vcd2csv.o
	gcc -o $@ $^



.PHONY: clean
clean:
	rm -rf bin/* build/*



