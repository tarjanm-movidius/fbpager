// Color.hh for Fluxbox Window Manager 
// Copyright (c) 2002-2004 Henrik Kinnunen (fluxgen@users.sourceforge.net)
//
// from Image.hh for Blackbox - an X11 Window manager
// Copyright (c) 1997 - 2000 Brad Hughes (bhughes@tcac.net)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// $Id: Color.hh,v 1.6 2003/12/16 17:06:49 fluxgen Exp $

#ifndef FBTK_COLOR_HH
#define FBTK_COLOR_HH

#include "NotCopyable.hh"

namespace FbTk {

/// Allocates rgb color and pixel value
class Color {
public:
    Color();
    explicit Color(unsigned long pixel);
    Color(const Color &col_copy);
    Color(unsigned short red, unsigned short green, unsigned short blue, int screen);
    /// parses and sets rgb and pixel value from a string
    Color(const char *color_string, int screen);
    ~Color();

    /// parses and sets rgb and pixel value from a string
    bool setFromString(const char *color_string, int screen);
    /// TODO don't like this
    void setPixel(unsigned long pixel) { m_pixel = pixel; }
   
    Color &operator = (const Color &col_copy);
	
    inline bool isAllocated() const { return m_allocated; }
    inline unsigned short red() const { return m_red; }
    inline unsigned short green() const { return m_green; }
    inline unsigned short blue() const { return m_blue; }
    inline unsigned long pixel() const { return m_pixel; }
	
private:
    void free();
    void copy(const Color &col_copy);
    void allocate(unsigned short red, unsigned short green, 
                  unsigned short blue, int screen);
    inline void setAllocated(bool a) { m_allocated = a; }
    void setRGB(unsigned short red, unsigned short green, unsigned short blue);


    unsigned short m_red, m_green, m_blue;
    unsigned long m_pixel;
    bool m_allocated;
    int m_screen;
};

} // end namespace FbTk

#endif // FBTK_COLOR_HH
