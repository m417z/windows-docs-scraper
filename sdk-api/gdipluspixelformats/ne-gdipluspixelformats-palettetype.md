# PaletteType enumeration

## Description

The **PaletteType** enumeration is used by the [Bitmap::InitializePalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-initializepalette) and [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) methods of the [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) class. The members of the enumeration identify several standard color palette formats.

## Constants

### `PaletteTypeCustom:0`

An arbitrary custom palette provided by the caller.

### `PaletteTypeOptimal:1`

An palette of colors that are optimal for a particular bitmap. To create an optimal palette, pass PaletteTypeOptimal, the number of colors you want in the palette, and the address of a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object to the [Bitmap::InitializePalette](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-initializepalette) method.

### `PaletteTypeFixedBW:2`

A palette that has two colors. This palette type is suitable for bitmaps that store 1 bit per pixel.

### `PaletteTypeFixedHalftone8:3`

A palette based on two intensities each (off or full) for the red, green, and blue channels. Also contains the 16 colors of the system palette. Because all eight of the on/off combinations of red, green, and blue are already in the system palette, this palette is the same as the system palette. This palette type is suitable for bitmaps that store 4 bits per pixel.

### `PaletteTypeFixedHalftone27:4`

A palette based on three intensities each for the red, green, and blue channels. Also contains the 16 colors of the system palette. Eight of the 16 system palette colors are among the 27 three-intensity combinations of red, green, and blue, so the total number of colors in the palette is 35. If the palette also includes the transparent color, the total number of colors is 36.

### `PaletteTypeFixedHalftone64:5`

A palette based on four intensities each for the red, green, and blue channels. Also contains the 16 colors of the system palette. Eight of the 16 system palette colors are among the 64 four-intensity combinations of red, green, and blue, so the total number of colors in the palette is 72. If the palette also includes the transparent color, the total number of colors is 73.

### `PaletteTypeFixedHalftone125:6`

A palette based on five intensities each for the red, green, and blue channels. Also contains the 16 colors of the system palette. Eight of the 16 system palette colors are among the 125 five-intensity combinations of red, green, and blue, so the total number of colors in the palette is 133. If the palette also includes the transparent color, the total number of colors is 134.

### `PaletteTypeFixedHalftone216:7`

A palette based on six intensities each for the red, green, and blue channels. Also contains the 16 colors of the system palette. Eight of the 16 system palette colors are among the 216 six-intensity combinations of red, green, and blue, so the total number of colors in the palette is 224. If the palette also includes the transparent color, the total number of colors is 225. This palette is sometimes called the Windows halftone palette or the Web palette.

### `PaletteTypeFixedHalftone252:8`

A palette based on 6 intensities of red, 7 intensities of green, and 6 intensities of blue. The system palette is not included. The total number of colors is 252. If the palette also includes the transparent color, the total number of colors is 253.

### `PaletteTypeFixedHalftone256:9`

A palette based on 8 intensities of red, 8 intensities of green, and 4 intensities of blue. The system palette is not included. The total number of colors is 256. If the transparent color is included in this palette, it must replace one of the RGB combinations.