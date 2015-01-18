#include "painter.h"
#include "domino.h"
#include "half_domino.h"

#include <Windows.h>

void PaintDominos(HDC hDC, const Domino dominos[]) {
  for (int i = 0; i < 7; ++i) {
    PaintDomino(hDC, dominos[i], i);
  }
}

void PaintDomino(HDC hDC, const Domino &domino, int domino_number) {
  int start_x = CONST_START_X + (domino_number % 4) * 200;
  int start_y = CONST_START_Y * ((domino_number > 3) ? 4 : 1);
  PaintRect(hDC, domino, start_x, start_y);
  PaintHalfs(hDC, domino, start_x, start_y);
}

void PaintRect(HDC hDC, const Domino &domino, int start_x, int start_y) {
  HBRUSH brush = CreateSolidBrush(domino.domino_color());
  SelectObject(hDC, brush);

  int left = start_x;
  int top = start_y;
  int right = start_x + domino.domino_width();
  int bottom = start_y + domino.domino_height();

  Rectangle(hDC, left, top, right, bottom);

  DeleteObject(brush);
}

//  FOR LATER WHY IS SQ_TOP AND SQ_BOTTOM 100?
void PaintHalfs(HDC hDC, const Domino &domino, int start_x, int start_y) {
  for (int i = 0; i < 2; ++i) {
    HalfDomino * half = domino.half(i);
    HBRUSH brush = CreateSolidBrush(half->square_color());
    SelectObject(hDC, brush);

    int sq_left = start_x + (domino.domino_width() - half->square_val()) / 2;
    int sq_top = start_y + (domino.domino_width() - half->square_val()) / 2 + 100 * i;
    int sq_right = start_x + (domino.domino_width() - half->square_val()) / 2 + half->square_val();
    int sq_bottom = start_y + (domino.domino_width() - half->square_val()) / 2 + half->square_val() + 100 * i;

    Rectangle(hDC, sq_left, sq_top, sq_right, sq_bottom);
    PaintDots(hDC, *half, sq_left, sq_top, sq_right, sq_bottom);

    DeleteObject(brush);
  }
}

void PaintDots(HDC hDC, const HalfDomino &half, int sq_left, int sq_top, int sq_right, int sq_bottom) {
  switch (half.num_dots()) {
  case 0: //  Draw no dots
    break;
  case 1: {
    PaintDot(hDC, half, 4, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  case 2: {
    PaintDot(hDC, half, 2, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 6, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  case 3: {
    PaintDot(hDC, half, 2, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 4, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 6, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  case 4: {
    PaintDot(hDC, half, 1, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 2, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 6, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 7, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  case 5: {
    PaintDot(hDC, half, 1, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 2, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 4, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 6, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 7, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  case 6: {
    PaintDot(hDC, half, 1, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 2, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 3, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 5, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 6, sq_left, sq_top, sq_right, sq_bottom);
    PaintDot(hDC, half, 7, sq_left, sq_top, sq_right, sq_bottom);
    break;
  }
  }
}

void PaintDot(HDC hDC, const HalfDomino &half, int dot, int sq_left, int sq_top, int sq_right, int sq_bottom) {
  HBRUSH brush = CreateSolidBrush(half.dot_color());
  SelectObject(hDC, brush);

  switch (dot) {
  case 1: {
    int cr_left1 = sq_left + half.square_val() / 4 - half.radius();
    int cr_top1 = sq_top + half.square_val() / 4 - half.radius();
    int cr_right1 = cr_left1 + half.radius() * 2;
    int cr_bottom1 = cr_top1 + half.radius() * 2;

    Ellipse(hDC, cr_left1, cr_top1, cr_right1, cr_bottom1);
    break;
  }
  case 2: {
    int cr_left2 = sq_left + 3 * (half.square_val() / 4) - half.radius();
    int cr_top2 = sq_top + half.square_val() / 4 - half.radius();
    int cr_right2 = cr_left2 + half.radius() * 2;
    int cr_bottom2 = cr_top2 + half.radius() * 2;

    Ellipse(hDC, cr_left2, cr_top2, cr_right2, cr_bottom2);
    break;
  }
  case 3: {
    int cr_left3 = sq_left + half.square_val() / 4 - half.radius();
    int cr_top3 = sq_top + 2 * (half.square_val() / 4) - half.radius();
    int cr_right3 = cr_left3 + half.radius() * 2;
    int cr_bottom3 = cr_top3 + half.radius() * 2;

    Ellipse(hDC, cr_left3, cr_top3, cr_right3, cr_bottom3);
    break;
  }
  case 4: {
    int cr_left4 = sq_left + 2 * (half.square_val() / 4) - half.radius();
    int cr_top4 = sq_top + 2 * (half.square_val() / 4) - half.radius();
    int cr_right4 = cr_left4 + half.radius() * 2;
    int cr_bottom4 = cr_top4 + half.radius() * 2;

    Ellipse(hDC, cr_left4, cr_top4, cr_right4, cr_bottom4);
    break;
  }
  case 5: {
    int cr_left5 = sq_left + 3 * (half.square_val() / 4) - half.radius();
    int cr_top5 = sq_top + 2 * (half.square_val() / 4) - half.radius();
    int cr_right5 = cr_left5 + half.radius() * 2;
    int cr_bottom5 = cr_top5 + half.radius() * 2;

    Ellipse(hDC, cr_left5, cr_top5, cr_right5, cr_bottom5);
    break;
  }
  case 6: {
    int cr_left6 = sq_left + half.square_val() / 4 - half.radius();
    int cr_top6 = sq_top + 3 * (half.square_val() / 4) - half.radius();
    int cr_right6 = cr_left6 + half.radius() * 2;
    int cr_bottom6 = cr_top6 + half.radius() * 2;

    Ellipse(hDC, cr_left6, cr_top6, cr_right6, cr_bottom6);
    break;
  }
  case 7: {
    int cr_left7 = sq_left + 3 * (half.square_val() / 4) - half.radius();
    int cr_top7 = sq_top + 3 * (half.square_val() / 4) - half.radius();
    int cr_right7 = cr_left7 + half.radius() * 2;
    int cr_bottom7 = cr_top7 + half.radius() * 2;

    Ellipse(hDC, cr_left7, cr_top7, cr_right7, cr_bottom7);
    break;
  }
  }
  DeleteObject(brush);
}