
SUBDIRS = doom setup # heretic hexen strife

execgamesdir = ${bindir}

execgames_PROGRAMS = @PROGRAM_PREFIX@doom     \
                     @PROGRAM_PREFIX@server
EXTRA_PROGRAMS =     @PROGRAM_PREFIX@heretic  \
                     @PROGRAM_PREFIX@hexen    \
                     @PROGRAM_PREFIX@strife

noinst_PROGRAMS = @PROGRAM_PREFIX@setup

SETUP_BINARIES = @PROGRAM_PREFIX@doom-setup$(EXEEXT)
#                @PROGRAM_PREFIX@heretic-setup$(EXEEXT) \
#                @PROGRAM_PREFIX@hexen-setup$(EXEEXT)   \
#                @PROGRAM_PREFIX@strife-setup$(EXEEXT)

execgames_SCRIPTS = $(SETUP_BINARIES)

AM_CFLAGS = -I$(top_srcdir)/textscreen            \
            -I$(top_srcdir)/opl                   \
            -I$(top_srcdir)/pcsound               \
            @SDLMIXER_CFLAGS@ @SDLNET_CFLAGS@

# Common source files used by absolutely everything:

COMMON_SOURCE_FILES=\
crispy.cpp             crispy.hpp              \
i_main.cpp                                   \
i_system.cpp           i_system.hpp            \
m_argv.cpp             m_argv.hpp              \
m_misc.cpp             m_misc.hpp

# Dedicated server (chocolate-server):

DEDSERV_FILES=\
d_dedicated.cpp                              \
d_iwad.cpp             d_iwad.hpp              \
d_mode.cpp             d_mode.hpp              \
deh_str.cpp            deh_str.hpp             \
i_timer.cpp            i_timer.hpp             \
m_config.cpp           m_config.hpp            \
net_common.cpp         net_common.hpp          \
net_dedicated.cpp      net_dedicated.hpp       \
net_io.cpp             net_io.hpp              \
net_packet.cpp         net_packet.hpp          \
net_sdl.cpp            net_sdl.hpp             \
net_query.cpp          net_query.hpp           \
net_server.cpp         net_server.hpp          \
net_structrw.cpp       net_structrw.hpp        \
z_native.cpp           z_zone.hpp

@PROGRAM_PREFIX@server_SOURCES=$(COMMON_SOURCE_FILES) $(DEDSERV_FILES)
@PROGRAM_PREFIX@server_LDADD = @LDFLAGS@ @SDLNET_LIBS@

# Source files used by the game binaries (chocolate-doom, etc.)

GAME_SOURCE_FILES=\
aes_prng.cpp           aes_prng.hpp            \
d_event.cpp            d_event.hpp             \
                     doomkeys.hpp            \
                     doomtype.hpp            \
d_iwad.cpp             d_iwad.hpp              \
d_loop.cpp             d_loop.hpp              \
d_mode.cpp             d_mode.hpp              \
                     d_ticcmd.hpp            \
deh_str.cpp            deh_str.hpp             \
gusconf.cpp            gusconf.hpp             \
i_cdmus.cpp            i_cdmus.hpp             \
i_endoom.cpp           i_endoom.hpp            \
i_glob.cpp             i_glob.hpp              \
i_input.cpp            i_input.hpp             \
i_joystick.cpp         i_joystick.hpp          \
                     i_swap.hpp              \
i_midipipe.cpp         i_midipipe.hpp          \
i_musicpack.cpp                              \
i_oplmusic.cpp                               \
i_pcsound.cpp                                \
i_sdlmusic.cpp                               \
i_sdlsound.cpp                               \
i_sound.cpp            i_sound.hpp             \
i_timer.cpp            i_timer.hpp             \
i_video.cpp            i_video.hpp             \
i_videohr.cpp          i_videohr.hpp           \
midifile.cpp           midifile.hpp            \
mus2mid.cpp            mus2mid.hpp             \
m_bbox.cpp             m_bbox.hpp              \
m_cheat.cpp            m_cheat.hpp             \
m_config.cpp           m_config.hpp            \
m_controls.cpp         m_controls.hpp          \
m_fixed.cpp            m_fixed.hpp             \
net_client.cpp         net_client.hpp          \
net_common.cpp         net_common.hpp          \
net_dedicated.cpp      net_dedicated.hpp       \
net_defs.hpp                                 \
net_gui.cpp            net_gui.hpp             \
net_io.cpp             net_io.hpp              \
net_loop.cpp           net_loop.hpp            \
net_packet.cpp         net_packet.hpp          \
net_petname.cpp        net_petname.hpp         \
net_query.cpp          net_query.hpp           \
net_sdl.cpp            net_sdl.hpp             \
net_server.cpp         net_server.hpp          \
net_structrw.cpp       net_structrw.hpp        \
sha1.cpp               sha1.hpp                \
memio.cpp              memio.hpp               \
tables.cpp             tables.hpp              \
v_diskicon.cpp         v_diskicon.hpp          \
v_video.cpp            v_video.hpp             \
                     v_patch.hpp             \
