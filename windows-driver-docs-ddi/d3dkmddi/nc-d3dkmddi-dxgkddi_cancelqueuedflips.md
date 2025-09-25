## Description

In the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the OS calls a display miniport driver's **DXGKDDI_CANCELQUEUEDFLIPS** function to synchronously cancel previously queued flips. This function was superseded by [**DXGKDDI_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips) starting in WDDM 3.0.

## Parameters

### `hAdapter`

[in] Handle to a display adapter.

### `pCancelQueuedFlips`

[in/out] Pointer to a [**DXGKARG_CANCELQUEUEDFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelqueuedflips) structure containing the parameters for this function.

## Return value

**DXGKDDI_CANCELQUEUEDFLIPS** returns STATUS_SUCCESS. The driver should always return a success code.

## Remarks

Asynchronously cancelled PresentIds are reported via the [VSync interrupt mechanism](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior).

## See also

[**DXGKDDI_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips)