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
// File: carcassonne/features/cloister.h
//
// Represents a cloister.  A cloister is only only on one tile, but scores 
// points based on the 8 neighboring tiles as well.

#ifndef CARCASSONNE_FEATURES_CLOISTER_H_
#define CARCASSONNE_FEATURES_CLOISTER_H_

#include "carcassonne/features/feature.h"

namespace carcassonne {
namespace features {

class Cloister : public Feature
{
public:
   Cloister(AssetManager& asset_mgr, int id, Tile& tile);
   Cloister(const Cloister& other, Tile& tile);
   virtual ~Cloister();

   virtual Type getType() const;
   virtual bool isComplete() const;
   virtual void score();

   void addTile(Tile& tile);

private:
   Cloister(const Cloister&);
   void operator=(const Cloister&);
};

} // namespace carcassonne::features
} // namespace carcassonne

#endif
