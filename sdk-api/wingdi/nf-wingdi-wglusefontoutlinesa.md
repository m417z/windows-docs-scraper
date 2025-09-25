# wglUseFontOutlinesA function

## Description

The **wglUseFontOutlines** function creates a set of display lists, one for each glyph of the currently selected outline font of a device context, for use with the current rendering context. The display lists are used to draw 3-D characters of TrueType fonts. Each display list describes a glyph outline in floating-point coordinates.

The run of glyphs begins with thefirstglyph of the font of the specified device context. The em square size of the font, the notional grid size of the original font outline from which the font is fitted, is mapped to 1.0 in the x- and y-coordinates in the display lists. The extrusion parameter sets how much depth the font has in the z direction.

Thelpgmfparameter returns a [GLYPHMETRICSFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetricsfloat) structure that contains information about the placement and orientation of each glyph in a character cell.

## Parameters

### `unnamedParam1`

Specifies the device context with the desired outline font. The outline font of *hdc* is used to create the display lists in the current rendering context.

### `unnamedParam2`

Specifies the first of the set of glyphs that form the font outline display lists.

### `unnamedParam3`

Specifies the number of glyphs in the set of glyphs used to form the font outline display lists. The **wglUseFontOutlines** function creates *count* display lists, one display list for each glyph in a set of glyphs.

### `unnamedParam4`

Specifies a starting display list.

### `unnamedParam5`

Specifies the maximum chordal deviation from the original outlines. When deviation is zero, the chordal deviation is equivalent to one design unit of the original font. The value of *deviation* must be equal to or greater than 0.

### `unnamedParam6`

Specifies how much a font is extruded in the negative *z* direction. The value must be equal to or greater than 0. When *extrusion* is 0, the display lists are not extruded.

### `unnamedParam7`

Specifies the format, either WGL_FONT_LINES or WGL_FONT_POLYGONS, to use in the display lists. When *format* is WGL_FONT_LINES, the **wglUseFontOutlines** function creates fonts with line segments. When *format* is WGL_FONT_POLYGONS, **wglUseFontOutlines** creates fonts with polygons.

### `unnamedParam8`

Points to an array of *count*[GLYPHMETRICSFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetricsfloat) structures that is to receive the metrics of the glyphs. When *lpgmf* is **NULL**, no glyph metrics are returned.

## Return value

When the function succeeds, the return value is **TRUE**.

When the function fails, the return value is **FALSE** and no display lists are generated. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **wglUseFontOutlines** function defines the glyphs of an outline font with display lists in the current rendering context. The **wglUseFontOutlines** function works with TrueType fonts only; stroke and raster fonts are not supported.

Each display list consists of either line segments or polygons, and has a unique identifying number starting with the *listBase* number.

The **wglUseFontOutlines** function approximates glyph outlines by subdividing the quadratic B-spline curves of the outline into line segments, until the distance between the outline and the interpolated midpoint is within the value specified by *deviation*. This is the final format used when *format* is WGL_FONT_LINES. When you specify WGL_FONT_OUTLINES, the display lists created don't contain any normals; thus lighting doesn't work properly. To get the correct lighting of lines use WGL_FONT_POLYGONS and set **glPolygonMode**( GL_FRONT, GL_LINE ). When you specify *format* as WGL_FONT_POLYGONS the outlines are further tessellated into separate triangles, triangle fans, triangle strips, or quadrilateral strips to create the surface of each glyph. With WGL_FONT_POLYGONS, the created display lists call **glFrontFace**( GL_CW ) or **glFrontFace**( GL_CCW ); thus the current front-face value might be altered. For the best appearance of text with WGL_FONT_POLYGONS, cull the back faces as follows:

```cpp
glCullFace(GL_BACK);
glEnable(GL_CULL_FACE);
```

A **GLYPHMETRICSFLOAT** structure contains information about the placement and orientation of each glyph in a character cell. The *lpgmf* parameter is an array of **GLYPHMETRICSFLOAT** structures holding the entire set of glyphs for a font. Each display list ends with a translation specified with the **gmfCellIncX** and **gmfCellIncY** members of the corresponding **GLYPHMETRICSFLOAT** structure. The translation enables the drawing of successive characters in their natural direction with a single call to [glCallLists](https://learn.microsoft.com/windows/desktop/OpenGL/glcalllists).

**Note** With OpenGL for Windows, you cannot make GDI calls to a device context when a pixel format is double-buffered. You can work around this limitation by using **wglUseFontOutlines** and [wglUseFontBitmaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglusefontbitmapsa), when using double-buffered device contexts.

#### Examples

The following code example shows how to draw text using **wglUseFontOutlines**.

```cpp
HDC    hdc;  // A TrueType font has already been selected
HGLRC  hglrc;
GLYPHMETRICSFLOAT agmf[256];

// Make hglrc the calling thread's current rendering context
wglMakeCurrent(hdc, hglrc);

// create display lists for glyphs 0 through 255 with 0.1 extrusion
// and default deviation. The display list numbering starts at 1000
// (it could be any number)
wglUseFontOutlines(hdc, 0, 255, 1000, 0.0f, 0.1f,
            WGL_FONT_POLYGONS, &agmf);

// Set up transformation to draw the string
glLoadIdentity();
glTranslate(0.0f, 0.0f, -5.0f)
glScalef(2.0f, 2.0f, 2.0f);

// Display a string
glListBase(1000); // Indicates the start of display lists for the glyphs
// Draw the characters in a string
glCallLists(24, GL_UNSIGNED_BYTE, "Hello Windows OpenGL World.");
```

> [!NOTE]
> The wingdi.h header defines wglUseFontOutlines as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GLYPHMETRICSFLOAT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetricsfloat)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[glCallLists](https://learn.microsoft.com/windows/desktop/OpenGL/glcalllists)

[glListBase](https://learn.microsoft.com/windows/desktop/OpenGL/gllistbase)

[glTexGen](https://learn.microsoft.com/windows/desktop/OpenGL/gltexgen-functions)

[wglUseFontBitmaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglusefontbitmapsa)