# FontFamily::GetLineSpacing

## Description

The **FontFamily::GetLineSpacing** method gets the line spacing, in design units, of this font family for the specified style or style combination. The line spacing is the vertical distance between the base lines of two consecutive lines of text.

## Parameters

### `style` [in]

Type: **INT**

Integer that specifies the style of the typeface. This value must be an element of the [FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle) enumeration or the result of a bitwise **OR** applied to two or more of these elements. For example, `FontStyleBold | FontStyleUnderline | FontStyleStrikeout` specifies a combination of the three styles.

## Return value

Type: **UINT16**

This method returns the line spacing of this font family.

## See also

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[FontFamily::GetCellAscent](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getcellascent)

[FontFamily::GetCellDescent](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getcelldescent)

[FontFamily::GetEmHeight](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-fontfamily-getemheight)

[FontStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-fontstyle)

[Obtaining Font Metrics](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-obtaining-font-metrics-use)