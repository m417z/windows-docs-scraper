# DrawString(WCHAR*,INT,Font*,RectF&,StringFormat*,Brush*)

## Description

The **Graphics::DrawString** method draws a string based on a font, a layout rectangle, and a format.

## Parameters

### `string`

Pointer to a wide-character string to be drawn.

### `length`

Integer that specifies the number of characters in the *string* array.
The *length* parameter can be set to -1 if the string is null terminated.

### `font`

Pointer to a [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object that specifies the font attributes (the family name, the size, and the style of the font) to use.

### `layoutRect`

Reference to a rectangle that bounds the string.

### `stringFormat`

Pointer to a [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object that specifies text layout information and display manipulations to be applied to the string.

### `brush`

Pointer to a [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to fill the string.

## Return value

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the **Status** enumeration.

## Remarks

Note that GDI+ does not support PostScript fonts or OpenType fonts which do not have TrueType outlines.

When you use the GDI+ API, you must not allow your application to download arbitrary fonts from untrusted sources.
The operating system requires elevated privileges to assure that all installed fonts are trusted.

#### Examples

The following example uses the specified formatting to draw a string in a layout rectangle.

```cpp
VOID Example_DrawString(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a string.
   WCHAR string[] = L"Sample Text";

   // Initialize arguments.
   Font myFont(L"Arial", 16);
   RectF layoutRect(0.0f, 0.0f, 200.0f, 50.0f);
   StringFormat format;
   format.SetAlignment(StringAlignmentCenter);
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Draw string.
   graphics.DrawString(
   string,
   11,
   &myFont,
   layoutRect,
   &format,
   &blackBrush);

   // Draw layoutRect.
   graphics.DrawRectangle(&Pen(Color::Black, 3), layoutRect);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)