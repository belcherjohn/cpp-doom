FONT_HDRS = small.hpp normal.hpp large.hpp codepage.hpp
EXTRA_DIST = small.png normal.png large.png convert-font $(FONT_HDRS)

noinst_DATA = $(FONT_HDRS)

if HAVE_PYTHON

small.hpp: small.png convert-font
	./convert-font small small.png small.hpp

normal.hpp: normal.png convert-font
	./convert-font normal normal.png normal.hpp

large.hpp: large.png convert-font
	./convert-font large large.png large.hpp

endif

