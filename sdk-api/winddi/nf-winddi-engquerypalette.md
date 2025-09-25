# EngQueryPalette function

## Description

The **EngQueryPalette** function queries the specified palette for its attributes.

## Parameters

### `hpal`

Handle to the palette to be queried.

### `piMode`

Pointer to a location that receives the palette mode, as originally specified in [EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette).

### `cColors`

Specifies the number of entries in the buffer to which *pulColors* points. The return value depends on whether *cColors* is negative.

### `pulColors`

Pointer to a buffer that receives the palette color information. If *cColors* is zero, *pulColors* can be **NULL**.

## Return value

When *cColors* is zero, **EngQueryPalette** returns the number of palette entries required in the buffer to which *pulColors* points in order to return the palette color information. When *cColors* is nonzero and *pulColors* is not **NULL**, **EngQueryPalette** returns the number of entries written in the buffer to which *pulColors* points.

## Remarks

If the palette mode is PAL_BITFIELDS, PAL_RGB, or PAL_BGR and the buffer that *pulColors* points to is large enough, *pulColors* points to three ULONG masks that represent the red, green, and blue color masks of the palette.

If the palette mode is PAL_INDEXED and the buffer that *pulColors* points to is large enough, *pulColors* contains all of the 24-bit RGB values that represent the palette colors.

A driver must test for the presence of the GCAPS_PALMANAGED flag to determine whether the colors represent a fixed or a changeable palette.

**EngQueryPalette** is intended for use by mirroring drivers that need to know the color format of the primary display. A mirroring driver typically calls this function in its [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) routine.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette)