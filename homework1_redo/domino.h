#ifndef DOMINO_H_
#define DOMINO_H_

#include "half_domino.h"

#include <Windows.h>

class Domino {
public:
  Domino() {};
  Domino(int domino_height, int domino_width, const COLORREF & color, int num_top_dots, int num_bottom_dots);

  int domino_height() const { return this->domino_height_; }
  int domino_width() const { return this->domino_width_; }
  const COLORREF &domino_color() const { return this->domino_color_; }
  int center_x() const { return this->center_x_; }
  int center_y() const { return this->center_y_; }
  bool even() const { return this->even_; }
  HalfDomino *half(int index) const { return this->halfs[index]; }
  double multiplier() const { return this->multiplier_; }

  void set_domino_height(int domino_height) { this->domino_height_ = domino_height; }
  void set_domino_width(int domino_width) { this->domino_width_ = domino_width; }
  void set_domino_color(const COLORREF &domino_color) { this->domino_color_ = domino_color; }
  void set_center_x(int x) { this->center_x_ = x; }
  void set_center_y(int y) { this->center_y_ = y; }
  void set_half(int index, HalfDomino *half) { this->halfs[index] = half; }
  void set_even(bool even) { this->even_ = even; }
  void set_multiplier(double multiplier) { this->multiplier_ = multiplier; }

private:
  int domino_height_;
  int domino_width_;
  COLORREF domino_color_;

  int center_x_;
  int center_y_;

  double multiplier_;

  HalfDomino * halfs[2];
  bool even_;
};


#endif