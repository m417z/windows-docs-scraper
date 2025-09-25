## Description

The OS calls **DXGKDDI_UPDATEFLIPQUEUELOG** to request that the display driver update the hardware flip queue log.

## Parameters

### `hAdapter`

[in] Handle to a display adapter.

### `pUpdateFlipQueueLog`

[in/out] Pointer to a [**DXGKARG_UPDATEFLIPQUEUELOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updateflipqueuelog) structure containing the parameters for this function.

## Return value

**DXGKDDI_UPDATEFLIPQUEUELOG** returns STATUS_SUCCESS. The driver should always return a success code.

## Remarks

See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

## See also

[**DXGKARG_UPDATEFLIPQUEUELOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updateflipqueuelog)