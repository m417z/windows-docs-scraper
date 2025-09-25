# EngMovePointer function

## Description

The **EngMovePointer** function moves the engine-managed pointer on the device.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the display device surface on which the pointer is to be moved.

### `x` [in]

Specify the x-coordinate on the display where the hot spot of the pointer should be positioned.

A negative *x* value indicates that the pointer should be removed from the display because drawing is about to occur at its present location. If the pointer has been removed from the display and the *x* value is nonnegative, the pointer should be restored.

### `y` [in]

Specify the y-coordinate on the display where the hot spot of the pointer should be positioned.

### `prcl` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure defining an area that bounds all pixels affected by the pointer on the display. The driver should pass the *prcl* parameter received by its [DrvMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvmovepointer) function. GDI will not draw in this rectangle without first removing the pointer from the screen. This parameter can be **NULL**.

## Return value

None

## Remarks

**EngMovePointer** must not be called while any thread is drawing in the display driver.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvmovepointer)

[EngSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetpointershape)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)