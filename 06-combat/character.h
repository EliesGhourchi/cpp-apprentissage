#pragma once
#include <string>
enum class Element { Fire, Wind, Water, Earth, None };

struct Character  {
    std::string name = "noname";
    int maxHp = 100;
    int hp = maxHp;
    int actionPoints = 6;
    int movePoints = 3;
    Element element = Element::None;
    int Pow = 0;
};





std::string elementName(Element element);
