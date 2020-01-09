NULL =

noinst_PROGRAMS = test-gail-gnome

INCLUDES =					\
	-I$(top_srcdir)				\
	-I$(top_srcdir)/gail-gnome		\
	$(GAIL_GNOME_DEBUG_CFLAGS)		\
	$(TEST_CFLAGS)				\
	$(NULL)

LDADD =						\
	../gail-gnome/libgail-gnome.la		\
	$(TEST_LIBS)				\
	$(NULL)

# Turn off this test since it's known to segfault
# see bugzilla.gnome.org #160384
#TESTS = test-gail-gnome
