## Description

The **DXGKARG_UPDATEFLIPQUEUELOG** structure contains parameters for the driver's [**DXGKDDI_UPDATEFLIPQUEUELOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateflipqueuelog) callback function.

## Members

### `VidPnSourceId`

[in] [in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source ID of the hardware flip queue.

### `LayerIndex`

[in] A zero-based index value that identifies the MPO plane index of the flip queue.

### `FirstFreeFlipQueueLogEntryIndex`

[out] Location in which the driver returns the index after the last written entry in the flip queue log buffer.

## Remarks

See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

## See also

[**DXGKDDI_UPDATEFLIPQUEUELOG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateflipqueuelog)