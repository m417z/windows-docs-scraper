## Description

In the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the OS calls a display miniport driver's [**DXGKDDI_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setflipqueuelogbuffer) function to provide the driver with the flip queue log.

## Parameters

### `hAdapter`

[in] Handle to a display adapter.

### `pSetFlipQueueLogBuffer`

[in] Pointer to a [**DXGKARG_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setflipqueuelogbuffer) structure containing the parameters for this function.

## Return value

**DXGKDDI_SETFLIPQUEUELOGBUFFER** returns an NTSTATUS code such as one of the following:

| Return value | Meaning |
| ------------ | ------- |
| STATUS_SUCCESS | The routine completed successfully. If DXGKARG_SETFLIPQUEUELOGBUFFER::LogBufferAddress is NULL then this DDI must return STATUS_SUCCESS. |
| STATUS_NO_MEMORY | The function failed because it was unable to allocate the amount of memory needed to complete successfully. |
| STATUS_NOT_IMPLEMENTED | The driver does not implement support for this operation. |

## Remarks

See [Obtaining present statistics for queued flips](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#obtaining-present-statistics-for-queued-flips) for more information.

## See also

[**DXGKARG_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setflipqueuelogbuffer)