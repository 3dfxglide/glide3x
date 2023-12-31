# OpenWatcom makefile for Glide3/SST1 and Texus2
# This makefile MUST be processed by GNU make!!!
#
#  Copyright (c) 2004 - Daniel Borca
#  Email : dborca@users.sourceforge.net
#  Web   : http://www.geocities.com/dborca
#
# $Header$
#


#
#  Available options:
#
#    Environment variables:
#	FX_GLIDE_HW	build for the given ASIC (sst1, sst96).
#			default = sst1
#	OPTFLAGS	pass given optimization flags to compiler
#			default = -ox -5s (Pentium, stack)
#	DEBUG=1		enable debugging checks and messages
#			default = no
#	USE_X86=1	use assembler triangle specializations!
#			default = no
#	TEXUS2=1	embed Texus2 functions into Glide3.
#			default = no
#
#    Targets:
#	all:		build everything
#	glide3x:	build Glide3x lib
#	clean:		remove object files
#	realclean:	remove all generated files
#



.PHONY: all glide3x clean realclean
.INTERMEDIATE: fxgasm.exe wlib.lbc
.SUFFIXES: .c .obj

###############################################################################
#	general defines (user settable?)
###############################################################################

GLIDE_LIB = glide3x.lib
TEXUS_EXE = texus2.exe

FX_GLIDE_HW ?= sst1
FX_GLIDE_SW = ../../../swlibs
GLIDE_LIBDIR = ../../lib
TEXUS_EXEDIR = $(FX_GLIDE_SW)/bin

###############################################################################
#	tools
###############################################################################

CC = wcl386
AS = nasm
AR = wlib

ifeq ($(wildcard $(addsuffix /rm.exe,$(subst ;, ,$(PATH)))),)
UNLINK = del $(subst /,\,$(1))
else
UNLINK = $(RM) $(1)
endif

###############################################################################
#	defines
###############################################################################

# platform
CDEFS = -D__DOS__ -D__DOS32__ -DINIT_DOS

# general
CDEFS += -DGLIDE3 -DGLIDE3_ALPHA -DGLIDE_HARDWARE

# subsystem
ifeq ($(FX_GLIDE_HW),sst1)
CDEFS += -DSST1
else
ifeq ($(FX_GLIDE_HW),sst96)
CDEFS += -DSST96
CDEFS += -DSST96_FIFO
#CDEFS += -DSST96_ALT_FIFO_WRAP
#CDEFS += -DINIT96VGASWAP -DINIT_ACCESS_DIRECT
CDEFS += -DGLIDE_USE_ALT_REGMAP
endif
endif

# debug
ifdef DEBUG
CDEFS += -DGDBG_INFO_ON -DGLIDE_DEBUG -DGLIDE_SANITY_ASSERT -DGLIDE_SANITY_SIZE
endif

# other
CDEFS += -DGLIDE_PLUG -DGLIDE_SPLASH

ifeq ($(TEXUS2),1)
CDEFS += -DHAVE_TEXUS2
endif

###############################################################################
#	flags
###############################################################################

# librarian
ARFLAGS = -c -fo -n -t -q

# assembler
ASFLAGS = -O6 -fobj -D__WATCOMD__ --prefix _
ASFLAGS += $(CDEFS)

# compiler
CFLAGS = -wx
CFLAGS += -I. -I../../incsrc -I../../init -I../../init/initvg -I../../init/init96
CFLAGS += -I$(FX_GLIDE_SW)/fxmisc -I$(FX_GLIDE_SW)/newpci/pcilib -I$(FX_GLIDE_SW)/fxmemmap
CFLAGS += -I$(FX_GLIDE_SW)/texus2/lib
OPTFLAGS ?= -ox -5s
CFLAGS += $(CDEFS) $(OPTFLAGS)

ifeq ($(USE_X86),1)
CFLAGS += -DGL_X86
else
CFLAGS += -DGLIDE_USE_C_TRISETUP
endif

# Watcom woes: pass parameters through environment vars
export WCC386 = $(subst /,\,$(CFLAGS))
export WCL386 = -zq

###############################################################################
#	objects
###############################################################################

GLIDE_OBJECTS = \
	distate.obj \
	diget.obj \
	gstrip.obj \
	distrip.obj \
	diglide.obj \
	disst.obj \
	ditex.obj \
	g3df.obj \
	gaa.obj \
	gbanner.obj \
	gdraw.obj \
	gerror.obj \
	gglide.obj \
	glfb.obj \
	gpci.obj \
	gsplash.obj \
	gsst.obj \
	gtex.obj \
	gtexdl.obj \
	gu.obj \
	gxdraw.obj

ifeq ($(USE_X86),1)
GLIDE_OBJECTS += \
	cpuid.o
ifeq ($(FX_GLIDE_HW),sst1)
GLIDE_OBJECTS += \
	xdraw.obj
else
GLIDE_OBJECTS += \
	xdraw96.obj
endif
endif

ifeq ($(FX_GLIDE_HW),sst96)
GLIDE_OBJECTS += \
	sst96.obj \
	../../init/init96/init96.obj \
	../../init/init96/dxdrvr.obj \
	../../init/init96/initat3d.obj \
	../../init/init96/initmcrx.obj
endif

GLIDE_OBJECTS += \
	../../init/init.obj \
	../../init/vgdrvr.obj \
	../../init/vg96drvr.obj \
	../../init/h3drvr.obj \
	../../init/initvg/gamma.obj \
	../../init/initvg/dac.obj \
	../../init/initvg/video.obj \
	../../init/initvg/parse.obj \
	../../init/initvg/sli.obj \
	../../init/initvg/util.obj \
	../../init/initvg/info.obj \
	../../init/initvg/print.obj \
	../../init/initvg/gdebug.obj \
	../../init/initvg/sst1init.obj \
	$(FX_GLIDE_SW)/newpci/pcilib/sst1_pci.obj \
	$(FX_GLIDE_SW)/newpci/pcilib/fxmsr.obj \
	$(FX_GLIDE_SW)/newpci/pcilib/fxpci.obj \
	$(FX_GLIDE_SW)/newpci/pcilib/fxdpmi2.obj

