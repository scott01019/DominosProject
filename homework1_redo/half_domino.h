#ifndef HALF_DOMINO_H_
#define HALF_DOMINO_H_

#include <Windows.h>

class HalfDomino {
public:
  HalfDomino(int num_dots, int square_val, int radius, const COLORREF &dot_color, const COLORREF &square_color)
    : num_dots_(num_dots), square_val_(square_val), radius_(radius), dot_color_(dot_color), square_color_(square_color) {}
  int num_dots() const { return this->num_dots_; }
  int square_val() const { return this->square_val_; }
  int radius() const { return this->radius_; }
  const COLORREF &dot_color() const { return this->dot_color_; }
  const COLORREF &square_color() const { return this->square_color_; }

  void set_num_dots(int num_dots) { this->num_dots_ = num_dots; }
  void set_square_val(int square_val) { this->square_val_ = square_val_; }
  void set_radius(int radius) { this->radius_ = radius; }
  void set_dot_color(const COLORREF &color) { this->dot_color_ = color; }
  void set_square_color(const COLORREF &color) { this->square_color_ = color; }

private:
  int num_dots_;
  int square_val_;
  int radius_;
  COLORREF dot_color_;
  COLORREF square_color_;
};

#endif