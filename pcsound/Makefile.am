
AM_CFLAGS=@SDLMIXER_CFLAGS@

EXTRA_DIST=CMakeLists.txt

noinst_LIBRARIES=libpcsound.a

libpcsound_a_SOURCES =                            \
        pcsound.cpp           pcsound.hpp             \
        pcsound_bsd.cpp                             \
        pcsound_sdl.cpp                             \
        pcsound_linux.cpp                           \
        pcsound_win32.cpp                           \
                            pcsound_internal.hpp

