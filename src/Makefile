#
# Environment
#
CROSS_COMPILE = arm-none-eabi-
CMSIS_DIR  = ./CMSISv1p30_LPC11xx

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

HEX = Tamagotchi.hex
ELF = Tamagotchi.elf
LNK = Tamagotchi.ld
MAP = Tamagotchi.map

CFLAGS  = -mcpu=cortex-m0 -mthumb -O1 -Wall -Werror -I$(CMSIS_DIR)/inc
LDFLAGS += -Map=$(MAP) -T$(LNK) -nostdlib

INCS  = $(CMSIS_DIR)/inc/core_cm0.h \
        $(CMSIS_DIR)/inc/LPC11xx.h \
        $(CMSIS_DIR)/inc/system_LPC11xx.h
INCS += main.h gpio.h uart.h music.h
OBJS += vector.o reset.o main.o gpio.o dsp.o uart.o music.o
SRCS += vector.s reset.c main.c gpio.c dsp.c uart.c music.c

#
#
#
all: $(HEX)

$(HEX) : $(ELF)
	$(OBJCOPY) -F ihex $< $@

$(ELF) : $(LNK) $(OBJS)
	$(LD) $(LDFLAGS) -o$@ $(OBJS) $(CMSIS_OBJS)

$(OBJS) : $(SRCS) $(INCS)
	for x in $(SRCS); do \
		$(CC) $(CFLAGS) -c $$x; \
	done

clean:
	$(RM) $(HEX) $(ELF) $(MAP)
	$(RM) $(OBJS)
