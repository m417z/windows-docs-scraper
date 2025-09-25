# Font::Font(IN const WCHAR,IN REAL,IN INT,IN Unit,IN const FontCollection)

## Description

Creates a **Font::Font** object based on a font family, a size, a font style, a unit of measurement, and a
[FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object.

## Parameters

### `familyName` [in]

Type: **const WCHAR***

Name of the font family.

### `emSize` [in]

Type: **REAL**

Real number that specifies the em size of the font measured in the units specified in the
*unit* parameter.

### `style` [in]

Type: **INT**

Optional. Integer that specifies the style of the typeface. This value must be an element of the [FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle) enumeration or the result of a bitwise
**OR** applied to two or more of these elements. For example, `FontStyleBold` | `FontStyleUnderline` | `FontStyleStrikeout` sets the style as a combination of the three styles. The default value is `FontStyleRegular`.

### `unit` [in]

Type: **[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)**

Optional. Element of the [Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration that specifies the unit of measurement for the font size. The default value is `UnitPoint`.

### `fontCollection` [in]

Type: **const [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection)***

Optional. Pointer to a
**FontCollection** object that specifies a user-defined group of fonts. If the value of this parameter is **NULL**, the system font collection is used. The default value is **NULL**.

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle)

[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)