v_trans.cpp            v_trans.hpp             \
w_checksum.cpp         w_checksum.hpp          \
w_main.cpp             w_main.hpp              \
w_wad.cpp              w_wad.hpp               \
w_file.cpp             w_file.hpp              \
w_file_stdc.cpp                              \
w_file_posix.cpp                             \
w_file_win32.cpp                             \
w_merge.cpp            w_merge.hpp             \
z_zone.cpp             z_zone.hpp

DEHACKED_SOURCE_FILES =                    \
deh_defs.hpp                                 \
deh_io.cpp             deh_io.hpp              \
deh_main.cpp           deh_main.hpp            \
deh_mapping.cpp        deh_mapping.hpp         \
deh_text.cpp

# Some games support dehacked patches, some don't:

SOURCE_FILES = $(COMMON_SOURCE_FILES) $(GAME_SOURCE_FILES)
SOURCE_FILES_WITH_DEH = $(SOURCE_FILES) $(DEHACKED_SOURCE_FILES)

EXTRA_LIBS =                                               \
               $(top_builddir)/textscreen/libtextscreen.a  \
               $(top_builddir)/pcsound/libpcsound.a        \
               $(top_builddir)/opl/libopl.a                \
               @LDFLAGS@                                   \
               @SDL_LIBS@                                  \
               @SDLMIXER_LIBS@                             \
               @SDLNET_LIBS@

if HAVE_WINDRES
@PROGRAM_PREFIX@doom_SOURCES=$(SOURCE_FILES_WITH_DEH) resource.rc
else
@PROGRAM_PREFIX@doom_SOURCES=$(SOURCE_FILES_WITH_DEH)
endif

@PROGRAM_PREFIX@doom_LDADD = doom/libdoom.a $(EXTRA_LIBS)

if HAVE_WINDRES
@PROGRAM_PREFIX@heretic_SOURCES=$(SOURCE_FILES_WITH_DEH) resource.rc
else
@PROGRAM_PREFIX@heretic_SOURCES=$(SOURCE_FILES_WITH_DEH)
endif

@PROGRAM_PREFIX@heretic_LDADD = heretic/libheretic.a $(EXTRA_LIBS)

if HAVE_WINDRES
@PROGRAM_PREFIX@hexen_SOURCES=$(SOURCE_FILES) resource.rc
else
@PROGRAM_PREFIX@hexen_SOURCES=$(SOURCE_FILES)
endif

@PROGRAM_PREFIX@hexen_LDADD = hexen/libhexen.a $(EXTRA_LIBS)

if HAVE_WINDRES
@PROGRAM_PREFIX@strife_SOURCES=$(SOURCE_FILES_WITH_DEH) resource.rc
else
@PROGRAM_PREFIX@strife_SOURCES=$(SOURCE_FILES_WITH_DEH)
endif

@PROGRAM_PREFIX@strife_LDADD = strife/libstrife.a $(EXTRA_LIBS)

$(SETUP_BINARIES): @PROGRAM_PREFIX@setup$(EXEEXT)
	cp @PROGRAM_PREFIX@setup$(EXEEXT) $@

# Make "make" aware of convenience libraries in subdirectories

doom/libdoom.a:
	$(MAKE) -C doom

heretic/libheretic.a:
	$(MAKE) -C heretic

hexen/libhexen.a:
	$(MAKE) -C hexen

strife/libstrife.a:
	$(MAKE) -C strife

# Source files needed for chocolate-setup:

