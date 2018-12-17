#2018 David DiPaola
#licensed under CC0 (public domain, see https://creativecommons.org/publicdomain/zero/1.0/)

BIN = text_aesthetic

.PHONY: all
all: $(BIN)

$(BIN): main.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN)

