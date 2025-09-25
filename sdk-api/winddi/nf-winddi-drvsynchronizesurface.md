# DrvSynchronizeSurface function

## Description

The **DrvSynchronizeSurface** function informs the driver that GDI needs to write to the specified surface. This function allows drawing operations performed by a device's coprocessor to be coordinated with GDI.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which the drawing synchronization is to occur.

### `prcl`

Specifies a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that represents the surface that GDI will draw into, or **NULL**. If this does not collide with the drawing operation in progress, the driver can elect to let GDI draw without waiting for the coprocessor to complete.

### `fl`

Is a flag that specifies the event for which GDI is making the synchronization request. This parameter can be one of the following values:

#### DSS_TIMER_EVENT

GDI is calling this function due to a synchronization timer event. Timer events are generated for only those drivers that specify the GCAPS2_SYNCTIMER bit of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

#### DSS_FLUSH_EVENT

GDI is calling this function due to a synchronization flush event. These flush events are generated for only those drivers that specify the GCAPS2_SYNCFLUSH bit of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

## Remarks

This function allows drawing operations performed by a device's coprocessor to be coordinated with GDI.

**DrvSynchronizeSurface** can be optionally implemented in display drivers. GDI calls this function only if it is hooked by [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). GDI calls **DrvSynchronizeSurface** just before drawing directly onto the device surface.

**DrvSynchronizeSurface** is intended to support devices that use a coprocessor for drawing. Such a device can start a long drawing operation and return to GDI while the operation continues. If the device driver does not perform all drawing operations to the surface, it is possible that a subsequent drawing operation will be handled by GDI. In this case, it is necessary for GDI to wait for the coprocessor to complete its work before GDI can draw on the surface.

This function should return when it is safe for GDI to draw on the surface within the rectangular region specified by *prcl*.

**DrvSynchronizeSurface** is not itself an output function.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvSynchronize](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronize)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)