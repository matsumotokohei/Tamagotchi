CC = ~/local/arm-2012.03/bin/arm-none-eabi-gcc
LD = ~/local/arm-2012.03/bin/arm-none-eabi-ld
OBJCOPY = ~/local/arm-2012.03/bin/arm-none-eabi-objcopy

CFLAGS  = -mcpu=cortex-m0 -mthumb
CFLAGS += -g -O0
CFLAGS += -I./ 

HEX = Tamagotchi.hex
ELF = Tamagotchi.elf
LNK = Tamagotchi.ld
MAP = Tamagotchi.map
OBJS = vector.o reset.o init.o main.o

all: $(HEX)

$(HEX) : $(ELF)
	$(OBJCOPY) -F ihex $< $@

$(ELF) : $(LNK) $(OBJS) 
	$(LD) -Map $(MAP) -o$@ -T$(LNK) $(OBJS)

.s.o : 
	$(CC) $(CFLAGS) -c $< 

.c.o : 
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(HEX) $(ELF) $(MAP)
	$(RM) $(OBJS)
