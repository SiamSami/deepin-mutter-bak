
pkglibdir = $(MUTTER_PLUGIN_DIR)

AM_CPPFLAGS = \
	$(MUTTER_CFLAGS)						\
	-I$(top_builddir)/src						\
	-I$(top_srcdir)/src						\
	-DMUTTER_LIBEXECDIR=\"$(libexecdir)\"				\
	-DMUTTER_LOCALEDIR=\"$(localedir)\"				\
	-DMUTTER_PKGDATADIR=\"$(pkgdatadir)\"				\
	-DMUTTER_DATADIR=\"$(datadir)\"					\
	-DG_LOG_DOMAIN=\"mutter\"					\
	-DSN_API_NOT_YET_FROZEN=1					\
	-DMUTTER_PLUGIN_DIR=\"$(MUTTER_PLUGIN_DIR)\"

default_la_CFLAGS   = -fPIC
default_la_SOURCES  = default.c
default_la_LDFLAGS  = -module -avoid-version -no-undefined
default_la_LIBADD   = $(CLUTTER_LIBS)

pkglib_LTLIBRARIES = default.la

# post-install hook to remove the .la and .a files we are not interested in
# (There is no way to stop libtool generating static libs locally, and we
# cannot do this globally because of libmutter-private.so).
install-exec-hook:
	-rm -f $(DESTDIR)$(pkglibdir)/*.a
	-rm -f $(DESTDIR)$(pkglibdir)/*.la

# Since we removed the .la file, 'make uninstall' doesn't work properly,
# since it counts on libtool to remove the .la files, so just kill the
# .so file manually.
uninstall-local:
	-rm -f $(DESTDIR)$(pkglibdir)/default.so
