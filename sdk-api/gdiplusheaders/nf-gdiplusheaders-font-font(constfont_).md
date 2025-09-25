# Font::Font(const Font &)

## Description

This topic lists the constructors of the
[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font) class. For a complete class listing, see **Font Class**.

### Overload list

| Constructor | Description |
| --- | --- |
| [Font(HDC,HFONT)](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-font(inhdc_inconsthfont)) | Creates a [Font::Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-font(inhdc_inconsthfont)) object indirectly from a GDI logical font by using a handle to a GDI **LOGFONT** structure. |
| [Font(HDC,LOGFONTA*)](https://learn.microsoft.com/previous-versions/ms536205(v=vs.85)) | Creates a [Font::Font](https://learn.microsoft.com/previous-versions/ms536205(v=vs.85)) object directly from a GDI logical font. The GDI logical font is a **LOGFONTA** structure, which is the one-byte character version of a logical font. This constructor is provided for compatibility with GDI. |
| [Font(HDC,LOGFONTW*)](https://learn.microsoft.com/previous-versions/ms536206(v=vs.85)) | Creates a [Font::Font](https://learn.microsoft.com/previous-versions/ms536206(v=vs.85)) object directly from a GDI logical font. The GDI logical font is a **LOGFONTW** structure, which is the wide character version of a logical font. This constructor is provided for compatibility with GDI. |
| [Font(FontFamily*,REAL,INT,Unit)](https://learn.microsoft.com/previous-versions/ms536203(v=vs.85)) | Creates a [Font::Font](https://learn.microsoft.com/previous-versions/ms536203(v=vs.85)) object based on a [FontFamily](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontfamily) object, a size, a font style, and a unit of measurement. |
| [Font(WCHAR*,REAL,INT,Unit,FontCollection*)](https://learn.microsoft.com/previous-versions/ms536207(v=vs.85)) | Creates a [Font::Font](https://learn.microsoft.com/previous-versions/ms536207(v=vs.85)) object based on a font family, a size, a font style, a unit of measurement, and a [FontCollection](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-fontcollection) object. |
| [Font(HDC)](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-font(inhdc)) | Creates a [Font::Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-font-font(inhdc)) object based on the GDI font object that is currently selected into a specified device context. This constructor is provided for compatibility with GDI. |

## Parameters