# Font::GetHeight(IN REAL)

## Description

The **Font::GetHeight** method gets the line spacing, in pixels, of this font. The line spacing is the vertical distance between the base lines of two consecutive lines of text. Thus, the line spacing includes the blank space between lines along with the height of the character itself.

## Parameters

### `dpi` [in]

Type: **REAL**

Real number that specifies the vertical resolution, in dots per inch, of the device that displays the font.

## Return value

Type: **REAL**

This method returns the line spacing of the font in pixels.

## Remarks

If the font unit is set to anything other than [UnitPixel](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit), the height, in pixels, is calculated using the specified vertical resolution. For example, suppose the font unit is inches and the font size is 0.3. Also suppose that for the corresponding font family, the em height is 2048 and the line spacing is 2355. If the specified vertical resolution is 96 dots per inch, the height is calculated as follows:

2355*(0.3/2048)*96 = 33.1171875

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Font::GetSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-getsize)

[Font::GetStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-getstyle)

[Font::GetUnit](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-getunit)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)