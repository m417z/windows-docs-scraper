# ImageAttributes::GetAdjustedPalette

## Description

The **ImageAttributes::GetAdjustedPalette** method adjusts the colors in a palette according to the adjustment settings of a specified category.

## Parameters

### `colorPalette` [in, out]

Type: **[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)***

Pointer to a [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) structure that on input, contains the palette to be adjusted and, on output, receives the adjusted palette.

### `colorAdjustType` [in]

Type: **[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category whose adjustment settings will be applied to the palette.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a color-remap table for the default category, a different color-remap table for the bitmap category, and still a different color-remap table for the pen category.

When you call **ImageAttributes::GetAdjustedPalette**, you can specify the adjustment category that is used to adjust the palette colors. For example, if you pass [ColorAdjustTypeBitmap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::GetAdjustedPalette** method, then the adjustment settings of the bitmap category are used to adjust the palette colors.

#### Examples

The following example initializes a [ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette) structure with four colors: aqua, black, red, and green. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and sets its bitmap remap table so that green will be converted to blue. Then the code adjusts the palette colors by passing the address of the palette to the **ImageAttributes::GetAdjustedPalette** method of the **ImageAttributes** object. The code displays the four palette colors twice: once before the adjustment and once after the adjustment.

```cpp

VOID Example_GetAdjustedPalette(HDC hdc)
{
   Graphics graphics(hdc);
   INT j;

   // Create a palette that has four entries.
   ColorPalette* palette =
      (ColorPalette*)malloc(sizeof(ColorPalette) + 3 * sizeof(ARGB));
   palette->Flags = 0;
   palette->Count = 4;

   palette->Entries[0] = 0xFF00FFFF;   // aqua
   palette->Entries[1] = 0xFF000000;   // black
   palette->Entries[2] = 0xFFFF0000;   // red
   palette->Entries[3] = 0xFF00FF00;   // green

   // Display the four palette colors with no adjustment.
   SolidBrush brush(Color());
   for(j = 0; j < 4; ++j)
   {
      brush.SetColor(palette->Entries[j]);
      graphics.FillRectangle(&brush, 30*j, 0, 20, 20);
   }

   // Create a remap table that converts green to blue.
   ColorMap map;
      map.oldColor = Color(255, 0, 255, 0);  // green
      map.newColor = Color(255, 0, 0, 255);  // blue

   // Create an ImageAttributes object, and set its bitmap remap table.
   ImageAttributes imAtt;
   imAtt.SetRemapTable(1, &map, ColorAdjustTypeBitmap);

   // Adjust the palette.
   imAtt.GetAdjustedPalette(palette, ColorAdjustTypeBitmap);

   // Display the four palette colors after the adjustment.
   for(j = 0; j < 4; ++j)
   {
      brush.SetColor(palette->Entries[j]);
      graphics.FillRectangle(&brush, 30*j, 30, 20, 20);
   }
}
				
```

The following illustration shows the output of the preceding code. Note that the green in the original palette was changed to blue.

![Illustration with two rows of colored rectangles; the last of which is green in Row 1, blue in Row 2](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributesgetadjustedpalette.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)

[ColorPalette](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ns-gdipluspixelformats-colorpalette)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[PaletteFlags](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-paletteflags)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)