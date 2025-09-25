# DrvRealizeBrush function

## Description

The **DrvRealizeBrush** function requests that the driver realize a specified brush for a specified surface.

## Parameters

### `pbo` [in]

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that is to be realized. All other parameters, except for *psoTarget*, can be queried from this object. Parameter specifications are provided as an optimization. This parameter is best used only as a parameter for [BRUSHOBJ_pvAllocRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvallocrbrush), which allocates the memory for the realized brush.

### `psoTarget` [in, out]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure for which the brush is to be realized. This surface can be the physical surface for the device, a device format bitmap, or a standard format bitmap.

### `psoPattern` [in]

Pointer to the SURFOBJ structure that describes the pattern for the brush. For a raster device, this is a bitmap. For a vector device, this is one of the pattern surfaces provided by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `psoMask` [in, optional]

Pointer to a SURFOBJ structure that describes a transparency mask for the brush. This is a 1 bit per pixel bitmap that has the same extent as the pattern. A mask of zero means the pixel is considered a background pixel for the brush. (In transparent background mode, the background pixels are unaffected in a fill.) Plotters can ignore this parameter because they never draw background information.

### `pxlo` [in]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the interpretation of colors in the pattern. If *pxlo* is **NULL**, no translation is needed. A XLATEOBJ_*Xxx* service routine can be called to translate the colors to device color indices. Vector devices should translate color zero through the XLATEOBJ to get the foreground color for the brush.

### `iHatch` [in]

Specifies whether *psoPattern* is one of the hatch brushes returned by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev). This is true if the value of this parameter is less than HS_DDI_MAX, which is defined in *winddi.h*.

## Return value

The return value is **TRUE** if the brush was successfully realized. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

To realize a brush, the driver converts a GDI brush into a form that can be used internally. A realized brush contains device-specific information needed by the device to accelerate drawing using the brush.

The driver's realization of a brush is written into the buffer allocated by a call to [BRUSHOBJ_pvAllocRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvallocrbrush).

**DrvRealizeBrush** is required for a driver that does any drawing to any surface.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[BRUSHOBJ_pvAllocRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvallocrbrush)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)