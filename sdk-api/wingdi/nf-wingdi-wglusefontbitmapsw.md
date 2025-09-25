# wglUseFontBitmapsW function

## Description

The **wglUseFontBitmaps** function creates a set of bitmap display lists for use in the current OpenGL rendering context. The set of bitmap display lists is based on the glyphs in the currently selected font in the device context. You can then use bitmaps to draw characters in an OpenGL image.

The **wglUseFontBitmaps** function creates *count* display lists, one for each of a run of *count* glyphs that begins with the first glyph in the *hdc* parameter's selected fonts.

## Parameters

### `unnamedParam1`

Specifies the device context whose currently selected font will be used to form the glyph bitmap display lists in the current OpenGL rendering context.

### `unnamedParam2`

Specifies the first glyph in the run of glyphs that will be used to form glyph bitmap display lists.

### `unnamedParam3`

Specifies the number of glyphs in the run of glyphs that will be used to form glyph bitmap display lists. The function creates *count* display lists, one for each glyph in the run.

### `unnamedParam4`

Specifies a starting display list.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **wglUseFontBitmaps** function defines *count* display lists in the current OpenGL rendering context. Each display list has an identifying number, starting at *listBase*. Each display list consists of a single call to [glBitmap](https://learn.microsoft.com/windows/desktop/OpenGL/glbitmap). The definition of bitmap *listBase* + *i* is taken from the glyph *first* + *i* of the font currently selected in the device context specified by *hdc*. If a glyph is not defined, then the function defines an empty display list for it.

The **wglUseFontBitmaps** function creates bitmap text in the plane of the screen. It enables the labeling of objects in OpenGL.

In the current version of Microsoft's implementation of OpenGL, you cannot make GDI calls to a device context that has a double-buffered pixel format. Therefore, you cannot use the GDI fonts and text functions with such device contexts. You can use the **wglUseFontBitmaps** function to circumvent this limitation and draw text in a double-buffered device context.

The function determines the parameters of each call to **glBitmap** as follows.

| glBitmap Parameter | Meaning |
| --- | --- |
| *width* | The width of the glyph's bitmap, as returned in the **gmBlackBoxX** member of the glyph's [GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics) structure. |
| *height* | The height of the glyph's bitmap, as returned in the **gmBlackBoxY** member of the glyph's **GLYPHMETRICS** structure. |
| *xorig* | The x offset of the glyph's origin, as returned in the **gmptGlyphOrigin.x** member of the glyph's **GLYPHMETRICS** structure. |
| *yorig* | The y offset of the glyph's origin, as returned in the **gmptGlyphOrigin.y** member of the glyph's **GLYPHMETRICS** structure. |
| *xmove* | The horizontal distance to the origin of the next character cell, as returned in the **gmCellIncX** member of the glyph's **GLYPHMETRICS** structure. |
| *ymove* | The vertical distance to the origin of the next character cell as returned in the **gmCellIncY** member of the glyph's **GLYPHMETRICS** structure. |
| *bitmap* | The bitmap for the glyph, as returned by [GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea) with *uFormat* equal to 1. |

#### Examples

The following code example shows how to use **wglUseFontBitmaps** to draw some text.

```cpp
HDC    hdc;
HGLRC  hglrc;

// create a rendering context
hglrc = wglCreateContext (hdc);

// make it the calling thread's current rendering context
wglMakeCurrent (hdc, hglrc);

// now we can call OpenGL API

// make the system font the device context's selected font
SelectObject (hdc, GetStockObject (SYSTEM_FONT));

// create the bitmap display lists
// we're making images of glyphs 0 thru 254
// the display list numbering starts at 1000, an arbitrary choice
wglUseFontBitmaps (hdc, 0, 255, 1000);

// display a string:
// indicate start of glyph display lists
glListBase (1000);
// now draw the characters in a string
glCallLists (24, GL_UNSIGNED_BYTE, "Hello Windows OpenGL World");
```

> [!NOTE]
> The wingdi.h header defines wglUseFontBitmaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics)

[GetGlyphOutline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getglyphoutlinea)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[glBitmap](https://learn.microsoft.com/windows/desktop/OpenGL/glbitmap)

[glCallLists](https://learn.microsoft.com/windows/desktop/OpenGL/glcalllists)

[glListBase](https://learn.microsoft.com/windows/desktop/OpenGL/gllistbase)

[wglUseFontOutlines](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglusefontoutlinesa)