//#pragma once

#ifndef MYRPGGAME_MENU_HPP
#define MYRPGGAME_MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <map>
#include <vector>

using namespace sf;
using namespace std;

enum MenuActions {
    ACTION_RESUME, ACTIONS_INVENTORY, ACTION_SETTINGS, ACTION_EXIT, ACTION_SUBMENU
};

class Menu {
protected:
    std::vector<sf::Text> *menuItems;
    sf::Font font;
    int currentMenuItemIdx;
    int numOfMenuItems;
    bool active; // indicator whether the menu is currently shown on screen (if switched off we'll go to parent menu)
    bool gameMenu = false;
    Menu *parentMenu; // for navigating backwards from the submenus
    vector<Menu*> *subMenus; // setting an option for every menu to have a sub menu
    map<int, Menu*> *subMenusIndexesMap;

    void setParentMenu(Menu *menu);

public:
    explicit Menu(std::vector<std::string> itemsStrings, bool gameMenu);
    ~Menu() = default;

    void initMenuItems(std::vector<std::string> itemsStrings);
    vector<Text> *getMenuItems();
    vector<Menu*> *getSubMenus();
    void render(int currentWindowX, int currentWindowY, RenderWindow *window);
    void moveUp();
    void moveDown();
    bool hasSubMenus();
    void addSubMenu(Menu *menu, int menuIndex);
    Menu *getParentMenu();
    void setIsActive(bool flag);
    bool isActive();
    bool isGameMenu();
    virtual bool isSubMenuItem();
    virtual int execute(Constants::GameState *state);
    void resetMenuItemIdx();
};

#endif //MYRPGGAME_MENU_HPP
