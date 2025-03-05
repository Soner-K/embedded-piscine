CC := avr-gcc #avr compiler
SRC := main.c

BIN = main.bin #compiled machine code, not human readable
HEX = main.hex #hex file human readable machine code

AVR_COPY = avr-objcopy #convert object files between different formats
AVRD = avrdude #used to flash the HEX file onto the microcontroller
F_CPU = 16000000UL #speed at which the CPU executes instructions (in herts)
BRATE = 115200 #rate at which information is transferred in a communication channel (in bits pers second)
PROGRAMMER = arduino
PARTNO = atmega328p #avr device
PORT = /dev/ttyUSB0 

#executes the hex rule and then the flash rule
all : hex flash

#compiles the code into a bin file, that is then copied into a hex file
hex : $(SRC)
		$(CC) $(SRC) -DF_CPU=$(F_CPU) -o $(BIN)
		$(AVR_COPY) -O ihex $(BIN) $(HEX) 

#flashing the hex file to the microcontroller
#flash memory doesnt depend on electricity (program can be kept in memory and run each time the mc is switched on)
flash : hex
		$(AVRD) -p $(PARTNO) -c $(PROGRAMMER) -b $(BRATE) -P $(PORT) -U flash:w:$(HEX)
clean :
		rm -rf $(HEX) $(BIN)