# DrvSynchronize function

## Description

The **DrvSynchronize** function informs the driver that GDI needs to access a device-managed surface. This function allows asynchronous drawing operations performed by a device's coprocessor to be coordinated with GDI accesses.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) structure that identifies the device to be synchronized with GDI. This parameter is the device handle returned to GDI by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `prcl`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure. This parameter should be ignored by the driver.

## Remarks

This function allows asynchronous drawing operations performed by a device's coprocessor to be coordinated with GDI accesses.

**DrvSynchronize** can be optionally implemented in display drivers. GDI calls this function only if it is hooked by [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). GDI calls **DrvSynchronize** just before drawing directly onto the device surface. GDI will call [DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface) instead of **DrvSynchronize** in drivers that implement both of these functions.

This function should return only when it is safe for GDI to access any device-managed surface. That is, **DrvSynchronize** should delay returning from the call until all asynchronous drawing operations have been completed by the device's coprocessor, thus indicating that it is safe for GDI to access any device-managed surface.

**DrvSynchronize** is intended to support devices that use a coprocessor for drawing. Such a device can treat some drawing operations as asynchronous, returning to GDI from the operation before the drawing is complete. If this is the case, it is possible that a subsequent drawing operation will be handled by GDI. In order for GDI to safely access device-managed surfaces, it must have a means of ensuring that any [asynchronous rendering](https://learn.microsoft.com/windows-hardware/drivers/) being done by the device's coprocessor is complete. By calling this function, GDI synchronizes access to a device-managed surface with the driver.

GDI will never call **DrvSynchronize** for device-managed surfaces. **DrvSynchronize** is not itself an output function.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)