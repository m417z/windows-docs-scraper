# Graphics::MeasureString(IN const WCHAR,IN INT,IN const Font,IN const RectF &,OUT RectF)

## Description

The **Graphics::MeasureString** method measures the extent of the string in the specified font and layout rectangle.

## Parameters

### `string` [in]

Type: **const WCHAR***

Pointer to a wide-character string to be measured.

**Important** For bidirectional languages, such as Arabic, the string length must not exceed 2046 characters.

### `length` [in]

Type: **INT**

Integer that specifies the number of characters in the *string* array. The *length* parameter can be set to –1 if the string is null terminated.

### `font` [in]

Type: **const [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)***

Pointer to a [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object that specifies the family name, size, and style of the font that is applied to the string.

### `layoutRect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a rectangle that bounds the string.

### `boundingBox` [out]

Type: **[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)***

Pointer to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the rectangle that bounds the string.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns OK, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)