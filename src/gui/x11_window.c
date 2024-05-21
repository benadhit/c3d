#include "gui/window.h"

#include <X11/X.h>
#include <X11/Xlib.h>

#define X11Display Display
#define X11Window  Window
struct C3DWindow
{
    X11Display* display;
    X11Window window;
};


C3DWindow c3dOpenWindow(WindowConfig *config)
{
    C3DWindow* window = malloc(sizeof(C3DWindow));
    window->display = XOpenDisplay(0);
    int screen = DefaultScreen(window->display);
    unsigned long black = BlackPixel(window->display, screen);
    unsigned long white = WhitePixel(window->display, screen);
    window->window = XCreateSimpleWindow(
        window->display, 
        DefaultRootWindow(window->display),
        config->x_pos,
        config->y_pos,
        config->width,
        config->height,
        5, 
        white,
        black);
    XSetStandardProperties(window->display,window->window, config->title, None,NULL,0, NULL);    
    XSelectInput(window->display, window->window, ExposureMask|ButtonPressMask|KeyPressMask);
    XClearWindow(window->display, window->window);
	XMapRaised(window->display, window->window);
}