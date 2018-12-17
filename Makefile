BIN = text_aesthetic

.PHONY: all
all: $(BIN)

$(BIN): main.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN)

