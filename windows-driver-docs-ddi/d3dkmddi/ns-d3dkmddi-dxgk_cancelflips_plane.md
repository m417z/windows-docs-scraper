## Description

In the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the **DXGK_CANCELFLIPS_PLANE** structure contains a [plane cancel request](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips).

## Members

### `PresentIdCancelRequested`

[in] Identifies the range of PresentIds to cancel. This value is the first flip in the range of [**PresentIdCancelRequested**, *LastSubmittedPresentIdToDriver*] flips to be cancelled.

### `PresentIdCancelled`

[out] Specifies the range of PresentIds that the driver synchronously cancelled. This value is the first flip in the range of [**PresentIdCancelled**, *LastSubmittedPresentIdToDriver*] flips that were cancelled. Possible values for **PresentIdCancelled** follow.

| Value | Meaning |
| ----- | ------- |
| **PresentIdCancelRequested** | The driver cancelled all pending flips in the specified range. |
| Greater than or equal to **PresentIdCancelRequested** | The driver couldn't cancel one or more of the pending presents in the specified range. |
| Zero | None of the pending presents were synchronously cancelled. |

### `LayerIndex`

[in] Identifies the MPO plane index in the flip queue.

## Remarks

The [**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips) structure contains a pointer to an array of **DXGK_CANCELFLIPS_PLANE** structures, each containing a per plane cancel request.

See [Cancelling interlocked flips on multiple planes](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#cancelling-interlocked-flips-on-multiple-planes) for more information.

## See also

[**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips)

[**DXGKDDI_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips)