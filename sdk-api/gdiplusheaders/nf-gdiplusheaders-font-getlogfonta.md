# Font::GetLogFontA

## Description

The **Font::GetLogFontA** method uses a
**LOGFONTA** structure to get the attributes of this
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) object.

## Parameters

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains attributes of the display device.

### `logfontA` [out]

Type: **LOGFONTA***

Pointer to a
**LOGFONTA** structure variable that receives the font attributes.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)