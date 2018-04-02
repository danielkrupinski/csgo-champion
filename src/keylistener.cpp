#include "keylistener.h"

//KeyListener::KeyListener(remote::Handle& h, Cfg& c)
//    : csgo{h}, cfg{c}
//{

//}
//

void KeyListener::listen(remote::Handle& csgo, Cfg& cfg)
{
    XQueryKeymap(display, keys);

    for (int i=0; i!=sizeof(keys); ++i)
    {
        if (keys[i] != lastkeys[i])
        {
            for (int j=0, test=1; j!=8; ++j, test*=2)
            {
                if ((keys[i] & test) && ((keys[i] & test) != (lastkeys[i] & test)))
                {
                    const int code = i * 8 + j;

                    if (code == cfg.keycodeGlow)
                    {
                        csgo.GlowEnabled = !csgo.GlowEnabled;
                        Logger::toggle("Glow ESP\t\t", csgo.GlowEnabled);
                    }

                    if (code == cfg.keycodeRCS)
                    {
                        csgo.RCSEnabled = !csgo.RCSEnabled;
                        Logger::toggle("RCS\t\t", csgo.RCSEnabled);
                    }

                    if (code == cfg.keycodeTriggerToggle)
                    {
                        csgo.TriggerEnabled = !csgo.TriggerEnabled;
                        Logger::toggle("Trigger\t\t", csgo.TriggerEnabled);
                    }
                }
            }
        }

        lastkeys[i] = keys[i];
    }
}


bool KeyListener::getKeyCodeState(KeyCode keyCode)
{
    if(!display)
    {
        return false;
    }

    char szKey[32];

    XQueryKeymap(display, szKey);

    return szKey[keyCode / 8] & (1 << (keyCode % 8));
}
