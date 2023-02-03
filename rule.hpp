// 兔年年兽第八关

// 本代码由 ./src/generateRule.py 自动生成
#ifndef RULE_HPP
#define RULE_HPP
#include "src/Calculator.hpp"

/**
 * @brief
 *
 * @param rule
 * @param s
 * @return int : the optimal `full` value
 */
int banquetRule(BanquetRule *const &rule, States &s) {
    BanquetStrictRule
        *strictRule[NUM_CHEFS *
                    DISH_PER_CHEF]; // 下一阶段的规则，不受意图生效次数的影响
    BanquetLenientRule *lenientRule[NUM_CHEFS * DISH_PER_CHEF];
    for (int i = 0; i < NUM_CHEFS * DISH_PER_CHEF; i++) {
        strictRule[i] = &rule[i].strictRule;
        lenientRule[i] = &rule[i].lenientRule;
    }


if (s.recipe[0]->cookAbility.boil > 0 && s.recipe[1]->cookAbility.boil > 0 && s.recipe[2]->cookAbility.boil > 0) {
	for (int i = 3; i < 6; i++) {
		if (s.recipe[i]->cookAbility.fry > 0) {
			strictRule[i]->addRule.buff+= 100;
		}
	}
}
if (s.recipe[0]->cookAbility.fry > 0 && s.recipe[1]->cookAbility.fry > 0 && s.recipe[2]->cookAbility.fry > 0) {
	for (int i = 3; i < 6; i++) {
		if (s.recipe[i]->cookAbility.steam > 0) {
			strictRule[i]->addRule.buff+= 100;
		}
	}
}
if (s.recipe[0]->cookAbility.bake > 0 && s.recipe[1]->cookAbility.bake > 0 && s.recipe[2]->cookAbility.bake > 0) {
	for (int i = 3; i < 6; i++) {
		if (s.recipe[i]->cookAbility.knife > 0) {
			strictRule[i]->addRule.buff+= 100;
		}
	}
}
if (s.recipe[0]->cookAbility.knife > 0 && s.recipe[1]->cookAbility.knife > 0 && s.recipe[2]->cookAbility.knife > 0) {
	for (int i = 3; i < 6; i++) {
		if (s.recipe[i]->cookAbility.stirfry > 0) {
			strictRule[i]->addRule.buff+= 100;
		}
	}
}

// 第2轮
for (int i = 3; i < 6; i++) {
	if (s.recipe[i]->flavor.sour == true) {
		lenientRule[i]->addRule.full+= -5;
		break;
	}
}
for (int i = 3; i < 6; i++) {
	if (s.recipe[i]->flavor.sweet) {
		lenientRule[i]->addRule.buff+= 100;
		break;
	}
}
for (int i = 3; i < 6; i++) {
	if (s.recipe[i]->flavor.spicy) {
		lenientRule[i]->baseRule.directAdd+= 500;
		break;
	}
}
for (int i = 3; i < 6; i++) {
	if (s.recipe[i]->flavor.bitter) {
		if (i+1 < 6) {
			if (s.recipe[i+1]->flavor.spicy == true) {
				lenientRule[i+1]->addRule.buff+= 100;
				break;
			}
		}
		break;
	}
}
for (int i = 6; i < 9; i++) {
	if (s.recipe[i]->rarity == 1) {
		lenientRule[i]->baseRule.directAdd+= 1000;
		break;
	}
}
for (int i = 6; i < 9; i++) {
	if (s.recipe[i]->rarity == 2) {
		lenientRule[i]->baseRule.buff+= 50;
		break;
	}
}
for (int i = 6; i < 9; i++) {
	if (s.recipe[i]->rarity == 3) {
		lenientRule[i]->addRule.buff+= 100;
		break;
	}
}
for (int i = 6; i < 9; i++) {
	if (s.recipe[i]->rarity == 4) {
		lenientRule[i]->addRule.full+= -4;
		break;
	}
}
return 24;

    
}

#endif

