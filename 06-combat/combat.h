#pragma once
#include <random>
#include "character.h"

int rollDice(std::mt19937& engine, int sides);

bool isAlive(const Character& character);
void applyDamage(Character& target, int amount);
int computeDamage(const Character& attacker, std::mt19937& engine);
int attack(const Character& attacker, Character& defender, std::mt19937& engine);
bool runDuel(Character first, Character second, std::mt19937& engine, bool showLog);