# FontFamily::FontFamily(IN const WCHAR,IN const FontCollection)

## Description

Creates a **FontFamily::FontFamily** object based on a specified font family.

## Parameters

### `name` [in]

Type: **const WCHAR***

Name of the font family. For example, Arial.ttf is the name of the Arial font family.

### `fontCollection` [in]

Type: **const [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection)***

Optional. Pointer to a
[FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object that specifies the collection that the font family belongs to. If
**FontCollection** is **NULL**, this font family is not part of a collection. The default value is **NULL**.

## See also

[FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily)

[InstalledFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-installedfontcollection)

[PrivateFontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-privatefontcollection)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)