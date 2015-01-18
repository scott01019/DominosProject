#ifndef PAINTER_H_
#define PAINTER_H_

#include "domino.h"
#include "half_domino.h"

#include <Windows.h>

const int CONST_START_X = 100;
const int CONST_START_Y = 100;

void PaintDominos(HDC, const Domino []);
void PaintDomino(HDC, const Domino &, int);
void PaintRect(HDC, const Domino &, int, int);
void PaintHalfs(HDC, const Domino &, int, int);
void PaintDots(HDC, const HalfDomino &, int, int, int, int);
void PaintDot(HDC, const HalfDomino &, int, int, int, int, int);
#endif