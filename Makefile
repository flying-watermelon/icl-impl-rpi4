CFLAGS=-Wall -Werror -O3

SRCPATH=src
OUTPATH=build
SRC=$(wildcard $(SRCPATH)/*.c)
OBJ=$(patsubst $(SRCPATH)/%.c,$(OUTPATH)/%.o,$(SRC))
TARGET=$(OUTPATH)/libicl-impl-rpi4.a

all: $(OUTPATH) $(TARGET)

$(OUTPATH):
	mkdir -p $(OUTPATH)

$(TARGET): $(OBJ)
	ar rcs $@ $^

$(OUTPATH)/%.o: $(SRCPATH)/%.c
	cc $< $(CFLAGS) -I$(ICL_PATH) -I./includes -c -o $@

clean:
	rm -rf $(OUTPATH)

.PHONY: all clean