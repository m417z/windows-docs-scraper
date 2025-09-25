## Description

The **DitherType** enumeration identifies the available algorithms for dithering when a bitmap is converted.

Calling the [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) method of a [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object changes the pixel format of that **Bitmap**. If the conversion results in a reduced bit depth (fewer bits per pixel), then certain colors in the original bitmap will be simulated by a dither (checkerboard) pattern made up of colors that are available in the new pixel format. The members of the **DitherType** enumeration identify the algorithms available for performing this dithering.

## Constants

### `DitherTypeNone:0`

No dithering is performed. Pixels in the source bitmap are mapped to the nearest color in the palette specified by the *palette* parameter of the [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) method. This algorithm can be used with any palette. If the palette specified by the *palette* parameter does not have one of the standard fixed formats listed in the [PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype) enumeration, pass **PaletteTypeCustom** to the *palettetype* parameter.

### `DitherTypeSolid:1`

No dithering is performed. Pixels in the source bitmap are mapped to the nearest color in the palette specified by the *palette* parameter of the [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) method. This algorithm can be used with any palette. If the palette specified by the *palette* parameter does not have one of the standard fixed formats listed in the [PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype) enumeration, pass **PaletteTypeCustom** to the *palettetype* parameter.

### `DitherTypeOrdered4x4:2`

You can use this algorithm to perform dithering based on the colors in one of the standard fixed palettes. You can also use this algorithm to convert a bitmap to a 16-bits-per-pixel format that has no palette.

### `DitherTypeOrdered8x8:3`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeOrdered16x16:4`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeSpiral4x4:5`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeSpiral8x8:6`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeDualSpiral4x4:7`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeDualSpiral8x8:8`

Dithering is performed using the colors in one of the standard fixed palettes.

### `DitherTypeErrorDiffusion:9`

Dithering is performed based on the palette specified by the *palette* parameter of the [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) method. This algorithm can be used with any palette. If the palette specified by the *palette* parameter does not have one of the standard fixed formats listed in the [PaletteType](https://learn.microsoft.com/windows/desktop/api/gdipluspixelformats/ne-gdipluspixelformats-palettetype) enumeration, pass **PaletteTypeCustom** to the *palettetype* parameter.

### `DitherTypeMax:10`

TBD

## Remarks

If you pass any of the ordered or spiral dither types (except **DitherTypeOrdered4x4**) to the *dithertype* parameter of the [Bitmap::ConvertFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-convertformat) method, you must pass one of the following fixed palette types to the *palettetype* parameter.

* **PaletteTypeFixedBW**
* **PaletteTypeFixedHalftone8**
* **PaletteTypeFixedHalftone27**
* **PaletteTypeFixedHalftone64**
* **PaletteTypeFixedHalftone125**
* **PaletteTypeFixedHalftone216**
* **PaletteTypeFixedHalftone252**
* **PaletteTypeFixedHalftone256**

The **DitherTypeOrdered4x4** algorithm is a special case. You can use it with the fixed palette types shown in the preceding list or you can use it to convert a bitmap to a 16-bits-per-pixel format.