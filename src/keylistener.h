#ifndef KEY_LISTENER_H
#define KEY_LISTENER_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <X11/extensions/XTest.h>
#include "logger.h"
#include "remote.h"
#include "config.h"


class KeyListener {
private:
    char keys[32];
	char lastkeys[32];
    remote::Handle csgo;
    Cfg cfg;
public:
    //void getKeyCodeState(KeyCode keyCode);
    KeyListener(remote::Handle&, Cfg&);
    void listen();
    Display* display {XOpenDisplay(0)};
    bool getKeyCodeState(KeyCode);
};
#endif // KEY_LISTENER_H
