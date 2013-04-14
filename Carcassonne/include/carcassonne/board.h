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
// File: carcassonne/board.h
//
// Represents a map of the game world - by using a std::unordered_map of tiles

#ifndef CARCASSONNE_BOARD_H_
#define CARCASSONNE_BOARD_H_
#include "carcassonne/_carcassonne.h"

#include <unordered_map>

#include "carcassonne/tile.h"

namespace carcassonne {

class Board
{
public:
   Board();

   Tile* getTileAt(const glm::ivec2& position) const;

   // If tile is a TYPE_EMPTY_* tile, return false if the position already has
   // a tile of any kind.
   // If tile is a TYPE_FLOATING tile, return false if the position does not
   // currently have a TYPE_EMPTY_PLACEABLE tile.
   bool placeTileAt(const glm::ivec2& position, std::unique_ptr<Tile>&& tile);

   void draw() const;

private:
   std::unordered_map<glm::ivec2, std::unique_ptr<Tile> > board_;

   // Disable copy-construction & assignment - do not implement
   Board(const Board&);
   void operator=(const Board&);
};

} // namespace carcassonne

#endif