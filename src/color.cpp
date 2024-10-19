#include "color.h"

#include <vector>
using namespace std;

const Color dark = {0, 0, 0, 200};
const Color green = {211, 255, 40, 255};
const Color red = {185, 0, 22, 255};
const Color orange = {255, 165, 0, 255};
const Color yellow = {255, 255, 56, 255};
const Color blue = {0, 219, 255, 255};
const Color purple = {128, 0, 188, 255};
const Color cyan = {186, 255, 255, 255};

vector<Color> GetCellColors() {
    return {dark, green, red, orange, yellow, blue, purple, cyan};
}