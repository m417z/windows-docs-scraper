# DrvIcmCheckBitmapBits function

## Description

The **DrvIcmCheckBitmapBits** function checks whether the pixels in the specified bitmap lie within the device gamut of the specified transform.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/).

### `hColorTransform`

Handle to the color transform against which the bitmap is to be checked. This transform was created by the driver through a prior call to its [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform) routine.

### `pso`

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) that contains the bitmap surface to be checked.

### `paResults`

Pointer to an array of bytes in which the driver returns the test results. GDI allocates this buffer to contain at least as many bytes as there are pixels in the bitmap. The driver need not perform any allocation or bound checking before writing to the array.

## Return value

**DrvIcmCheckBitmapBits** returns **TRUE** upon success. Otherwise, it reports an error and returns **FALSE**.

## Remarks

Each byte in the array to which *paResults* points corresponds with a pixel in the bitmap. For each pixel, the driver determines whether its color value is in the device gamut and then writes a value between zero and 255 in the corresponding array byte. The values have the following meanings:

| Value | Meaning |
| --- | --- |
| Zero | The color is in the device gamut. |
| Nonzero | The color is outside of the gamut. A value of *n+1* indicates that the color is at least as far out of the gamut as a value of *n*. |

**DrvIcmCheckBitmapBits** can be optionally implemented in drivers that support ICM. A driver indicates support for ICM by setting the GCAPS_ICM flag in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

## See also

[DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform)