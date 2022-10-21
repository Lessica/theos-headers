/*
 
GSMainScreen.h ... Manipulating the main screen

Copyright (c) 2009  KennyTM~ <kennytm@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the KennyTM~ nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef GSMAINSCREEN_H
#define GSMAINSCREEN_H

#include <CoreGraphics/CoreGraphics.h>
#include <Availability2.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#if CGFLOAT_IS_DOUBLE
typedef float GSFloat;
struct GSPoint {
    GSFloat x;
    GSFloat y;
};
struct GSSize {
    GSFloat width;
    GSFloat height;
};
struct GSRect {
    GSPoint origin;
    GSSize size;
};
struct GSAffineTransform {
    GSFloat a, b, c, d;
    GSFloat tx, ty;
};
#else
typedef CGFloat GSFloat;
typedef CGPoint GSPoint;
typedef CGSize GSSize;
typedef CGRect GSRect;
typedef CGAffineTransform GSAffineTransform;
#endif

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
GSRect GSFullScreenApplicationContentRect();
#endif
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2
GSSize GSMainScreenPixelSize(void); // default to 320 x 480.
GSSize GSMainScreenPointSize(void); // default to 320 x 480.
#endif

void GSSetMainScreenInfo(GSSize screenSize, GSFloat screenScale, int screenOrientation);
GSAffineTransform GSMainScreenPositionTransform();
GSAffineTransform GSMainScreenWindowTransform();
int GSMainScreenOrientation();
GSFloat GSMainScreenScaleFactor();
GSSize GSMainScreenSize();

__END_DECLS

#endif
