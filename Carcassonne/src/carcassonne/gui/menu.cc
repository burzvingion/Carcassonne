// Copyright (c) 2013 Dougrist Productions
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
// Author: Benjamin Crist
// File: carcassonne/gui/menu.cc

#include "carcassonne/gui/menu.h"

#include "carcassonne/game.h"
#include "carcassonne/gui/main_menu.h"

namespace carcassonne {
namespace gui {

std::unique_ptr<Menu> Menu::load(Game& game, const std::string& name)
{
   if (name == "splash")
      return std::unique_ptr<Menu>(new MainMenu(game));

   throw std::runtime_error("Menu not found!");
}

Menu::Menu(Game& game)
   : game_(game)
{
}

Menu::Menu(const Menu& other)
   : game_(other.game_),
     buttons_(other.buttons_)
{
   InputManager* input_mgr(&input_mgr_);
   input_mgr_.setMouseDownHandler(sf::Mouse::Left, ([=](){ onHover(input_mgr->getMousePosition()); }));
}

Menu::~Menu()
{
}

std::unique_ptr<Menu> Menu::clone() const
{
   return std::unique_ptr<Menu>(new Menu(*this));
}

void Menu::onMouseMoved(const glm::vec3& world_coords)
{
}

void Menu::onMouseWheel(int delta)
{
}

void Menu::onMouseButton(sf::Mouse::Button Button, bool down)
{
}

void Menu::onKey(const sf::Event::KeyEvent& event, bool down)
{
}

void Menu::onCharacter(const sf::Event::TextEvent& event)
{
}

void Menu::onResized()
{
}

void Menu::onBlurred()
{
}

bool Menu::onClosed()
{
   return true;
}

void Menu::update()
{
}

void Menu::draw()
{
}

void Menu::cancelInput()
{
}

} // namespace carcassonne::gui
} // namespace carcassonne
