## Description

The **DXGKARG_CANCELQUEUEDFLIPS** structure contains parameters for the driver's [**DXGKDDI_CANCELQUEUEDFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelqueuedflips) callback function. This structure was superseded by [**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips) starting in WDDM 3.0.

## Members

### `VidPnSourceId`

[in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source ID of the flip queue.

### `LayerIndex`

[in] Identifies the MPO plane index in the flip queue.

### `PresentIdCancelRequested`

[in] Identifies the range of PresentIds to cancel. This value is the first flip in the range of [**PresentIdCancelRequested**, *LastSubmittedPresentIdToDriver*] flips to be cancelled.

### `PresentIdCancelled`

[out] Specifies the range of PresentIds that the driver synchronously cancelled. This value is the first flip in the range of [**PresentIdCancelled**, *LastSubmittedPresentIdToDriver*] flips that were cancelled. Possible values for **PresentIdCancelled** follow.

| Value | Meaning |
| ----- | ------- |
| **PresentIdCancelRequested** | The driver cancelled all pending flips in the specified range. |
| Greater than or equal to **PresentIdCancelRequested** | The driver couldn't cancel one or more of the pending presents in the specified range. |
| Zero | None of the pending presents were synchronously cancelled. |

## Remarks

Asynchronously cancelled PresentIds are reported via the [VSync interrupt mechanism](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior).

## See also

[**DXGKARG_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_cancelflips)