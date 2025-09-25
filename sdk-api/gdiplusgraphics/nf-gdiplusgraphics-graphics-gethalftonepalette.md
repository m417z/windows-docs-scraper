# Graphics::GetHalftonePalette

## Description

The **Graphics::GetHalftonePalette** method gets a Windows halftone palette.

## Return value

Type: **static**

This method returns a handle to a Windows halftone palette.

## Remarks

The purpose of the **Graphics::GetHalftonePalette** method is to enable GDI+ to produce a better quality halftone when the display uses 8 bits per pixel. To display an image using the halftone palette, use the following procedure:

1. Call **Graphics::GetHalftonePalette** to get a GDI+ halftone palette.
2. Select the halftone palette into a device context.
3. Realize the palette by calling the
   [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) function.
4. Construct a
   [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object from a handle to the device context.
5. Call the
   [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536028(v=vs.85)) method of the
   [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

Be sure to delete the palette when you have finished using it. If you do not follow the preceding procedure, then on an 8-bits-per-pixel-display device, the default, 16-color process is used, which results in a lesser quality halftone.

#### Examples

The following example draws the same image twice. Before the image is drawn the second time, the code gets a halftone palette, selects the palette into a device context, and realizes the palette.

```cpp
VOID Example_GetHalftonePalette(HDC hdc)
{
   Image image(L"Mosaic.png");

   Graphics* graphics1 = new Graphics(hdc);
   graphics1->DrawImage(&image, 10, 10);
   delete graphics1;

   HPALETTE hPalette = Graphics::GetHalftonePalette();
   SelectPalette(hdc, hPalette, FALSE);
   RealizePalette(hdc);
   Graphics* graphics2 = new Graphics(hdc);
   graphics2->DrawImage(&image, 300, 10);
   delete graphics2;
   DeleteObject(hPalette);
}
```

## See also

[GetPalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getpalette)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)

 [SetPalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setpalette)