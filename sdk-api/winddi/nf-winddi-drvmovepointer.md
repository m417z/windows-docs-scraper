# DrvMovePointer function

## Description

The **DrvMovePointer** function moves the pointer to a new position and ensures that GDI does not interfere with the display of the pointer.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface of a display device.

### `x` [in]

Specify the *x* coordinate on the display where the driver should position the hot spot of the pointer.

A negative *x* value indicates that the driver should remove the pointer from the display because drawing is about to occur where it is presently located. If the pointer has been removed from the display and the *x* value is nonnegative, the driver should restore the pointer.

### `y` [in]

Specify the *y* coordinate on the display where the driver should position the hot spot of the pointer.

When the driver has set the GCAPS_PANNING flag in the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure, a negative *y* value indicates that GDI is calling this function only to notify the driver of the cursor's current position. The current position can be computed as (*x*, *y*+*pso*->sizlBitmap.cy). A driver that does not set the GCAPS_PANNING flag will never receive a negative *y* coordinate.

### `prcl` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure defining an area that bounds all pixels affected by the pointer on the display. GDI will not draw in this rectangle without first removing the pointer from the screen. This parameter can be **NULL**.

## Remarks

Drivers sometimes need to know the current position of the pointer on the screen − even when GDI is simulating the pointer (such that the driver no longer gets normal **DrvMovePointer** calls) − in order to handle panning virtual displays. To receive this notification, the driver should set the GCAPS_PANNING flag in the **flGraphicsCaps** field of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

**DrvMovePointer** will not be called while any thread is drawing in the display driver unless the GCAPS_ASYNCMOVE flag is set in the **flGraphicsCaps** member of DEVINFO.

**DrvMovePointer** must be implemented in display drivers only when [DrvSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpointershape) is also implemented.

If a driver has registered the specified pointer using [DrvSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpointershape), **DrvMovePointer** must not fail.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpointershape)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)