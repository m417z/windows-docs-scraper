# MeasureString(WCHAR*,INT,Font*,RectF&,StringFormat*,RectF*,INT*,INT*)

## Description

The **Graphics::MeasureString** method measures the extent of the string in the specified font, format, and layout rectangle.

## Parameters

### `string`

Pointer to a wide-character string to be measured.

**Important** For bidirectional languages, such as Arabic, the string length must not exceed 2046 characters.

### `length`

Integer that specifies the number of characters in the *string* array.
The *length* parameter can be set to -1 if the string is null terminated.

### `font`

Pointer to a [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object that specifies the family name, size, and style of the font to be applied to the string.

### `layoutRect`

Reference to the rectangle that bounds the string.

### `stringFormat`

Pointer to a [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object that specifies the layout information, such as alignment, trimming, tab stops, and so forth.

### `boundingBox`

Pointer to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the rectangle that bounds the string.

### `codepointsFitted`

Optional. Pointer to an **INT** that receives the number of characters that actually fit into the layout rectangle.
The default value is a **NULL** pointer.

### `linesFilled`

Optional.
Pointer to an **INT** that receives the number of lines that fit into the layout rectangle.
The default value is a **NULL** pointer.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

#### Examples

The following example measures the size of a string and then draws a rectangle that represents that size.

```cpp
VOID Example_MeasureString2(HDC hdc)
{
   Graphics graphics(hdc);
   // Set up the string.
   WCHAR string[] = L"Measure Text";
   Font font(L"Arial", 16);
   RectF layoutRect(0.0f, 0.0f, 100.0f, 50.0f);
   StringFormat format;
   format.SetAlignment(StringAlignmentFar);
   RectF boundRect;
   // Measure the string.
   graphics.MeasureString(string, 12, &font, layoutRect, &format, &boundRect);
   // Draw a rectangle that represents the size of the string.
   graphics.DrawRectangle(&Pen(Color(255, 0, 0, 0)), boundRect);
}
```

## See also

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)