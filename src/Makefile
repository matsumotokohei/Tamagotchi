#
# Environment
#
CROSS_COMPILE = ~/local/arm-2012.03/bin/arm-none-eabi-
CMSIS_DIR  = ./CMSISv1p30_LPC11xx

CC = $(CROSS_COMPILE)gcc
#CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
#LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

HEX = Tamagotchi.hex
ELF = Tamagotchi.elf
LNK = Tamagotchi.ld
MAP = Tamagotchi.map

CFLAGS  = -mcpu=cortex-m0 -mthumb
CFLAGS += -O2 -Wall -Werror
CFLAGS += -I$(CMSIS_DIR)/inc 

LDFLAGS += -Wl,-Map=$(MAP) -Wl,-T$(LNK)
#LDFLAGS += -Map=$(MAP) -T$(LNK)

INCS = $(CMSIS_DIR)/inc/core_cm0.h \
       $(CMSIS_DIR)/inc/LPC11xx.h \
       $(CMSIS_DIR)/inc/system_LPC11xx.h
OBJS = core_cm0.o \
       system_LPC11xx.o
SRCS = $(CMSIS_DIR)/src/core_cm0.c \
       $(CMSIS_DIR)/src/system_LPC11xx.c

OBJS += vector.o reset.o main.o
SRCS += vector.s reset.c main.c

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
