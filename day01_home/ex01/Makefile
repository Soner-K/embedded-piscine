CC := avr-gcc
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

BIN = main.bin
HEX = main.hex

AVR_COPY = avr-objcopy 
AVRD = avrdude 
F_CPU = 16000000UL
BRATE = 115200
PROGRAMMER = arduino
PARTNO = atmega328p
PORT = /dev/ttyUSB0 
INCLUDES = /usr/lib/avr/include/

all : hex flash

#new added flag : -Os to allow for optimization
%.o : %.c
			$(CC) -c -Os -I $(INCLUDES) -mmcu=$(PARTNO) $< -DF_CPU=$(F_CPU) -o $@

$(BIN) : $(OBJ)
			$(CC) -I $(INCLUDES) -mmcu=$(PARTNO) $(OBJ) -o $(BIN)

hex : $(BIN)
			$(AVR_COPY) -O ihex $(BIN) $(HEX) 

flash : hex
			$(AVRD) -p $(PARTNO) -c $(PROGRAMMER) -b $(BRATE) -P $(PORT) -U flash:w:$(HEX):i

clean :
			rm -rf $(HEX) $(BIN) $(OBJ)