SETUP_FILES=                               \
deh_str.cpp            deh_str.hpp             \
d_mode.cpp             d_mode.hpp              \
d_iwad.cpp             d_iwad.hpp              \
i_timer.cpp            i_timer.hpp             \
m_config.cpp           m_config.hpp            \
m_controls.cpp         m_controls.hpp          \
net_io.cpp             net_io.hpp              \
net_packet.cpp         net_packet.hpp          \
net_petname.cpp        net_petname.hpp         \
net_sdl.cpp            net_sdl.hpp             \
net_query.cpp          net_query.hpp           \
net_structrw.cpp       net_structrw.hpp        \
z_native.cpp           z_zone.hpp

if HAVE_WINDRES
@PROGRAM_PREFIX@setup_SOURCES=$(SETUP_FILES) $(COMMON_SOURCE_FILES) setup-res.rc
else
@PROGRAM_PREFIX@setup_SOURCES=$(SETUP_FILES) $(COMMON_SOURCE_FILES)
endif
@PROGRAM_PREFIX@setup_LDADD = setup/libsetup.a                             \
                        $(top_builddir)/textscreen/libtextscreen.a   \
                        @LDFLAGS@ @SDL_LIBS@ @SDLMIXER_LIBS@ @SDLNET_LIBS@

EXTRA_DIST =                        \
        CMakeLists.txt              \
        icon.cpp                      \
        Doom_Screensaver.desktop.in \
        manifest.xml

metainfodir = $(prefix)/share/metainfo
metainfo_DATA =                             \
        @PACKAGE_RDNS@.Doom.metainfo.xml
#       @PACKAGE_RDNS@.Heretic.metainfo.xml \
#       @PACKAGE_RDNS@.Hexen.metainfo.xml   \
#       @PACKAGE_RDNS@.Strife.metainfo.xml

@PACKAGE_RDNS@.Doom.metainfo.xml : Doom.metainfo.xml
	cp Doom.metainfo.xml $@

@PACKAGE_RDNS@.Heretic.metainfo.xml : Heretic.metainfo.xml
	cp Heretic.metainfo.xml $@

@PACKAGE_RDNS@.Hexen.metainfo.xml : Hexen.metainfo.xml
	cp Hexen.metainfo.xml $@

@PACKAGE_RDNS@.Strife.metainfo.xml : Strife.metainfo.xml
	cp Strife.metainfo.xml $@

appdir = $(prefix)/share/applications
app_DATA =                                 \
           @PACKAGE_RDNS@.Doom.desktop
#          @PACKAGE_RDNS@.Heretic.desktop \
#          @PACKAGE_RDNS@.Hexen.desktop   \
#          @PACKAGE_RDNS@.Strife.desktop

@PACKAGE_RDNS@.Doom.desktop : Doom.desktop
	cp Doom.desktop $@

@PACKAGE_RDNS@.Heretic.desktop : Heretic.desktop
	cp Heretic.desktop $@

@PACKAGE_RDNS@.Hexen.desktop : Hexen.desktop
	cp Hexen.desktop $@

@PACKAGE_RDNS@.Strife.desktop : Strife.desktop
	cp Strife.desktop $@

screensaverdir = $(prefix)/share/applications/screensavers
screensaver_DATA = @PACKAGE_RDNS@.Doom_Screensaver.desktop

@PACKAGE_RDNS@.Doom_Screensaver.desktop: Doom_Screensaver.desktop
	cp Doom_Screensaver.desktop $@

CLEANFILES = $(execgames_SCRIPTS) $(app_DATA) $(screensaver_DATA)

.rc.o:
	$(WINDRES) $< -o $@
%.o : %.rc
	$(WINDRES) $< -o $@

if HAVE_PYTHON

icon.cpp : $(top_builddir)/data/doom.png
	$(top_builddir)/data/convert-icon $(top_builddir)/data/doom.png $@

endif

midiread : midifile.cpp
	$(CC) -DTEST $(CFLAGS) @LDFLAGS@ midifile.cpp -o $@

MUS2MID_SRC_FILES = mus2mid.cpp memio.cpp z_native.cpp i_system.cpp m_argv.cpp m_misc.cpp
mus2mid : $(MUS2MID_SRC_FILES)
	$(CC) -DSTANDALONE -I$(top_builddir) $(CFLAGS) @LDFLAGS@ \
              $(MUS2MID_SRC_FILES) -o $@

