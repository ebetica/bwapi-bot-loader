#ifndef DDRAW_H
#define DDRAW_H

#include "wintypes.h"
#include <stdint.h>

namespace native_window_drawing {

	struct color {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	struct palette {
		virtual ~palette() {}
		virtual void set_colors(color colors[256]) = 0;
	};

	struct surface {
		virtual ~surface() {}
		virtual void create(wintypes::HWND wnd) = 0;
		virtual void set_palette(palette* pal) = 0;
		virtual void* lock() = 0;
		virtual void unlock() = 0;
	};

	palette* new_palette();
	void delete_palette(palette*);
	surface* new_surface();
	void delete_surface(surface*);

}

#endif