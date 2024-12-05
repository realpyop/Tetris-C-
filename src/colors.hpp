#ifndef COLORS_HPP
#define COLORS_HPP

#include <raylib.h>
#include <vector>

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow; 
extern const Color purple;
extern const Color cyan;
extern const Color blue;

std::vector<Color> GetCellColors();

#endif