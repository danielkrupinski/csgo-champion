#include <libconfig.h++>
#include "types.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <X11/extensions/XTest.h>

class Cfg {
public:
    Cfg(Display* d) : display{d} {};
    std::string getConfigValue(std::string property);
    void updateConfigValues();
//private:
    libconfig::Config cfg;
    Display* display;
    int keycodeGlow;
    int keycodeRCS;
    int keycodeTriggerToggle;
    int keycodeTriggerKey;

    double enemyRed;
    double enemyGreen;
    double enemyBlue;
    double enemyAlpha;

    bool fullBloom;
    int glowStyle;

    bool healthBased;

    bool rainbowOn;

    float sensitivity;

    bool paintBlack;

    float m_pitch;
    float m_yaw;

    Vector2D rcsValue;

    bool disablePostProcessing;

    bool musicKitEnabled;
    int musicKitID;

    bool iFovEnabled;
    int iFov;

    bool NoFlashEnabled;

    ColorRGBA colors;

    bool triggerKeyEnabled;
};