TEXUS_SOURCES = \
	$(FX_GLIDE_SW)/texus2/lib/texuslib.c \
	$(FX_GLIDE_SW)/texus2/lib/clamp.c \
	$(FX_GLIDE_SW)/texus2/lib/read.c \
	$(FX_GLIDE_SW)/texus2/lib/resample.c \
	$(FX_GLIDE_SW)/texus2/lib/mipmap.c \
	$(FX_GLIDE_SW)/texus2/lib/quantize.c \
	$(FX_GLIDE_SW)/texus2/lib/ncc.c \
	$(FX_GLIDE_SW)/texus2/lib/nccnnet.c \
	$(FX_GLIDE_SW)/texus2/lib/pal256.c \
	$(FX_GLIDE_SW)/texus2/lib/pal6666.c \
	$(FX_GLIDE_SW)/texus2/lib/dequant.c \
	$(FX_GLIDE_SW)/texus2/lib/view.c \
	$(FX_GLIDE_SW)/texus2/lib/util.c \
	$(FX_GLIDE_SW)/texus2/lib/diffuse.c \
	$(FX_GLIDE_SW)/texus2/lib/write.c \
	$(FX_GLIDE_SW)/texus2/lib/tga.c \
	$(FX_GLIDE_SW)/texus2/lib/3df.c \
	$(FX_GLIDE_SW)/texus2/lib/ppm.c \
	$(FX_GLIDE_SW)/texus2/lib/rgt.c \
	$(FX_GLIDE_SW)/texus2/lib/txs.c \
	$(FX_GLIDE_SW)/texus2/lib/codec.c \
	$(FX_GLIDE_SW)/texus2/lib/eigen.c \
	$(FX_GLIDE_SW)/texus2/lib/bitcoder.c

ifeq ($(TEXUS2),1)
GLIDE_OBJECTS += $(TEXUS_SOURCES:.c=.obj)
endif

###############################################################################
#	rules
###############################################################################

.c.obj:
	$(CC) -fo=$@ -c $<

###############################################################################
#	main
###############################################################################
all: glide3x $(TEXUS_EXEDIR)/$(TEXUS_EXE)

glide3x: $(GLIDE_LIBDIR)/$(GLIDE_LIB)

$(GLIDE_LIBDIR)/$(GLIDE_LIB): wlib.lbc
	$(AR) $(ARFLAGS) -o $(subst /,\,$@) @wlib

$(TEXUS_EXEDIR)/$(TEXUS_EXE): $(FX_GLIDE_SW)/texus2/cmd/cmd.c $(GLIDE_LIBDIR)/$(GLIDE_LIB)
ifeq ($(TEXUS2),1)
	$(CC) -fe=$(subst /,\,$@) $(subst /,\,$^)
else
	$(warning Texus2 not enabled... Skipping $(TEXUS_EXE))
endif

###############################################################################
#	rules(2)
###############################################################################

cpuid.obj: cpudtect.asm
	$(AS) -o $@ $(ASFLAGS) $<
xdraw.obj: xdraw.asm
	$(AS) -o $@ $(ASFLAGS) $<
xdraw96.obj: xdraw96.asm
	$(AS) -o $@ $(ASFLAGS) $<

ifeq ($(FX_GLIDE_HW),sst96)
..\..\init\initvg\gamma.obj: ..\..\init\initvg\gamma.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\dac.obj: ..\..\init\initvg\dac.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\video.obj: ..\..\init\initvg\video.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\parse.obj: ..\..\init\initvg\parse.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\sli.obj: ..\..\init\initvg\sli.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\util.obj: ..\..\init\initvg\util.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\info.obj: ..\..\init\initvg\info.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\print.obj: ..\..\init\initvg\print.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\gdebug.obj: ..\..\init\initvg\gdebug.c
	$(CC) -fo=$@ -USST96 -c $<
..\..\init\initvg\sst1init.obj: ..\..\init\initvg\sst1init.c
	$(CC) -fo=$@ -USST96 -c $<
endif

$(GLIDE_OBJECTS): fxinline.h fxgasm.h

fxinline.h: fxgasm.exe
	$< -inline > $@

fxgasm.h: fxgasm.exe
	$< -hex > $@

fxgasm.exe: fxgasm.c
	$(CC) -fe=$@ $<

wlib.lbc: $(subst /,\,$(GLIDE_OBJECTS))
	@echo $(addprefix +,$^) > wlib.lbc

###############################################################################
#	clean, realclean
###############################################################################

clean:
	-$(call UNLINK,*.obj)
	-$(call UNLINK,../../init/*.obj)
	-$(call UNLINK,../../init/initvg/*.obj)
	-$(call UNLINK,../../init/init96/*.obj)
	-$(call UNLINK,$(FX_GLIDE_SW)/newpci/pcilib/*.obj)
	-$(call UNLINK,fxinline.h)
	-$(call UNLINK,fxgasm.h)
	-$(call UNLINK,$(FX_GLIDE_SW)/texus2/lib/*.obj)
	-$(call UNLINK,*.err)

realclean: clean
	-$(call UNLINK,$(GLIDE_LIBDIR)/$(GLIDE_LIB))
	-$(call UNLINK,$(TEXUS_EXEDIR)/$(TEXUS_EXE))
