# FIXME: Use autoconf ?
HAS_GTK_GUI = 0
HAS_NCURSES = 0

#CC = $(CROSS_COMPILE)
CC=gcc
DESTDIR =
SBINDIR = /usr/sbin
XCFLAGS = -W  -g `pkg-config --cflags glib-2.0` -D_FORTIFY_SOURCE=2 -Wno-sign-compare
LDF = -Wl,--as-needed `pkg-config --libs glib-2.0`   

OBJS= latencytop.o text_dump.o translate.o fsync.o

ifdef HAS_GTK_GUI
  XCFLAGS += `pkg-config --cflags gtk+-2.0` -DHAS_GTK_GUI
  LDF += `pkg-config --libs gtk+-2.0`
  OBJS += gtk_display.o 
endif

ifdef HAS_NCURSES
  XCFLAGS += -DHAS_NCURSES
  LDF += -lncursesw 
  OBJS += text_display.o 
endif


#
# The w in -lncursesw is not a typo; it is the wide-character version
# of the ncurses library, needed for multi-byte character languages
# such as Japanese and Chinese etc.
#
# On Debian/Ubuntu distros, this can be found in the
# libncursesw5-dev package. 
#

# We write explicity this "implicit rule"
%.o : %.c
	$(CC) -c $(CFLAGS) $(XCFLAGS) $< -o $@

latencytop:  $(OBJS) latencytop.h Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LDF) -o latencytop 

clean:
	rm -f *~ latencytop DEADJOE *.o

install: latencytop
	mkdir -p $(DESTDIR)/usr/share/latencytop
	mkdir -p $(DESTDIR)/$(SBINDIR)
	install -m 0644 latencytop.trans $(DESTDIR)/usr/share/latencytop/latencytop.trans
	install -m 0644 *.png $(DESTDIR)/usr/share/latencytop/
	install -m 0755 latencytop $(DESTDIR)$(SBINDIR)/
