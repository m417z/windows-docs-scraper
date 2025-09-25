# DrvIcmDeleteColorTransform function

## Description

The **DrvIcmDeleteColorTransform** function deletes the specified color transform.

## Parameters

### `dhpdev` [in]

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/).

### `hcmXform` [in]

Handle to the color transform to be deleted. This color transform was created by the driver in a call to [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform).

## Return value

**DrvIcmDeleteColorTransform** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

Drivers that report ICM support should implement this function. A driver indicates support for ICM by setting the GCAPS_ICM flag in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

## See also

[DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvicmcreatecolortransform)