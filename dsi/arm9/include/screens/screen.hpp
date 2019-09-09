#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <memory>
#include <nds.h>

class SCREEN
{
public:
    virtual ~SCREEN() {}
    virtual void Logic(u16 hDown, touchPosition touch) = 0;
    virtual void Draw() const = 0;
private:
};

#endif