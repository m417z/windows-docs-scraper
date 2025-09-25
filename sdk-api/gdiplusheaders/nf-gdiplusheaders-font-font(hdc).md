# Font::Font(IN HDC)

## Description

Creates a **Font::Font** object based on the Windows Graphics Device Interface (GDI) font object that is currently selected into a specified device context. This constructor is provided for compatibility with GDI.

## Parameters

### `hdc` [in]

Type: **HDC**

Handle to a Windows device context that has a font selected. A handle is a number that Windows uses internally to reference an object.

## Remarks

In most cases when you obtain a device context handle by calling the
[GetHDC](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gethdc) method of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, the device context will not have a font selected. If you pass such a handle to this constructor, the constructor will fail.

A device context is a structure that is maintained internally. It is associated with a particular device, such as a video monitor or a printer. There is usually one device context associated with each window displayed on a video monitor. A device context contains some graphics attributes used by GDI+.

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)