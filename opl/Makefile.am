
AM_CFLAGS=@SDLMIXER_CFLAGS@

EXTRA_DIST=CMakeLists.txt

SUBDIRS = . examples

noinst_LIBRARIES=libopl.a

libopl_a_SOURCES =                                \
                            opl_internal.hpp        \
        opl.cpp               opl.hpp                 \
        opl_linux.cpp                               \
        opl_obsd.cpp                                \
        opl_queue.cpp         opl_queue.hpp           \
        opl_sdl.cpp                                 \
        opl_timer.cpp         opl_timer.hpp           \
        opl_win32.cpp                               \
        ioperm_sys.cpp        ioperm_sys.hpp          \
        opl3.cpp              opl3.hpp

