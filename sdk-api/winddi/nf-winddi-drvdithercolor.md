# DrvDitherColor function

## Description

The **DrvDitherColor** function requests the device to create a brush dithered against a device palette.

## Parameters

### `dhpdev` [in]

Handle to the PDEV structure that describes the physical device against whose palettes the specified color should be dithered.

### `iMode` [in]

Determines the palette to dither against. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| DM_DEFAULT | The driver should create a dither for the native, default color space of the device. For example, if the device is running at 16bpp, the resulting dither should be in a 16bpp format. |
| DM_MONOCHROME | The driver should create the dither for monochrome color space; that is, the dither should be returned as a 1bpp bitmap. |

### `rgb` [in]

Specifies the RGB color that is to be dithered.

### `pul` [in, out]

Pointer to the memory location that receives the dithering information. Memory must have been allocated for a standard-format bitmap with dithered brush dimensions **cxDither** by **cyDither**. These dimensions are members of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure. The bitmap format is determined by the **iDitherFormat** member of the DEVINFO structure.

## Return value

The return value is DCR_DRIVER if the dither values have been calculated by the driver, DCR_SOLID if the engine should use the best solid color approximation of the color, or DCR_HALFTONE if the engine should create a halftone approximation for the driver.

## Remarks

The result of the dither is a set of device color indices stored in *pul*. A brush created using these colors for its pattern should be a good approximation of the given color *rgb*.

*DrvDitherColor* is an optional function that is called only if **cxDither** and **cyDither** are nonzero. Monochrome device drivers, including most raster printers, should use the *iMode* parameter to tell GDI how to get good gray-scale patterns.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)