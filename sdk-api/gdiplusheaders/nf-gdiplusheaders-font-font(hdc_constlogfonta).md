# Font::Font(IN HDC,IN const LOGFONTA)

## Description

Creates a **Font::Font** object directly from a Windows Graphics Device Interface (GDI) logical font. The GDI logical font is a
**LOGFONTA** structure, which is the one-byte character version of a logical font. This constructor is provided for compatibility with GDI.

## Parameters

### `hdc` [in]

Type: **HDC**

Handle to a Windows device context. A handle is a number that Windows uses internally to reference an object.

### `logfont` [in]

Type: **const LOGFONTA***

Pointer to a
**LOGFONTA** structure variable that contains attributes of the font. The
**LOGFONTA** structure is the one-byte character version of the logical font.

## Remarks

A device context is a structure that is maintained internally. It is associated with a particular device, such as a video monitor or a printer. There is usually one device context associated with each window displayed on a video monitor. A device context contains some graphics attributes used by GDI+.

A
**LOGFONTA** structure is a GDI structure. GDI+ uses only some of the attributes contained in this structure.

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)