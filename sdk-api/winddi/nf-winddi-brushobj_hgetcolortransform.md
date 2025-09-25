# BRUSHOBJ_hGetColorTransform function

## Description

The **BRUSHOBJ_hGetColorTransform** function retrieves the color transform for the specified brush.

## Parameters

### `pbo`

Pointer to the [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure whose color transform is being queried. The color transform was created in a prior call to [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform).

## Return value

**BRUSHOBJ_hGetColorTransform** returns a handle to the color transform for the specified BRUSHOBJ structure upon success. Otherwise, it returns **NULL**.

## Remarks

**BRUSHOBJ_hGetColorTransform** returns **NULL** when ICM is disabled.

The color transform for a translation object is obtained by calling [XLATEOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_hgetcolortransform).

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform)

[XLATEOBJ_hGetColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_hgetcolortransform)