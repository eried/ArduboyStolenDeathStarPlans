#include <Arduboy2.h>
#include "anim.h"

Arduboy2 arduboy;
Sprites sprites;
byte frame = 0, repeats = 0;

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(5);
}

const byte x = 32, y = 0;

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  arduboy.clear();

  sprites.drawSelfMasked(x + 2, y + 2, anim, frame++);
  arduboy.drawRect(x, y, 63, 64);

  if (repeats < 200)
    if (frame >= 42)
    {
      frame = 0;
      repeats++;
    }

  arduboy.display();
}
