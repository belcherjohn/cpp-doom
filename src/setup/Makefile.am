
AM_CFLAGS = @SDL_CFLAGS@                                           \
            @SDLMIXER_CFLAGS@                                      \
            -I$(top_srcdir)/textscreen -I$(top_srcdir)/src

noinst_LIBRARIES = libsetup.a

libsetup_a_SOURCES =                            \
    compatibility.cpp   compatibility.hpp           \
    display.cpp         display.hpp                 \
    joystick.cpp        joystick.hpp                \
    keyboard.cpp        keyboard.hpp                \
    mainmenu.cpp                                  \
    mode.cpp            mode.hpp                    \
    mouse.cpp           mouse.hpp                   \
    multiplayer.cpp     multiplayer.hpp             \
    sound.cpp           sound.hpp                   \
    execute.cpp         execute.hpp                 \
    txt_joyaxis.cpp     txt_joyaxis.hpp             \
    txt_joybinput.cpp   txt_joybinput.hpp           \
    txt_keyinput.cpp    txt_keyinput.hpp            \
    txt_mouseinput.cpp  txt_mouseinput.hpp

EXTRA_DIST=                                     \
    CMakeLists.txt                              \
    setup_icon.cpp

appdir = $(prefix)/share/applications
app_DATA = @PACKAGE_RDNS@.Setup.desktop

CLEANFILES = $(app_DATA)

@PACKAGE_RDNS@.Setup.desktop : Setup.desktop
	cp Setup.desktop $@

if HAVE_PYTHON

setup_icon.cpp : $(top_builddir)/data/setup.png
	$(top_builddir)/data/convert-icon $(top_builddir)/data/setup.png $@

endif

