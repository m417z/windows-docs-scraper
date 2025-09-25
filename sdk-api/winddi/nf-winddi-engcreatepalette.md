# EngCreatePalette function

## Description

The **EngCreatePalette** function sends a request to GDI to create an RGB palette.

## Parameters

### `iMode` [in]

Specifies how the palette will be defined. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| PAL_BITFIELDS | The palette is defined by the *flRed*, *flGreen*, and *flBlue* parameters. |
| PAL_BGR | The device accepts RGB colors directly, with B (blue) as the least significant byte. |
| PAL_CMYK | The device accepts CMYK colors directly, with C (cyan) as the least significant byte. |
| PAL_INDEXED | An array of RGB colors is provided with *cColors* and *pulColors*. |
| PAL_RGB | The device accepts RGB colors directly, with R (red) as the least significant byte. |

### `cColors` [in]

If the *iMode* parameter is PAL_INDEXED, *cColors* specifies the number of colors provided in the array pointed to by *pulColors*. Otherwise, this parameter should be zero.

### `pulColors` [in]

Pointer to the beginning of an array of ULONG values if *iMode* is PAL_INDEXED. The low-order 3 bytes of each ULONG define the RGB colors in the palette.

### `flRed` [in]

If the *iMode* parameter is PAL_BITFIELDS, the *flRed*, *flGreen* and *flBlue* parameters are masks that show which bits correspond to red, green, and blue. Each mask must consist of contiguous bits and should not overlap other masks. All combinations of bitfields are supported by GDI.

### `flGreen` [in]

If the *iMode* parameter is PAL_BITFIELDS, the *flRed*, *flGreen* and *flBlue* parameters are masks that show which bits correspond to red, green, and blue. Each mask must consist of contiguous bits and should not overlap other masks. All combinations of bitfields are supported by GDI.

### `flBlue` [in]

If the *iMode* parameter is PAL_BITFIELDS, the *flRed*, *flGreen* and *flBlue* parameters are masks that show which bits correspond to red, green, and blue. Each mask must consist of contiguous bits and should not overlap other masks. All combinations of bitfields are supported by GDI.

## Return value

The return value is a handle to the new palette if the function is successful. Otherwise, it is zero, and an error code is logged.

## Remarks

The driver can associate the new palette with a device by returning a pointer to the palette in the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

A PAL_INDEXED palette associated with the device must have its first index entry set to black (red = 0, green = 0, blue = 0) and its last entry set to white (255, 255, 255). All other entries should be set so that entries whose indexes are one's complements of each other have colors that contrast greatly. For example, if entry 0x9 of a 16 entry palette is set to pure green (0,255,0), entry 0x6 (=~0x9) should be set to a color that contrasts well with green, such as dark purple (128,0,128). Setting entries in this way allows XOR raster operations to behave reasonably. You should delete the palette when you no longer need it by using [EngDeletePalette](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engdeletepalette).

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvSetPalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpalette)

[EngDeletePalette](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engdeletepalette)