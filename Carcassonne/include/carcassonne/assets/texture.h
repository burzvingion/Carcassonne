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
// File: carcassonne/assets/texture.h

#ifndef CARCASSONNE_ASSETS_TEXTURE_H_
#define CARCASSONNE_ASSETS_TEXTURE_H_
#include "carcassonne/_carcassonne.h"

#include <string>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

namespace bmc {

class Texture
{
public:
   Texture(const std::string& filename);
   Texture(const char* filename);
   Texture(const GLubyte* data, int width, int height);
   ~Texture();

   GLuint getTextureGlId() const;

   void enable() const;
   void enable(GLenum mode) const;
   void enable(GLenum mode, const glm::vec4& color) const;
   void disable() const;

   static void disableAny();

private:
   void upload(const GLubyte* data);

   static void checkUnknown();
   static void checkMode(GLenum mode);
   void checkTexture() const;
   
   enum State { UNKNOWN, DISABLED, ENABLED };

   static State state_;
   static GLuint bound_id_;
   static GLenum mode_;
   static glm::vec4 color_;

   int width_;
   int height_;

   GLuint texture_id_;

   Texture(const Texture& other);  // disable copy construction
   void operator=(const Texture& other); // disable assignment
};

} // namespace bmc

#endif
