# GetGlyphOutlineA function

## Description

The **GetGlyphOutline** function retrieves the outline or bitmap for a character in the TrueType font that is selected into the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `uChar` [in]

The character for which data is to be returned.

### `fuFormat` [in]

The format of the data that the function retrieves. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GGO_BEZIER** | The function retrieves the curve data as a cubic Bézier spline (not in quadratic spline format). |
| **GGO_BITMAP** | The function retrieves the glyph bitmap. For information about memory allocation, see the following Remarks section. |
| **GGO_GLYPH_INDEX** | Indicates that the *uChar* parameter is a TrueType Glyph Index rather than a character code. See the [ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) function for additional remarks on Glyph Indexing. |
| **GGO_GRAY2_BITMAP** | The function retrieves a glyph bitmap that contains five levels of gray. |
| **GGO_GRAY4_BITMAP** | The function retrieves a glyph bitmap that contains 17 levels of gray. |
| **GGO_GRAY8_BITMAP** | The function retrieves a glyph bitmap that contains 65 levels of gray. |
| **GGO_METRICS** | The function only retrieves the [GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics) structure specified by *lpgm*. The *lpvBuffer* is ignored. This value affects the meaning of the function's return value upon failure; see the Return Values section. |
| **GGO_NATIVE** | The function retrieves the curve data points in the rasterizer's native format and uses the font's design units. |
| **GGO_UNHINTED** | The function only returns unhinted outlines. This flag only works in conjunction with GGO_BEZIER and GGO_NATIVE. |

Note that, for the GGO_GRAYn_BITMAP values, the function retrieves a glyph bitmap that contains n^2+1 (n squared plus one) levels of gray.

### `lpgm` [out]

A pointer to the [GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics) structure describing the placement of the glyph in the character cell.

### `cjBuffer` [in]

The size, in bytes, of the buffer (**lpvBuffer*) where the function is to copy information about the outline character. If this value is zero, the function returns the required size of the buffer.

### `pvBuffer` [out]

A pointer to the buffer that receives information about the outline character. If this value is **NULL**, the function returns the required size of the buffer.

### `lpmat2` [in]

A pointer to a [MAT2](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-mat2) structure specifying a transformation matrix for the character.

## Return value

If GGO_BITMAP, GGO_GRAY2_BITMAP, GGO_GRAY4_BITMAP, GGO_GRAY8_BITMAP, or GGO_NATIVE is specified and the function succeeds, the return value is greater than zero; otherwise, the return value is GDI_ERROR. If one of these flags is specified and the buffer size or address is zero, the return value specifies the required buffer size, in bytes.

If GGO_METRICS is specified and the function fails, the return value is GDI_ERROR.

## Remarks

The glyph outline returned by the **GetGlyphOutline** function is for a grid-fitted glyph. (A grid-fitted glyph is a glyph that has been modified so that its bitmapped image conforms as closely as possible to the original design of the glyph.) If an application needs an unmodified glyph outline, it can request the glyph outline for a character in a font whose size is equal to the font's em unit. The value for a font's em unit is stored in the **otmEMSquare** member of the [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure.

The glyph bitmap returned by **GetGlyphOutline** when GGO_BITMAP is specified is a DWORD-aligned, row-oriented, monochrome bitmap. When GGO_GRAY2_BITMAP is specified, the bitmap returned is a DWORD-aligned, row-oriented array of bytes whose values range from 0 to 4. When GGO_GRAY4_BITMAP is specified, the bitmap returned is a DWORD-aligned, row-oriented array of bytes whose values range from 0 to 16. When GGO_GRAY8_BITMAP is specified, the bitmap returned is a DWORD-aligned, row-oriented array of bytes whose values range from 0 to 64.

The native buffer returned by **GetGlyphOutline** when GGO_NATIVE is specified is a glyph outline. A glyph outline is returned as a series of one or more contours defined by a [TTPOLYGONHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolygonheader) structure followed by one or more curves. Each curve in the contour is defined by a [TTPOLYCURVE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolycurve) structure followed by a number of [POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx) data points. **POINTFX** points are absolute positions, not relative moves. The starting point of a contour is given by the **pfxStart** member of the **TTPOLYGONHEADER** structure. The starting point of each curve is the last point of the previous curve or the starting point of the contour. The count of data points in a curve is stored in the **cpfx** member of **TTPOLYCURVE** structure. The size of each contour in the buffer, in bytes, is stored in the **cb** member of **TTPOLYGONHEADER** structure. Additional curve definitions are packed into the buffer following preceding curves and additional contours are packed into the buffer following preceding contours. The buffer contains as many contours as fit within the buffer returned by **GetGlyphOutline**.

The [GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics) structure specifies the width of the character cell and the location of a glyph within the character cell. The origin of the character cell is located at the left side of the cell at the baseline of the font. The location of the glyph origin is relative to the character cell origin. The height of a character cell, the baseline, and other metrics global to the font are given by the [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure.

An application can alter the characters retrieved in bitmap or native format by specifying a 2-by-2 transformation matrix in the *lpMatrix* parameter. For example the glyph can be modified by shear, rotation, scaling, or any combination of the three using matrix multiplication.

Additional information on a glyph outlines is located in the TrueType and the OpenType technical specifications.

> [!NOTE]
> The wingdi.h header defines GetGlyphOutline as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ExtTextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta)

[FORM_INFO_1](https://learn.microsoft.com/windows/desktop/printdocs/form-info-1)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GLYPHMETRICS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-glyphmetrics)

[GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa)

[MAT2](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-mat2)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[POINTFX](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pointfx)

[TTPOLYCURVE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolycurve)

[TTPOLYGONHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-ttpolygonheader)