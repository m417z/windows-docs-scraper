# XLATEOBJ_hGetColorTransform function

## Description

The **XLATEOBJ_hGetColorTransform** function returns the color transform for the specified translation object.

## Parameters

### `pxlo`

Pointer to the [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure whose color transform is being queried. The color transform was created in a prior call to [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform).

## Return value

**XLATEOBJ_hGetColorTransform** returns a handle to the color transform for the specified XLATEOBJ upon success. Otherwise, it returns **NULL**.

## Remarks

**XLATEOBJ_hGetColorTransform** returns **NULL** when it is called in host ICM context or when ICM is disabled.

The color transform for a brush is obtained by calling [BRUSHOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_hgetcolortransform).

## See also

[BRUSHOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_hgetcolortransform)

[DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)