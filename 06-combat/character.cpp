#include "character.h"
#include <string>
// les données
std::string elementName(Element element){
    switch (element)
    {
        case Element::Fire:  return "Fire";
        case Element::Wind:  return "Wind";
        case Element::Earth:  return "Earth";
        case Element::Water:  return "Water";
        case Element::None:  return "None";
    }
    return"";
}