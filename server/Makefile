# ------------------------------------------------
# Arduino Mega 2560 Makefile
#
# Author: valentin.vergez@gmail.com
# Date  : 24/04/2014
#
# Changelog :
#   24/04/2014 - first version
# ------------------------------------------------

# Project name (generate executable with this name)
TARGET   = arduinoServer

# Options
MCU_TARGET     = atmega2560

OPTIMIZE       = -O2
WARNINGS	   = -Wall
DEFINES        = -DF_CPU=16000000L

LIBS           =

rm 				= rm -f

# Compiler
CXX      = avr-g++

# Compiling flags here
override CFLAGS   = -g $(WARNINGS) $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFINES)

# Linker
LINKER   = $(CXX) -o

# Linking flags here
override LDFLAGS   = -Wl,-Map,$(BINDIR)/$(TARGET).map -mmcu=$(MCU_TARGET) 

# Object tools
OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

# Directories
SRCDIR   = src
INCDIR   = include
OBJDIR   = build
BINDIR   = bin

# Files
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.hpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Dependencies
# MAKEDEPEND = gcc -MM -o $(OBJDIR)/.depend
# DEPFLAGS = -g $(WARNINGS) $(OPTIMIZE) $(DEFINES)
# MAKEDEPEND = gcc -M $(DEPFLAGS) -o $(<:$(SRCDIR)/%.cpp=$(OBJDIR)/%.depend) $<
MAKEDEPEND = /usr/bin/makedepend

# ------------------------------------------------------------
### Rules
# Default
target: $(BINDIR)/$(TARGET).hex

all: $(BINDIR)/$(TARGET).elf lst text eeprom

# Dependencies
.PHONY: depend
depend: 
	@touch $(OBJDIR)/prerules.depend
	@$(MAKEDEPEND) -I$(SRCDIR) $(SOURCES) -f $(OBJDIR)/prerules.depend 2> /dev/null
	@ sed -e "s/^$(SRCDIR)/$(OBJDIR)/g" $(OBJDIR)/prerules.depend > $(OBJDIR)/rules.depend
	@echo "Dependencies built!"

-include $(OBJDIR)/rules.depend

# Target
$(BINDIR)/$(TARGET).elf: depend $(OBJECTS) 
	@$(LINKER) $@ $(LDFLAGS) $(OBJECTS) $(LIBS)
	@echo "Linking complete!"

# Objects
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

# Lst
lst:  $(BINDIR)/$(TARGET).lst

$(BINDIR)/%.lst: $(BINDIR)/%.elf
	@$(OBJDUMP) -h -S $< > $@


# Rules for building the .text rom images
text: hex bin srec

hex:  $(BINDIR)/$(TARGET).hex
bin:  $(BINDIR)/$(TARGET).bin
srec: $(BINDIR)/$(TARGET).srec

$(BINDIR)/%.hex: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .text -j .data -O ihex $< $@ 

$(BINDIR)/%.srec: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .text -j .data -O srec $< $@

$(BINDIR)/%.bin: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .text -j .data -O binary $< $@

# Rules for building the .eeprom rom images

eeprom: ehex ebin esrec

ehex:  $(BINDIR)/$(TARGET)_eeprom.hex
ebin:  $(BINDIR)/$(TARGET)_eeprom.bin
esrec: $(BINDIR)/$(TARGET)_eeprom.srec

$(BINDIR)/%_eeprom.hex: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@  2> /dev/null \
	|| { echo empty $@ not generated; exit 0; }

$(BINDIR)/%_eeprom.srec: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@  2> /dev/null \
	|| { echo empty $@ not generated; exit 0; }

$(BINDIR)/%_eeprom.bin: $(BINDIR)/%.elf
	@$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@  2> /dev/null \
	|| { echo empty $@ not generated; exit 0; }

# Every thing below here is used by avr-libc's build system and can be ignored
# by the casual user.

FIG2DEV                 = fig2dev
EXTRA_CLEAN_FILES       = $(BINDIR)/*.hex $(BINDIR)/*.bin $(BINDIR)/*.srec $(BINDIR)/*.lst $(BINDIR)/*.map $(OBJDIR)/*.depend $(OBJDIR)/*.bak
dox: eps png pdf

eps: $(BINDIR)/$(TARGET).eps
png: $(BINDIR)/$(TARGET).png
pdf: $(BINDIR)/$(TARGET).pdf

$(BINDIR)/%.eps: $(BINDIR)/%.fig
	@$(FIG2DEV) -L eps $< $@

$(BINDIR)/%.pdf: $(BINDIR)/%.fig
	@$(FIG2DEV) -L pdf $< $@

$(BINDIR)/%.png: $(BINDIR)/%.fig
	@$(FIG2DEV) -L png $< $@

# --------------------------------------------
# Upload
BAUDRATE = 115200
DUDE = /usr/bin/avrdude
TERM = /dev/ttyACM0
PROGRAMMER = stk500v2
ARCH = m2560
# UP_VERBOSE = -v -v -v -v

upload: $(BINDIR)/$(TARGET).hex
	sudo stty -F $(TERM) hupcl # reset
	sudo $(DUDE) -p $(ARCH) -P $(TERM) -c $(PROGRAMMER) -b $(BAUDRATE) -F -u -U flash:w:$(BINDIR)/$(TARGET).hex $(UP_VERBOSE)

# --------------------------------------------
# Clean and remove rules
.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) *.o *.eps *.png *.pdf *.bak 
	@$(rm) *.lst *.map $(EXTRA_CLEAN_FILES)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET).elf
	@echo "Executable removed!"