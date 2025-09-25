# BRUSHOBJ structure

## Description

The **BRUSHOBJ** structure contains three public members that describe a brush object.

## Members

### `iSolidColor`

Specifies the color index of a solid brush. This index has been translated to the target surface's palette. Drawing can proceed without realization of the brush. A value of 0xFFFFFFFF indicates that a nonsolid brush must be realized.

### `pvRbrush`

Pointer to the driver's realized brush.

### `flColorType`

Specifies an FLONG value containing flags that describe this brush object. This member can be a combination of any of the following values (only one of BR_HOST_ICM and BR_DEVICE_ICM can be set):

| Value | Meaning |
| --- | --- |
| BR_CMYKCOLOR | When this bit is set, **iSolidColor** contains a 32-bit [CMYK](https://learn.microsoft.com/windows-hardware/drivers/) color value. Otherwise, **iSolidColor** contains a palette index or 0xFFFFFFFF. |
| BR_DEVICE_ICM | The driver performs image color management for the brush color. |
| BR_HOST_ICM | The driver need not perform image color management for the brush color because GDI (or the calling application) is responsible. |

## Remarks

Drivers can call *BRUSHOBJ_Xxx* service routines to realize brushes or to find previously realized brushes.

If the **iSolidColor** member is 0xFFFFFFFF or the **pvRbrush** member is **NULL**, the driver must call the [BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush) function to realize the brush.

If neither BR_HOST_ICM or BR_DEVICE_ICM are set, ICM is not enabled in the graphics engine or in the driver.

For a description of the FLONG data type, see [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

## See also

[BRUSHOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_hgetcolortransform)

**BRUSHOBJ_pvGetRbrush**

[BRUSHOBJ_ulGetBrushColor](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_ulgetbrushcolor)