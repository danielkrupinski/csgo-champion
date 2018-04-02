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
    std::string getValue(std::string property);
    void updateValues();
//private:
    libconfig::Config cfg;
    Display* display;
    int keycodeGlow {0};
    int keycodeRCS {0};
    int keycodeTriggerToggle {0};
    int keycodeTriggerKey {0};

    double enemyRed {0.0};
    double enemyGreen {0.0};
    double enemyBlue {0.0};
    double enemyAlpha {0.0};

    bool fullBloom {0};
    int glowStyle {0};

    bool healthBased {0};

    bool rainbowOn {0};

    float sensitivity {0.0};

    bool paintBlack {0};

    float m_pitch {0.0};
    float m_yaw {0.0};

    Vector2D rcsValue {0.0,0.0};

    bool disablePostProcessing {0};

    bool musicKitEnabled {0};
    unsigned musicKitID {0};

    bool iFovEnabled {0};
    int iFov {0};

    bool NoFlashEnabled {0};

    ColorRGBA colors {0.0,0.0,0.0,0.0};

    bool triggerKeyEnabled {0};
};
