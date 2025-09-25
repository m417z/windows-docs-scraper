# BRUSHOBJ_pvGetRbrush function

## Description

The **BRUSHOBJ_pvGetRbrush** function retrieves a pointer to the driver's realization of a specified brush.

## Parameters

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure whose realization is requested.

## Return value

The return value is a pointer to the realized brush if the function is successful. If the brush cannot be realized, the return value is null and an error code is logged.

## Remarks

**BRUSHOBJ_pvGetRbrush** is called when the brush is a pattern brush that has not yet been realized; that is, it is called when the **iSolidColor** member of the BRUSHOBJ structure is 0xFFFFFFFF and the **pvRbrush** member is null.

If the brush has not been realized when **BRUSHOBJ_pvGetRbrush** is called, GDI calls the driver-supplied [DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush) function to obtain the driver's realization of the brush. As an acceleration, GDI caches this realization in the **pvRbrush** member of the BRUSHOBJ structure. Then, when an application reuses this brush for another drawing operation, the driver doesn't have to call **BRUSHOBJ_pvGetRbrush** again.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[BRUSHOBJ_pvAllocRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvallocrbrush)

[DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush)