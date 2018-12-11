## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = my_coach

my_coach_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        nafkhmajdi.c nafkhmajdi.h \
        ajoutdate.c ajoutdate.h \
        checkdate.c checkdate.h \
        verif.c verif.h \
        lastlogin.c lastlogin.h \
        suppper.c suppper.h \
        dispo.c dispo.h

my_coach_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

