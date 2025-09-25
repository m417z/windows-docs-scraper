# EngDitherColor function

## Description

The **EngDitherColor** function returns a standard 8x8 dither that approximates the specified RGB color.

## Parameters

### `hdev`

Handle to the device. This is the handle that GDI passed to [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev).

### `iMode`

Determines the palette that GDI should dither against. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| DM_DEFAULT | Requests that GDI create a dither for the native, default color space of the device. For example, if the device is running at 16bpp, the resulting dither is in a 16bpp format. |
| DM_MONOCHROME | Requests that GDI create the dither for monochrome color space; that is, the dither is returned as a 1bpp bitmap. |

### `rgb`

Specifies the RGB color that is to be dithered. GDI ignores the high byte of this ULONG value.

### `pul`

Pointer to the memory location in which GDI returns the dithering information. The driver must have allocated memory for a standard-format bitmap with dithered brush dimensions of 8x8. The driver must also set the **cxDither** and **cyDither** members of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure to 8.

## Return value

The return value is DCR_DRIVER if the dither values have been calculated by the driver, or DCR_SOLID if the engine should use the best solid color approximation of the color.

## Remarks

**EngDitherColor** can be called for bitmaps that are 8bpp or higher.

## See also

[DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush)