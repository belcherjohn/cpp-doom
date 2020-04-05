
AM_CFLAGS=-I$(top_srcdir)/src @SDLMIXER_CFLAGS@

EXTRA_DIST=CMakeLists.txt

if HAVE_WINDRES

noinst_PROGRAMS = @PROGRAM_PREFIX@midiproc

@PROGRAM_PREFIX@midiproc_LDADD = @SDLMIXER_LIBS@
@PROGRAM_PREFIX@midiproc_SOURCES = buffer.cpp buffer.hpp main.cpp proto.hpp

endif
