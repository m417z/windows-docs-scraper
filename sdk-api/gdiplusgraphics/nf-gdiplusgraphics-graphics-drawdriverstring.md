# Graphics::DrawDriverString

## Description

The **Graphics::DrawDriverString** method draws characters at the specified positions. The method gives the client complete control over the appearance of text. The method assumes that the client has already set up the format and layout to be applied.

## Parameters

### `text` [in]

Type: **const UINT16***

Pointer to an array of 16-bit values. If the **DriverStringOptionsCmapLookup** flag is set, each value specifies a Unicode character to be displayed. Otherwise, each value specifies an index to a font glyph that defines a character to be displayed.

### `length` [in]

Type: **INT**

Integer that specifies the number of values in the
*text* array. The
*length* parameter can be set to
–1 if the string is null terminated.

### `font` [in]

Type: **const [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)***

Pointer to a [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object that specifies the family name, size, and style of the font that is to be applied to the string.

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to fill the string.

### `positions` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

If the **DriverStringOptionsRealizedAdvance** flag is set, *positions* is a pointer to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object that specifies the position of the first glyph. Otherwise, *positions* is an array of **PointF** objects, each of which specifies the origin of an individual glyph.

### `flags` [in]

Type: **INT**

Integer that specifies the options for the appearance of the string. This value must be an element of the [DriverStringOptions](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-driverstringoptions) enumeration or the result of a bitwise
**OR** applied to two or more of these elements.

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies the transformation matrix to apply to each value in the
*text* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method does not support the handling of complex scripts and assumes that the client has set up all text layout in some other way. This method is useful for creating owner-drawn menu items. The client should use the
[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush)) method for general purposes.

## See also

[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

[DriverStringOptions](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-driverstringoptions)

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::MeasureDriverString](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-measuredriverstring)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)