# Graphics::DrawString(const WCHAR,INT,const Font,const PointF &,const Brush)

## Description

The **Graphics::DrawString** method draws a string based on a font and an origin for the string.

## Parameters

### `string` [in]

Type: **const WCHAR***

Pointer to a wide-character string to be drawn.

### `length` [in]

Type: **INT**

Integer that specifies the number of characters in the
*string* array. The
*length* parameter can be set to
–1 if the string is null terminated.

### `font` [in]

Type: **const [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)***

Pointer to a [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object that specifies the font attributes (the family name, the size, and the style of the font) to use.

### `origin` [in, ref]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)**

Reference to a
[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) object that specifies the starting point for the string.

### `brush` [in]

Type: **const [Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush)***

Pointer to a
[Brush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-brush) object that is used to fill the string.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Note that GDI+ does not support PostScript fonts or OpenType fonts which do not have TrueType outlines.

When you use the GDI+ API, you must not allow your application to download arbitrary fonts from untrusted sources.
The operating system requires elevated privileges to assure that all installed fonts are trusted.

#### Examples

The following example draws a string at the specified origin.

```cpp
VOID Example_DrawString2(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a string.
   WCHAR string[] = L"Sample Text";

   // Initialize arguments.
   Font myFont(L"Arial", 16);
   PointF origin(0.0f, 0.0f);
   SolidBrush blackBrush(Color(255, 0, 0, 0));

   // Draw string.
   graphics.DrawString(
   string,
   11,
   &myFont,
   origin,
   &blackBrush);
}
```

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)