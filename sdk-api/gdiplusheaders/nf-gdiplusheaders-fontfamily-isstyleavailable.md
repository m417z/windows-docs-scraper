# FontFamily::IsStyleAvailable

## Description

The **FontFamily::IsStyleAvailable** method determines whether the specified style is available for this font family.

## Parameters

### `style` [in]

Type: **INT**

Integer that specifies the style of the typeface. This value must be an element of the [FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle) enumeration or the result of a bitwise **OR** applied to two or more of these elements. For example, `FontStyleBold | FontStyleUnderline | FontStyleStrikeout`  specifies a combination of the three styles.

## Return value

Type: **BOOL**

If the style or combination of styles is available, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

This method returns a misleading result on some third-party fonts. For example, `IsStyleAvailable(FontStyleUnderline)` may return **FALSE** because it is really testing for a regular style font that also is an underlined font: `(FontStyleRegular | FontStyleUnderline)`. If the font does not have a regular style, the IsStyleAvailable method returns **FALSE**.

#### Examples

The following example creates a [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object. If the font family has a regular style available, the example draws text.

```cpp
VOID Example_IsStyleAvailable(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a FontFamily object.
   FontFamily myFontFamily(L"arial");

   // Check to see if the regular style is available.
   BOOL isStyleAvailable = myFontFamily.IsStyleAvailable(FontStyleRegular);

   // If regular style is available, draw text.
   if (isStyleAvailable)
   {
       SolidBrush solidbrush(Color(255, 0, 0, 0));
       Font       font(&myFontFamily, 16);
       WCHAR      string[100];
       swprintf_s(string, L"myFontFamily is available in regular style");
       graphics.DrawString(string,
                           wcslen(string), &font, PointF(0, 0), &solidbrush);
   }
}
```

## See also

[Creating a Private Font Collection](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-private-font-collection-use)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle)