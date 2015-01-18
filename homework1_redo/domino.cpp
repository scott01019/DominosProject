#include "domino.h"
#include "half_domino.h"

#include <stdlib.h>
#include <time.h>

Domino::Domino(int domino_height, int domino_width, const COLORREF & color, int num_top_dots, int num_bottom_dots)
  : domino_height_(domino_height), domino_width_(domino_width), domino_color_(color) {
  this->set_half(0, new HalfDomino(
    num_top_dots,
    80,
    8,
    RGB(rand() % 256, rand() % 256, rand() % 256),
    RGB(rand() % 256, rand() % 256, rand() % 256)
    )
    );
  this->set_half(1, new HalfDomino(
    num_bottom_dots,
    80,
    8,
    RGB(rand() % 256, rand() % 256, rand() % 256),
    RGB(rand() % 256, rand() % 256, rand() % 256)
    )
    );
}