# FontFamily::GetEmHeight

## Description

The **FontFamily::GetEmHeight** method gets the size (commonly called em size or em height), in design units, of this font family.

## Parameters

### `style` [in]

Type: **INT**

Integer that specifies the style of the typeface. This value must be an element of the [FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle) enumeration or the result of a bitwise **OR** applied to two or more of these elements. For example, `FontStyleBold | FontStyleUnderline | FontStyleStrikeout` specifies a combination of the three styles.

## Return value

Type: **UINT16**

This method returns the size, in design units, of this font family.

## See also

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[FontFamily::GetCellDescent](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getcelldescent)

[FontFamily::GetEmHeight](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getemheight)

[FontFamily::GetLineSpacing](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getlinespacing)

[FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle)

[Obtaining Font Metrics](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-obtaining-font-metrics-use)