## Description

In the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the OS calls a display miniport driver's **DXGKDDI_CANCELFLIPS** function to synchronously cancel previously queued flips.

## Parameters

### `hAdapter`

[in] Handle to a display adapter.

### `pCancelFlips`

[in/out] Pointer to a [**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips) structure containing the parameters for this function.

## Return value

**DXGKDDI_CANCELFLIPS** returns an NTSTATUS code such as one of the following:

| Return value | Meaning |
| ------------ | ------- |
| STATUS_SUCCESS | The routine completed successfully. |
| STATUS_NOT_IMPLEMENTED | The driver does not implement support for this operation. For this return status, the OS will follow up with a call to [**DxgkDdiCancelQueuedFlips**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelqueuedflips). |

## Remarks

Asynchronously cancelled PresentIds are reported via the [VSync interrupt mechanism](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior).

See [Cancelling interlocked flips on multiple planes](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#cancelling-interlocked-flips-on-multiple-planes) for more information.

## See also

[**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips)