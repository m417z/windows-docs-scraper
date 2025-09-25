# GraphicsPath::AddString(IN const WCHAR,IN INT,IN const FontFamily,IN INT,IN REAL,IN const RectF &,IN const StringFormat)

## Description

The **GraphicsPath::AddString** method adds the outline of a string to this path.

## Parameters

### `string` [in]

Type: **const WCHAR***

Pointer to a wide-character string.

### `length` [in]

Type: **INT**

Integer that specifies the number of characters to display. If the *string* parameter points to a **NULL**-terminated string, this parameter can be set to –1.

### `family` [in]

Type: **const [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)***

Pointer to a [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object that specifies the font family for the string.

### `style` [in]

Type: **INT**

Integer that specifies the style of the typeface. This value must be an element of the [FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle) enumeration or the result of a bitwise **OR** applied to two or more of these elements. For example, `FontStyleBold | FontStyleUnderline | FontStyleStrikeout` sets the style as a combination of the three styles.

### `emSize` [in]

Type: **REAL**

Real number that specifies the em size, in world units, of the string characters.

### `layoutRect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that specifies, in world units, the bounding rectangle for the string.

### `format` [in]

Type: **const [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)***

Pointer to a [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object that specifies layout information (alignment, trimming, tab stops, and the like) for the string.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Note that GDI+ does not support PostScript fonts or OpenType fonts which do not have TrueType outlines.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object *path*, adds a **NULL**-terminated string to *path*, and then draws *path*.

```cpp
VOID Example_AddString(HDC hdc)
{
   Graphics graphics(hdc);
   FontFamily fontFamily(L"Times New Roman");
   GraphicsPath path;

   path.AddString(
      L"Hello World",
      -1,                 // NULL-terminated string
      &fontFamily,
      FontStyleRegular,
      48,
      RectF(50.0f, 50.0f, 150.0f, 100.0f),
      NULL);

   Pen pen(Color(255, 255, 0, 0));
   graphics.DrawPath(&pen, &path);
}
```

## See also

[AddString Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addstring(inconstwchar_inint_inconstfontfamily_inint_inreal_inconstpoint__inconststringformat))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)